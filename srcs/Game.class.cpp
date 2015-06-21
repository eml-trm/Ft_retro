/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 19:10:22 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "PetitMechant.class.hpp"
#include "GrosMechant.class.hpp"
#include "MoyenMechant.class.hpp"
#include "LittleMissile.class.hpp"
#include "MoyenMissile.class.hpp"
#include "GrosMissile.class.hpp"
#include <ctime>
#include <chrono>
#include <thread>

/*-------------- Constructors -------------*/
Game::Game(void) :
	_player(0, 0),
	_running(true),
	_width(0),
	_height(0),
	_time(0),
	_life(3)
{

	std::srand(std::time(0));
	for (int i = 0; i < MAX_ENEMY; i++)
		this->_enemy[i] = 0;
	for (int i = 0; i < MAX_MISSIL_ENEMY; i++)
		this->_mEnemy[i] = 0;
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++) {
		this->_mPlayer[i] = 0;
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
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
}

#include <stdio.h>

void			Game::handleEvent(int ch) {
	if (ch == 27) {
		this->_running = false;
		endwin();
		exit(0);
	}
	if (ch == KEY_LEFT) {
		if (this->_player.getX() > LIMIN_SPACE_X)
			this->_player.setX(this->_player.getX() - 2);
	}
	if (ch == KEY_RIGHT) {
		if (this->_player.getX() < LIMAX_SPACE_X)
			this->_player.setX(this->_player.getX() + 2);
	}
	if (ch == KEY_DOWN) {
		if (this->_player.getY() < LIMAX_SPACE_Y)
			this->_player.setY(this->_player.getY() + 1);
	}
	if (ch == KEY_UP) {
		if (this->_player.getY() > LIMIN_SPACE_X)
			this->_player.setY(this->_player.getY() - 1);
	}
	if (ch == ' ') {
		for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
		{
			if (!this->_mPlayer[i])
			{
				this->_mPlayer[i] = new GrosMissile(this->_player.getX(), this->_player.getY());
				this->_mPlayer[i]->setX(this->_mPlayer[i]->getX() - this->_mPlayer[i]->getSizeX() / 2);
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
			if (this->_mPlayer[i] && this->_enemy[j]) {

				for (int y = 0; y < this->_mPlayer[i]->getSizeY(); y++)
				{
					for (int x = 0; x < this->_mPlayer[i]->getSizeX(); x++)
					{
							if (this->_mPlayer[i]->getY() + y >= this->_enemy[j]->getY() 
									&& this->_mPlayer[i]->getY() + y <= (this->_enemy[j]->getY() + this->_enemy[j]->getSizeY())
									&& this->_mPlayer[i]->getX() + x >= this->_enemy[j]->getX()
									&& this->_mPlayer[i]->getX() + x <= (this->_enemy[j]->getX() + this->_enemy[j]->getSizeX()))
							{
								this->_score += this->_enemy[j]->getValue();
								delete this->_mPlayer[i];
								delete this->_enemy[j];
								this->_mPlayer[i] = 0;
								this->_enemy[j] = 0;
								return ;
							}
					}
				}
			}
		}

		if (this->_mPlayer[i] && this->_mPlayer[i]->getY() < LIMIN_SPACE_Y) {
			delete this->_mPlayer[i];
			this->_mPlayer[i] = 0;
		}
	}

	for (int j = 0; j < MAX_ENEMY; j++)
	{
		if (this->_player.getAlive() && this->_enemy[j]) {

			if (this->_player.getY() >= this->_enemy[j]->getY()
					&& this->_player.getY() <= (this->_enemy[j]->getY() + this->_enemy[j]->getSizeY())
					&& this->_player.getX() >= this->_enemy[j]->getX()
					&& this->_player.getX() <= (this->_enemy[j]->getX() + this->_enemy[j]->getSizeX()))
			{
				this->_player.die();
				this->_life--;
				delete this->_enemy[j];
				this->_enemy[j] = 0;
				this->_running = false;	
			}
		}
		if (this->_enemy[j] && this->_enemy[j]->getY() > LIMAX_SPACE_Y) {
			delete this->_enemy[j];
			this->_enemy[j] = 0;
		}
	}
}

void			Game::spawnEnemy(void) {
	int		ran = rand() % 100;
	int		x = rand() % (this->_width - 10) + 5;
	int		type = rand() % 3;

	if (ran == 0)
	{
		for (int i = 0; i < MAX_ENEMY; i++) {
			if (!this->_enemy[i]) {
				if (type == 0)
					this->_enemy[i] = new PetitMechant(x, 0);
				else if (type == 1)
					this->_enemy[i] = new MoyenMechant(x, 0);
				else if (type == 2)
					this->_enemy[i] = new GrosMechant(x, 0);
				return ;
			}
		}
	}
}

void			Game::run(void) {

	//int		x;
	int		mSpeed = 0;
	int		enemySpeed = 0;
	int		ch;
	int 	time = 0;

	while (this->_life > 0)
	{
		if (this->_life != 3)
		{
			move(LIMAX_SPACE_Y / 2, LIMAX_SPACE_X / 2);
			printw("You lose one life");
			refresh();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		this->_player.setX(this->_width / 2);
		this->_player.setY(LIMAX_SPACE_Y);
		this->_player.born();
		while (this->_running) {

			this->spawnEnemy();
			while ((ch = getch()) != ERR)
				this->handleEvent(ch);

			if (enemySpeed == 20)
			{
				enemySpeed = 0;
				for (int i = 0; i < MAX_ENEMY; i++)
				{
					if (this->_enemy[i])
						this->_enemy[i]->setY(this->_enemy[i]->getY() + 1);
				}
				this->collision();
			}

			if (mSpeed == 1)
			{
				mSpeed = 0;
				for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
				{
					if (this->_mPlayer[i])
						this->_mPlayer[i]->setY(this->_mPlayer[i]->getY() - 1);
				}
				this->collision();
			}
			mSpeed++;
			enemySpeed++;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			time++;
			if (time == 100)
			{
				this->_time++;
				time = 0;
			}
			this->render();
		}
		this->_running = true;
	}
	move(LIMAX_SPACE_Y / 2, LIMAX_SPACE_X / 2);
	printw("Game Over");
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	endwin();
}



void			Game::render(void) const {
	clear();
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		if (this->_mPlayer[i]) {
			for (int h = 0; h < this->_mPlayer[i]->getSizeY(); h++) {
				move(this->_mPlayer[i]->getY() + h, this->_mPlayer[i]->getX());
				printw("%s", this->_mPlayer[i]->getSkin().c_str());
			}
		}
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (this->_enemy[i]) {
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
	this->printInfo();
	refresh();
}

void			Game::printInfo(void) const {

	attron(COLOR_PAIR(1));
	move(LIMAX_SPACE_Y + 1, 0);
	printw("+------------------+\n");
	printw("| Score: %d\n", this->_score);
	printw("| Lifes: %d\n", this->_life);
	printw("| Time: %ds\n",this->_time);
	printw("+------------------+");
	attroff(COLOR_PAIR(1));
}
