/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosMissile.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:49:58 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:49:59 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GrosMISSILE_CLASS_HPP
# define GrosMISSILE_CLASS_HPP

# include "Missile.class.hpp"

class GrosMissile: public Missile
{

public:
	GrosMissile( int x, int y);
	virtual ~GrosMissile( void );


protected:
	int _damage;

private:
	GrosMissile( void );
	GrosMissile( GrosMissile const & src);
	GrosMissile & operator=( GrosMissile const & rhs);
};

#endif
