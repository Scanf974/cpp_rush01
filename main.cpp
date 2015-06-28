/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:46:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 20:27:29 by bsautron         ###   ########.fr       */
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

	AModule				*host = 0;
    AModule				*date = 0;
    AModule				*cpu = 0;
    AModule				*ram = 0;
    AModule				*os = 0;
    AModule				*net = 0;
    AModule				*proc = 0;

	int					ll;

	std::cout << "0: Console" << std::endl;
	std::cout << "1: Graphic" << std::endl;
	std::cin >> ll;


	if (ll == 0)
	{
		AModule				*tuteur = new Ram(10, 10); 
		(void)tuteur;
		host = new Hostname(1, 1);
		date = new Date(8, 1);

		cpu = new Cpu(1, 4);
		proc = new Processes(4, 3); 
		ram = new Ram(8, 4);

		os = new Osinfo(8, 8);
		net = new NetworkThroughput(1, 8); 
	}
	else
	{
		date = new Date(0, 0);
		host = new Hostname(0, 1);
		os = new Osinfo(2, 0);
		cpu = new Cpu(3, 0);
		ram = new Ram(3, 1);
		net = new NetworkThroughput(4, 0); 
		proc = new Processes(4, 1); 
	}
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
