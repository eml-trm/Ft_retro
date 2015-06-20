/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:13:02 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 15:14:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AShip.class.hpp"

/*-------------- Constructors -------------*/
AShip::AShip(std::string name, int X, int Y) : _name(name), _X(X), _Y(Y) {
	std::cout << "AShip: Default constructor" << std::endl;
	return ;
}


/*--------------- Destructors --------------*/
AShip::~AShip(void) {
	std::cout << "AShip: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string			AShip::getName(void) const {
	return (this->_name);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

