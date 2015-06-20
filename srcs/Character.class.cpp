/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:32:27 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 14:32:28 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("default"), _type("default") {

	std::cout << " Your Character " << this->_name << "was created !" << std::endl;
	return;
}

Character::Charatcer( Character const & src) {
	*this = src;
	return ;
}

Character::~Character( void ) {

	std::cout << "Your Character was destroyed !" << std::endl;
	return ;
}

Character & Character::operator=( Character const & rhs) {

	if (this != &rhs)
	{
	
	}
	return;
}