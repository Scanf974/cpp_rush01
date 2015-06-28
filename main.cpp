/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:46:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 20:09:02 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Hostname.class.hpp"
#include "GKrellM.class.hpp"
#include "AModule.class.hpp"
#include "Date.class.hpp"
#include "Osinfo.class.hpp"
#include "Ram.class.hpp"
#include "Cpu.class.hpp"
#include "NetworkThroughput.class.hpp"
#include "Processes.class.hpp"
#include <string.h>


int		main(int ac, char **av)
{

	GKrellM				g;
	AModule				*tuteur = new Ram(4, 3); 
	(void)tuteur;

	AModule				*host = new Hostname(1, 1);
	AModule				*date = new Date(3, 1);
	AModule				*cpu = new Cpu(1, 2);
	AModule				*ram = new Ram(3, 2);
	AModule				*os = new Osinfo(3, 3);
	AModule				*net = new NetworkThroughput(1, 3); 
	AModule				*proc = new Processes(2, 1); 

	int					ll;

	std::cout << "0: Console" << std::endl;
	std::cout << "1: Graphic" << std::endl;
	std::cin >> ll;

	g.addModule(ram);
	g.addModule(date);
	g.addModule(os);
	g.addModule(cpu);
	g.addModule(host);
	g.addModule(net);
	g.addModule(proc);

	if (ll == 0)
		g.init_curses();
	else
		g.init_Qt(ac, av);
	g.render(ll);
	return (0);
}
