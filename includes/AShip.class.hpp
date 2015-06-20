/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AShip.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 15:13:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 16:09:21 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASHIP_CLASS_HPP 
# define ASHIP_CLASS_HPP

# include <iostream>

class	AShip
{
	public:
		AShip(std::string type, int X, int Y);
		virtual ~AShip(void);

		std::string		getType(void) const;


	private:
		AShip(void);
		AShip(AShip const & src);

		AShip		& operator=(AShip const & right);

	protected:
		std::string	_type;
		int			_X;
		int			_Y;

};

#endif

