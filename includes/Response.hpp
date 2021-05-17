#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <iostream>
# include <map>
# include <ctime>
# include <sys/stat.h>
# include "Request.hpp"

class Request;
class Server;
class Location;

class Response
{
	private:
		std::string raw_response;
		void	makeDefaultBody(std::string &body, int error);
	public:
		Response(void);
		Response(const Response& src);
		virtual ~Response(void);
		Response&	operator=(const Response& src);

		void	initResponse(void);
		void	makeResponse(const Request& request, Location& location);
		void	makeErrorReponse(const Request& request, Location& location, int error);

		int		makeFirstLine(int code);
		int		makeAllow(const Request& request, Location& location);
		int		makeContentLanguage(void);
		int		makeContentLength(int size);
		int		makeContentLocation(const Request& request, Location &location);
		int		makeContentType(const Request& request, const std::string &mime_type);
		int		makeDate(const Request& request);
		int		makeLastModified(const Request& request, Location &location);
		int		makeLocation(Location &location);
		int		makeRetryAfter();
		int		makeServer();
		int		makeWWWAuthenticate();
		int		makeBody(const Request& request, Location &location);

		const std::string&	getRawResponse(void);
};

#endif
