/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 11:29:30 by etermeau          #+#    #+#             */
/*   UpCpud: 2015/06/28 11:29:35 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cpu.class.hpp"
#include "AModule.class.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <ncurses.h>
#include <cstdlib>
#include <sstream>


/*--------------- Constructors --------------*/
Cpu::Cpu(int x, int y) : AModule("Cpu", x, y) {
    //std::cout << "Cpu: Default constructor" << std::endl;
    return ;
}


/*--------------- Destructors --------------*/
Cpu::~Cpu(void) {
    //std::cout << "Cpu: Destructor" << std::endl;
    return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void                Cpu::getInfos(void) {

	int					i;
	size_t				size_int = sizeof(i);

	sysctlbyname("hw.ncpu", &i, &size_int, NULL, 0);
	this->_nbCpu = i;

	sysctlbyname("hw.physicalcpu", &i, &size_int, NULL, 0);
	this->_physicalCpu = i;

	sysctlbyname("hw.logicalcpu", &i, &size_int, NULL, 0);
	this->_logicalCpu = i;

	sysctlbyname("hw.cpufrequency", &i, &size_int, NULL, 0);
	this->_frequencyCpu = i;	
	
	return ;
}

void				Cpu::renderNcurses(int h, int w) const {
	move((h / AModule::_maxY) * this->_Y + 1, (w / AModule::_maxX) * this->_X);
	printw("Number CPU: %d", this->_nbCpu);
	move((h / AModule::_maxY) * this->_Y + 2, (w / AModule::_maxX) * this->_X);
	printw("Physical CPU: %d", this->_physicalCpu);
	move((h / AModule::_maxY) * this->_Y + 3, (w / AModule::_maxX) * this->_X);
	printw("Logical CPU: %d", this->_logicalCpu);
	move((h / AModule::_maxY) * this->_Y + 4, (w / AModule::_maxX) * this->_X);
	printw("Frequency CPU: %d", this->_nbCpu);
}

char const *				Cpu::printInfos(void) const {


	std::ostringstream 	ss;
	std::string 		str;

	ss << "CPU Number:\n";
	ss << this->_nbCpu;
	ss << "\n\nPhysical CPU:\n";
	ss << this->_physicalCpu;
	ss << "\n\nLogical CPU:\n";
	ss << this->_logicalCpu;
	ss << "\n\nFrequncy CPU:\n";
	ss << this->_frequencyCpu;
	str = ss.str();

	return (str.c_str());
}


void				Cpu::renderQt(void) const {

}

