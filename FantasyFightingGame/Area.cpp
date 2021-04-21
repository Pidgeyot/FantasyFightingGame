/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */
#include "Area.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

Area::Area()
{
}

Player Area::generateEncounter(Player player)
{
	int choice = 0;
	level = ((player.getArmorTier() + player.getWeaponTier()) / 2) + 1;
	cout << "\nCurrent Level: " << level << endl;
	cout << "Please choose an area to fight in. (Type the number of the area or 0 to exit) " << endl;
	cout << "1. Green Hills" << endl;
	cout << "2. Desert Canyon" << endl;
	cout << "3. Watery Marshes" << endl;
	cout << "4. Spooky Forest" << endl;
	cin >> choice;
	//if statment of generating areas based on input
	if (choice == 0) {
		exit;
	}
	else if (typeid(choice) == typeid(1) && choice <= 4) {
		player = AreaChoosen(choice, level, player);
	}
	else {
		cout << "\nThat is not a valid area!" << endl;
		generateEncounter(player);
	}
	return player;
}

Player Area::AreaChoosen(int choice, int level, Player player) {
	cout << "Level " << choice << endl;
	vector<Enemy> enemies;
	string action;
	int enemyAmount = 1;
	if (choice > level) {
		enemyAmount = choice + level;
	}
	else if (choice == level) {
		enemyAmount = 3;
	}
	else {
		enemyAmount = level;
	}
	//do enemy amount based on choice and level
	for (int i = 0; i < enemyAmount; i++) {
		enemies.push_back(Enemy(choice));
	}
	if (enemies.size() != 0) {
		//for the size of the enemiex vector
		for (int i = 0; i < enemies.size(); i++) {
			//while the enemy has health
			while (enemies[i].getHealth() > 0) {
				cout << "\n" << enemies[i].getName() << " appears! (" << enemies[i].getHealth() << " health)" << endl;
				//ask user for action
				cout << "\nWhat would you like to do?" << endl << "Attack" << endl << "Defend" << endl << "Flee" << endl;
				cin >> action;
				if (action == "attack" || action == "Attack") {
					//take the players attack from enemy health
					enemies[i].takeDamage(player.attack());
					//tell the user how much damage has been dealt
					cout << "\n" << enemies[i].getName() << " takes " << player.attack() << " damage." << endl;
				}
				else if (action == "defend" || action == "Defend") {
					//take player defense from enemy attack
					enemies[i].setAttack(player.defend());
				}
				else if (action == "flee" || action == "Flee") {
					cout << "\nYou flee!" << endl;
					return player;
				}
				//if health is 0, enemy doesn't attack
				if (enemies[i].getHealth() > 0) {
					player.takeHealth(enemies[i].getDamage());
					if (player.getHealth() < 0) {
						cout << "\n" << enemies[i].getName() << " attacks! It does " << enemies[i].getDamage() << " damage." << endl;
						cout << "\nYou died! RIP X-X" << endl << "Better luck next time!" << endl;
						ofstream playerFile;
						//open player.txt
						playerFile.open("Player.txt");
						//get 6 values of player and write them to player.txt on seperate lines
						playerFile << "";
						//close file
						playerFile.close();
						exit(5);
					}
					else {
						cout << "\n" << enemies[i].getName() << " attacks! It does " << enemies[i].getDamage() << " damage. (" << player.getHealth() << "/ " << player.getMaxHealth() << ")" << endl;
					}
				}
			}
			//enemy death
			cout << "\n" << enemies[i].getName() << " perishes! You get " << enemies[i].getGold() << " gold" << endl;
			//give player gold based on the enemy type
			player.addMoney(enemies[i].getGold());
		}
		//once all enemeies have been defeated
		cout << "\nAll enemies have been defeated!" << endl;
		return player;
	}
	return player;
}