/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:24:14 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP 

#include <iostream>

#include "AModule.class.hpp"

class Cpu : public AModule
{
public:
	Cpu( int x, int y );
	virtual ~Cpu( void );



	virtual void		getInfos(void);
	virtual void		renderNcurses( int h, int w ) const;
	virtual char const 	*printInfos(void) const;
	virtual void		renderQt( void ) const;

private:
	Cpu( Cpu const & src );
	Cpu & operator=( Cpu const & rhs );

	int		_nbCpu;
	int		_physicalCpu;
	int		_logicalCpu;
	int		_frequencyCpu;
};

#endif
