/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:13:10 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/27 17:50:41 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOUDULE_HPP
# define AMOUDULE_HPP 

#include "IMonitorDisplay.class.hpp"
#include "IMonitorModule.class.hpp"
#include <iostream>

class AModule : public IMonitorModule, public IMonitorDisplay
{
	public:
		AModule(std::string name);
		virtual ~AModule(void);

		void			getName(void) const;
		virtual void	getInfos(void) = 0;
		virtual void	renderNcurses( void ) const = 0;
		virtual void	renderQt( void ) const = 0;

	private:
		AModule(void);
		AModule & operator=( AModule const & rhs );
		AModule( AModule const & src );

		std::string			_name;

};

#endif
