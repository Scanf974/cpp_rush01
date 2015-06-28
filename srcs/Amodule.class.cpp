/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:38:15 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 18:09:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AModule.class.hpp"

int			AModule::_maxX = 0;
int			AModule::_maxY = 0;

/*-------------- Constructors -------------*/
AModule::AModule(std::string name, int x, int y) : _name(name), _X(x), _Y(y) {
	if (x + 1 > AModule::_maxX)
		AModule::_maxX = x + 1;
	if (y + 1 > AModule::_maxY)
		AModule::_maxY = y + 1;
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

