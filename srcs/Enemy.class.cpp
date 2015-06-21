/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:58:37 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 13:14:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include "AShip.class.hpp"
#include <stdio.h>

/*-------------- Constructors -------------*/
Enemy::Enemy(std::string type, int X, int Y, int sizex, int sizey, int HP, int value, std::string skin) : AShip(type, X, Y, sizex, sizey, skin), _HP(HP), _value(value) {
	//std::cout << "Enemy(" << this->_type << "): popped at " << this->_X << "/" << this->_Y << std::endl;

	return ;
}


/*--------------- Destructors --------------*/
Enemy::~Enemy(void) {
	//std::cout << "Enemy: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
int                 Enemy::getHP(void) const {
	    return (this->_HP);
}
int                 Enemy::getValue(void) const {
	    return (this->_value);
}



/*------------------ Seter -----------------*/

void				Enemy::setHP(int hp) {
	this->_HP = hp;
	return ;
}


/*------------------ Other -----------------*/

