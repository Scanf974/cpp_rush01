/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Processes.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/28 19:48:33 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 19:53:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESSES_CLASS_HPP 
# define PROCESSES_CLASS_HPP

# include <iostream>

# include "AModule.class.hpp"

class	Processes : public AModule
{
	public:
		Processes( int x, int y );
		virtual ~Processes(void);

		virtual void        getInfos(std::string result);
		virtual void        renderNcurses( int h, int w ) const;
		virtual void        renderQt( QGridLayout **grid ) const;
		virtual char const  *printInfos(void) const;


	private:
		Processes(void);
		Processes(Processes const & src);
		Processes		& operator=(Processes const & right);

		int			_total;
		int			_running;
		int			_stuck;
		int			_sleeping;
		int			_threads;

};

#endif

