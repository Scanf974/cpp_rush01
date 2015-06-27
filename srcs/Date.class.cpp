/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:36:26 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 16:36:28 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.class.hpp"

/*--------------- Constructors --------------*/
Date::Date(void) {
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
	strftime(buffer, 80, "Time: %e/%m/%Y %I:%M:%S%p", timeinfo);

	result = std::string(buffer);
	this->_time = result;
	return ;
}
