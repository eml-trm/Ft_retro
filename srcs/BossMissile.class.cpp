/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossMissile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 22:02:21 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 22:58:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BossMissile.class.hpp"
#include "Missile.class.hpp"

/* Constructor */
BossMissile::BossMissile( int X, int Y): Missile("Boss Missile", 500, X, Y, 4, 3, "0000") {
//		std::cout << "Boss missile was created" << std::endl;
		return ;
}


/* Destructor */
BossMissile::~BossMissile( void ) {
//	std::cout << "Boss missile was destroyed" << std::endl;
	return ;
}

/* Operator */


/* Get */


