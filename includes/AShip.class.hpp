/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:13:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 18:53:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASHIP_CLASS_HPP 
# define ASHIP_CLASS_HPP

# include <iostream>
# include "AWeapon.class.hpp"
# include "Identity.class.hpp"

class	AShip : public Identity
{
	public:
		AShip(std::string type, int X, int Y, std::string skin);
		virtual ~AShip(void);

		AWeapon			* getWeapon(void) const;


	private:
		AShip(void);
		AShip(AShip const & src);

		AShip		& operator=(AShip const & right);

	protected:
		AWeapon		*_weapon;

};

#endif

