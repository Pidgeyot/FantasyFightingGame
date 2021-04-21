/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef AREA_H
#define AREA_H
#include "Player.h"

class Area {
protected:
	int level;
	//int enemyStrength;
public:
	Area();
	Player generateEncounter(Player player);
	Player AreaChoosen(int choice, int level, Player player);
};

#endif
