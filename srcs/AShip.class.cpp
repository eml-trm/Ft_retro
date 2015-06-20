/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:13:02 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 16:12:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AShip.class.hpp"

/*-------------- Constructors -------------*/
AShip::AShip(std::string type, int X, int Y) : _type(type), _X(X), _Y(Y) {
	//std::cout << "AShip: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
AShip::~AShip(void) {
	//std::cout << "AShip: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string			AShip::getType(void) const {
	return (this->_type);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

