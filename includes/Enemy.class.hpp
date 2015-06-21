/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:56:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 13:14:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP 
# define ENEMY_CLASS_HPP

# include <iostream>
# include "AShip.class.hpp"

class	Enemy : public AShip
{
	public:
		Enemy(std::string type, int X, int Y, int sizex, int sizey, int HP, int value, std::string skin);
		virtual ~Enemy(void);

		int				getHP(void) const;
		int				getValue(void) const;

	private:
		Enemy(void);
		Enemy(Enemy const & src);

		Enemy		& operator=(Enemy const & right);

	protected:
		int					_HP;
		int					_value;
};

#endif

