/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Potion.h"

Potion::Potion()
{
}

Potion::Potion(int num) {
	//for a certain inputted number, set the values to represent different potions
	if (num == 1) {
		heal = 20;
		cost = 10;
		name = "Basic Potion";
	}
	else if (num == 2) {
		heal = 65;
		cost = 35;
		name = "Greater Potion";
	}
	else if (num == 3) {
		heal = 125;
		cost = 60;
		name = "Litre Potion";
	}
}

int Potion::healPlayer()
{
	return heal;
}

int Potion::getCost()
{
	return cost;
}

string Potion::getName()
{
	return name;
}