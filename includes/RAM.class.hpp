/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAM.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:24:27 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAM_HPP
# define RAM_HPP 

class Ram
{
public:
	Ram( void );

	virtual ~Ram( void );

	Ram & operator=( Ram const & rhs );
private:
	Ram( Ram const & src );
};

#endif
