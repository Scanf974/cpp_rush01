/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Osinfo.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:20:27 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 16:27:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP 

#include "Amodule.class.hpp"

class Osinfo: public AModule
{
	public:
		Osinfo( int x, int y );
		virtual ~Osinfo( void );

		std::string         getModel(void) const;
		std::string         getRelease(void) const;

		virtual void		getInfos(std::string result);
		virtual void		renderNcurses(int h, int w) const;
		virtual char const	*printInfos(void) const ;
		virtual void		renderQt(QGridLayout **grid) const;

	private:
		Osinfo & operator=( Osinfo const & rhs );
		Osinfo( Osinfo const & src );

		std::string		_release;
		std::string		_model;
};

#endif
