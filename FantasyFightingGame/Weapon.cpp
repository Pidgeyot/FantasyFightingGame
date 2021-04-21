/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Weapon.h"
#include <iostream>

Weapon::Weapon()
{
}

Weapon::Weapon(int num)
{
	//for a certain inputted number, set the values to represent different weapons
	if (num == 0) {
		attack = 10;
		cost = 0;
		name = "Basic Sword";
		tier = 0;
	}
	else if (num == 1) {
		attack = 40;
		cost = 35;
		name = "Starter Sword";
		tier = 1;
	}
	else if (num == 2) {
		attack = 75;
		cost = 60;
		name = "Great Sword";
		tier = 2;
	}
	else if (num == 3) {
		attack = 130;
		cost = 95;
		name = "Masters Sword";
		tier = 3;
	}
}

int Weapon::getAttack()
{
	return attack;
}

int Weapon::getCost()
{
	return cost;
}

string Weapon::getName()
{
	return name;
}

int Weapon::getTier()
{
	return tier;
}