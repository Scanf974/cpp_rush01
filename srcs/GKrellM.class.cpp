/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:44:31 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 19:01:52 by bsautron         ###   ########.fr       */
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
	start_color();

	init_color(COLOR_ORANGE, 245 * 3, 128 * 3, 34 * 3);
	init_color(COLOR_GREEN, 143 * 3, 181 * 3, 0 * 3);
	init_color(COLOR_RED, 214 * 3, 62 * 3, 18 * 3);
	init_color(COLOR_TITLE, 0 * 3, 146 * 3, 148 * 3);
	init_pair(COLOR_ORANGE, 0, COLOR_ORANGE);
	init_pair(COLOR_GREEN, 0, COLOR_GREEN);
	init_pair(COLOR_RED, 0, COLOR_RED);
	init_pair(COLOR_TITLE, COLOR_WHITE, COLOR_TITLE);
}

void			GKrellM::init_Qt(int ac, char **av) {

	this->_height = 1000;
	this->_width = 800;
	this->_app = new QApplication(ac, av);
	this->_win = new QWidget();
	this->_win->setWindowTitle("ZAZ loves cats !");
	this->_win->setFixedSize(this->_width, this->_height);
	this->_grid = new QGridLayout();
	this->_win->setLayout(this->_grid);
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

std::string 	GKrellM::getTop(void) const {

	FILE*       pipe = popen("top -l 1 -n 0 ", "r");
	char        buffer[128];
	std::string result;

	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	return (result);
}

void			GKrellM::render(int lib) {
	std::list<AModule *>		tmp = this->_module;

	std::list<AModule *>::iterator		beg = tmp.begin();
	std::list<AModule *>::iterator		end = tmp.end();

	std::string		result;

	int		ch;

	if (lib == 0)
	{
		while (1)
		{
			result = this->getTop();
			while ((ch = getch()) != ERR)
				this->handleEvent(ch);
			std::list<AModule *>		tmp = this->_module;
			std::list<AModule *>::iterator		beg = tmp.begin();
			std::list<AModule *>::iterator		end = tmp.end();

			clear();
			for (; beg != end; beg++)
			{
				(*beg)->getInfos(result);
				move((this->_height / AModule::_maxY) * (*beg)->getY(), (this->_width / AModule::_maxX) * (*beg)->getX());
				attron(COLOR_PAIR(COLOR_TITLE));
				printw(" --- Module: %s --- ", (*beg)->getName().c_str());
				attroff(COLOR_PAIR(COLOR_TITLE));
				(*beg)->renderNcurses(this->_height, this->_width);
			}
			refresh();
		}
	}
	else
	{
		result = this->getTop();
		for (; beg != end; beg++)
		{
			(*beg)->getInfos(result);
			(*beg)->renderQt(&this->_grid);
		}
		this->show();
	}
}

void	GKrellM::show( void ) {
	this->_win->show();
	this->_app->exec();
}
