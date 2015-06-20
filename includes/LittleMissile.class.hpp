/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LittleMissile.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:04:34 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 16:04:35 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTLEMISSILE_CLASS_HPP
# define LITTLEMISSILE_CLASS_HPP

#include "Missile.class.hpp"

class LittleMissile: public Missile
{

public:
	LittleMissile( void );
	virtual ~LittleMissile( void );


protected:
	int _damage;

private:
	LittleMissile( LittleMissile const & src);
	LittleMissile & operator=( LittleMissile const & rhs);
};

#endif
