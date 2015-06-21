/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/21 01:01:05 by bsautron          #+#    #+#             */
/*   Updated: 2015/06/21 22:59:43 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "PetitMechant.class.hpp"
#include "GrosMechant.class.hpp"
#include "MoyenMechant.class.hpp"
#include "LittleMissile.class.hpp"
#include "MoyenMissile.class.hpp"
#include "GrosMissile.class.hpp"
#include "GrosWeapon.class.hpp"
#include "PetitWeapon.class.hpp"
#include "MoyenWeapon.class.hpp"
#include "Boss.class.hpp"
#include "BossWeapon.class.hpp"
#include "BossMissile.class.hpp"
#include <ctime>
#include <chrono>
#include <thread>

bool			Game::_sBoss = false;
bool			Game::_kBoss = false;

/*-------------- Constructors -------------*/
Game::Game(void) :
	_player(0, 0),
	_running(true),
	_width(0),
	_height(0),
	_score(0),
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
	this->_boss = 0;
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
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
}


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
				if (this->_player.getWeapon()->getType() == "Petit Weapon")
					this->_mPlayer[i] = new LittleMissile(this->_player.getX(), this->_player.getY());
				if (this->_player.getWeapon()->getType() == "Moyen Weapon")
					this->_mPlayer[i] = new MoyenMissile(this->_player.getX(), this->_player.getY());
				if (this->_player.getWeapon()->getType() == "Gros Weapon")
					this->_mPlayer[i] = new GrosMissile(this->_player.getX(), this->_player.getY());
				if (this->_player.getWeapon()->getType() == "Boss Weapon")
					this->_mPlayer[i] = new BossMissile(this->_player.getX(), this->_player.getY());

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
							if (this->_enemy[j]->getHP() > 20)
							{
								this->_enemy[j]->setHP(this->_enemy[j]->getHP() - this->_mPlayer[i]->getDamage());
							}
							else
							{
								this->_score += this->_enemy[j]->getValue();
								delete this->_enemy[j];
								this->_enemy[j] = 0;
							}
							delete this->_mPlayer[i];
							this->_mPlayer[i] = 0;
							return ;

						}

						if (this->_boss)
						{
							if (this->_mPlayer[i]->getY() + y >= this->_boss->getY() 
									&& this->_mPlayer[i]->getY() + y <= (this->_boss->getY() + this->_boss->getSizeY())
									&& this->_mPlayer[i]->getX() + x >= this->_boss->getX()
									&& this->_mPlayer[i]->getX() + x <= (this->_boss->getX() + this->_boss->getSizeX()))
							{
								if (this->_boss->getHP() > 20)
								{
									this->_boss->setHP(this->_boss->getHP() - this->_mPlayer[i]->getDamage());
								}
								else
								{
									this->_score += this->_boss->getValue();
									delete this->_boss;
									this->_boss = 0;
									Game::_sBoss = true;
									Game::_kBoss = true;
								}
								delete this->_mPlayer[i];
								this->_mPlayer[i] = 0;
								return ;
							}
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

	for (int i = 0; i < MAX_MISSIL_ENEMY; i++)
	{
		if (this->_mEnemy[i])
		{
			if (this->_player.getY() >= this->_mEnemy[i]->getY()
					&& this->_player.getY() <= (this->_mEnemy[i]->getY() + this->_mEnemy[i]->getSizeY())
					&& this->_player.getX() >= this->_mEnemy[i]->getX()
					&& this->_player.getX() <= (this->_mEnemy[i]->getX() + this->_mEnemy[i]->getSizeX()))
			{
				this->_player.die();
				this->_life--;
				delete this->_mEnemy[i];
				this->_mEnemy[i] = 0;
				this->_running = false;
				std::cout << "\a" << std::endl;
				return ;
			}
			if (this->_mEnemy[i] && this->_mEnemy[i]->getY() > LIMAX_SPACE_Y) {
				delete this->_mEnemy[i];
				this->_mEnemy[i] = 0;
			}
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
				std::cout << "\a" << std::endl;
			}
		}
		if (this->_enemy[j] && this->_enemy[j]->getY() > LIMAX_SPACE_Y) {
			delete this->_enemy[j];
			this->_enemy[j] = 0;
		}
	}

	if (this->_boss)
	{
		if (this->_player.getY() >= this->_boss->getY()
				&& this->_player.getY() <= (this->_boss->getY() + this->_boss->getSizeY())
				&& this->_player.getX() >= this->_boss->getX()
				&& this->_player.getX() <= (this->_boss->getX() + this->_boss->getSizeX()))
		{
			this->_player.die();
			this->_life--;
			delete this->_boss;
			this->_boss = 0;
			Game::_sBoss = true;
			this->_running = false;
			std::cout << "\a" << std::endl;
		}

		if (this->_boss && this->_boss->getY() > LIMAX_SPACE_Y) {
			delete this->_boss;
			this->_boss = 0;
			Game::_sBoss = true;
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
	if (this->_score > 6000 && !this->_boss && Game::_sBoss == false)
		this->_boss = new Boss(this->_width / 2, 5);
}

void			Game::run(void) {

	//int		x;
	int		mSpeedPlayer = 0;
	int		mSpeedEnemy = 0;
	int		enemySpeed = 0;
	int		bossSpeed = 0;
	int		ch;
	int 	time = 0;
	int		randAtt = 0;

	this->createBackground();

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


			AWeapon		*petit = new PetitWeapon(this->_player.getX(), this->_player.getY());
			AWeapon		*moyen = new MoyenWeapon(this->_player.getX(), this->_player.getY());
			AWeapon		*gros = new GrosWeapon(this->_player.getX(), this->_player.getY());
			AWeapon		*boss = new BossWeapon(this->_player.getX(), this->_player.getY());

			if (this->_score > 5000)
				this->_player.setWeapon(gros);
			else if (this->_score > 2000)
				this->_player.setWeapon(moyen);
			else
				this->_player.setWeapon(petit);
			if (Game::_kBoss)
				this->_player.setWeapon(boss);
			this->_player.getWeapon()->getMissile()->setX(this->_player.getX() - this->_player.getWeapon()->getMissile()->getSizeX() / 2);

			this->spawnEnemy();
			while ((ch = getch()) != ERR)
				this->handleEvent(ch);

			if (enemySpeed == 20)
			{
				enemySpeed = 0;
				for (int i = 0; i < MAX_ENEMY; i++)
				{
					if (this->_enemy[i])
					{
						this->_enemy[i]->setY(this->_enemy[i]->getY() + 1);
						randAtt = rand() % 100;
						if (randAtt == 0) {
							for (int j = 0; j < MAX_MISSIL_ENEMY; j++) {
								if (!this->_mEnemy[j]) {
									if (this->_enemy[i]->getWeapon()->getMissile()->getType() == "Little Missile")
										this->_mEnemy[j] = new LittleMissile(this->_enemy[i]->getX(), this->_enemy[i]->getY());
									if (this->_enemy[i]->getWeapon()->getMissile()->getType() == "Moyen Missile")
										this->_mEnemy[j] = new MoyenMissile(this->_enemy[i]->getX(), this->_enemy[i]->getY());
									if (this->_enemy[i]->getWeapon()->getMissile()->getType() == "Gros Missile")
										this->_mEnemy[j] = new GrosMissile(this->_enemy[i]->getX(), this->_enemy[i]->getY());
									break ;
								}
							}
						}
					}
				}
				this->collision();
			}

			if (bossSpeed == 25)
			{
				bossSpeed = 0;
				if (this->_boss) {
					this->_boss->setY(this->_boss->getY() + 1);

					randAtt = rand() % 10;
					if (randAtt == 0) {
						for (int j = 0; j < MAX_MISSIL_ENEMY; j++) {
							if (!this->_mEnemy[j]) {
								this->_mEnemy[j] = new BossMissile(this->_boss->getX() + this->_boss->getSizeX() / 2 - this->_boss->getWeapon()->getMissile()->getSizeX() / 2, this->_boss->getY());
								break ;
							}
						}
					}
				}
			}
			if (mSpeedEnemy == 5)
			{
				mSpeedEnemy = 0;
				for (int i = 0; i < MAX_MISSIL_ENEMY; i++)
				{
					if (this->_mEnemy[i])
						this->_mEnemy[i]->setY(this->_mEnemy[i]->getY() + 1);
				}
			}

			if (mSpeedPlayer == 1)
			{
				mSpeedPlayer = 0;
				for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
				{
					if (this->_mPlayer[i])
						this->_mPlayer[i]->setY(this->_mPlayer[i]->getY() - 1);
				}
				this->collision();
			}
			mSpeedPlayer++;
			mSpeedEnemy++;
			enemySpeed++;
			bossSpeed++;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			time++;
			if (time == 100)
			{
				this->_time++;
				time = 0;
			}
			this->render();
			delete	petit;
			delete	moyen;
			delete	gros;
		}
		this->_running = true;
	}
	this->gameOver();
}

