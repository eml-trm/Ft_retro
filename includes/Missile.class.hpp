/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:44:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 15:44:27 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_CLASS_HPP
# define MISSILE_CLASS_HPP

#include <iostream>

class Missile
{

public:
	Missile( std::string type, int damage);
	virtual ~Missile( void );

	int 		getDamage( void );
	std::string	getType( void );

protected:
	std::string _type;
	int			_damage;

private:
	Missile( void );
	
	Missile & operator=( Missile const & rhs);
	Missile( Missile const & src);
};

#endif