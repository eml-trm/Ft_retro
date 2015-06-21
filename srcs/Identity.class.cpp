/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:49:25 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 11:16:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identity.class.hpp"

/*-------------- Constructors -------------*/
Identity::Identity(std::string type, int X, int Y, std::string skin):
		_type(type),
		_X(X),
		_Y(Y),
		_skin(skin),
		_alive(true) {
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
int 				Identity::getSizeX(void) const {
	return (this->_sizeX);
}
int 				Identity::getSizeY(void) const {
	return (this->_sizeY);
}
std::string			Identity::getSkin(void) const {
	return (this->_skin);
}
bool				Identity::getAlive(void) const {
	return (this->_alive);
}



/*------------------ Seter -----------------*/
void				Identity::setX(int X) {
	this->_X = X;
	return ;
}
void				Identity::setY(int Y) {
	this->_Y = Y;
	return ;
}


/*------------------ Other -----------------*/
void				Identity::die(void) {
	this->_alive = false;
}
void				Identity::born(void) {
	this->_alive = true;
}
