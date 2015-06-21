/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 02:26:14 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "PetitMechant.class.hpp"

/*-------------- Constructors -------------*/
Game::Game(void) :
	_player(0, 0),
	_running(true),
	_width(0),
	_height(0)
{

	for (int i = 0; i < MAX_ENEMY; i++)
		this->_enemy[i] = 0;
	std::cout << "Welcome to ft_retro !" << std::endl;
	init_curses();
	return ;
}

/*--------------- Destructors --------------*/
Game::~Game(void) {
	std::cout << "Bye !" << std::endl;
	return ;
}


/*---------------- Operators ---------------*/


/*------------------ Geter -----------------*/




/*------------------ Seter -----------------*/

/*------------------ Other -----------------*/
void			Game::init_curses(void)
{
	initscr();
	cbreak();
	noecho();
	//nodelay(stdscr);
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, this->_height, this->_width);
}
void			Game::run(void) {
	int		x;
	int		y;
	for (int i = 0; i < MAX_ENEMY; i++) {
		x = rand() % this->_width;
		y = rand() % (this->_height - 50);
		this->_enemy[i] = new PetitMechant(x, y);
	}
	while (this->_running) {
		for (int i = 0; i < MAX_ENEMY; i++) {
			this->_enemy[i]->setY(this->_enemy[i]->getY() + 1);
		}
		for (int i = 0; i < 90000000; i++);
		this->render();
	}
}

void			Game::render(void) const{
	clear();
	for (int i = 0; i < MAX_ENEMY; i++) {
		move(this->_enemy[i]->getY(), this->_enemy[i]->getX());
		printw("#");
		refresh();
	}
}