void			Game::gameOver(void) {

	move(LIMAX_SPACE_Y / 2, LIMAX_SPACE_X / 2);
	printw("Game Over");
	refresh();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	endwin();
}


void			Game::render(void) const {
	clear();
	this->drawBackground();
	attron(COLOR_PAIR(2)|A_BOLD);
	for (int i = 0; i < MAX_MISSIL_PLAYER; i++)
	{
		if (this->_mPlayer[i]) {
			for (int h = 0; h < this->_mPlayer[i]->getSizeY(); h++) {
				move(this->_mPlayer[i]->getY() + h, this->_mPlayer[i]->getX());
				printw("%s", this->_mPlayer[i]->getSkin().c_str());
			}
		}
	}

	for (int i = 0; i < MAX_MISSIL_ENEMY; i++)
	{
		if (this->_mEnemy[i]) {
			for (int h = 0; h < this->_mEnemy[i]->getSizeY(); h++) {
				move(this->_mEnemy[i]->getY() + h, this->_mEnemy[i]->getX());
				printw("%s", this->_mEnemy[i]->getSkin().c_str());
			}
		}
	}
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(3));
	if (this->_boss) {
		for (int h = 0; h < this->_boss->getSizeY(); h++)
		{
			move(this->_boss->getY() + h, this->_boss->getX());
			printw("%s", this->_boss->getSkin().c_str());
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
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
	if (this->_player.getAlive()) {
		move(this->_player.getY(), this->_player.getX());
		printw("%s", this->_player.getSkin().c_str());
	}
	attroff(COLOR_PAIR(4));
	this->printInfo();
	refresh();

}

void			Game::createBackground(void) {

	int x = 0;
	int y = 0;

	for (int i = 0; i < this->_height; i++)
	{

		for (int j = 0; j < this->_width; j++)
			this->_bg[i][j] = 0;

	}

	for (int i = 0; i < 20; i++) {

		x = rand() % (this->_width - 10) + 1;
		y = rand() % (this->_height - 10) + 1;
		this->_bg[y][x] = '.';
	}
	for (int i = 0; i < 6; i++) {

		x = rand() % (this->_width - 10) + 1;
		y = rand() % (this->_height - 10) + 1;
		this->_bg[y][x] = '*';
	}
	for (int i = 0; i < 4; i++) {

		x = rand() % (this->_width - 10) + 1;
		y = rand() % (this->_height - 10) + 1;
		this->_bg[y][x] = 'o';
	}

}
void			Game::drawBackground(void) const {

	for (int i = 0; i < this->_height; i++)
	{
		for (int j = 0; j < this->_width; j++)
		{
			if (this->_bg[i][j] != 0)
			{
				move(i, j);
				printw("%c", this->_bg[i][j]);
			}
		}
	}
	// attron(COLOR_PAIR(2)|A_BOLD);
	// move(LIMAX_SPACE_Y / i, LIMAX_SPACE_X / j);
	// attroff(COLOR_PAIR(2));
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
