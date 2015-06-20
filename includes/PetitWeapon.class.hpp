/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitWeapon.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:04:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 17:04:26 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETITWEAPON_CLASS_HPP
# define PETITWEAPON_CLASS_HPP

#include "AWeapon.class.hpp"

class PetitWeapon: public AWeapon
{

public:
	PetitWeapon( void );
	virtual ~PetitWeapon( void );

	// virtual void attack( void ) const ;

private:
	PetitWeapon( PetitWeapon const & src);
	PetitWeapon & operator=( PetitWeapon const & rhs);
};

#endif
