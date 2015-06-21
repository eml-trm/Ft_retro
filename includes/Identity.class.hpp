/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:48:11 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 02:41:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTITY_CLASS_HPP 
# define IDENTITY_CLASS_HPP

# include <iostream>

class	Identity
{
	public:
		Identity(std::string type, int X, int Y, std::string skin);
		virtual ~Identity(void);

		std::string	getType(void) const;
		int			getX(void) const;
		int			getY(void) const;
		int 		getSizeX(void) const;
		int 		getSizeY(void) const;
		std::string	getSkin(void) const;
		bool		getAlive(void) const;

		void		setX(int X);
		void		setY(int Y);

		void		born(void);
		void		die(void);


	private:
		Identity(void);
		Identity(Identity const & src);
		Identity		& operator=(Identity const & right);

	protected:
		std::string	_type;
		int			_X;
		int			_Y;
		int 		_sizeX;
		int 		_sizeY;
		std::string _skin;
		bool		_alive;

};

#endif

