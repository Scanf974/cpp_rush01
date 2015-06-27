/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:19:49 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:19:50 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP 

class Hostname : public IMonitorModule
{
public:
	Hostname( void );
	virtual ~Hostname( void );

	virtual void		getInfos(void);


private:
	Hostname( Hostname const & src );
	Hostname & operator=( Hostname const & rhs );

	std::string		_hostName;
	std::string		_userName;
};

#endif