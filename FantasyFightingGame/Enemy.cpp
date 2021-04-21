/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
}

Enemy::Enemy(int num)
{
	//for a certain inputted number, set the values to represent different enemies
	if (num == 1) {
		name = "Trickster Crow";
		health = 20;
		damage = 10;
		gold = 10;
	}
	else if (num == 2) {
		name = "Living Rock";
		health = 50;
		damage = 25;
		gold = 20;
	}
	else if (num == 3) {
		name = "Mutant Fish";
		health = 100;
		damage = 50;
		gold = 25;
	}
	else if (num == 4) {
		name = "Petulant Ghost";
		health = 200;
		damage = 70;
		gold = 35;
	}
}

int Enemy::attack()
{
	return damage;
}

void Enemy::setAttack(int playerDefense) {
	//take player defense from enemy attack
	if (damage > playerDefense) {
		damage = damage - playerDefense;
		cout << "\nYou defend " << playerDefense << " damage until the enemy dies." << endl;
	}
	else if (damage > (playerDefense / 2)) {
		damage = damage - (playerDefense - 2);
		cout << "\nYou defend " << (playerDefense / 2) << " damage until the enemy dies." << endl;
	}
	else {
		cout << "\nYour defense is too high to lower damage from this enemy!" << endl;
	}
}

void Enemy::takeDamage(int damage)
{
	health = health - damage;
}

int Enemy::getDamage() {
	return damage;
}

int Enemy::getGold()
{
	return gold;
}

int Enemy::getHealth()
{
	return health;
}

string Enemy::getName() {
	return name;
}