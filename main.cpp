#include <iostream>
#include "Snapshot.hpp"
#include "deps/wsdd.nsmap"
#include "deps/wsseapi.h"
#include "deps/wsaapi.h"
#include "deps/soapDeviceBindingProxy.h"
#include "deps/soapMediaBindingProxy.h"
#include "deps/soapPTZBindingProxy.h"
#include "deps/soapPullPointSubscriptionBindingProxy.h"
#include "deps/soapRemoteDiscoveryBindingProxy.h"
#include <openssl/rsa.h>

#define MAX_HOSTNAME_LEN 128

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

    soap_register_plugin(proxyDevice.soap, soap_wsse);
    soap_register_plugin(proxyDiscovery.soap, soap_wsse);
    soap_register_plugin(proxyMedia.soap, soap_wsse);

    struct soap *soap = soap_new();

    if (soap_wsse_add_UsernameTokenDigest(proxyDevice.soap, NULL, camUsr, camPwd) != SOAP_OK)
        return 1;

    if (soap_wsse_add_Timestamp(proxyDevice.soap, "Time", 10) != SOAP_OK)
        return 1;

    _tds__GetDeviceInformation *device_info
        = soap_new__tds__GetDeviceInformation(soap, -1);
    _tds__GetDeviceInformationResponse *device_info_response
        = soap_new__tds__GetDeviceInformationResponse(soap, -1);

    if (proxyDevice.GetDeviceInformation(device_info, *device_info_response) == SOAP_OK) {
        log("-------------------DeviceInformation-------------------");
        log("Manufacturer: %s",    device_info_response->Manufacturer.c_str());
        log("Model: %s",           device_info_response->Model.c_str());
        log("FirmwareVersion: %s", device_info_response->FirmwareVersion.c_str());
        log("SerialNumber: %s",    device_info_response->SerialNumber.c_str());
        log("HardwareId: %s",      device_info_response->HardwareId.c_str());
    } else {
        log_soap_error(proxyDevice.soap);
        return 1;
    }

    soap_destroy(soap);
    soap_end(soap);

    _tds__GetCapabilities *capabilities = soap_new__tds__GetCapabilities(soap, -1);
    _tds__GetCapabilitiesResponse *capabilities_response
        = soap_new__tds__GetCapabilitiesResponse(soap, -1);

    if (proxyDevice.GetCapabilities(capabilities, *capabilities_response) == SOAP_OK) {
        if (capabilities_response->Capabilities->Media != NULL) {
            log("-------------------Media-------------------");
            log("XAddr: %s", capabilities_response->Capabilities->Media->XAddr.c_str());

            log("-------------------streaming-------------------");
            log("RTPMulticast: %s",
                    (capabilities_response->Capabilities->Media->StreamingCapabilities->RTPMulticast)
                    ? "Y" : "N");
            log("RTP_TCP: %s", (capabilities_response->Capabilities->Media->StreamingCapabilities->RTP_USCORETCP) ? "Y" : "N");
            log("RTP_RTSP_TCP: %s", (capabilities_response->Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP) ? "Y" : "N");

            proxyMedia.soap_endpoint = capabilities_response->Capabilities->Media->XAddr.c_str();
        }
    }

    if (soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, camUsr, camPwd) != SOAP_OK)
        return 1;

    if (soap_wsse_add_Timestamp(proxyMedia.soap, "Time", 10) != SOAP_OK)
        return 1;

    _trt__GetProfiles *get_profiles = soap_new__trt__GetProfiles(soap, -1);
    _trt__GetProfilesResponse *get_profiles_response = soap_new__trt__GetProfilesResponse(soap, -1);

    if (proxyMedia.GetProfiles(get_profiles, *get_profiles_response) == SOAP_OK) {
        _trt__GetSnapshotUri *get_snapshot_uri = soap_new__trt__GetSnapshotUri(soap, -1);
        _trt__GetSnapshotUriResponse *get_snapshot_uri_response = soap_new__trt__GetSnapshotUriResponse(soap, -1);

        for (size_t i = 0; i < get_profiles_response->Profiles.size(); i++) {
            get_snapshot_uri->ProfileToken = get_profiles_response->Profiles[i]->token;

            if (soap_wsse_add_UsernameTokenDigest(proxyMedia.soap, NULL, camUsr, camPwd) != SOAP_OK)
                return 1;

            if (proxyMedia.GetSnapshotUri(get_snapshot_uri, *get_snapshot_uri_response) == SOAP_OK) {
                log("Profile Name- %s", get_profiles_response->Profiles[i]->Name.c_str());
                log("SNAPSHOT URI- %s", get_snapshot_uri_response->MediaUri->Uri.c_str());

                Snapshot *snapshot = new Snapshot("./downloads", "1.jpg");

                snapshot->download(get_snapshot_uri_response->MediaUri->Uri);

                // Delete current 'Snapshot' instance
                // delete snapshot;

                // Break out of the media profiles loop (now that we have one snapshot uploaded),
                // so we only take one Snapshot per camera.
                break;
            } else
                log_soap_error(proxyMedia.soap);
        }
    } else
        log_soap_error(proxyMedia.soap);

    soap_destroy(soap);
    soap_end(soap);
}

