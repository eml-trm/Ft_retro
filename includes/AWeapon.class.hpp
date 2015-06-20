/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:06:38 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 17:05:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_CLASS_HPP
# define AWEAPON_CLASS_HPP

#include <iostream>

class AWeapon
{

public:
	AWeapon(std::string type);
	virtual ~AWeapon();
	

	std::string 	getType() const;
	virtual void 	attack() const = 0;

protected:
	std::string _type;

private:
	AWeapon( void );
	AWeapon( AWeapon const & src);

	AWeapon & operator=( AWeapon const & rhs);
};

#endif
