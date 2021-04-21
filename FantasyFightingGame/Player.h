/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Armor.h"

class Player {
private:
	Weapon weapon;
	Armor armor;
	string name;
	int maxHealth;
	int health;
	int money;

public:
	Player();
	void showCharacter();
	string getName();
	void setName(string name);
	void setName();
	int getHealth();
	void addHealth(int heal);
	void takeHealth(int damage);
	void setHealth(int heal);
	int getMaxHealth();
	void addMaxHealth(int newHealth);
	void setMaxHealth(int newHealth);
	int getMoney();
	void takeMoney(int cost);
	void addMoney(int cost);
	void setMoney(int cost);
	int getWeaponTier();
	void setWeapon(int weapon);
	int getArmorTier();
	void setArmor(int newArmor);
	int attack();
	int defend();
};

#endif