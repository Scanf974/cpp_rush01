/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:23:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:24:01 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP 

class Date
{
public:
	Date( void );
	virtual ~Date( void );

	virtual void	getInfos(void) ;
	virtual void	renderNcurses( void ) const;
	virtual void	renderQt( void ) const 
private:
	Date( Date const & src );
	Date & operator=( Date const & rhs );

	std::string		_time;
};

#endif
