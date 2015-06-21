/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosMechant.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:57:40 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:57:41 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GrosMechant.class.hpp"
#include "Enemy.class.hpp"
#include "GrosMissile.class.hpp"
#include "GrosWeapon.class.hpp"

/*-------------- Constructors -------------*/
GrosMechant::GrosMechant(int X, int Y) : Enemy("Gros Mechant", X, Y, 150, 500, "###\n###\n###") {
	AWeapon		*Gros = new GrosWeapon(X, Y);

	this->_weapon = Gros;
	//std::cout << "GrosMechant: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
GrosMechant::~GrosMechant(void) {
	//std::cout << "GrosMechant: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

