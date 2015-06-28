/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:13:10 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/28 16:32:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMOUDULE_HPP
# define AMOUDULE_HPP 

#include "IMonitorDisplay.class.hpp"
#include "IMonitorModule.class.hpp"
#include <QApplication>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QSlider>
#include <iostream>

class AModule : public IMonitorModule, public IMonitorDisplay
{
	public:
		AModule(std::string name, int x, int y);
		virtual ~AModule(void);


		int				getX(void) const;
		int				getY(void) const;
		std::string		getName(void) const;

		virtual void	getInfos(std::string result) = 0;
		virtual void	renderNcurses( int h, int w ) const = 0;
		virtual char const	*printInfos( void ) const = 0;	
		virtual void	renderQt( QGridLayout **grid ) const = 0;
		static int			_maxX;
		static int			_maxY;

	private:
		AModule(void);
		AModule & operator=( AModule const & rhs );
		AModule( AModule const & src );

	protected:
		std::string			_name;
		int					_X;
		int					_Y;

};

#endif
