/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 18:06:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GKrellM.class.hpp"

/*-------------- Constructors -------------*/
GKrellM::GKrellM(void) {
	//std::cout << "GKrellM: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
GKrellM::~GKrellM(void) {
	//std::cout << "GKrellM: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/



/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void			GKrellM::addModule(AModule *module) {
	this->_module.push_back(module);
}

void			GKrellM::render(int lib) {
	(void)lib;
	std::list<AModule *>		tmp = this->_module;

	std::list<AModule *>::iterator		beg = tmp.begin();
	std::list<AModule *>::iterator		end = tmp.end();

	for (; beg != end; beg++)
	{
		(*beg)->getInfos();
		std::cout << "-- Module: " << (*beg)->getName() << " --" << std::endl;
		(*beg)->renderNcurses();
		std::cout  << std::endl;
	}
}
