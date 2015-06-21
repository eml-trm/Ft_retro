/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 13:10:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "PetitMechant.class.hpp"
#include "LittleMissile.class.hpp"
#include <ctime>

/*-------------- Constructors -------------*/
Game::Game(void) :
	_player(0, 0),
	_running(true),
	_width(0),
	_height(0)
{

	std::srand(std::time(0));
	for (int i = 0; i < MAX_ENEMY; i++)
		this->_enemy[i] = 0;
	for (int i = 0; i < MAX_MISSIL_ENEMY; i++)
		this->_mEnemy[i] = 0;
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
		this->_mPlayer[i] = 0;
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


void			Game::collision(void) {

	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		for (int j = 0; j < MAX_ENEMY; j++)
		{
			if (this->_mPlayer[i]->getAlive() && this->_enemy[j]->getAlive()) {

				if (this->_mPlayer[i]->getY() == this->_enemy[j]->getY() 
						&& this->_mPlayer[i]->getX() == this->_enemy[j]->getX())
				{
					this->_mPlayer[i]->die();
					this->_enemy[j]->die();
				}
			}
		}
	}
}

void			Game::run(void) {

	int		x;
	int		y;

	for (int i = 0; i < MAX_ENEMY; i++) {
		x = rand() % 3 + 1;
		y = rand() % 10 + 1;
		this->_enemy[i] = new PetitMechant(x, y);
	}

	for (int i = 0; i < MAX_MISSIL_PLAYER; i++) {
		x = rand() % 3 + 1;
		y = rand() % 10 + 15;
		this->_mPlayer[i] = new LittleMissile(x, y);
	}

	while (this->_running) {

		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (this->_enemy[i]->getAlive())
				this->_enemy[i]->setY(this->_enemy[i]->getY() + 1);
		}
		this->collision();

		for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
		{
			if (this->_mPlayer[i]->getAlive())
				this->_mPlayer[i]->setY(this->_mPlayer[i]->getY() - 1);
		}
		this->collision();

		for (int i = 0; i < 120000000; i++);
		this->render();
	}
}



void			Game::render(void) const {
	clear();
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		if (this->_mPlayer[i]->getAlive()) {
			move(this->_mPlayer[i]->getY(), this->_mPlayer[i]->getX());
			printw("|");
			refresh();
		}
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (this->_enemy[i]->getAlive()) {
			move(this->_enemy[i]->getY(), this->_enemy[i]->getX());
			printw("#");
			refresh();
		}
	}
}
