//
//  Copyright (C) 2009 by  Haris Kurtagic  www.sl-king.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifndef _c_RestResult_h
#define _c_RestResult_h

#include "RestStatusCodes.h"
#include "c_ExceptionGeoREST.h"
#include "Poco\Exception.h"
#include "Poco\Net\HTTPResponse.h"
class c_RestRequest;
class c_RestResult;
class MgException;
class FdoException;

template class REST_REQUEST_HANDLER_API Ptr<c_RestResult>;

//////////////////////////////////////////////////////////////////
/// <summary>
/// Represents a result returned by a call to a Mg Service.
/// A c_RestResult contains a status code plus data.
/// </summary>
class REST_REQUEST_HANDLER_API  c_RestResult : public MgDisposable
{
EXTERNAL_API:
    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Destructor. This will clean up the result.
    /// </summary>
    virtual ~c_RestResult();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the status code of the result.
    /// <returns>
    /// Success/Error code.
    /// </returns>
    /// </summary>
    Poco::Net::HTTPResponse::HTTPStatus GetStatusCode();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the status code of the result.
    /// <returns>
    /// Nothing.
    /// </returns>
    /// </summary>
    void SetStatusCode(Poco::Net::HTTPResponse::HTTPStatus status);

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the error message in the result.
    /// <returns>
    /// Error message or empty string if error message not set.
    /// </returns>
    /// </summary>
    STRING GetErrorMessage();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the detailed error message in the result.
    /// <returns>
    /// Error message or empty string if error message not set.
    /// </returns>
    /// </summary>
    STRING GetDetailedErrorMessage();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the HTTP status message in the result.
    /// <returns>
    /// Error message or empty string if error message not set.
    /// </returns>
    /// </summary>
    STRING GetHttpStatusMessage();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the error message in the result.
    /// <returns>
    /// Nothing.
    /// </returns>
    /// </summary>
    void SetErrorMessage(CREFSTRING errorMsg);

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the detailed error message in the result.
    /// <returns>
    /// Nothing.
    /// </returns>
    /// </summary>
    void SetDetailedErrorMessage(CREFSTRING errorMsg);

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the HTTP error message in the result.
    /// <returns>
    /// Nothing.
    /// </returns>
    /// </summary>
    void SetHttpStatusMessage(CREFSTRING errorMsg);

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the result object.
    /// <returns>
    /// Pointer to an object
    /// </returns>
    /// </summary>
    MgDisposable* GetResultObject();

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the result object.
    /// </summary>
    /// <param name="resultObject">
    /// object returned by the API
    /// </param>
    /// <param name="contentType">
    /// content type of the result
    /// </param>
    /// <returns>
    /// Nothing.
    /// </returns>
    void SetResultObject(MgDisposable* resultObject, CREFSTRING contentType);

    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Gets the result content type.
    /// <returns>
    /// Content type (e.g. "text/xml")
    /// </returns>
    /// </summary>
    STRING GetResultContentType();

INTERNAL_API:
    //////////////////////////////////////////////////////////////////
    /// <summary>
    /// Constructor. Create a new c_RestResult object.
    /// </summary>
    c_RestResult();

    c_RestResult(MgDisposable* resultObject);

    ///////////////////////////////////////////////////////////////////////////
    /// <summary>
    /// Sets the error information based on a Mg exception.
    /// </summary>
    ///
    void SetErrorInfo(c_RestRequest* awRequest, MgException* mgException);
    
    void SetErrorInfo(c_RestRequest* awRequest, c_ExceptionHTTPStatus& Exception);
    void SetErrorInfo(c_RestRequest* awRequest, Poco::Exception& Exception);
    void SetErrorInfo( c_RestRequest* awRequest, FdoException* Exception );

protected:
    /// <summary>
    /// This method is responsible for releasing all
    /// its member variables and then destruct itself.
    /// </summary>
    /// <returns>Returns nothing</returns>
    virtual void Dispose();

    /// <summary>
    /// Get the class Id
    /// </summary>
    /// <returns>
    /// The integer value
    /// </returns>
    INT32 GetClassId();

private:
    Ptr<MgDisposable> m_pResultObject;
    
public:    
    
    int m_FeatureReader_StartIndex;  // in case when feature reader is returned as result 
    int m_FeatureReader_Count;    
    bool m_IsSitemapXML;
    
private:    
    Poco::Net::HTTPResponse::HTTPStatus    m_StatusCode;
    STRING    m_ErrorMessage;
    STRING    m_DetailedMessage;
    STRING    m_HttpStatusMessage;
    STRING    m_contentType;

};

#endif
