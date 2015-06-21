/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:44:14 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 19:15:29 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"

/* Constructor */
Missile::Missile( std::string type, int damage, int X, int Y ) : Identity(type, X, Y, "|"), _damage(damage) {
		return ;
}

/* Destructor */
Missile::~Missile( void ) {
	return ;
}

/* Operator */


/* Get */

int 		Missile::getDamage( void ) {
	return (this->_damage);
}
