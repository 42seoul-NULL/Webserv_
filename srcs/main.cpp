/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:32:06 by honlee            #+#    #+#             */
/*   Updated: 2021/05/11 12:51:58 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_cpp/libft.hpp"
#include "../includes/parser.hpp"

int	main(int ac, char **av)
{

	ac = 0;
	if(!Config::getInstance()->makeConfig(av[1]))
		return (1);
	Config::getInstance()->show();
}