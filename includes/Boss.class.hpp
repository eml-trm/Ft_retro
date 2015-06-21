/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 22:06:48 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 22:06:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_CLASS_HPP 
# define BOSS_CLASS_HPP

# include <iostream>
# include "Enemy.class.hpp"

class	Boss : public Enemy
{
	public:
		Boss(int X, int Y);
		~Boss(void);

	private:
		Boss(void);
		Boss(Boss const & src);

		Boss		& operator=(Boss const & right);

};

#endif
