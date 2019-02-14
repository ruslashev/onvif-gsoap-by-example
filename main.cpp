/**
 * ./ipconvif -cIp '192.168.1.53' -cUsr 'admin' -cPwd 'admin' -fIp '192.168.1.51:21' -fUsr 'ftpuser' -fPwd 'Ftpftp123
 *
 */

#include <iostream>
#include "stdio.h"
#include "deps/wsdd.nsmap"
#include "deps/wsseapi.h"
#include "deps/wsaapi.h"
#include <openssl/rsa.h>

#include "deps/soapDeviceBindingProxy.h"
#include "deps/soapMediaBindingProxy.h"
#include "deps/soapPTZBindingProxy.h"
#include "deps/soapPullPointSubscriptionBindingProxy.h"
#include "deps/soapRemoteDiscoveryBindingProxy.h"

#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
#include <ctime>
#include <sstream>   // For stringstream
#include "Snapshot.hpp"
#include <algorithm>

#define MAX_HOSTNAME_LEN 128
#define MAX_LOGMSG_LEN 256

#define log(...) do { printf(__VA_ARGS__); puts(""); } while (0)

#define die(...) do { log(__VA_ARGS__); exit(1); } while (0)

void log_soap_error(struct soap* _psoap)
{
    fflush(stdout);
    log("error=%d faultstring=%s faultcode=%s faultsubcode=%s faultdetail=%s", _psoap->error,
            *soap_faultstring(_psoap), *soap_faultcode(_psoap),*soap_faultsubcode(_psoap),
            *soap_faultdetail(_psoap));
}

int main(int argc, char* argv[])
{
    char szHostName[MAX_HOSTNAME_LEN] = { 0 };

    // Proxy declarations
    DeviceBindingProxy proxyDevice;
    RemoteDiscoveryBindingProxy proxyDiscovery;
    MediaBindingProxy proxyMedia;

    const char *camIp = "x.x.x.x";
    const char *camUsr = "asdf";
    const char *camPwd = "asdf";

    strcat(szHostName, "http://");
    strcat(szHostName, camIp);
    strcat(szHostName, "/onvif/device_service");

    proxyDevice.soap_endpoint = szHostName;

    // Register plugins
    soap_register_plugin(proxyDevice.soap, soap_wsse);
    soap_register_plugin(proxyDiscovery.soap, soap_wsse);
    soap_register_plugin(proxyMedia.soap, soap_wsse);

    struct soap *soap = soap_new();
    // For DeviceBindingProxy
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyDevice.soap, NULL, camUsr, camPwd))
    {
        return -1;
    }

    if (SOAP_OK != soap_wsse_add_Timestamp(proxyDevice.soap, "Time", 10))
    {
        return -1;
    }

    // Get Device info
    _tds__GetDeviceInformation *tds__GetDeviceInformation = soap_new__tds__GetDeviceInformation(soap, -1);
    _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse = soap_new__tds__GetDeviceInformationResponse(soap, -1);

    if (SOAP_OK == proxyDevice.GetDeviceInformation(tds__GetDeviceInformation, *tds__GetDeviceInformationResponse))
    {
        log("-------------------DeviceInformation-------------------");
        log("Manufacturer:%s\nModel:%s\nFirmwareVersion:%s\nSerialNumber:%s\nHardwareId:%s",
                tds__GetDeviceInformationResponse->Manufacturer.c_str(),
                tds__GetDeviceInformationResponse->Model.c_str(),
                tds__GetDeviceInformationResponse->FirmwareVersion.c_str(),
                tds__GetDeviceInformationResponse->SerialNumber.c_str(),
                tds__GetDeviceInformationResponse->HardwareId.c_str());
    }
    else
    {
        log_soap_error(proxyDevice.soap);
        return -1;
    }

    // DeviceBindingProxy ends
    soap_destroy(soap);
    soap_end(soap);

    // Get Device capabilities
    _tds__GetCapabilities *tds__GetCapabilities = soap_new__tds__GetCapabilities(soap, -1);
    _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse = soap_new__tds__GetCapabilitiesResponse(soap, -1);

    if (SOAP_OK == proxyDevice.GetCapabilities(tds__GetCapabilities, *tds__GetCapabilitiesResponse))
    {

        if (tds__GetCapabilitiesResponse->Capabilities->Media != NULL)
        {
            log("-------------------Media-------------------");
            log("XAddr:%s", tds__GetCapabilitiesResponse->Capabilities->Media->XAddr.c_str());

            log("-------------------streaming-------------------");
            log("RTPMulticast:%s", (tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTPMulticast) ? "Y" : "N");
            log("RTP_TCP:%s", (tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP) ? "Y" : "N");
            log("RTP_RTSP_TCP:%s", (tds__GetCapabilitiesResponse->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP) ? "Y" : "N");

            proxyMedia.soap_endpoint = tds__GetCapabilitiesResponse->Capabilities->Media->XAddr.c_str();

            // TODO: Add check to see if device is capable of 'GetSnapshotUri', if not skip this device!
        }
    }

    // For MediaBindingProxy
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, camUsr, camPwd))
    {
        return -1;
    }

    if (SOAP_OK != soap_wsse_add_Timestamp(proxyMedia.soap, "Time", 10))
    {
        return -1;
    }

    // Get Device Profiles
    _trt__GetProfiles *trt__GetProfiles = soap_new__trt__GetProfiles(soap, -1);
    _trt__GetProfilesResponse *trt__GetProfilesResponse = soap_new__trt__GetProfilesResponse(soap, -1);


    if (SOAP_OK == proxyMedia.GetProfiles(trt__GetProfiles, *trt__GetProfilesResponse))
    {
        _trt__GetSnapshotUriResponse *trt__GetSnapshotUriResponse = soap_new__trt__GetSnapshotUriResponse(soap, -1);
        _trt__GetSnapshotUri *trt__GetSnapshotUri = soap_new__trt__GetSnapshotUri(soap, -1);

        // log(-------------------ONE SNAPSHOT PER PROFILE-------------------");

        // Loop for every profile
        for (int i = 0; i < trt__GetProfilesResponse->Profiles.size(); i++)
        {
            trt__GetSnapshotUri->ProfileToken = trt__GetProfilesResponse->Profiles[i]->token;

            if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, camUsr, camPwd))
            {
                return -1;
            }

            // Get Snapshot URI for profile
            if (SOAP_OK == proxyMedia.GetSnapshotUri(trt__GetSnapshotUri, *trt__GetSnapshotUriResponse))
            {
                log("Profile Name- %s", trt__GetProfilesResponse->Profiles[i]->Name.c_str());
                log("SNAPSHOT URI- %s", trt__GetSnapshotUriResponse->MediaUri->Uri.c_str());

                // Create a 'Snapshot' instance
                Snapshot *snapshot = new Snapshot("./downloads", "1.jpg");

                // Download snapshot file locally
                CURLcode result = snapshot->download(trt__GetSnapshotUriResponse->MediaUri->Uri);

                // Delete current 'Snapshot' instance
                // delete snapshot;

                // Break out of the media profiles loop (now that we have one snapshot uploaded),
                // so we only take one Snapshot per camera.
                break;
            }
            else
            {
                log_soap_error(proxyMedia.soap);
            }
        }
    }
    else
    {
        log_soap_error(proxyMedia.soap);
    }

    // MediaBindingProxy ends
    soap_destroy(soap);
    soap_end(soap);

    return 0;
}

