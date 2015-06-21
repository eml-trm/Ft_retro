/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoyenMechant.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 09:40:32 by etermeau          #+#    #+#             */
/*   Updated: 2015/06/21 09:40:33 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOYENMECHANT_CLASS_HPP 
# define MOYENMECHANT_CLASS_HPP

# include <iostream>
# include "Enemy.class.hpp"

class	MoyenMechant : public Enemy
{
	public:
		MoyenMechant(int X, int Y);
		~MoyenMechant(void);

	private:
		MoyenMechant(void);
		MoyenMechant(MoyenMechant const & src);

		MoyenMechant		& operator=(MoyenMechant const & right);

};

#endif
