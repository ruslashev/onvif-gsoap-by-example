/* soapImagingBindingProxy.cpp
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

#include "soapImagingBindingProxy.h"

ImagingBindingProxy::ImagingBindingProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ImagingBindingProxy::ImagingBindingProxy(const ImagingBindingProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

ImagingBindingProxy::ImagingBindingProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	ImagingBindingProxy_init(_soap->imode, _soap->omode);
}

ImagingBindingProxy::ImagingBindingProxy(struct soap *_soap, const char *soap_endpoint_url)
{	this->soap = _soap;
	this->soap_own = false;
	ImagingBindingProxy_init(_soap->imode, _soap->omode);
	soap_endpoint = soap_endpoint_url;
}

ImagingBindingProxy::ImagingBindingProxy(const char *soap_endpoint_url)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = soap_endpoint_url;
}

ImagingBindingProxy::ImagingBindingProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingProxy_init(iomode, iomode);
}

ImagingBindingProxy::ImagingBindingProxy(const char *soap_endpoint_url, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingProxy_init(iomode, iomode);
	soap_endpoint = soap_endpoint_url;
}

ImagingBindingProxy::ImagingBindingProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	ImagingBindingProxy_init(imode, omode);
}

ImagingBindingProxy::~ImagingBindingProxy()
{	if (this->soap_own)
		soap_free(this->soap);
}

void ImagingBindingProxy::ImagingBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL },
        { "SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "chan", "http://schemas.microsoft.com/ws/2005/02/duplex", NULL, NULL },
        { "wsa5", "http://www.w3.org/2005/08/addressing", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL },
        { "wsdd", "http://schemas.xmlsoap.org/ws/2005/04/discovery", NULL, NULL },
        { "c14n", "http://www.w3.org/2001/10/xml-exc-c14n#", NULL, NULL },
        { "ds", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL },
        { "saml1", "urn:oasis:names:tc:SAML:1.0:assertion", NULL, NULL },
        { "saml2", "urn:oasis:names:tc:SAML:2.0:assertion", NULL, NULL },
        { "wsu", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd", NULL, NULL },
        { "xenc", "http://www.w3.org/2001/04/xmlenc#", NULL, NULL },
        { "wsc", "http://docs.oasis-open.org/ws-sx/ws-secureconversation/200512", "http://schemas.xmlsoap.org/ws/2005/02/sc", NULL },
        { "wsse", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd", "http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd", NULL },
        { "ns2", "http://www.onvif.org/ver10/pacs", NULL, NULL },
        { "xmime", "http://tempuri.org/xmime.xsd", NULL, NULL },
        { "xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL },
        { "tt", "http://www.onvif.org/ver10/schema", NULL, NULL },
        { "wsrfbf", "http://docs.oasis-open.org/wsrf/bf-2", NULL, NULL },
        { "wstop", "http://docs.oasis-open.org/wsn/t-1", NULL, NULL },
        { "wsrfr", "http://docs.oasis-open.org/wsrf/r-2", NULL, NULL },
        { "ns1", "http://www.onvif.org/ver10/accesscontrol/wsdl", NULL, NULL },
        { "ns10", "http://www.onvif.org/ver10/thermal/wsdl", NULL, NULL },
        { "ns11", "http://www.onvif.org/ver10/uplink/wsdl", NULL, NULL },
        { "ns3", "http://www.onvif.org/ver10/actionengine/wsdl", NULL, NULL },
        { "ns4", "http://www.onvif.org/ver10/authenticationbehavior/wsdl", NULL, NULL },
        { "ns5", "http://www.onvif.org/ver10/credential/wsdl", NULL, NULL },
        { "ns6", "http://www.onvif.org/ver10/doorcontrol/wsdl", NULL, NULL },
        { "ns7", "http://www.onvif.org/ver20/media/wsdl", NULL, NULL },
        { "ns8", "http://www.onvif.org/ver10/provisioning/wsdl", NULL, NULL },
        { "ns9", "http://www.onvif.org/ver10/schedule/wsdl", NULL, NULL },
        { "tan", "http://www.onvif.org/ver20/analytics/wsdl", NULL, NULL },
        { "tas", "http://www.onvif.org/ver10/advancedsecurity/wsdl", NULL, NULL },
        { "tdn", "http://www.onvif.org/ver10/network/wsdl", NULL, NULL },
        { "tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL },
        { "tev", "http://www.onvif.org/ver10/events/wsdl", NULL, NULL },
        { "wsnt", "http://docs.oasis-open.org/wsn/b-2", NULL, NULL },
        { "timg", "http://www.onvif.org/ver20/imaging/wsdl", NULL, NULL },
        { "tls", "http://www.onvif.org/ver10/display/wsdl", NULL, NULL },
        { "tmd", "http://www.onvif.org/ver10/deviceIO/wsdl", NULL, NULL },
        { "tptz", "http://www.onvif.org/ver20/ptz/wsdl", NULL, NULL },
        { "trc", "http://www.onvif.org/ver10/recording/wsdl", NULL, NULL },
        { "trp", "http://www.onvif.org/ver10/replay/wsdl", NULL, NULL },
        { "trt", "http://www.onvif.org/ver10/media/wsdl", NULL, NULL },
        { "trv", "http://www.onvif.org/ver10/receiver/wsdl", NULL, NULL },
        { "tse", "http://www.onvif.org/ver10/search/wsdl", NULL, NULL },
        { NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

ImagingBindingProxy *ImagingBindingProxy::copy()
{	ImagingBindingProxy *dup = SOAP_NEW_UNMANAGED(ImagingBindingProxy);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}

ImagingBindingProxy& ImagingBindingProxy::operator=(const ImagingBindingProxy& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
		this->soap_endpoint = rhs.soap_endpoint;
	}
	return *this;
}

void ImagingBindingProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void ImagingBindingProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	ImagingBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void ImagingBindingProxy::soap_noheader()
{	this->soap->header = NULL;
}

void ImagingBindingProxy::soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct wsdd__AppSequenceType *wsdd__AppSequence, struct _wsse__Security *wsse__Security)
{
	::soap_header(this->soap);
	this->soap->header->wsa5__MessageID = wsa5__MessageID;
	this->soap->header->wsa5__RelatesTo = wsa5__RelatesTo;
	this->soap->header->wsa5__From = wsa5__From;
	this->soap->header->wsa5__ReplyTo = wsa5__ReplyTo;
	this->soap->header->wsa5__FaultTo = wsa5__FaultTo;
	this->soap->header->wsa5__To = wsa5__To;
	this->soap->header->wsa5__Action = wsa5__Action;
	this->soap->header->chan__ChannelInstance = chan__ChannelInstance;
	this->soap->header->wsdd__AppSequence = wsdd__AppSequence;
	this->soap->header->wsse__Security = wsse__Security;
}

::SOAP_ENV__Header *ImagingBindingProxy::soap_header()
{	return this->soap->header;
}

::SOAP_ENV__Fault *ImagingBindingProxy::soap_fault()
{	return this->soap->fault;
}

const char *ImagingBindingProxy::soap_fault_subcode()
{	return ::soap_fault_subcode(this->soap);
}

const char *ImagingBindingProxy::soap_fault_string()
{	return ::soap_fault_string(this->soap);
}

const char *ImagingBindingProxy::soap_fault_detail()
{	return ::soap_fault_detail(this->soap);
}

int ImagingBindingProxy::soap_close_socket()
{	return ::soap_closesock(this->soap);
}

int ImagingBindingProxy::soap_force_close_socket()
{	return ::soap_force_closesock(this->soap);
}

void ImagingBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void ImagingBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *ImagingBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int ImagingBindingProxy::GetServiceCapabilities(const char *soap_endpoint_url, const char *soap_action, _timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse)
{
	struct __timg__GetServiceCapabilities soap_tmp___timg__GetServiceCapabilities;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetServiceCapabilities";
	soap_tmp___timg__GetServiceCapabilities.timg__GetServiceCapabilities = timg__GetServiceCapabilities;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetServiceCapabilities(soap, &soap_tmp___timg__GetServiceCapabilities);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetServiceCapabilities(soap, &soap_tmp___timg__GetServiceCapabilities, "-timg:GetServiceCapabilities", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetServiceCapabilities(soap, &soap_tmp___timg__GetServiceCapabilities, "-timg:GetServiceCapabilities", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetServiceCapabilitiesResponse*>(&timg__GetServiceCapabilitiesResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetServiceCapabilitiesResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetServiceCapabilitiesResponse.soap_get(soap, "timg:GetServiceCapabilitiesResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetImagingSettings(const char *soap_endpoint_url, const char *soap_action, _timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse)
{
	struct __timg__GetImagingSettings soap_tmp___timg__GetImagingSettings;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetImagingSettings";
	soap_tmp___timg__GetImagingSettings.timg__GetImagingSettings = timg__GetImagingSettings;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetImagingSettings(soap, &soap_tmp___timg__GetImagingSettings);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetImagingSettings(soap, &soap_tmp___timg__GetImagingSettings, "-timg:GetImagingSettings", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetImagingSettings(soap, &soap_tmp___timg__GetImagingSettings, "-timg:GetImagingSettings", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetImagingSettingsResponse*>(&timg__GetImagingSettingsResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetImagingSettingsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetImagingSettingsResponse.soap_get(soap, "timg:GetImagingSettingsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::SetImagingSettings(const char *soap_endpoint_url, const char *soap_action, _timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse)
{
	struct __timg__SetImagingSettings soap_tmp___timg__SetImagingSettings;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/SetImagingSettings";
	soap_tmp___timg__SetImagingSettings.timg__SetImagingSettings = timg__SetImagingSettings;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__SetImagingSettings(soap, &soap_tmp___timg__SetImagingSettings);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__SetImagingSettings(soap, &soap_tmp___timg__SetImagingSettings, "-timg:SetImagingSettings", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__SetImagingSettings(soap, &soap_tmp___timg__SetImagingSettings, "-timg:SetImagingSettings", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__SetImagingSettingsResponse*>(&timg__SetImagingSettingsResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__SetImagingSettingsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__SetImagingSettingsResponse.soap_get(soap, "timg:SetImagingSettingsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetOptions(const char *soap_endpoint_url, const char *soap_action, _timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse)
{
	struct __timg__GetOptions soap_tmp___timg__GetOptions;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetOptions";
	soap_tmp___timg__GetOptions.timg__GetOptions = timg__GetOptions;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetOptions(soap, &soap_tmp___timg__GetOptions);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetOptions(soap, &soap_tmp___timg__GetOptions, "-timg:GetOptions", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetOptions(soap, &soap_tmp___timg__GetOptions, "-timg:GetOptions", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetOptionsResponse*>(&timg__GetOptionsResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetOptionsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetOptionsResponse.soap_get(soap, "timg:GetOptionsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::Move(const char *soap_endpoint_url, const char *soap_action, _timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse)
{
	struct __timg__Move soap_tmp___timg__Move;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/Move";
	soap_tmp___timg__Move.timg__Move = timg__Move;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__Move(soap, &soap_tmp___timg__Move);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__Move(soap, &soap_tmp___timg__Move, "-timg:Move", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__Move(soap, &soap_tmp___timg__Move, "-timg:Move", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__MoveResponse*>(&timg__MoveResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__MoveResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__MoveResponse.soap_get(soap, "timg:MoveResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::Stop(const char *soap_endpoint_url, const char *soap_action, _timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse)
{
	struct __timg__Stop soap_tmp___timg__Stop;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/FocusStop";
	soap_tmp___timg__Stop.timg__Stop = timg__Stop;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__Stop(soap, &soap_tmp___timg__Stop);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__Stop(soap, &soap_tmp___timg__Stop, "-timg:Stop", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__Stop(soap, &soap_tmp___timg__Stop, "-timg:Stop", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__StopResponse*>(&timg__StopResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__StopResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__StopResponse.soap_get(soap, "timg:StopResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetStatus(const char *soap_endpoint_url, const char *soap_action, _timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse)
{
	struct __timg__GetStatus soap_tmp___timg__GetStatus;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetStatus";
	soap_tmp___timg__GetStatus.timg__GetStatus = timg__GetStatus;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetStatus(soap, &soap_tmp___timg__GetStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetStatus(soap, &soap_tmp___timg__GetStatus, "-timg:GetStatus", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetStatus(soap, &soap_tmp___timg__GetStatus, "-timg:GetStatus", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetStatusResponse*>(&timg__GetStatusResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetStatusResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetStatusResponse.soap_get(soap, "timg:GetStatusResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetMoveOptions(const char *soap_endpoint_url, const char *soap_action, _timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse)
{
	struct __timg__GetMoveOptions soap_tmp___timg__GetMoveOptions;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetMoveOptions";
	soap_tmp___timg__GetMoveOptions.timg__GetMoveOptions = timg__GetMoveOptions;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetMoveOptions(soap, &soap_tmp___timg__GetMoveOptions);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetMoveOptions(soap, &soap_tmp___timg__GetMoveOptions, "-timg:GetMoveOptions", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetMoveOptions(soap, &soap_tmp___timg__GetMoveOptions, "-timg:GetMoveOptions", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetMoveOptionsResponse*>(&timg__GetMoveOptionsResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetMoveOptionsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetMoveOptionsResponse.soap_get(soap, "timg:GetMoveOptionsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetPresets(const char *soap_endpoint_url, const char *soap_action, _timg__GetPresets *timg__GetPresets, _timg__GetPresetsResponse &timg__GetPresetsResponse)
{
	struct __timg__GetPresets soap_tmp___timg__GetPresets;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetPresets";
	soap_tmp___timg__GetPresets.timg__GetPresets = timg__GetPresets;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetPresets(soap, &soap_tmp___timg__GetPresets);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetPresets(soap, &soap_tmp___timg__GetPresets, "-timg:GetPresets", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetPresets(soap, &soap_tmp___timg__GetPresets, "-timg:GetPresets", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetPresetsResponse*>(&timg__GetPresetsResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetPresetsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetPresetsResponse.soap_get(soap, "timg:GetPresetsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::GetCurrentPreset(const char *soap_endpoint_url, const char *soap_action, _timg__GetCurrentPreset *timg__GetCurrentPreset, _timg__GetCurrentPresetResponse &timg__GetCurrentPresetResponse)
{
	struct __timg__GetCurrentPreset soap_tmp___timg__GetCurrentPreset;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/GetCurrentPreset";
	soap_tmp___timg__GetCurrentPreset.timg__GetCurrentPreset = timg__GetCurrentPreset;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__GetCurrentPreset(soap, &soap_tmp___timg__GetCurrentPreset);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__GetCurrentPreset(soap, &soap_tmp___timg__GetCurrentPreset, "-timg:GetCurrentPreset", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__GetCurrentPreset(soap, &soap_tmp___timg__GetCurrentPreset, "-timg:GetCurrentPreset", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__GetCurrentPresetResponse*>(&timg__GetCurrentPresetResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__GetCurrentPresetResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__GetCurrentPresetResponse.soap_get(soap, "timg:GetCurrentPresetResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int ImagingBindingProxy::SetCurrentPreset(const char *soap_endpoint_url, const char *soap_action, _timg__SetCurrentPreset *timg__SetCurrentPreset, _timg__SetCurrentPresetResponse &timg__SetCurrentPresetResponse)
{
	struct __timg__SetCurrentPreset soap_tmp___timg__SetCurrentPreset;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver20/imaging/wsdl/SetCurrentPreset";
	soap_tmp___timg__SetCurrentPreset.timg__SetCurrentPreset = timg__SetCurrentPreset;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___timg__SetCurrentPreset(soap, &soap_tmp___timg__SetCurrentPreset);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___timg__SetCurrentPreset(soap, &soap_tmp___timg__SetCurrentPreset, "-timg:SetCurrentPreset", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___timg__SetCurrentPreset(soap, &soap_tmp___timg__SetCurrentPreset, "-timg:SetCurrentPreset", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!static_cast<_timg__SetCurrentPresetResponse*>(&timg__SetCurrentPresetResponse)) // NULL ref?
		return soap_closesock(soap);
	timg__SetCurrentPresetResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	timg__SetCurrentPresetResponse.soap_get(soap, "timg:SetCurrentPresetResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
