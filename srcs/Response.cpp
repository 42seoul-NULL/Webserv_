/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:40:53 by juyang            #+#    #+#             */
/*   Updated: 2021/05/17 17:48:08 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.hpp"
#include "../includes/Response.hpp"

Response::Response(void)
{
	initResponse();
}

Response::Response(const Response& src) : raw_response(src.raw_response)
{

}

Response::~Response(void)
{

}

Response&	Response::operator=(const Response& src)
{
	this->raw_response = src.raw_response;
	return (*this);
}

void	Response::initResponse(void)
{
	this->raw_response.clear();
}

int		Response::makeAllow(const Request& request, Location& location)
{
	int ret = 405;

	this->raw_response += "Allow:";
	for (std::list<std::string>::iterator iter = location.getAllowMethods().begin(); iter != location.getAllowMethods().end(); iter++)
	{
		this->raw_response += ' ';
		this->raw_response += (*iter);
		if (request.getMethod() == *iter)
			ret = 200;
	}
	this->raw_response += "\r\n";
	return (ret);
}

void	Response::makeDefaultBody(std::string &body, int error)
{
	body += "<!DOCTYPE html>\n";
	body += "<html>\n";
	body += "<head>\n";
	body += "</head>\n";
	body += "<body>\n";
	body += "<h1>";
	body += ft_itoa(error);
	body += "<h1>\n";
	body += "</body>\n";
	body += "</html>";	
}

void	Response::makeErrorReponse(const Request &request, Location &location, int error)
{
	initResponse();

	// 나중에 처리 할 것

	std::string body;
	
	if (location.getErrorPages().find(error) == location.getErrorPages().end())
		makeDefaultBody(body, error);
	else
	{
		size_t buffer_size = 1000;
		int fd;
		char buf[buffer_size + 1];
		int rb;

		fd = open(location.getErrorPages()[error].c_str(), O_RDONLY);
		if (fd < 0)
			makeDefaultBody(body, error);
		else
		{
			while ( (rb = read(fd, buf, buffer_size)) > 0 )
			{
				buf[rb] = 0;
				body += std::string(buf);
			}
			if (rb < 0)
			{
				body.clear();
				makeDefaultBody(body, error);
			}
			close (fd);
		}
	}
	
	makeFirstLine(error);
	this->raw_response += "Allow:";
	for (std::list<std::string>::iterator iter = location.getAllowMethods().begin(); iter != location.getAllowMethods().end(); iter++)
	{
		raw_response += ' ';
		raw_response += *iter;
	}
	raw_response += "\r\n";
	makeDate(request);
	this->raw_response += "Content-Type: " + Config::getInstance()->getMimeType()[".html"] + "\r\n";
	this->raw_response += "Content-Length: " + ft_itoa(body.size()) + "\r\n";
	this->raw_response += "\r\n";
	this->raw_response += body;
	
	return ;
}

int		Response::makeContentLanguage()
{
	this->raw_response += "Content-Language: ko-kr\r\n";
	return (200);
}

int		Response::makeContentLength(int size)
{
	this->raw_response += "Content-Length: " + ft_itoa(size) + "\r\n";
	return (200);
}

int		Response::makeContentLocation(const Request& request, Location &location)
{
	// 서버에 대한 리소스 접근의 절대적 경로.
	// 추가적인 URI 파싱을 진행 후 서버에 대한 정리를 한 후 해야할 듯
	// 서버 내의 파일 형태와 구조에 대해 생각 해 보아야 함.
	// 지금 작성한 내용은 루트에 대해 해당하는 내용임

	// 반환된 데이터에 대한 위치 //   처리하는 location 이 리다이렉션이 있을 경우 리다이렉션을 처리해서 리다이렉션 주소를 여기에 찍어줌. 예시) content_location: https://www.naver.com\r\n
	if (request.getMethod() == "GET" || request.getMethod() == "HEAD")
	{
		std::string absol_path(location.getRoot());
		absol_path.erase(--(absol_path.end()));
		absol_path += request.getUri();

		this->raw_response += "Content-Location: " + absol_path + "\r\n";		
	}
	return (200);
}

int		Response::makeContentType(const Request& request, const std::string &mime_type)
{
	if (request.getMethod() == "GET" || request.getMethod() == "HEAD")
	{
		// GET // URI    /honlee/asdf.jpg    /naver.com/hello
		// GET / http/1.1    /docs/
		this->raw_response += "Content-Type: " + mime_type + "\r\n";
	}
	return (200);
}

int		Response::makeDate(const Request& request)
{
	// Date 함수 살펴 본 후 작성하자.
	// 메시지가 만들어진 날짜, 객체 생성 시의 시간? 보내기 전 Raw화 하기전의 시간?
	// juyang 의 유산
	time_t t;
	char buffer[4096];
	struct tm* timeinfo;
	(void)request;

	t = time(NULL);
	timeinfo = localtime(&t);
	strftime(buffer, 4096, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);
	this->raw_response += "Date: " + std::string(buffer) + "\r\n";
	return (200);
}

int	Response::makeLastModified(const Request& request, Location &location)
{
	int fd;
	struct stat	sb;
	struct tm*	timeinfo;
	char buffer[4096];
	(void)request;

	std::string absol_path(location.getRoot());
	absol_path.erase(--(absol_path.end()));
	absol_path += request.getUri();

	if ((fd = open(absol_path.c_str(), O_RDONLY)) < 0)
		return (500);
	if (fstat(fd, &sb) < 0)
	{
		close(fd);
		return (500);
	}
	timeinfo = localtime(&sb.st_mtime);
	strftime(buffer, 4096, "%a, %d %b %Y %H:%M:%S GMT", timeinfo); // 연도 잘 안나옴
	this->raw_response += "Last-Modified: " + std::string(buffer) + "\r\n";
	close(fd);
	return (200);
}

int		Response::makeLocation(Location &location)
{
	//redirection
	this->raw_response += "Location: " + location.getRedirectAddr() + "\r\n";
	return (200);
}

int		Response::makeRetryAfter()
{
	this->raw_response += "Retry-After: 120\r\n"; 
	return (200);
}

int		Response::makeServer()
{
	this->raw_response += "Server: ft_nginx_too_many_drivers_without_license\r\n";
	return (200);
}

int		Response::makeWWWAuthenticate()
{
	// HTTPS를 단순하게나마 따라하기 위해 작성하는 듯 함.
	// 첫 Client의 Request를 401 Unauthorized 로 인증 요청 후 재전송 된 Authorization 필드를 이용해 작성
	// config의 auth_basic 관련 해서 회의 필요.
	// 우리는 거대한 서비스 작성이 아니니 basic type 으로 고정

	this->raw_response += "WWW-Authenticate: Basic realm=\"Give me ID:PASS encoded base64\"";
	return (200);
}

int		Response::makeFirstLine(int code)
{
	std::string temp = ft_itoa(code);
	this->raw_response += ("HTTP/1.1 " + temp + " " + Config::getInstance()->getStatusCode()[temp] + "\r\n");
	return (code);
}

int		Response::makeBody(const Request& request, Location &location)
{
	//여기서 만들기 직전에 makeContentType 호출
	int fd;
	struct stat	sb;
	size_t buffer_size = 1001;
	char buf[buffer_size + 1];
	int rb;
	size_t idx;

	std::string absol_path(location.getRoot());
	absol_path.erase(--(absol_path.end()));
	absol_path += request.getUri();

	idx = absol_path.find_first_of('/');
	idx = absol_path.find_first_of('.',idx);
	if (idx == std::string::npos) // 확장자가 없다.
		makeContentType(request, "application/octet-stream");
	else
		makeContentType(request, Config::getInstance()->getMimeType()[absol_path.substr(idx)]);

	if ((fd = open(absol_path.c_str(), O_RDONLY)) < 0)
		return (500);
	if (fstat(fd, &sb) < 0)
	{
		close(fd);
		return (500);
	}

	makeContentLength((int)sb.st_size);
	this->raw_response += "\r\n";

	while ( (rb = read(fd, buf, buffer_size)) > 0 )
	{
		buf[rb] = 0;
		this->raw_response += buf;
	}
	if (rb < 0)
	{
		close(fd);
		return (500);
	}
	close(fd);
	return (200);
}

void	Response::makeResponse(const Request& request, Location &location)
{
	int ret;

	if (request.getMethod() == "GET" || request.getMethod() == "HEAD")
	{
		//   first line :  GET /index/hello 1.1
		if (location.getRedirectReturn() != 0)
		{
			// 따로 처리 (리다이렉션)
			return ;
		}
		
		if (
				(ret = makeFirstLine(200)) != 200 ||
				(ret = makeAllow(request, location)) != 200 ||
				(ret = makeContentLanguage()) != 200 ||
				(ret = makeContentLocation(request, location)) != 200 ||
				(ret = makeDate(request)) != 200 ||
				(ret = makeLastModified(request, location)) != 200 ||
				(ret = makeRetryAfter()) != 200 ||
				(ret = makeServer()) != 200 ||
				(ret = makeWWWAuthenticate()) != 200 ||
				(ret = makeBody(request, location)) != 200
			)
		{
			makeErrorReponse(request, location, ret);
			return ;
		}
		return ;
	}
	return ;
}

const std::string&	Response::getRawResponse(void)
{
	return (this->raw_response);
}