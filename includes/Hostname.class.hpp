/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:19:49 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 16:26:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP 

# include <iostream>
# include "AModule.class.hpp"

class Hostname : public AModule
{
	public:
		Hostname( int x, int y );
		virtual ~Hostname( void );

		std::string			getHostName(void) const;
		std::string			getUserName(void) const;

		virtual void			getInfos(std::string result);
		virtual void			renderNcurses(int h, int w) const;
		virtual	char const 		*printInfos(void) const;
		virtual void			renderQt(QGridLayout **grid) const;



	private:
		Hostname(void);
		Hostname( Hostname const & src );
		Hostname & operator=( Hostname const & rhs );

		std::string		_hostName;
		std::string		_userName;
};

#endif
