/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 23:39:12 by bsautron         ###   ########.fr       */
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
}

void			GKrellM::addModule(AModule *module) {
	this->_module.push_back(module);
}

void			GKrellM::render(int lib) {
	(void)lib;
	std::list<AModule *>		tmp = this->_module;

	std::list<AModule *>::iterator		beg = tmp.begin();
	std::list<AModule *>::iterator		end = tmp.end();

	while (1)
	{
	for (; beg != end; beg++)
	{
		(*beg)->getInfos();
		printw("--- Module: %s ---\n", (*beg)->getName().c_str());
		(*beg)->renderNcurses();
	}
	refresh();
	for(int i = 0; i < 90000000; i++);
	}
}
