/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:13:02 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 19:12:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AShip.class.hpp"
#include "AWeapon.class.hpp"
#include "Identity.class.hpp"

/*-------------- Constructors -------------*/
AShip::AShip(std::string type, int X, int Y, std::string skin) : Identity(type, X, Y, skin), _weapon(0) {
	//std::cout << "AShip: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
AShip::~AShip(void) {
	//std::cout << "AShip: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
AWeapon				*AShip::getWeapon(void) const {
	return (this->_weapon);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

