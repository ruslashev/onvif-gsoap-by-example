/* soapImagingBindingProxy.h
   Generated by gSOAP 2.8.74 for deps/onvif/onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapImagingBindingProxy_H
#define soapImagingBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC ImagingBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        /// flag indicating that this context is owned by this proxy and should be deleted by the destructor
        bool soap_own;
        /// Endpoint URL of service 'ImagingBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in deps/onvif/onvif.h, if any
        /// Construct a proxy with new managing context
        ImagingBindingProxy();
        /// Copy constructor
        ImagingBindingProxy(const ImagingBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        ImagingBindingProxy(struct soap*);
        /// Construct proxy given a shared managing context and endpoint URL
        ImagingBindingProxy(struct soap*, const char *soap_endpoint_url);
        /// Constructor taking an endpoint URL
        ImagingBindingProxy(const char *soap_endpoint_url);
        /// Constructor taking input and output mode flags for the new managing context
        ImagingBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        ImagingBindingProxy(const char *soap_endpoint_url, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        ImagingBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~ImagingBindingProxy();
        /// Initializer used by constructors
        virtual void ImagingBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual ImagingBindingProxy *copy();
        /// Copy assignment
        ImagingBindingProxy& operator=(const ImagingBindingProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Add SOAP Header to message
        virtual void soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct wsdd__AppSequenceType *wsdd__AppSequence, struct _wsse__Security *wsse__Security);
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault subcode QName string (NULL when absent)
        virtual const char *soap_fault_subcode();
        /// Get SOAP Fault string/reason (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail XML string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Web service operation 'GetServiceCapabilities' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetServiceCapabilities(_timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse) { return this->GetServiceCapabilities(NULL, NULL, timg__GetServiceCapabilities, timg__GetServiceCapabilitiesResponse); }
        /// Web service operation 'GetServiceCapabilities' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetServiceCapabilities(const char *soap_endpoint_url, const char *soap_action, _timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse);
        /// Web service operation 'GetImagingSettings' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetImagingSettings(_timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse) { return this->GetImagingSettings(NULL, NULL, timg__GetImagingSettings, timg__GetImagingSettingsResponse); }
        /// Web service operation 'GetImagingSettings' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetImagingSettings(const char *soap_endpoint_url, const char *soap_action, _timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse);
        /// Web service operation 'SetImagingSettings' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int SetImagingSettings(_timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse) { return this->SetImagingSettings(NULL, NULL, timg__SetImagingSettings, timg__SetImagingSettingsResponse); }
        /// Web service operation 'SetImagingSettings' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int SetImagingSettings(const char *soap_endpoint_url, const char *soap_action, _timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse);
        /// Web service operation 'GetOptions' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetOptions(_timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse) { return this->GetOptions(NULL, NULL, timg__GetOptions, timg__GetOptionsResponse); }
        /// Web service operation 'GetOptions' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetOptions(const char *soap_endpoint_url, const char *soap_action, _timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse);
        /// Web service operation 'Move' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int Move(_timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse) { return this->Move(NULL, NULL, timg__Move, timg__MoveResponse); }
        /// Web service operation 'Move' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int Move(const char *soap_endpoint_url, const char *soap_action, _timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse);
        /// Web service operation 'Stop' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int Stop(_timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse) { return this->Stop(NULL, NULL, timg__Stop, timg__StopResponse); }
        /// Web service operation 'Stop' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int Stop(const char *soap_endpoint_url, const char *soap_action, _timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse);
        /// Web service operation 'GetStatus' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetStatus(_timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse) { return this->GetStatus(NULL, NULL, timg__GetStatus, timg__GetStatusResponse); }
        /// Web service operation 'GetStatus' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetStatus(const char *soap_endpoint_url, const char *soap_action, _timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse);
        /// Web service operation 'GetMoveOptions' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetMoveOptions(_timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse) { return this->GetMoveOptions(NULL, NULL, timg__GetMoveOptions, timg__GetMoveOptionsResponse); }
        /// Web service operation 'GetMoveOptions' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetMoveOptions(const char *soap_endpoint_url, const char *soap_action, _timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse);
        /// Web service operation 'GetPresets' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetPresets(_timg__GetPresets *timg__GetPresets, _timg__GetPresetsResponse &timg__GetPresetsResponse) { return this->GetPresets(NULL, NULL, timg__GetPresets, timg__GetPresetsResponse); }
        /// Web service operation 'GetPresets' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetPresets(const char *soap_endpoint_url, const char *soap_action, _timg__GetPresets *timg__GetPresets, _timg__GetPresetsResponse &timg__GetPresetsResponse);
        /// Web service operation 'GetCurrentPreset' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int GetCurrentPreset(_timg__GetCurrentPreset *timg__GetCurrentPreset, _timg__GetCurrentPresetResponse &timg__GetCurrentPresetResponse) { return this->GetCurrentPreset(NULL, NULL, timg__GetCurrentPreset, timg__GetCurrentPresetResponse); }
        /// Web service operation 'GetCurrentPreset' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int GetCurrentPreset(const char *soap_endpoint_url, const char *soap_action, _timg__GetCurrentPreset *timg__GetCurrentPreset, _timg__GetCurrentPresetResponse &timg__GetCurrentPresetResponse);
        /// Web service operation 'SetCurrentPreset' to the default endpoint with the default SOAP Action header, returns SOAP_OK or error code
        virtual int SetCurrentPreset(_timg__SetCurrentPreset *timg__SetCurrentPreset, _timg__SetCurrentPresetResponse &timg__SetCurrentPresetResponse) { return this->SetCurrentPreset(NULL, NULL, timg__SetCurrentPreset, timg__SetCurrentPresetResponse); }
        /// Web service operation 'SetCurrentPreset' to an endpoint with a SOAP Action header, returns SOAP_OK or error code
        virtual int SetCurrentPreset(const char *soap_endpoint_url, const char *soap_action, _timg__SetCurrentPreset *timg__SetCurrentPreset, _timg__SetCurrentPresetResponse &timg__SetCurrentPresetResponse);
    };
#endif
