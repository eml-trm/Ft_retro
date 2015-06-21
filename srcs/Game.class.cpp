/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 17:07:35 by bsautron         ###   ########.fr       */
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
	// init_color(COLOR_1, 20, 255, 24);
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
			if (!this->_mPlayer[i])
			{
				this->_mPlayer[i] = new LittleMissile(this->_player.getX(), this->_player.getY());
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

				if (this->_mPlayer[i]->getY() >= this->_enemy[j]->getY() 
						&& this->_mPlayer[i]->getY() <= (this->_enemy[j]->getY() + this->_enemy[j]->getSizeY())
						&& this->_mPlayer[i]->getX() >= this->_enemy[j]->getX()
						&& this->_mPlayer[i]->getX() <= (this->_enemy[j]->getX() + this->_enemy[j]->getSizeX()))
				{
					delete this->_mPlayer[i];
					delete this->_enemy[j];
					this->_mPlayer[i] = 0;
					this->_enemy[j] = 0;
				}
			}
		}
		if (this->_mPlayer[i] && this->_mPlayer[i]->getY() < 1) {
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
				delete this->_enemy[j];
				this->_enemy[j] = 0;
				this->_running = false;
			}
		}
		if (this->_enemy[j] && this->_enemy[j]->getY() > this->_height - 3) {
			delete this->_enemy[j];
			this->_enemy[j] = 0;
		}
	}
}

void			Game::spawnEnemy(void) {
	int		ran = rand() % 100;
	int		x = rand() % (this->_width - 10) + 5;

	if (ran == 0)
	{
		for (int i = 0; i < MAX_ENEMY; i++) {
			if (!this->_enemy[i]) {
				this->_enemy[i] = new PetitMechant(x, 0);
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

	this->_player.setX(this->_width / 2);
	this->_player.setY(this->_height - 2);

	while (1)
	{
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
			for (int i = 0; i < 4000000; i++);
			this->render();
		}
	}
}



void			Game::render(void) const {
	clear();
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		if (this->_mPlayer[i]) {
			move(this->_mPlayer[i]->getY(), this->_mPlayer[i]->getX());
			printw("%s", this->_mPlayer[i]->getSkin().c_str());
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
	mvprintw(this->_height - 4, this->_height - 80, "-------------------");
	mvprintw(80, 5, "Score: ");
	mvprintw(80, 12, "%d", this->_score);
	mvprintw(this->_height - 2, this->_height - 80, "-------------------");
	refresh();
	attroff(COLOR_PAIR(1));
	
	
}
















