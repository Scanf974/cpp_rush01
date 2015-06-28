/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 19:51:38 by bsautron         ###   ########.fr       */
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

		virtual void		getInfos(std::string result);
		virtual void		renderNcurses( int h, int w ) const;
		virtual void		renderQt( QGridLayout **grid ) const;
		virtual char const 	*printInfos(void) const;
		void				ft_putInfo(char const *label, float data, int line, int h, int w) const;

	private:
		Cpu( Cpu const & src );
		Cpu & operator=( Cpu const & rhs );

		int		_nbCpu;
		int		_physicalCpu;
		int		_logicalCpu;
		int		_frequencyCpu;
		float	_user;
		float	_sys;
		float	_idle;
};

#endif
