/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Armor.h"

Armor::Armor()
{
}

Armor::Armor(int num)
{
	//for a certain inputted number, set the values to represent different armors
	if (num == 0) {
		defense = 5;
		cost = 0;
		name = "Leather Armor";
		tier = 0;
	}
	else if (num == 1) {
		defense = 25;
		cost = 25;
		name = "Chainmail Armor";
		tier = 1;
	}
	else if (num == 2) {
		defense = 40;
		cost = 50;
		name = "Iron Armor";
		tier = 2;
	}
	else if (num == 3) {
		defense = 50;
		cost = 85;
		name = "Mythical Armor";
		tier = 3;
	}
}

int Armor::getDefense()
{
	return defense;
}

int Armor::getCost()
{
	return cost;
}

string Armor::getName()
{
	return name;
}

int Armor::getTier()
{
	return tier;
}