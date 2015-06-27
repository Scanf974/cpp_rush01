/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cpu.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:13 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:24:14 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_HPP
# define CPU_HPP 

class Cpu
{
public:
	Cpu( void );
	virtual ~Cpu( void );

	Cpu & operator=( Cpu const & rhs );
private:
	Cpu( Cpu const & src );
};

#endif
