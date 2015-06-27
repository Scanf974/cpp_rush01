/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:04:46 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 16:06:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_CLASS_HPP 
# define IMONITORDISPLAY_CLASS_HPP

class	IMonitorDisplay
{
	public:
		virtual void	renderNcurses(void) const = 0;
		virtual void	renderQt(void) const = 0;
};

#endif

