/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitWeapon.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:04:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 19:11:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PetitWeapon.class.hpp"
#include "AWeapon.class.hpp"
#include "LittleMissile.class.hpp"

/* Constructor */
PetitWeapon::PetitWeapon( int X, int Y ): AWeapon("Petit Weapon", X, Y) {
	Missile 	*petit = new LittleMissile(X, Y);
	this->_missile = petit;
	return ;
}


/* Destructor */
PetitWeapon::~PetitWeapon( void ) {
	return ;
}

// void	PetitWeapon::attack( void ) const {


// 	return ;
// }

/* Operator */


/* Get */
