/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PetitMechant.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:13:10 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 16:20:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETITMECHANT_CLASS_HPP 
# define PETITMECHANT_CLASS_HPP

# include <iostream>
# include "Enemy.class.hpp"

class	PetitMechant : public Enemy
{
	public:
		PetitMechant(int X, int Y);
		~PetitMechant(void);

	private:
		PetitMechant(void);
		PetitMechant(PetitMechant const & src);

		PetitMechant		& operator=(PetitMechant const & right);

};

#endif

