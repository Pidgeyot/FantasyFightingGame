/*
  Paige mabbitt
  Fantasy Fighting Game
  This is all my own work
  */

#include "Player.h"
#include "Shop.h"
#include "Area.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//initialize player, shop, and area
Player player;
Shop shop;
Area area;

void start() {
	string load;
	cout << "Welcome to Fantasy Adventure Fight! Would you like to load a save or start a new character? (Please type load or new)" << endl;
	cin >> load;
	//load character
	if (load == "load") {
		//initialize values
		ifstream playerRead;
		string playerText;
		vector<string> playerValues;
		//open player.txt
		playerRead.open("Player.txt");
		//check if file is empty
		if (playerRead.peek() == std::ifstream::traits_type::eof()) {
			cout << "\nThe file is empty! Please start a new file" << endl;
			start();
		}
		else {
			//put each line in player.txt as an element in vector playerValues
			for (int i = 0; i < 6; i++) {
				while (getline(playerRead, playerText)) {
					playerValues.push_back(playerText);
				}
			}
			//use each value in playerValues to set the aspects of player
			player.setName(playerValues[0]);
			player.setArmor(stoi(playerValues[1]));
			player.setWeapon(stoi(playerValues[2]));
			player.setHealth(stoi(playerValues[3]));
			player.setMaxHealth(stoi(playerValues[4]));
			player.setMoney(stoi(playerValues[5]));
			//close player.txt
			playerRead.close();
		}
	}
	else if (load == "new") {
		//ask player to set the name for the new character
		player.setName();
	}
	else {
		//if the player inputs anything other than load or new
		cout << "\nThat is not a valid choice! Please choose again" << endl;
		start();
	}
}

void chooseArea() {
	//show character stats
	player.showCharacter();
	string load;
	cout << "\nWould you like to go to the shop, go fight, or exit game? (Please type shop, fight, or exit)" << endl;
	cin >> load;
	if (load == "shop") {
		//return the player as affected by the shop
		player = (shop.openInventory(shop.returnWeapons(), shop.returnArmors(), player));
		chooseArea();
	}
	else if (load == "fight") {
		//retun the player as affected by the area
		player = area.generateEncounter(player);
		if (player.getHealth() < 0) {
			exit;
		}
		else {
			chooseArea();
		}
	}
	else if (load == "exit") {
		//save character values to the Player.txt
		cout << "\nSaving character..." << endl;
		ofstream playerFile;
		//open player.txt
		playerFile.open("Player.txt");
		//get 6 values of player and write them to player.txt on seperate lines
		playerFile << player.getName() << "\n";
		playerFile << player.getArmorTier() << "\n";
		playerFile << player.getWeaponTier() << "\n";
		playerFile << player.getHealth() << "\n";
		playerFile << player.getMaxHealth() << "\n";
		playerFile << player.getMoney() << "\n";
		//close file
		playerFile.close();
		cout << "See you next time!" << endl;
		exit;
	}
	else {
		//if the player inputs anything other than load or new
		cout << "\nThat is not a valid choice! Please choose again" << endl;
		chooseArea();
	}
}

int main() {
	//when main starts, it only runs start to decide character and then chooseArea once. chooseArea is then self sufficent until the game is closed
	start();
	chooseArea();
}