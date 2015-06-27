/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Osinfo.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:20:27 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:20:28 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFO_HPP
# define OSINFO_HPP 

#include "Amodule.class.hpp"

class Osinfo: public AModule
{
public:
	Osinfo( void );
	virtual ~Osinfo( void );

	virtual void		getInfos(void);
	virtual void		renderNcurses(void) const;
	virtual void		renderQt(void) const;

private:
	Osinfo & operator=( Osinfo const & rhs );
	Osinfo( Osinfo const & src );

	std::string		_release;
	std::string		_model;
};

#endif
