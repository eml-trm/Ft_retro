/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:48:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/20 19:20:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTITY_CLASS_HPP 
# define IDENTITY_CLASS_HPP

# include <iostream>

class	Identity
{
	public:
		Identity(std::string type, int X, int Y);
		virtual ~Identity(void);

		int			getX(void) const;
		int			getY(void) const;
		std::string	getType(void) const;

	private:
		Identity(void);
		Identity(Identity const & src);
		Identity		& operator=(Identity const & right);

	protected:
		std::string	_type;
		int			_X;
		int			_Y;

};

#endif

