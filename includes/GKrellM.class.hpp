/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GKrellM.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:36:28 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/27 14:38:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_CLASS_HPP 
# define GKRELLM_CLASS_HPP

# include <iostream>
# include "IMonitorModule.class.hpp"
# include "Hostname.class.hpp"

class	GKrellM
{
	public:
		GKrellM(void);
		GKrellM(GKrellM const & src);
		~GKrellM(void);

		GKrellM		& operator=(GKrellM const & right);

	private:
		IMonitorModule		_hostname;
};

#endif

