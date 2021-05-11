/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:32:06 by honlee            #+#    #+#             */
/*   Updated: 2021/05/11 22:08:57 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_cpp/libft.hpp"
#include "../includes/parser.hpp"
#include "../includes/nginx.hpp"

int	main(int ac, char **av)
{
	ac = 0;
	if(!Config::getInstance()->makeConfig(av[1]))
		return (1);

	Nginx nginx;
	struct timeval		timeout;

	timeout.tv_sec = 5;
	timeout.tv_usec = 0;


	try
	{
		nginx.initServers(5);
		nginx.run(timeout, 100);
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}
}