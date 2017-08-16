#include "Room.hpp"
#include "Item.hpp"
#include "Feature.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "Dungeon.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
        Room myRoom = Room("nine.txt", 0);
        Room otherRoom = Room("eight.txt", 0);
	Player myPlayer = Player();
	Item itemOne = Item("Test Thing", "First Test", "to Test", 2, 4, false, 0, 1);
	Item itemTwo = Item("Another Thing", "Second Test", "test for multiple", 0, 0, true, 1, 3);
	myPlayer.loadPlayer();
	myPlayer.printPlayerInfo();
	myPlayer.addToBag(itemOne);
	myPlayer.addToBag(itemTwo);
	myPlayer.setCurrentLocation(&myRoom);
	myPlayer.setLastLocation(&otherRoom);
	myPlayer.printPlayerInfo();
	myPlayer.savePlayer();
	//Dungeon myDungeon = Dungeon();
	//myDungeon.playGame();
	//myDungeon.saveDungeon();
	//cout << "hi" << endl;
	//myRoom.printAllData();
	//myRoom.loadRoom("three.txt");
	//myRoom.saveRoom("threeTest.txt");
	//myPlayer.savePlayer();
	//myDungeon.loadDungeon(&myPlayer);
	//myPlayer.printPlayerInfo();
	//cout << "before the return" << endl;
        exit(0);
}

