/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GrosMechant.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:58:16 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:58:17 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROSMECHANT_CLASS_HPP 
# define GROSMECHANT_CLASS_HPP

# include <iostream>
# include "Enemy.class.hpp"

class	GrosMechant : public Enemy
{
	public:
		GrosMechant(int X, int Y);
		~GrosMechant(void);

	private:
		GrosMechant(void);
		GrosMechant(GrosMechant const & src);

		GrosMechant		& operator=(GrosMechant const & right);

};

#endif
