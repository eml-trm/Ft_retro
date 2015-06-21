/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:06:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 13:20:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.class.hpp"

/* Constructor */
<<<<<<< HEAD
AWeapon::AWeapon( std::string type, int X, int Y) : Identity(type, X, Y, "") , _missile(0) {
=======
AWeapon::AWeapon( std::string type, int X, int Y) : Identity(type, X, Y, 0, 0) , _missile(0) {
>>>>>>> db210f60052ec3288f2eda2e1b1a5eaf5ddd0d9a
		return ;
}

/* Destructor */
AWeapon::~AWeapon( void ) {
	return ;
}

/* Operator */

/* Get */
Missile  	*AWeapon::getMissile( void ) const {
	return (this->_missile);
}
