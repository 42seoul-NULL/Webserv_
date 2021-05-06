/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:58:37 by honlee            #+#    #+#             */
/*   Updated: 2021/05/06 15:59:24 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLETON_HPP
# define SINGLETON_HPP

# include <stdlib.h>

class config
{
    private :
        config(){ this->port = 0; }      // 기본 생성자를 숨겨준다.
		config(const config& origin){}
		config& operator=(const config& origin)	{return (*this);}

		static config*	instance;
		int		port;
	public	:
		virtual ~config()
		{
			delete instance;
		}

		static config* getInstance()
		{
			if (instance == NULL)
				instance = new config();
			return (instance);
		}
		
		void	setPort(int value)
		{
			this->port = value;
		}

		int		getPort(void)
		{
			return (this->port);
		}
};

config* config::instance; // 참고 https://stackoverflow.com/questions/16284629/undefined-reference-to-static-variable-c

#endif