/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Upgrade.h"

Upgrade::Upgrade()
{
}

Upgrade::Upgrade(int num) {
	//for a certain inputted number, set the values to represent different upgrades
	if (num == 1) {
		increase = 20;
		cost = 50;
		name = "Health Up I";
	}
	else if (num == 2) {
		increase = 30;
		cost = 80;
		name = "Health Up II";
	}
	else if (num == 3) {
		increase = 50;
		cost = 120;
		name = "Health Up III";
	}
}

int Upgrade::increaseHealth()
{
	return increase;
}

int Upgrade::getCost()
{
	return cost;
}

string Upgrade::getName()
{
	return name;
}