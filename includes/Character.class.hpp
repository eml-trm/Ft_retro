/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 14:31:59 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/20 19:26:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AShip.class.hpp"

class Character : public AShip
{

	public:
		Character(int X, int Y);
		virtual ~Character( void );


	private:
		Character(void);
		Character( Character const & src);

		Character & operator=( Character const & rhs);
};

#endif
