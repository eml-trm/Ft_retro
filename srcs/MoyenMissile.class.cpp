/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenMissile.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:53:30 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 18:23:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MoyenMissile.class.hpp"
#include "Missile.class.hpp"

/* Constructor */
MoyenMissile::MoyenMissile( int X, int Y): Missile("Moyen Missile", 20, X, Y, 2, 1, "()") {
//		std::cout << "Moyen missile was created" << std::endl;
		return ;
}


/* Destructor */
MoyenMissile::~MoyenMissile( void ) {
//	std::cout << "Moyen missile was destroyed" << std::endl;
	return ;
}

/* Operator */


/* Get */

