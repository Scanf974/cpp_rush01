/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:19:49 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 15:39:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP 

# include <iostream>
# include "IMonitorModule.class.hpp"

class Hostname : public IMonitorModule
{
public:
	Hostname( void );
	virtual ~Hostname( void );

	std::string			getHostName(void) const;
	std::string			getUserName(void) const;
	virtual void		getInfos(void);


private:
	Hostname( Hostname const & src );
	Hostname & operator=( Hostname const & rhs );

	std::string		_hostName;
	std::string		_userName;
};

#endif
