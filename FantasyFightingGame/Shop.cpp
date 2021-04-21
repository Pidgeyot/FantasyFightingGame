/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Shop.h"
#include <iostream>
#include <vector>
using namespace std;

//potions and upgrades are not affecting the player stats

Shop::Shop()
{
	//create weapon, armor, potion, and upgrade vectors
	weapons = { Weapon(1), Weapon(2), Weapon(3) };
	armors = { Armor(1), Armor(2), Armor(3) };
	potions = { Potion(1), Potion(2), Potion(3) };
	upgrades = { Upgrade(1), Upgrade(2), Upgrade(3) };
}

vector<Weapon> Shop::returnWeapons() {
	return Shop::weapons;
}

vector<Armor> Shop::returnArmors() {
	return Shop::armors;
}

Player Shop::openInventory(vector<Weapon> weapons, vector<Armor> armors, Player player)
{
	player.showCharacter();
	//print the vector of each item that can be bought
	cout << "\nWeapons" << endl;
	for (int i = 0; i < weapons.size(); i++) {
		cout << i + 1 << ": " << weapons[i].getName() << ":  Attk: " << weapons[i].getAttack() << "  Cost: " << weapons[i].getCost() << endl;
	}

	cout << "\nArmors" << endl;
	for (int i = 0; i < armors.size(); i++) {
		cout << i + 1 << ": " << armors[i].getName() << ":  Def: " << armors[i].getDefense() << "  Cost: " << armors[i].getCost() << endl;
	}

	cout << "\nPotions" << endl;
	for (int i = 0; i < potions.size(); i++) {
		cout << i + 1 << ": " << potions[i].getName() << ":  Heal: " << potions[i].healPlayer() << "  Cost: " << potions[i].getCost() << endl;
	}

	cout << "\nUpgrades" << endl;
	for (int i = 0; i < potions.size(); i++) {
		cout << i + 1 << ": " << upgrades[i].getName() << ":  Increase: " << upgrades[i].increaseHealth() << "  Cost: " << upgrades[i].getCost() << endl;
	}

	cout << "\nCurrent Gold: " << player.getMoney() << endl;
	string load = "";
	cout << "\nWhat would you like to buy? (Please type the item type or exit to leave the shop)" << endl;
	cin >> load;
	//have the player choose a type of item to buy
	//each type returns an updated player with the respective changed values
	if (load == "exit") {
		cout << "\nExiting shop..." << endl;
		exit;
	}
	else {
		if (load == "weapon" || load == "Weapon") {
			player = shopWeapons(weapons, armors, player);
			exit;
			//openInventory(weapons, armors, player);
		}
		else if (load == "armor" || load == "Armors") {
			player = shopArmors(weapons, armors, player);
			exit;
			//openInventory(weapons, armors, player);
		}
		else if (load == "potion" || load == "Potion") {
			player = shopPotions(weapons, armors, potions, player);
			exit;
			//openInventory(weapons, armors, player);
		}
		else if (load == "upgrade" || load == "Upgrade") {
			player = shopUpgrades(weapons, armors, upgrades, player);
			exit;
			//openInventory(weapons, armors, player);
		}
		else {
			cout << "That is not a valid option!" << endl;
			exit;
			//openInventory(weapons, armors, player);
		}
		//set player inventory to openInventory
		player = openInventory(weapons, armors, player);
	}
	//return player for the final time
	return player;
}

Player Shop::shopWeapons(vector<Weapon> weapons, vector<Armor> armors, Player player) {
	int choice = 0;
	cout << "\nWhich weapon would you like to buy? (Please type the item number or 0 to exit)" << endl;
	cin >> choice;
	if (choice == 0) {
		exit;
	}
	//if the input is a number and lower than 4
	else if (typeid(choice) == typeid(1) && choice < 4) {
		//if the players money is higher than the cost
		if (player.getMoney() >= weapons[choice - 1].getCost()) {
			//if the players current weapon is a lower teir than the weapon they are buying
			if (player.getWeaponTier() < weapons[choice - 1].getTier()) {
				//set the weapon to weapon of choice
				player.setWeapon(choice);
				//take cost from player gold
				player.takeMoney(weapons[choice - 1].getCost());
				cout << "\nItem bought!" << endl;
			}
			else {
				cout << "\nThis is useless to you!" << endl;
			}
		}
		else {
			cout << "\nYou cannot afford that!" << endl;
		}
	}
	else {
		cout << "\nThat is not a valid option!" << endl;
		shopWeapons(weapons, armors, player);
	}
	return player;
}

Player Shop::shopArmors(vector<Weapon> weapons, vector<Armor> armors, Player player) {
	int choice = 0;
	cout << "\nWhich armor would you like to buy? (Please type the item number or 0 to exit)" << endl;
	cin >> choice;
	if (choice == 0) {
		exit;
	}
	//if the input is a number and lower than 4
	else if (typeid(choice) == typeid(1) && choice < 4) {
		//if the players money is higher than the cost
		if (player.getMoney() >= armors[choice - 1].getCost()) {
			//if the players current armor is a lower teir than the armor they are buying
			if (player.getArmorTier() < armors[choice - 1].getTier()) {
				//set armor to armor of choice
				player.setArmor(choice);
				//take cost from player gold
				player.takeMoney(armors[choice - 1].getCost());
				cout << "\nItem bought!" << endl;
			}
			else {
				cout << "\nThis is useless to you!" << endl;
			}
		}
		else {
			cout << "\nYou cannot afford that!" << endl;
		}
	}
	else {
		cout << "\nThat is not a valid option!" << endl;
		shopArmors(weapons, armors, player);
	}
	return player;
}

Player Shop::shopPotions(vector<Weapon> weapons, vector<Armor> armors, vector<Potion> potions, Player player) {
	int choice = 0;
	cout << "\nWhich potion would you like to buy? (Please type the item number or 0 to exit)" << endl;
	cin >> choice;
	if (choice == 0) {
		exit;
	}
	//if the input is a number and lower than 4
	else if (typeid(choice) == typeid(1) && choice < 4) {
		//if the players money is higher than the cost
		if (player.getMoney() >= potions[choice - 1].getCost()) {
			//heal player for potion amount
			player.addHealth(potions[choice - 1].healPlayer());
			//take cost from player gold
			player.takeMoney(potions[choice - 1].getCost());
			cout << "\nItem bought!" << endl;
		}
		else {
			cout << "\nYou cannot afford that!" << endl;
		}
	}
	else {
		cout << "\nThat is not a valid option!" << endl;
		shopPotions(weapons, armors, potions, player);
	}
	return player;
}

Player Shop::shopUpgrades(vector<Weapon> weapons, vector<Armor> armors, vector<Upgrade> upgrades, Player player) {
	int choice = 0;
	cout << "\nWhich upgrade would you like to buy? (Please type the item number or 0 to exit)" << endl;
	cin >> choice;
	if (choice == 0) {
		exit;
	}
	//if the input is a number and lower than 4
	else if (typeid(choice) == typeid(1) && choice < 4) {
		//if the players money is higher than the cost
		if (player.getMoney() >= upgrades[choice - 1].getCost()) {
			//add upgrade health to max health
			player.addMaxHealth(upgrades[choice - 1].increaseHealth());
			//take cost from player
			player.takeMoney(upgrades[choice - 1].getCost());
			cout << "\nItem bought!" << endl;
		}
		else {
			cout << "\nYou cannot afford that!" << endl;
		}
	}
	else {
		cout << "\nThat is not a valid option!" << endl;
		shopUpgrades(weapons, armors, upgrades, player);
	}
	return player;
}