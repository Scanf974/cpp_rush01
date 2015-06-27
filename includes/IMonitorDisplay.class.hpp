/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:04:46 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/28 00:47:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP 
# define IMONITORDISPLAY_CLASS_HPP

class	IMonitorDisplay
{
	public:
		virtual void	renderNcurses(int h, int w) const = 0;
		virtual void	renderQt(void) const = 0;
};

#endif

