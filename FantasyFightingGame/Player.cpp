/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Player.h"
#include <iostream>
#include "Weapon.h"
using namespace std;

Weapon weapon;
Armor armor;

Player::Player() {
	name = name;
	armor = Armor(0);
	weapon = Weapon(0);
	health = 50;
	maxHealth = 50;
	money = 10;
}

void Player::showCharacter()
{
	//display character name, current armor, weapon, and health
	cout << "\n";
	cout << "Name: " << name << endl;
	cout << "Armor: " << armor.getName() << endl;
	cout << "Def: " << armor.getDefense() << endl;
	cout << "Weapon:" << weapon.getName() << endl;
	cout << "Attk: " << weapon.getAttack() << endl;
	cout << "Health: " << health << "/" << maxHealth << endl;
	cout << "Gold: " << money << endl;
}

string Player::getName()
{
	return name;
}

void Player::setName(string newName) {
	name = newName;
}

void Player::setName() {
	cout << "\nPlease input a character name: " << endl;
	cin >> name;
}

int Player::getHealth()
{
	return health;
}

void Player::addHealth(int heal)
{
	health += heal;
	//if health would be higher than the max health, simply make new health the max health
	if (health > maxHealth) {
		health = maxHealth;
	}
}

void Player::takeHealth(int damage)
{
	health = health - damage;
}

void Player::setHealth(int heal)
{
	health = heal;
}

int Player::getMaxHealth()
{
	return maxHealth;
}

void Player::addMaxHealth(int newHealth)
{
	maxHealth = maxHealth + newHealth;
}

void Player::setMaxHealth(int newHealth)
{
	maxHealth = newHealth;
}

int Player::getMoney()
{
	return money;
}

void Player::takeMoney(int cost)
{
	money = money - cost;
}

void Player::addMoney(int cost)
{
	money = money + cost;
}

void Player::setMoney(int cost)
{
	money = cost;
}

int Player::getWeaponTier()
{
	return weapon.getTier();
}

void Player::setWeapon(int newWeapon)
{
	weapon = Weapon(newWeapon);
}

int Player::getArmorTier()
{
	return armor.getTier();
}

void Player::setArmor(int newArmor)
{
	armor = Armor(newArmor);
}

int Player::attack()
{
	return weapon.getAttack();
}

int Player::defend()
{
	return armor.getDefense();
}