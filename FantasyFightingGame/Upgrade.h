/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef UPGRADE_H
#define UPGRADE_H

#include <string>
using namespace std;

class Upgrade {
protected:
	int increase;
	int cost;
	string name;
public:
	Upgrade();
	Upgrade(int num);
	int increaseHealth();
	int getCost();
	string getName();
};

#endif#pragma once
