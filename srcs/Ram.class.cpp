/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 12:06:13 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 13:14:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ram.class.hpp"
#include "Amodule.class.hpp"
#include <stdio.h>
#include <ncurses.h>
#include <streambuf>
#include <string>

/*-------------- Constructors -------------*/
Ram::Ram(int x, int y) : AModule("RAM", x, y) {
	//std::cout << "Ram: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
Ram::~Ram(void) {
	//std::cout << "Ram: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/




/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/
void				Ram::getInfos(void) {

	int			len;
	FILE* 		pipe = popen("top -l 1 -n 0 ", "r");
	char 		buffer[128];
	std::string	result;

	if (!pipe)
		return ;
	while(!feof(pipe)) {
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);

	len =  result.find("VM") - result.find("PhysMem");
	this->_str = result.substr(result.find("PhysMem"), len);
}

void				Ram::renderNcurses(int h, int w) const {
	move((h / 2) * this->_Y + 1, (w / 2) * this->_X);
	printw("%s", this->_str.c_str());
}

void				Ram::renderQt(void) const {

}

char const			* Ram::printInfos(void) const {
	std::string		str;

	str = this->_str;
	return (str.c_str());
}
