/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThroughput.class.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 16:27:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP 

#include <iostream>

#include "AModule.class.hpp"

class NetworkThroughput: public AModule
{
public:
	NetworkThroughput( int x, int y );
	virtual ~NetworkThroughput( void );

	virtual void		getInfos(std::string result);
	virtual void		renderNcurses( int h, int w ) const;
	virtual void		renderQt( QGridLayout **grid ) const;
	virtual char const 	*printInfos(void) const;

private:
	NetworkThroughput( NetworkThroughput const & src );
	NetworkThroughput & operator=( NetworkThroughput const & rhs );

	int			_in1;
	int			_in2;
	int			_out1;
	int			_out2;

};

#endif
