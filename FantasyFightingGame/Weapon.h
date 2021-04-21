/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon {
protected:
	int attack;
	int cost;
	string name;
	int tier;
public:
	Weapon();
	Weapon(int num);
	int getAttack();
	int getCost();
	string getName();
	int getTier();
};

#endif
