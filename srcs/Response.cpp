/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyang <juyang@42student.co.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:40:53 by juyang            #+#    #+#             */
/*   Updated: 2021/05/12 16:40:54 by juyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Response.hpp"

std::map<std::string, std::string> Response::mime_type = {
	{".aac", "audio/aac"},
	{".abw", "application/x-abiword"},
	{".arc", "application/octet-stream"},
	{".avi", "video/x-msvideo"},
	{".azw", "application/vnd.amazon.ebook"},
	{".bin", "application/octet-stream"},
	{".bz", "application/x-bzip"},
	{".bz2", "application/x-bzip2"},
	{".csh", "application/x-csh"},
	{".css", "text/css"},
	{".csv", "text/csv"},
	{".doc", "application/msword"},
	{".epub", "application/epub+zip"},
	{".gif", "image/gif"},
	{".htm", "text/html"},
	{".html", "text/html"},
	{".ico", "image/x-icon"},
	{".ics", "text/calendar"},
	{".jar", "Temporary Redirect"},
	{".jpeg", "image/jpeg"},
	{".jpg", "image/jpeg"},
	{".js", "application/js"},
	{".json", "application/json"},
	{".mid", "audio/midi"},
	{".midi", "audio/midi"},
	{".mpeg", "video/mpeg"},
	{".mpkg", "application/vnd.apple.installer+xml"},
	{".odp", "application/vnd.oasis.opendocument.presentation"},
	{".ods", "application/vnd.oasis.opendocument.spreadsheet"},
	{".odt", "application/vnd.oasis.opendocument.text"},
	{".oga", "audio/ogg"},
	{".ogv", "video/ogg"},
	{".ogx", "application/ogg"},
	{".pdf", "application/pdf"},
	{".ppt", "application/vnd.ms-powerpoint"},
	{".rar", "application/x-rar-compressed"},
	{".rtf", "application/rtf"},
	{".sh", "application/x-sh"},
	{".svg", "image/svg+xml"},
	{".swf", "application/x-shockwave-flash"},
	{".tar", "application/x-tar"},
	{".tif", "image/tiff"},
	{".tiff", "image/tiff"},
	{".ttf", "application/x-font-ttf"},
	{".vsd", " application/vnd.visio"},
	{".wav", "audio/x-wav"},
	{".weba", "audio/webm"},
	{".webm", "video/webm"},
	{".webp", "image/webp"},
	{".woff", "application/x-font-woff"},
	{".xhtml", "application/xhtml+xml"},
	{".xls", "application/vnd.ms-excel"},
	{".xml", "application/xml"},
	{".xul", "application/vnd.mozilla.xul+xml"},
	{".zip", "application/zip"},
	{".3gp", "video/3gpp audio/3gpp"},
	{".3g2", "video/3gpp2 audio/3gpp2"},
	{".7z", "application/x-7z-compressed"},
};

std::map<std::string, std::string> Response::status_code = {
	{"100", "Continue"},
	{"101", "Switching Protocols"},
	{"102", "Processing"},
	{"200", "OK"},
	{"201", "Created"},
	{"202", "Accepted"},
	{"203", "Non-authoritative Information"},
	{"204", "No Content"},
	{"205", "Reset Content"},
	{"206", "Partial Content"},
	{"207", "Multi-Status"},
	{"208", "Already Reported"},
	{"226", "IM Used"},
	{"300", "Multiple Choices"},
	{"301", "Moved Permanently"},
	{"302", "Found"},
	{"303", "See Other"},
	{"304", "Not Modified"},
	{"305", "Use Proxy"},
	{"307", "Temporary Redirect"},
	{"308", "Permanent Redirect"},
	{"400", "Bad Request"},
	{"401", "Unauthorized"},
	{"402", "Payment Required"},
	{"403", "Forbidden"},
	{"404", "Not found"},
	{"405", "Method Not Allowed"},
	{"406", "Not Acceptable"},
	{"407", "Proxy Authentication Required"},
	{"408", "Required Timeout"},
	{"409", "Conflict"},
	{"410", "Gone"},
	{"411", "Length Required"},
	{"412", "Precondition Failed"},
	{"413", "Request Entity Too Large"},
	{"414", "Request URI Too Long"},
	{"415", "Unsupported Media Type"},
	{"416", "Requested Range Not Satisfiable"},
	{"417", "Expectation Failed"},
	{"418", "IM_A_TEAPOT"},
	{"500", "Internal Server Error"},
	{"501", "Not Implemented"},
	{"502", "Bad Gateway"},
	{"503", "Service Unavailable"},
	{"504", "Gateway Timeout"},
	{"505", "HTTP Version Not Supported"},
	{"506", "Variant Also Negotiates"},
	{"507", "Insufficient Storage"},
	{"508", "Loop Detected"},
	{"510", "Not Extened"},
	{"511", "Network Authentication Required"},
	{"599", "Network Connect Timeout Error"},
};

Response::Response(void) : allow(""), content_language(""), content_length(""), content_location(""), content_type(""), date(""), last_modified(""), location(""), retry_after(""), server(""), transfer_encoding(""), www_authenticate("");
{

}

Response::Response(const Response& src) : allow(src.allow), content_language(src.content_language), content_length(src.content_length), content_location(src.content_location), content_type(src.content_type), date(src.date), last_modified(src.last_modified), location(src.location), retry_after(src.retry_after), server(src.server), transfer_encoding(src.transfer_encoding), www_authenticate(src.www_authenticate)
{

}

Response::~Response(void)
{

}

Response&	Response::operator=(const Response& src)
{
	this->allow = src.allow;
	this->content_language = src.content_language;
	this->content_length = src.content_length;
	this->content_location = src.content_location;
	this->content_type = src.content_type;
	this->date = src.date;
	this->last_modified = src.last_modified;
	this->location = src.location;
	this->retry_after = src.retry_after;
	this->server = src.server;
	this->transfer_encoding = src.transfer_encoding;
	this->www_authenticate = src.www_authenticate;

	return (*this);
}

const std::string&	Response::getAllow(void) const
{
	return (this->allow);
}

const std::string&	Response::getContentLanguage(void) const
{
	return (this->content_language);
}

const std::string&	Response::getContentLength(void) const
{
	return (this->content_length);
}

const std::string&	Response::getContentType(void) const
{
	return (this->content_type);
}

const std::string&	Response::getDate(void) const
{
	return (this->date);
}

const std::string&	Response::getLastModified(void) const
{
	return (this->server);
}

const std::string&	Response::getLocation(void) const
{
	return (this->location);
}

const std::string&	Response::getRetryAfter(void) const
{
	return (this->retry_after);
}

const std::string&	Response::getServer(void) const
{
	return (this->server);
}

const std::string&	Response::getTransferEncoding(void) const
{
	return (this->transfer_encoding);
}

const std::string&	Response::getWWWAuthenticate(void) const
{
	return (this->www_authenticate);
}

void	Response::setAllow(const std::string& allow)
{
	this->allow = allow;
}

void	Response::setContentLanguage(const std::string& content_language)
{
	this->content_language = content_language;
}

void	Response::setContentLength(const std::string& content_length)
{
	this->content_length = content_length;
}

void	Response::setContentLocation(const std::string& content_location)
{
	this->content_location = content_location;
}

void	Response::setContentType(const std::string& content_type)
{
	this->content_type = content_type;
}

void	Response::setDate(const std::string& date)
{
	this->date = date;
}

void	Response::setLastModified(const std::string& last_modified)
{
	this->last_modified = last_modified;
}

void	Response::setLocation(const std::string& location)
{
	this->location = location;
}

void	Response::setRetryAfter(const std::string& retry_after)
{
	this->retry_after = retry_after;
}

void	Response::setServer(const std::string& server)
{
	this->server = server;
}

void	Response::setTransferEncoding(const std::string& transfer_encoding)
{
	this->transfer_encoding = transfer_encoding;
}

void	Response::setWWWAuthenticate(const std::string& www_authenticate)
{
	this->www_authenticate = www_authenticate;
}

void	Response::initResponse(void)
{
	this->allow = "";
	this->content_language = "";
	this->content_length = "";
	this->content_location = "";
	this->content_type = "";
	this->date = "";
	this->last_modified = "";
	this->location = "";
	this->retry_after = "";
	this->server = "";
	this->transfer_encoding = "";
	this->www_authenticate = "";
}

void	Response::createResponse(const Request& request)
{
	
}

void	Response::generateAllow(const Request& request, Server& server)
{
	for (std::map<std::string, Location>::iterator location_iter = server.getLocations().begin(); location_iter != server.getLocations().begin(); location_iter++)
	{
		for (std::list<std::string>::iterator iter = location_iter->second.getAllowMethods().begin(); iter != location_iter->second.getAllowMethods().end(); iter++)
		{
			// Request에서 URI 처리 후 맞는 Location_Iter Key 찾은 후 작성
		}
	}
}

void	Response::generateContentLanguage(const Request& request)
{
	// 절대적인 규칙의 헤더 필드가 아님, 일본 사람한테 일본 데이터를 보내도 ko-kr일 수 있으니, 회의 후 고정 값 사용해도 무리가 없을 듯 함
	// 고로 Request의 Accept-Language 그대로 사용 가능 할 듯 함.

	this->content_language += request.getAcceptLanguage();
}

void	Response::generateContentLength(const Request& request)
{
	// Body를 모두 고려 한 후 Chunked 에 대한 규칙을 조금 더 논의 한 후 작성해야 할 필요가 있음
	// Entity 에 대한 정의와 규칙이 아직 모호함.
}

void	Response::generateContentLocation(const Request& request)
{
	// 서버에 대한 리소스 접근의 절대적 경로.
	// 추가적인 URI 파싱을 진행 후 서버에 대한 정리를 한 후 해야할 듯
	// 서버 내의 파일 형태와 구조에 대해 생각 해 보아야 함.
	// 지금 작성한 내용은 루트에 대해 해당하는 내용임
	// Accept에 따라 파일의 형태가 달라질 수 있으나, 구현 필요에 대해 생각
	// Accept: application/xml -> /documents/foo.xml
	// Accept: application/json -> /documents/foo.json

	this->content_location += "/";
}

void	Response::generateContentType(const Request& request)
{
	// Body에 대한 데이터 해석
	// Accept에 대한 내용이 있으면 맞춰줘야 할 듯
	// 없을 경우에 개인적인 생각으로는 plain 과 같은 고정으로 사용을 하고, 나머지에 대한 규칙은 cgi 구현 단에서 생각하자.

	this->content_type = request.getContentType();
}

void	Response::generateDate(const Request& request)
{
	// Date 함수 살펴 본 후 작성하자.
	// 메시지가 만들어진 날짜, 객체 생성 시의 시간? 보내기 전 Raw화 하기전의 시간?
}

void	Response::generateLastModified(const Request& request)
{
	// 파일의 최종 수정 시간.
	// stat 함수 체크하자.
	// URI 에 대한 파싱 진행 완료 후 stat 함수를 통해 정보를 읽은 후 수정 날짜를 규격에 맞춰서 작성하면 될듯
}

void	Response::generateLocation(const Request& request, const Server& server)
{
	// 처리 후 완료하는 리다이렉선 URI를 작성하면 될듯.
	// Server 내의 Location 중에서 선택 후 추가 URI 작성하는 방향이 규칙 선정에 효율적일 듯 함
}

void	Response::generateRetryAfter(const Request& request)
{
	// 에러 페이지, 즉 Status Code 중 에러 후 재전송에 대한 값인데,
	// 대부분의 브라우저에서는 무시한다.
	// 어느 정도의 틀만 정한 후 보내주면 될 듯한다.
	// 에러 상황일 때 에러 페이지를 띄워주고 Location으로 Redirection 하기 전의 딜레이 정도로만 생각하자.
}

void	Response::generateServer(const Request& request)
{
	// 사실상 프로젝트 이름 수준이다.
	// 추후 회의를 위해 좋은 이름을 선정 해 보자

	this->server = "NoBusWebserv/1.0 HTTP/1.1";
}

void	Response::generateTransferEncoding(const Request& request)
{
	// chunked 에 대한 기준이 필요함. chunked 해서 Response 까지 보낼 것인지 선택하는게 관건
	// default 로 gzip

	this->transfer_encoding += "gzip";
}

void	Response::generateWWWAuthenticate(const Request& request)
{
	// HTTPS를 단순하게나마 따라하기 위해 작성하는 듯 함.
	// 첫 Client의 Request를 401 Unauthorized 로 인증 요청 후 재전송 된 Authorization 필드를 이용해 작성
	// config의 auth_basic 관련 해서 회의 필요.
	// 우리는 거대한 서비스 작성이 아니니 basic type 으로 고정

	this->www_authenticate += "basic ";
	this->www_authenticate += "realm=";
	// 여기서 auth_basic을 추가하면 될 듯함.
}