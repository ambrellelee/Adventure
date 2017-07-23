#include "Dungeon.hpp"
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//add method to set exits to newRoom
//test and then add loop to create all rooms
using std::transform;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;
Dungeon::Dungeon()
{
	newRoom = new Room;
		newRoom->setName("");
//		newRoom->setType;
//		newRoom->setDescription;
//		newRoom->setMonster;
//		newRoom->setMonsterDesc;
//		newRoom->setItem;

	newPlayer = new Player;
		newPlayer->setName("");
//		newplayer->setHitPoints;
//		newPlayer->setStamina;
//		newPlayer->setScore;

	//newParser = new Parser;
}
/*
void Dungeon::setGameDescription(newDesc)
{
	gameDesc = newDesc;
}

void Dungeon::showGameDescription()
{
	return gameDesc;
}
*/
/*void Dungeon::playGame()
{
}
*/

Dungeon::~Dungeon()
{
	delete newRoom;
	delete newPlayer;
//	delete newParser;
}

main()
{

    std::cout << "test" << std::endl;
    std::cout << "creating new room..." << std::endl;
    Room testRoom;
    std::cout << "creating new player..." << std::endl;
    Player testPlayer;

//test GO to room
    std::vector<std::string> curSentence;
    curSentence.push_back("Go");
    curSentence.push_back("To");
    curSentence.push_back("Treasure");
    curSentence.push_back("Room");

	cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    Parser* p = new Parser;
    p->parser(testRoom, testPlayer, curSentence);
    curSentence.clear();
    curSentence.push_back("Go");
    curSentence.push_back("To");
    curSentence.push_back("Riddle");
    curSentence.push_back("Room");

	cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);

//test Use item
    curSentence.clear();
    curSentence.push_back("Use");
    curSentence.push_back("SWORD");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);

    curSentence.clear();
    curSentence.push_back("Use");
    curSentence.push_back("chest");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);

//test open object
    curSentence.clear();
    curSentence.push_back("Open");
    curSentence.push_back("Chest");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);
    curSentence.clear();
    curSentence.push_back("Open");
    curSentence.push_back("rock");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);


//test take item
    curSentence.clear();
    curSentence.push_back("Take");
    curSentence.push_back("SWORD");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);
    curSentence.clear();
    curSentence.push_back("Take");
    curSentence.push_back("shield");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);

//test look
    curSentence.clear();
    curSentence.push_back("Look");
    curSentence.push_back("at");
    curSentence.push_back("chest");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);
    curSentence.clear();
    curSentence.push_back("Look");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);

//test help
    curSentence.clear();
    curSentence.push_back("HELP");
    cout << endl;
    std::cout << "sending in parsing request" << std::endl;
    p->parser(testRoom, testPlayer, curSentence);
 //testing vector
/*
    std::cout << "testing > string to lowercase." << std::endl;
    std::cout << "String To Test." << std::endl;

    vector<string>::iterator i;
    for (i = curSentence.begin(); i != curSentence.end(); ++i)
	{
		//converts the chars in string all into lower case to compare
		//https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
		cout << *i << " > ";
		std::transform(i->begin(), i->end(), i->begin(), ::tolower);
        cout << " " << *i << " | ";
		if (*i == "test")
		{
			cout << endl << "test found" << endl;
		}
	}

*/


    return 0;
}
