/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenMissile.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:53:22 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:53:24 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOYENMISSILE_CLASS_HPP
# define MOYENMISSILE_CLASS_HPP

# include "Missile.class.hpp"

class MoyenMissile: public Missile
{

public:
	MoyenMissile( int x, int y);
	virtual ~MoyenMissile( void );


protected:
	int _damage;

private:
	MoyenMissile( void );
	MoyenMissile( MoyenMissile const & src);
	MoyenMissile & operator=( MoyenMissile const & rhs);
};

#endif
