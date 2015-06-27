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
GKrellM::GKrellM(int ac, char **av) {

	init_Qt(ac ,av);
	//std::cout << "GKrellM: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
GKrellM::~GKrellM(void) {
	delete this->_grid;
	delete this->_win;
    delete this->_app;
	//std::cout << "GKrellM: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/



/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void			GKrellM::addModule(AModule *module) {

	QVBoxLayout *vBox = new QVBoxLayout;
	QGroupBox *groupBox = new QGroupBox( QString::fromStdString(module.getName()) );
	this->_grid->addWidget(groupBox, 1, 1);

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

void			GKrellM::init_Qt(int ac, char **av) {

	this->_app = new QApplication(ac, av);
	this->_win = new QWidget();
	this->_win->setFixedSize(700, 500);
	this->_grid = new QGridLayout();
	this->_win->setLayout(this->_grid);
}

void	GKrellM::show( void ) {
	this->_win->show();
	this->_app->exec();
}