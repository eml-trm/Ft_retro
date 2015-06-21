/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 21:58:19 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 22:02:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.class.hpp"
#include "Enemy.class.hpp"
#include "BossWeapon.class.hpp"

/*-------------- Constructors -------------*/
Boss::Boss(int X, int Y) : Enemy("Boss", X, Y, 10, 5, 2500, 5000, "##########") {
	AWeapon		*boss = new BossWeapon(X, Y);

	this->_weapon = boss;
	//std::cout << "Boss: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
Boss::~Boss(void) {
	//std::cout << "Boss: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

