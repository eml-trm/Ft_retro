/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BossMissile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 22:02:29 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 22:02:31 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROSMISSILE_CLASS_HPP
# define GROSMISSILE_CLASS_HPP

# include "Missile.class.hpp"

class BossMissile: public Missile
{

public:
	BossMissile( int x, int y);
	virtual ~BossMissile( void );


protected:
	int _damage;

private:
	BossMissile( void );
	BossMissile( BossMissile const & src);
	BossMissile & operator=( BossMissile const & rhs);
};

#endif

