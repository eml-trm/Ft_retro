/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LittleMissile.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:03:48 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 16:03:51 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LittleMissile.class.hpp"
#include "Missile.class.hpp"

/* Constructor */
LittleMissile::LittleMissile( int x, int y ): Missile("Little Missile", 10, x, y) {
		std::cout << "little missile was created" << std::endl;
		return ;
}


/* Destructor */
LittleMissile::~LittleMissile( void ) {
	std::cout << "little missile was destroyed" << std::endl;
	return ;
}

/* Operator */


/* Get */
