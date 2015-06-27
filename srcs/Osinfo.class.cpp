/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Osinfo.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:33:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 17:49:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Osinfo.hpp"
#include "AModule.class.hpp"

/*--------------- Constructors --------------*/
Osinfo::Osinfo(void) : AModule("OS Infos") {
    //std::cout << "Osinfo: Default constructor" << std::endl;
    return ;
}


/*--------------- Destructors --------------*/
Osinfo::~Osinfo(void) {
    //std::cout << "Osinfo: Destructor" << std::endl;
    return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string         Osinfo::getRelease(void) const {
    return (this->_release);
}
std::string         Osinfo::getModel(void) const {
    return (this->_model);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void                Osinfo::getInfos(void) {
	char str[256];

	size_t size = sizeof(str);
	sysctlbyname("kern.osrelease", str, &size, NULL, 0);

	this->_release = str;

	char tmp[256];
	size_t size_int = sizeof(tmp); 

	sysctlbyname("hw.model", tmp, &size_int, NULL, 0);
	this->_model = tmp;

	return ;
}
