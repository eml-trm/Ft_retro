/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 15:53:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "PetitMechant.class.hpp"
#include "GrosMechant.class.hpp"
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
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++) {
		this->_mPlayer[i] = new LittleMissile(0, 0);
		this->_mPlayer[i]->die();
	}
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
	nodelay(stdscr, true);
	curs_set(0);
	keypad(stdscr, true);
	getmaxyx(stdscr, this->_height, this->_width);
}


void			Game::handleEvent(int ch) {
	if (ch == 27) {
		this->_running = false;
		endwin();
		exit(0);
	}
	if (ch == KEY_LEFT) {
		if (this->_player.getX() > 0)
			this->_player.setX(this->_player.getX() - 1);
	}
	if (ch == KEY_RIGHT) {
		if (this->_player.getX() < this->_width - 1)
		this->_player.setX(this->_player.getX() + 1);
	}
	if (ch == KEY_DOWN) {
		if (this->_player.getY() < this->_height - 1)
			this->_player.setY(this->_player.getY() + 1);
	}
	if (ch == KEY_UP) {
		if (this->_player.getY() > 0)
			this->_player.setY(this->_player.getY() - 1);
	}
	if (ch == ' ') {
		for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
		{
			if (!this->_mPlayer[i]->getAlive())
			{
				this->_mPlayer[i]->setX(this->_player.getX());
				this->_mPlayer[i]->setY(this->_player.getY());
				this->_mPlayer[i]->born();
				return ;
			}
		}
	}
}

void			Game::collision(void) {

	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		for (int j = 0; j < MAX_ENEMY; j++)
		{
			if (this->_mPlayer[i]->getAlive() && this->_enemy[j]->getAlive()) {

				if (this->_mPlayer[i]->getY() >= this->_enemy[j]->getY() 
					&& this->_mPlayer[i]->getY() <= (this->_enemy[j]->getY() + this->_enemy[j]->getSizeY())
					&& this->_mPlayer[i]->getX() >= this->_enemy[j]->getX()
					&& this->_mPlayer[i]->getX() <= (this->_enemy[j]->getX() + this->_enemy[j]->getSizeX()))
				{
					this->_mPlayer[i]->die();
					this->_enemy[j]->die();
				}

				if (this->_mPlayer[i]->getY() < 0)
					this->_mPlayer[i]->die();
				if (this->_enemy[j]->getY() > this->_height - 1)
					this->_enemy[j]->die();
			}
		}
	}
	for (int j = 0; j < MAX_ENEMY; j++)
	{
		if (this->_player.getAlive() && this->_enemy[j]->getAlive()) {
		
			if (this->_player.getY() >= this->_enemy[j]->getY()
				&& this->_player.getY() <= (this->_enemy[j]->getY() + this->_enemy[j]->getSizeY())
				&& this->_player.getX() >= this->_enemy[j]->getX()
				&& this->_player.getX() <= (this->_enemy[j]->getX() + this->_enemy[j]->getSizeX()))
			{
				this->_player.die();
				this->_enemy[j]->die();
			}
		}
	}
}

void			Game::run(void) {

	int		x;
	int		y;
	int		mSpeed = 0;
	int		enemySpeed = 0;
	int		ch;

	this->_player.setX(this->_width / 2);
	this->_player.setY(this->_height - 2);

	for (int i = 0; i < MAX_ENEMY; i++) {
		x = rand() % (this->_width - 10) + 5;
		y = rand() % 10 + 1;
		this->_enemy[i] = new GrosMechant(x, y);
	}
	while (this->_running) {

		while ((ch = getch()) != ERR)
		{
			this->handleEvent(ch);
		}
		if (enemySpeed == 5)
		{
			enemySpeed = 0;
			for (int i = 0; i < MAX_ENEMY; i++)
			{
				if (this->_enemy[i]->getAlive())
					this->_enemy[i]->setY(this->_enemy[i]->getY() + 1);
			}
			this->collision();
		}

		if (mSpeed == 1)
		{
			mSpeed = 0;
			for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
			{
				if (this->_mPlayer[i]->getAlive())
					this->_mPlayer[i]->setY(this->_mPlayer[i]->getY() - 1);
			}
			this->collision();
		}
		mSpeed++;
		enemySpeed++;
		for (int i = 0; i < 12000000; i++);
		this->render();
	}
}



void			Game::render(void) const {
	clear();
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		if (this->_mPlayer[i]->getAlive()) {
			move(this->_mPlayer[i]->getY(), this->_mPlayer[i]->getX());
			printw("%s", this->_mPlayer[i]->getSkin().c_str());
		}
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (this->_enemy[i]->getAlive()) {
			for (int h = 0; h < this->_enemy[i]->getSizeY(); h++)
			{
				move(this->_enemy[i]->getY() + h, this->_enemy[i]->getX());
				printw("%s", this->_enemy[i]->getSkin().c_str());
			}
		}
	}

	if (this->_player.getAlive()) {
		move(this->_player.getY(), this->_player.getX());
		printw("%s", this->_player.getSkin().c_str());
	}

	refresh();
}

// void			Game::printfInfo(void) const {

// 	mvprint
// }
