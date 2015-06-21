/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenMechant.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:40:15 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 13:15:36 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoyenMechant.class.hpp"
#include "Enemy.class.hpp"
#include "MoyenMissile.class.hpp"
#include "MoyenWeapon.class.hpp"

/*-------------- Constructors -------------*/
MoyenMechant::MoyenMechant(int X, int Y) : Enemy("Moyen Mechant", X, Y, 2, 2, 60, 200, "##\n##") {
	AWeapon		*moyen = new MoyenWeapon(X, Y);

	this->_weapon = moyen;
	//std::cout << "MoyenMechant: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
MoyenMechant::~MoyenMechant(void) {
	//std::cout << "MoyenMechant: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

