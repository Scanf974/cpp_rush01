/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:13:10 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 01:02:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOUDULE_HPP
# define AMOUDULE_HPP 

#include "IMonitorDisplay.class.hpp"
#include "IMonitorModule.class.hpp"
#include <iostream>

class AModule : public IMonitorModule, public IMonitorDisplay
{
	public:
		AModule(std::string name, int x, int y);
		virtual ~AModule(void);


		int				getX(void) const;
		int				getY(void) const;
		std::string		getName(void) const;

		virtual void	getInfos(void) = 0;
		virtual void	renderNcurses( int h, int w ) const = 0;
		virtual char const	*printInfos( void ) const = 0;	
		virtual void	renderQt( void ) const = 0;

	private:
		AModule(void);
		AModule & operator=( AModule const & rhs );
		AModule( AModule const & src );

	protected:
		std::string			_name;
		int					_X;
		int					_Y;

};

#endif
