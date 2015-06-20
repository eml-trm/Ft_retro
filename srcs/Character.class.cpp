/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:32:27 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 16:05:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"
#include "AShip.class.hpp"

/*-------------------- Constructors ---------------------*/
Character::Character( void ) : AShip("Player", 0, 0) {

	std::cout << "Your Character Type: " << this->_type << "in position " << this->_X << "/" << this->_Y << " was created !" << std::endl;
	return;
}

/*-------------------- Destructors ---------------------*/
Character::~Character( void ) {

	std::cout << "Your Character was destroyed !" << std::endl;
	return ;
}

