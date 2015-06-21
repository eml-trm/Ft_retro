/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:06:38 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 13:21:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_CLASS_HPP
# define AWEAPON_CLASS_HPP

# include <iostream>
# include "Missile.class.hpp"
# include "Identity.class.hpp"

class AWeapon : public Identity
{

	public:
		AWeapon(std::string type, int X, int Y);
		virtual ~AWeapon();


		Missile 		*getMissile() const;
		// virtual void 	attack() const = 0;

	private:
		AWeapon( void );
		AWeapon( AWeapon const & src);

		AWeapon & operator=( AWeapon const & rhs);

	protected:
		Missile		*_missile;

};

#endif
