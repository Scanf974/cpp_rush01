/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:36:28 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 12:59:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_CLASS_HPP 
# define GKRELLM_CLASS_HPP

# include <iostream>
# include <list>
# include "AModule.class.hpp"

class    GKrellM
{
	public:
		GKrellM(void);
		~GKrellM(void);

		int            getHeight(void) const;
		int            getWidth(void) const;

		void        addModule(AModule* module);

		void        init_curses(void);
		void        init_Qt(int ac, char **av);
		void        show( void );
		void        render(int lib);

	private:
		GKrellM(GKrellM const & src);
		GKrellM        & operator=(GKrellM const & right);

		std::list<AModule *>      	  _module;
		QApplication              	  *_app;
		QWidget                   	  *_win;
		QGridLayout                    *_grid;
		int                            _lib;
		int                            _height;
		int                            _width;
};

#endif
