/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkThroughput.class.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 11:24:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 11:25:01 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORK_HPP
# define NETWORK_HPP 

class NetworkThrough
{
public:
	NetworkThrough( int x, int y );
	virtual ~NetworkThrough( void );

	

private:
	NetworkThrough( NetworkThrough const & src );
	NetworkThrough & operator=( NetworkThrough const & rhs );
};

#endif
