/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:06:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 15:06:26 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.class.hpp"

/* Constructor */
AWeapon::AWeapon( std::string type ): _type(type) {
		return ;
}

/* Destructor */
AWeapon::~AWeapon( void ) {
	return ;
}

/* Operator */

/* Get */
std::string 	AWeapon::getType( void ) const {
	return (this->_type);
}
