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

class Osinfo
{
public:
	Osinfo( void );
	virtual ~Osinfo( void );

	Osinfo & operator=( Osinfo const & rhs );
private:
	Osinfo( Osinfo const & src );
};

#endif
