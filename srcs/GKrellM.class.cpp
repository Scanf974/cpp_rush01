/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 13:17:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GKrellM.class.hpp"
#include <ncurses.h>

/*-------------- Constructors -------------*/
GKrellM::GKrellM(void) {


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
int			GKrellM::getHeight(void) const {
	return (this->_height);
}

int			GKrellM::getWidth(void) const {
	return (this->_width);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void			GKrellM::init_curses(void) {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, this->_height, this->_width);
}

void			GKrellM::addModule(AModule *module) {



	this->_module.push_back(module);
}

void			GKrellM::render(int lib) {
	std::list<AModule *>		tmp = this->_module;

	std::list<AModule *>::iterator		beg = tmp.begin();
	std::list<AModule *>::iterator		end = tmp.end();

	if (lib == 0)
	{
		while (1)
		{
			std::list<AModule *>		tmp = this->_module;
			std::list<AModule *>::iterator		beg = tmp.begin();
			std::list<AModule *>::iterator		end = tmp.end();

			clear();
			for (; beg != end; beg++)
			{
				(*beg)->getInfos();
				move((this->_height / 2) * (*beg)->getY(), (this->_width / 2) * (*beg)->getX());
				printw("--- Module: %s ---", (*beg)->getName().c_str());
				(*beg)->renderNcurses(this->_height, this->_width);
			}
			refresh();
		}
	}
	else
	{
		for (; beg != end; beg++)
		{
			(*beg)->getInfos();
			QVBoxLayout *vBox = new QVBoxLayout;
			QGroupBox *groupBox = new QGroupBox( QString::fromStdString((*beg)->getName()) );
			this->_grid->addWidget(groupBox, (*beg)->getX(), (*beg)->getY());

			QLabel *name = new QLabel( QString::fromStdString((*beg)->printInfos()));
			vBox->addWidget(name);

			vBox->addStretch(2);
			groupBox->setLayout(vBox);
		}
		this->show();
	}
}

void			GKrellM::init_Qt(int ac, char **av) {

	this->_height = 500;
	this->_width = 550;
	this->_app = new QApplication(ac, av);
	this->_win = new QWidget();
	this->_win->setWindowTitle("ZAZ loves cats !");
	this->_win->setFixedSize(this->_width, this->_height);
	this->_grid = new QGridLayout();
	this->_win->setLayout(this->_grid);
}

void	GKrellM::show( void ) {
	this->_win->show();
	this->_app->exec();
}
