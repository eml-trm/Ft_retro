/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:44:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 18:21:45 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_CLASS_HPP
# define MISSILE_CLASS_HPP

# include <iostream>
# include "Identity.class.hpp"

class Missile : public Identity
{

	public:
		Missile( std::string type, int damage, int X, int Y, int sizeX, int sizeY, std::string skin);
		virtual ~Missile( void );

		int 		getDamage( void );

	protected:
		int			_damage;

	private:
		Missile( void );

		Missile & operator=( Missile const & rhs);
		Missile( Missile const & src);
};

#endif
