/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossWeapon.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:58:25 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 22:07:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSSWEAPON_CLASS_HPP
# define BOSSWEAPON_CLASS_HPP

# include "AWeapon.class.hpp"

class BossWeapon: public AWeapon
{

	public:
		BossWeapon( int X, int Y );
		virtual ~BossWeapon( void );

		// virtual void attack( void ) const ;

	private:
		BossWeapon( void );
		BossWeapon( BossWeapon const & src);
		BossWeapon & operator=( BossWeapon const & rhs);
};

#endif


