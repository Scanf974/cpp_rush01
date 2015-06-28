/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Osinfo.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 15:33:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 20:10:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Osinfo.class.hpp"
#include "AModule.class.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <ncurses.h>

/*--------------- Constructors --------------*/
Osinfo::Osinfo(int x, int y) : AModule("OS Infos", x, y) {
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
void                Osinfo::getInfos(std::string result) {
	char str[256];
	(void)result;

	size_t size = sizeof(str);
	sysctlbyname("kern.osrelease", str, &size, NULL, 0);

	this->_release = str;

	char tmp[256];
	size_t size_int = sizeof(tmp); 

	sysctlbyname("hw.model", tmp, &size_int, NULL, 0);
	this->_model = tmp;

	return ;
}

void				Osinfo::renderNcurses(int h, int w) const {
	move((h / AModule::_maxY) * this->_Y + 1, (w / AModule::_maxX) * this->_X);
	printw("Release:\t%s", this->_release.c_str());
	move((h / AModule::_maxY) * this->_Y + 2, (w / AModule::_maxX) * this->_X);
	printw("Model:\t%s", this->_model.c_str());
}

char const * 				Osinfo::printInfos(void) const{

	std::string 	str;

	str = "Release: \n";
	str += this->_release;
	str += "\n\nModel: \n";
	str += this->_model;

	return (str.c_str());
}

void				Osinfo::renderQt(QGridLayout **grid) const {

	QVBoxLayout *vBox = new QVBoxLayout;
	QGroupBox *groupBox = new QGroupBox( QString::fromStdString(this->getName()) );
	(*grid)->addWidget(groupBox, this->getX(), this->getY());
	
	QLabel *name = new QLabel( QString::fromStdString(this->printInfos()));
	vBox->addWidget(name);
	
	vBox->addStretch(2);
	groupBox->setLayout(vBox);

}
