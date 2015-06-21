/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitMechant.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:14:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 13:18:16 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PetitMechant.class.hpp"
#include "Enemy.class.hpp"
#include "LittleMissile.class.hpp"
#include "PetitWeapon.class.hpp"

/*-------------- Constructors -------------*/
PetitMechant::PetitMechant(int X, int Y) : Enemy("Petit Mechant", X, Y, 1, 1, 10, 100) {
	AWeapon		*petit = new PetitWeapon(X, Y);

	this->_weapon = petit;
	//std::cout << "PetitMechant: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
PetitMechant::~PetitMechant(void) {
	//std::cout << "PetitMechant: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

