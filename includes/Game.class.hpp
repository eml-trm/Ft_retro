/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGame.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 00:58:24 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 22:50:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP 
# define GAME_CLASS_HPP

# include <iostream>
# include "Identity.class.hpp"
# include "Character.class.hpp"
# include "Enemy.class.hpp"
# include "Character.class.hpp"
# include <curses.h>

# define	MAX_ENEMY			10
# define	MAX_MISSIL_ENEMY	30
# define	MAX_MISSIL_PLAYER	100
# define	LIMAX_SPACE_Y		(this->_height - 6)
# define	LIMAX_SPACE_X		(this->_width - 2)
# define	LIMIN_SPACE_Y		2
# define	LIMIN_SPACE_X		2

# define	COLOR_1				20

class	Game
{
	public:
		Game(void);
		virtual ~Game(void);

		void	handleEvent(int ch);
		void	spawnEnemy(void);
		void	init_curses(void);
		void	run(void);
		void	collision(void);
		void	render(void) const;
		void	printInfo(void) const;
		void	gameOver(void) ;
		void	createBackground(void) ;
		void	drawBackground(void) const ;


	private:
		Game(Game const & src);

		Game		& operator=(Game const & right);

		void			_init_curses(void);

		Character		_player;
		bool			_running;
		int				_width;
		int				_height;
		int				_score;
		int 			_time;
		int 			_life;

		Enemy			*_enemy[MAX_ENEMY];
		Missile			*_mEnemy[MAX_MISSIL_ENEMY];
		Missile			*_mPlayer[MAX_MISSIL_PLAYER];
		char 			_bg[100][100];
		Enemy			*_boss;
		static bool		_sBoss;
		static bool		_kBoss;

};

#endif

