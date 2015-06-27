/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:23:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 00:45:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP 

#include <iostream>

#include "AModule.class.hpp"

class Date : public AModule
{
	public:
		Date(int x, int y);
		virtual ~Date( void );

		std::string		getTime(void) const;

		virtual void	getInfos(void);
		virtual void	renderNcurses( int h, int w ) const;
		virtual void	renderQt( void ) const;

	private:
		Date( Date const & src );
		Date & operator=( Date const & rhs );

		std::string		_time;
};

#endif
