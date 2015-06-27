/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:13:10 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 17:13:11 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOUDULE_HPP
# define AMOUDULE_HPP 

class AModule
{
public:
	AModule();
	virtual ~AModule();
	
	virtual void	renderNcurses( void ) const = 0;
	virtual void	renderQt( void ) const = 0;

private:
	AModule & operator=( AModule const & rhs );
	AModule( AModule const & src );

};

#endif
