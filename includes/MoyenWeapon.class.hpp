/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenWeapon.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:44:46 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:44:47 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOYENWEAPON_CLASS_HPP
# define MOYENWEAPON_CLASS_HPP

# include "AWeapon.class.hpp"

class MoyenWeapon: public AWeapon
{

	public:
		MoyenWeapon( int X, int Y );
		virtual ~MoyenWeapon( void );

		// virtual void attack( void ) const ;

	private:
		MoyenWeapon( void );
		MoyenWeapon( MoyenWeapon const & src);
		MoyenWeapon & operator=( MoyenWeapon const & rhs);
};

#endif

