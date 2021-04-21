/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef ARMOR_H
#define ARMOR_H

#include <string>
using namespace std;

class Armor {
private:
	int defense;
	int cost;
	string name;
	int tier;
public:
	Armor();
	Armor(int num);
	int getDefense();
	int getCost();
	string getName();
	int getTier();
};

#endif
