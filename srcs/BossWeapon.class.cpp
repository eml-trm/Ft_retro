/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossWeapon.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:57:51 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 22:08:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BossWeapon.class.hpp"
#include "AWeapon.class.hpp"
#include "BossMissile.class.hpp"

/* Constructor */
BossWeapon::BossWeapon( int X, int Y ): AWeapon("Boss Weapon", X, Y) {
	Missile 	*Boss = new BossMissile(X, Y);
	this->_missile = Boss;
	return ;
}


/* Destructor */
BossWeapon::~BossWeapon( void ) {
	return ;
}

// void	BossWeapon::attack( void ) const {


// 	return ;
// }

/* Operator */


/* Get */

