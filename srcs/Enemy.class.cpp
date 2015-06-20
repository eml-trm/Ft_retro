/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:58:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 17:44:41 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include "AShip.class.hpp"
#include <stdio.h>

/*-------------- Constructors -------------*/
Enemy::Enemy(std::string type, int X, int Y) : AShip(type, X, Y) {
	std::cout << "Enemy(" << this->_type << "): popped at " << this->_X << "/" << this->_Y << " with a " << std::endl;
	printf("%p\n", this->_weapon);
	return ;
}


/*--------------- Destructors --------------*/
Enemy::~Enemy(void) {
	std::cout << "Enemy: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/




/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

