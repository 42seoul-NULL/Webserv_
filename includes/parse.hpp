/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:58:37 by honlee            #+#    #+#             */
/*   Updated: 2021/05/06 15:59:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

class location;

class config
{
	private :
		config(){};
		config(const config& origin){};
		config& operator=(const config& origin);

		static config*	instance;

	public	:
		virtual ~config();
		static config* getInstance();
};

class server
{
	private	:
		std::string		ip;
		int				port;
		std::string		server_name;
		std::string		error_page;
		std::map<std::string, location> locations;

	public	:
		server(){};
		server(const server& origin){};
		server& operator=(const server& origin);
		virtual	~server();

		void	setPort(int value);
		void	setIP(const std::string& ip);
		void	setServerName(const std::string& server_name);

		const std::string& getIP();
		const std::string& getServerName();
		int				   getPort();

		std::map<std::string, location>& getLocations();
};

class location
{
	private	:
		std::string		root;
		std::list<std::string> index;
		std::list<std::string> allow_methods;
		unsigned int	client_body_buffer_size;
		std::string		error_page;

	public	:
		location(){};
		virtual ~location(){};
		location(const location& origin);
		location& operator=(const location& origin);

		void			setRoot(const std::string& root);
		void			setClientBodyBufferSize(unsigned int value);
		void			setErrorPage(const std::string& error_page);

		const std::string& getRoot();
		std::list<std::string>& getIndex();
		std::list<std::string>& getAllowMethods();
		const unsigned int getClientBodyBufferSize();
		const std::string& getErrorPage();
};
#endif