/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosMissile.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:49:44 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 18:23:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GrosMissile.class.hpp"
#include "Missile.class.hpp"

/* Constructor */
GrosMissile::GrosMissile( int X, int Y): Missile("Gros Missile", 50, X, Y, 3, 3, "|||") {
//		std::cout << "Gros missile was created" << std::endl;
		return ;
}


/* Destructor */
GrosMissile::~GrosMissile( void ) {
//	std::cout << "Gros missile was destroyed" << std::endl;
	return ;
}

/* Operator */


/* Get */

