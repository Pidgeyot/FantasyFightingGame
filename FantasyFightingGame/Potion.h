/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef POTION_H
#define POTION_H

#include <string>
using namespace std;

class Potion {
protected:
	int heal;
	int cost;
	string name;
public:
	Potion();
	Potion(int num);
	int healPlayer();
	int getCost();
	string getName();
};

#endif
