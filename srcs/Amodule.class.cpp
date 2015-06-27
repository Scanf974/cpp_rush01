/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:38:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 18:05:29 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AModule.class.hpp"

/*-------------- Constructors -------------*/
AModule::AModule(std::string name, int x, int y) : _name(name), _X(x), _Y(y) {
	//std::cout << "AModule: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
AModule::~AModule(void) {
	//std::cout << "AModule: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string			AModule::getName(void) const {
	return this->_name;
}
int					AModule::getX(void) const {
	return (this->_X);
}
int					AModule::getY(void) const {
	return (this->_Y);
}



/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

