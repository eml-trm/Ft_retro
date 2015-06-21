/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:06:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 13:20:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.class.hpp"

/* Constructor */

AWeapon::AWeapon( std::string type, int X, int Y) : Identity(type, X, Y, 0, 0, "") , _missile(0) {
		return ;
}

/* Destructor */
AWeapon::~AWeapon( void ) {
	return ;
}

/* Operator */

/* Get */
Missile  	*AWeapon::getMissile( void ) const {
	return (this->_missile);
}
