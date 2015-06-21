/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenWeapon.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:44:57 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:44:58 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoyenWeapon.class.hpp"
#include "AWeapon.class.hpp"
#include "MoyenMissile.class.hpp"

/* Constructor */
MoyenWeapon::MoyenWeapon( int X, int Y ): AWeapon("Moyen Weapon", X, Y) {
	Missile 	*Moyen = new MoyenMissile(X, Y);
	this->_missile = Moyen;
	return ;
}


/* Destructor */
MoyenWeapon::~MoyenWeapon( void ) {
	return ;
}

// void	MoyenWeapon::attack( void ) const {


// 	return ;
// }

/* Operator */


/* Get */

