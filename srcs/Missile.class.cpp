/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:44:14 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 15:44:15 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"

/* Constructor */
Missile::Missile( std::string type, int damage, int x, int y) : _type(type), _damage(damage), _X(x), _Y(y) {
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

std::string	Missile::getType( void ) {
	return (this->_type);
}

int 		Missile::getX( void ) {
	return (this->_X);
}

int			Missile::getY( void ) {
	return (this->_Y);
}