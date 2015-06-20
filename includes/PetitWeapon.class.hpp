/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitWeapon.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 17:04:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 19:11:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETITWEAPON_CLASS_HPP
# define PETITWEAPON_CLASS_HPP

# include "AWeapon.class.hpp"

class PetitWeapon: public AWeapon
{

	public:
		PetitWeapon( int X, int Y );
		virtual ~PetitWeapon( void );

		// virtual void attack( void ) const ;

	private:
		PetitWeapon( void );
		PetitWeapon( PetitWeapon const & src);
		PetitWeapon & operator=( PetitWeapon const & rhs);
};

#endif
