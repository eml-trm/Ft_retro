/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitWeapon.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:04:07 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 17:04:09 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PetitWeapon.class.hpp"
#include "AWeapon.class.hpp"
#include "LittleMissile.class.hpp"

/* Constructor */
PetitWeapon::PetitWeapon( void ): AWeapon("Petit Weapon") {
	Missile 	*petit = new LittleMissile(0, 0);
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
