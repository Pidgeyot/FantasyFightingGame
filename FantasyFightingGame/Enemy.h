/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;

class Enemy {
private:
	string name;
	int health;
	int damage;
	int gold;
public:
	Enemy();
	Enemy(int num);
	void showCharacter();
	int attack();
	void setAttack(int playerDefense);
	void takeDamage(int damage);
	int getDamage();
	int getGold();
	int getHealth();
	string getName();
};

#endif
