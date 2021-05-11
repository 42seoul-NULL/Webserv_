/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nginx.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:37:04 by honlee            #+#    #+#             */
/*   Updated: 2021/05/11 19:08:37 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NGINX_HPP
# define NGINX_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <sys/select.h>
# include "parser.hpp"

class Nginx
{
	private :
		fd_set	reads;
		fd_set	writes;
		fd_set	errors;
		
		int		fd_max;

		std::map<int, Server> servers;
		std::map<int, Client> clients;

	public	:
		Nginx();
		virtual ~Nginx();

		bool	initServers(int queue_size);
		bool	run(struct timeval	timeout, unsigned int buffer_size);
};

#endif