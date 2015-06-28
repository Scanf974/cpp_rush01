/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:46:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 13:17:26 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/utsname.h>
#include <unistd.h>
#include "Hostname.class.hpp"
#include "IMonitorModule.class.hpp"
#include "GKrellM.class.hpp"
#include "AModule.class.hpp"
#include "Date.class.hpp"
#include "Osinfo.class.hpp"
#include "Ram.class.hpp"
#include "Cpu.class.hpp"
#include <string.h>

void	sysinfstr(char const  *str)
{
	size_t		size;
	char		buf[256];

	size = sizeof buf;
	sysctlbyname(str, buf, &size, NULL, 0);
	dprintf(1, "%s\n", buf);
}

void	sysinfint(char const *str)
{
	int			i;
	size_t		size_int;

	size_int = sizeof i;
	sysctlbyname(str, &i, &size_int, NULL, 0);
	dprintf(1, "%i\n", i);
}

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
/*
	int mib[2], i;
	size_t len;

	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	len = sizeof(i);
	sysctl(mib, 2, &i, &len, NULL, 0);
	printf("%d\n" ,i);
*/

	int		ll;
	GKrellM				g;
	AModule *ram = new Ram(0, 0);
	AModule *date = new Date(0, 1);
	AModule *os = new Osinfo(1, 0);
	AModule *cpu = new Cpu(1, 1);
	AModule *net = new NetworkThrough(1, 2); 

	std::cout << "0: Consol" << std::endl;
	std::cout << "1: Graphic" << std::endl;
	std::cin >> ll;

	g.addModule(ram);
	g.addModule(date);
	g.addModule(os);
	g.addModule(cpu);
	if (ll == 0)
		g.init_curses();
	else
		g.init_Qt(ac, av);
	g.render(ll);
	return (0);
}
