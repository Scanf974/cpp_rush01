/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ram.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 14:17:47 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP 

# include <iostream>
# include "AModule.class.hpp"

class Ram : public AModule
{
	public:
		Ram( int x, int y );
		virtual ~Ram( void );

		virtual void		getInfos(void);
		virtual void		renderNcurses(int h, int w) const;
		virtual void		renderQt(QGridLayout **grid) const;
		virtual char const	*printInfos(void) const;

	private:
		Ram( void );
		Ram & operator=( Ram const & rhs );
		Ram( Ram const & src );

		int			_used;
		int			_wired;
		int			_unused;
};

#endif
