/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:49:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 19:21:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identity.class.hpp"

/*-------------- Constructors -------------*/
Identity::Identity(std::string type, int X, int Y) :_type(type),  _X(X), _Y(Y) {
	//std::cout << "Identity: Default constructor" << std::endl;
	return ;
}

/*--------------- Destructors --------------*/
Identity::~Identity(void) {
	//std::cout << "Identity: Destructor" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/
std::string			Identity::getType(void) const {
	return (this->_type);
}
int					Identity::getX(void) const {
	return (this->_X);
}
int					Identity::getY(void) const {
	return (this->_Y);
}


/*------------------ Seter -----------------*/




/*------------------ Other -----------------*/

