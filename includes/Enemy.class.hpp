/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:56:14 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 17:28:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP 
# define ENEMY_CLASS_HPP

# include <iostream>
# include "AShip.class.hpp"

class	Enemy : public AShip
{
	public:
		Enemy(std::string type, int X, int Y);
		virtual ~Enemy(void);


	private:
		Enemy(void);
		Enemy(Enemy const & src);

		Enemy		& operator=(Enemy const & right);

	protected:
		int					_HP;
};

#endif

