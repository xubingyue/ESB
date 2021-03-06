/* soapStub.h
   Generated by gSOAP 2.8.24 from ESBServiceWSDL.h

gSOAP XML Web services tools
Copyright (C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef soapStub_H
#define soapStub_H
#include <deque>
#include <list>
#include <vector>
#include <set>
#include "stdsoap2.h"
#if GSOAP_VERSION != 20824
# error "GSOAP VERSION 20824 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, because it is declared already in a library or in other parts of the user's project */

#endif

#if 0 /* volatile type: do not declare here, because it is declared already in a library or in other parts of the user's project */

#endif

#ifndef SOAP_TYPE___ns1__ESBOperationResponse
#define SOAP_TYPE___ns1__ESBOperationResponse (15)
/* Operation wrapper: */
struct __ns1__ESBOperationResponse
{
public:
	std::string results;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of XSD type xsd:string */
public:
	int soap_type() const { return 15; } /* = unique type id SOAP_TYPE___ns1__ESBOperationResponse */
	         __ns1__ESBOperationResponse();
	virtual ~__ns1__ESBOperationResponse() { }
};
#endif

#ifndef SOAP_TYPE___ns1__ESBOperation
#define SOAP_TYPE___ns1__ESBOperation (16)
/* Operation wrapper: */
struct __ns1__ESBOperation
{
public:
	std::string session;	/* required element of XSD type xsd:uuid */
	std::string inputs;	/* required element of XSD type xsd:string */
public:
	int soap_type() const { return 16; } /* = unique type id SOAP_TYPE___ns1__ESBOperation */
	         __ns1__ESBOperation();
	virtual ~__ns1__ESBOperation() { }
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (17)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 17; } /* = unique type id SOAP_TYPE_SOAP_ENV__Header */
	         SOAP_ENV__Header();
	virtual ~SOAP_ENV__Header() { }
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (18)
/* Type SOAP_ENV__Code is a recursive data type (in)directly referencing itself through its (base) class members */
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of XSD type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of XSD type SOAP-ENV:Code */
public:
	int soap_type() const { return 18; } /* = unique type id SOAP_TYPE_SOAP_ENV__Code */
	         SOAP_ENV__Code();
	virtual ~SOAP_ENV__Code() { }
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (20)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below)
	   WARNING: do not create a cyclic data structure graph throught this element unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
	void *fault;	/* transient (not serialized) */
public:
	int soap_type() const { return 20; } /* = unique type id SOAP_TYPE_SOAP_ENV__Detail */
	         SOAP_ENV__Detail();
	virtual ~SOAP_ENV__Detail() { }
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (23)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of XSD type xsd:string */
public:
	int soap_type() const { return 23; } /* = unique type id SOAP_TYPE_SOAP_ENV__Reason */
	         SOAP_ENV__Reason();
	virtual ~SOAP_ENV__Reason() { }
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (24)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of XSD type xsd:QName */
	char *faultstring;	/* optional element of XSD type xsd:string */
	char *faultactor;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of XSD type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of XSD type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of XSD type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of XSD type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of XSD type SOAP-ENV:Detail */
public:
	int soap_type() const { return 24; } /* = unique type id SOAP_TYPE_SOAP_ENV__Fault */
	         SOAP_ENV__Fault();
	virtual ~SOAP_ENV__Fault() { }
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE_xsd__uuid
#define SOAP_TYPE_xsd__uuid (12)
typedef std::string xsd__uuid;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 __ns1__ESBOperation(struct soap*, std::string session, std::string inputs, std::string &results);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__ESBOperation(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__ESBOperation(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string session, std::string inputs, std::string &results);

#endif

/* End of soapStub.h */
