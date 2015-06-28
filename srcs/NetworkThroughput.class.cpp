/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThroughput.class.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 15:24:15 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 17:40:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkThroughput.class.hpp"
#include "AModule.class.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <ncurses.h>
#include <cstdlib>
#include <sstream>


/*--------------- Constructors --------------*/
NetworkThroughput::NetworkThroughput(int x, int y) : AModule("NetworkThroughput", x, y) {
    //std::cout << "NetworkThroughput: Default constructor" << std::endl;
    return ;
}


/*--------------- Destructors --------------*/
NetworkThroughput::~NetworkThroughput(void) {
    //std::cout << "NetworkThroughput: Destructor" << std::endl;
    return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void                NetworkThroughput::getInfos(std::string result) {

	int			len;	
	int			nb = 0;
    len = result.find("out") - result.find("Network");
	    char const  *tmp = result.substr(result.find("Network"), len).c_str();

	for (int i = 0; tmp[i]; i++)
	{
		if (isdigit(tmp[i]))
		{
			if (nb == 0)
				this->_in1 = std::atoi(&tmp[i]);
			else if (nb == 1)
				this->_in2 = std::atoi(&tmp[i]);
			else if (nb == 2)
				this->_out1 = std::atoi(&tmp[i]);
			else if (nb == 3)
				this->_out2 = std::atoi(&tmp[i]);
			else
				return ;
			while (isdigit(tmp[i]) || tmp[i] == '.') i++;
			nb++;
		}
	}

	return ;
}

void				NetworkThroughput::renderNcurses(int h, int w) const {
	move((h / AModule::_maxY) * this->_Y + 1, (w / AModule::_maxX) * this->_X);
	printw("Network packets: %d/%dG in", this->_in1, this->_in2);
	move((h / AModule::_maxY) * this->_Y + 2, (w / AModule::_maxX) * this->_X);
	printw("Network packets: %d/%dM out", this->_out1, this->_out2);
}

char const *				NetworkThroughput::printInfos(void) const {


	std::ostringstream 	ss;
	std::string 		str;

	ss << "Network packets:\n";
	ss << this->_in1;
	ss << "/";
	ss << this->_in2;
	ss << "G in\n\nNetwork packets:\n";
	ss << this->_out1;
	ss << "/";
	ss << this->_out2;
	ss << "M out";
	str = ss.str();

	return (str.c_str());
}


void				NetworkThroughput::renderQt(QGridLayout **grid) const {

	QVBoxLayout *vBox = new QVBoxLayout;
	QGroupBox *groupBox = new QGroupBox( QString::fromStdString(this->getName()) );
	(*grid)->addWidget(groupBox, this->getX(), this->getY());
	
	QLabel *name = new QLabel( QString::fromStdString(this->printInfos()));
	vBox->addWidget(name);
	
	vBox->addStretch(2);
	groupBox->setLayout(vBox);

}


