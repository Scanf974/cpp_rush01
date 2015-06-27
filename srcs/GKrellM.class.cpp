/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 17:09:35 by bsautron         ###   ########.fr       */
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
void			GKrellM::addModule(IMonitorModule *module) {
	this->_module.push_back(module);
}

void			GKrellM::render(int lib) {
	(void)lib;
	std::list<IMonitorModule *>		tmp = this->_module;

	std::list<IMonitorModule *>::iterator		beg = tmp.begin();
	std::list<IMonitorModule *>::iterator		end = tmp.end();

	for (; beg != end; beg++)
	{
		(*beg)->renderNcurses();
	}
}
