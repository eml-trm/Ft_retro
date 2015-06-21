/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosWeapon.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:57:51 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:57:52 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GrosWeapon.class.hpp"
#include "AWeapon.class.hpp"
#include "GrosMissile.class.hpp"

/* Constructor */
GrosWeapon::GrosWeapon( int X, int Y ): AWeapon("Gros Weapon", X, Y) {
	Missile 	*Gros = new GrosMissile(X, Y);
	this->_missile = Gros;
	return ;
}


/* Destructor */
GrosWeapon::~GrosWeapon( void ) {
	return ;
}

// void	GrosWeapon::attack( void ) const {


// 	return ;
// }

/* Operator */


/* Get */

