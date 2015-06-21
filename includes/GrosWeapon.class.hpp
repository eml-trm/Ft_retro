/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosWeapon.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:58:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:58:27 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROSWEAPON_CLASS_HPP
# define GROSWEAPON_CLASS_HPP

# include "AWeapon.class.hpp"

class GrosWeapon: public AWeapon
{

	public:
		GrosWeapon( int X, int Y );
		virtual ~GrosWeapon( void );

		// virtual void attack( void ) const ;

	private:
		GrosWeapon( void );
		GrosWeapon( GrosWeapon const & src);
		GrosWeapon & operator=( GrosWeapon const & rhs);
};

#endif


