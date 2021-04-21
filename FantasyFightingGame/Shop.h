#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <vector>
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Upgrade.h"
/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Player.h"
using namespace std;

class Shop {
private:
	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Potion> potions;
	vector<Upgrade> upgrades;
public:
	Shop();
	vector<Weapon> returnWeapons(); //needed to give source the vector(s)
	vector<Armor> returnArmors();
	//vector<Potion> returnPotions();

	//put all vectors in for inventory use
	Player openInventory(vector<Weapon> weapons, vector<Armor> armors, Player player);
	Player shopWeapons(vector<Weapon> weapons, vector<Armor> armors, Player player);
	Player shopArmors(vector<Weapon> weapons, vector<Armor> armors, Player player);
	Player shopPotions(vector<Weapon> weapons, vector<Armor> armors, vector<Potion> potions, Player player);
	Player shopUpgrades(vector<Weapon> weapons, vector<Armor> armors, vector<Upgrade> upgrades, Player player);
	//weapons choosen
	//armor choosen
	//potions
	//upgrade
};

#endif
