/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 10:46:39 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 22:59:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/sysctl.h>
#include <sys/param.h>
#include <sys/utsname.h>
#include <unistd.h>
#include "Hostname.class.hpp"
#include "IMonitorModule.class.hpp"
#include "GKrellM.class.hpp"
#include "AModule.class.hpp"
#include "Date.class.hpp"
#include "Osinfo.class.hpp"
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
	GKrellM				g(ac, av);
	AModule *host = new Hostname(0, 0);
	AModule *date = new Date(1, 0);
	AModule *os = new Osinfo(0, 1);

	g.addModule(host);
	g.addModule(date);
	g.addModule(os);
	//g.init_curses();
	g.render(1);
	g.show();

 	return (0);
}
