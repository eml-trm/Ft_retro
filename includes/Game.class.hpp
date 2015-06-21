/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGame.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:58:24 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 02:20:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP 
# define GAME_CLASS_HPP

# include <iostream>
# include "Identity.class.hpp"
# include "Character.class.hpp"
# include <curses.h>

# define	MAX_ENEMY	10

class	Game
{
	public:
		Game(void);
		virtual ~Game(void);

		//void	handleEvent(int ch);
		//void	addEnemy(void);
		void	init_curses(void);
		void	run(void);
		void	render(void) const;
	//	void	gameOver(void);


	private:
		Game(Game const & src);

		Game		& operator=(Game const & right);

		void			_init_curses(void);

		Character		_player;
		bool			_running;
		int				_width;
		int				_height;

		Identity		*_enemy[MAX_ENEMY];


};

#endif

