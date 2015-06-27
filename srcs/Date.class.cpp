/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:36:26 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 18:03:19 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.class.hpp"
#include "AModule.class.hpp"

/*--------------- Constructors --------------*/
Date::Date(void) : AModule("Date") {
    //std::cout << "Date: Default constructor" << std::endl;
    return ;
}


/*--------------- Destructors --------------*/
Date::~Date(void) {
    //std::cout << "Date: Destructor" << std::endl;
    return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string         Date::getTime(void) const {
    return (this->_time);
}

/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void                Date::getInfos(void) {
	
	std::string			result;
    time_t				rawtime;
    struct tm			*timeinfo;
    char				buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%e/%m/%Y %I:%M:%S%p", timeinfo);

	result = std::string(buffer);
	this->_time = result;
	return ;
}

void				Date::renderNcurses(void) const {
	std::cout << "Time: " << this->_time << std::endl;
}

void				Date::renderQt(void) const {

}
