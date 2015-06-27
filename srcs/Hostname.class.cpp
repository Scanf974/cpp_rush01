/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 12:23:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 14:33:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Hostname.class.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

/*-------------- Constructors -------------*/
Hostname::Hostname(void) {
	//std::cout << "Hostname: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
Hostname::~Hostname(void) {
	//std::cout << "Hostname: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string			Hostname::getHostName(void) const {
	return (this->_hostName);
}
std::string			Hostname::getUserName(void) const {
	return (this->_userName);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void				Hostname::getInfos(void) {
	char	buf[256];

	gethostname(buf, sizeof(buf));
	this->_hostName = buf;

	char *userName = getenv("LOGNAME");
	std::stringstream ss;
	std::string userNameString;
	ss << userName;
	ss >> userNameString;

	this->_userName = userNameString;
}
