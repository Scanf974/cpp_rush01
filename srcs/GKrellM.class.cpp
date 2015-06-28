/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 15:53:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GKrellM.class.hpp"
#include "AModule.class.hpp"
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
	nodelay(stdscr, true);
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, this->_height, this->_width);
}

void			GKrellM::handleEvent(int ch) {
	if (ch == 27) {
		endwin();
		exit(0);
	}
}

void			GKrellM::addModule(AModule *module) {

	this->_module.push_back(module);
}

void			GKrellM::render(int lib) {
	std::list<AModule *>		tmp = this->_module;

	std::list<AModule *>::iterator		beg = tmp.begin();
	std::list<AModule *>::iterator		end = tmp.end();

	int		ch;

	if (lib == 0)
	{
		while (1)
		{
			while ((ch = getch()) != ERR)
				this->handleEvent(ch);
			std::list<AModule *>		tmp = this->_module;
			std::list<AModule *>::iterator		beg = tmp.begin();
			std::list<AModule *>::iterator		end = tmp.end();

			clear();
			for (; beg != end; beg++)
			{
				(*beg)->getInfos();
				move((this->_height / AModule::_maxY) * (*beg)->getY(), (this->_width / AModule::_maxX) * (*beg)->getX());
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
			(*beg)->renderQt(&this->_grid);
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
