/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:36:28 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 16:45:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_CLASS_HPP 
# define GKRELLM_CLASS_HPP

# include <iostream>
# include <list>
# include "IMonitorModule.class.hpp"

class	GKrellM
{
	public:
		GKrellM(void);
		~GKrellM(void);

		void		addModule(IMonitorModule  * module);
		//void		init_curses(void);
		//void		init_Qt(void);
		//void		render(int lib) const;

	private:
		GKrellM(GKrellM const & src);
		GKrellM		& operator=(GKrellM const & right);

		std::list<IMonitorModule const *>		_module;
		int										_lib;
};

#endif

