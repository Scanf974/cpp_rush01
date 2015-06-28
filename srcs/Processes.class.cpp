/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Processes.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 19:53:33 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 20:08:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Processes.class.hpp"
#include <sstream>
#include <ncurses.h>

/*-------------- Constructors -------------*/
Processes::Processes(int x, int y) : AModule("Processes", x, y) {
	//std::cout << "Processes: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
Processes::~Processes(void) {
	//std::cout << "Processes: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/




/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void			Processes::getInfos(std::string result) {
	int         len;
	int         nb = 0;

	len = result.find("Load") - result.find("Processes");
	char const  *tmp = result.substr(result.find("Processes")).c_str();

	for (int i = 0; tmp[i]; i++)
	{
		if (isdigit(tmp[i]))
		{
			if (nb == 0)
				this->_total = std::atof(&tmp[i]);
			else if (nb == 1)
				this->_running = std::atof(&tmp[i]);
			else if (nb == 2)
				this->_stuck = std::atof(&tmp[i]);
			else if (nb == 3)
				this->_sleeping = std::atof(&tmp[i]);
			else if (nb == 4)
				this->_threads = std::atof(&tmp[i]);
			else
				return ;
			while (isdigit(tmp[i]) || tmp[i] == '.') i++;
			nb++;
		}
	}
	return ;
}

void				Processes::renderNcurses(int h, int w) const {
	move((h / AModule::_maxY) * this->_Y + 1, (w / AModule::_maxX) * this->_X);
	printw("Total:\t\t%d", this->_total);
	move((h / AModule::_maxY) * this->_Y + 2, (w / AModule::_maxX) * this->_X);
	printw("Running:\t%d", this->_running);
	move((h / AModule::_maxY) * this->_Y + 3, (w / AModule::_maxX) * this->_X);
	printw("Stuck:\t\t%d", this->_stuck);
	move((h / AModule::_maxY) * this->_Y + 4, (w / AModule::_maxX) * this->_X);
	printw("Sleeping:\t%d", this->_sleeping);
	move((h / AModule::_maxY) * this->_Y + 5, (w / AModule::_maxX) * this->_X);
	printw("Threads:\t%d", this->_threads);

}

char const			*Processes::printInfos(void) const {
	std::ostringstream  ss;
	std::string         str;


	ss << "Total: ";
	ss << this->_total;
	ss << "\n\nRunning: ";
	ss << this->_running;
	ss << "\n\nStuck: ";
	ss << this->_stuck;
	ss << "\n\nSleeping: ";
	ss << this->_sleeping;
	ss << "\n\nThreads: ";
	ss << this->_threads;

	str = ss.str();
	return (str.c_str());
}

void				Processes::renderQt(QGridLayout ** grid) const {
	QVBoxLayout *vBox = new QVBoxLayout;
	QGroupBox *groupBox = new QGroupBox( QString::fromStdString(this->getName()) );
	(*grid)->addWidget(groupBox, this->getX(), this->getY());

	QLabel *name = new QLabel( QString::fromStdString(this->printInfos()));
	vBox->addWidget(name);

	vBox->addStretch(2);
	groupBox->setLayout(vBox);
}











