#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <stdlib.h>
# include <string>
# include <map>
# include <list>
# include <unistd.h>
# include <fcntl.h>
# include <iostream>
# include <vector>
# include "../libft_cpp/libft.hpp"
# include <queue>
# include "Request.hpp"

typedef enum			t_status
{
	REQUEST_RECEIVING,
	RESPONSE_READY
}						t_status;

class Location;
class Server;

class Config
{
	private :
		Config(){};
		Config(const Config &src);
		Config& operator=(const Config& src);
		bool	returnFalseWithMsg(const char *str);
		bool	isReserved(const std::string &src);

		std::map<std::string, Server> servers;
		static Config*	instance;

	public	:
		virtual ~Config();
		static Config* getInstance();
		std::map<std::string, Server>& getServers();
		bool	makeConfig(const char *path);
		
		//for test
		void	show();
};

class Client
{
	private	:
		t_status		status;
		int				server_socket_fd;
		int				socket_fd;
		Request			request;
		long long		remain_body;
		unsigned long	last_request_ms;

	public	:
		Client();
		Client(int server_socket_fd, int socket_fd);
		~Client();

		void		setSocketFd(int socket_fd);
		void		setServerSocketFd(int server_socket_fd);
		void		setStatus(t_status status);
		void		setRemainBody(long long remain_body);
		void		setLastRequestMs(unsigned long last_request_ms);

		int			getSocketFd();
		int			getServerSocketFd();
		Request		&getRequest();
		t_status	getStatus();
		long long	getRemainBody();
		unsigned long getLastRequestMs();
};

class Server
{
	private	:
		std::string		ip;
		unsigned short	port;
		std::string		server_name;
		std::string		error_page;
		int				socket_fd;
		std::map<std::string, Location> locations;

	public	:
		Server();
		Server(const Server &src);
		Server& operator=(const Server &src);
		virtual	~Server();

		void	setPort(unsigned short port);
		void	setIP(const std::string &ip);
		void	setServerName(const std::string &server_name);
		void	setSocketFd(int socket_fd);

		const std::string &getIP() const;
		const std::string &getServerName() const;
		unsigned short	   getPort() const;
		int				   getSocketFd() const;
		Location			&getPerfectLocation(std::string &uri);

		std::map<std::string, Location> &getLocations();
		//for test//
		void	show();
};

class Location
{
	private	:
		std::string		root;
		std::list<std::string> index;
		std::list<std::string> allow_methods;
		int	client_body_buffer_size;
		std::string		error_page;
		std::string		error_number;
		std::string		upload_path;
		bool			auto_index;
		std::string		cgi_extension;
		std::string		auth_key;

	public	:
		Location();
		virtual ~Location(){};
		Location(const Location &src);
		Location& operator=(const Location &src);

		void			setRoot(const std::string &root);
		void			setClientBodyBufferSize(int client_body_buffer_size);
		void			setErrorPage(const std::string &error_page);
		void			setErrorNumber(const std::string &error_number);
		void			setUploadPath(const std::string &upload_path);
		void			setAutoIndex(bool auto_index);
		void			setCgiExtension(const std::string &cgi_extension);
		void			setAuthKey(const std::string &auth_key);

		const std::string &getRoot();
		std::list<std::string> &getIndex();
		std::list<std::string> &getAllowMethods();
		int getClientBodyBufferSize();
		const std::string &getErrorPage();
		const std::string &getErorrNumber();
		const std::string &getUploadPath();
		bool	getAutoIndex();
		const std::string &getCgiExtension();
		const std::string &getAuthKey();

		//for test//
		void	show();
};
#endif