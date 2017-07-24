#include "Dungeon.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::cin;

void newGame(Dungeon& newD, Player& newP)
{
    std::ifstream readFile("rooms.txt");
    if(readFile)
    {
        newD.readRooms(readFile);  //load rooms from file on dungeon
    }
    else
    {
        std::cout << "failed to load rooms" << std::endl;
    }
    readFile.close();
    std::ifstream readFile2("room2.txt");
    if(readFile2)
    {
        newD.readRooms(readFile2);  //load rooms from file on dungeon
    }
    else
    {
        std::cout << "failed to load rooms" << std::endl;
    }
    readFile2.close();
}

std::vector<string> split(const string& s)
{
	std::vector<string> temp;

	//split string into vector
	//http://code.runnable.com/VHb0hWMZp-ws1gAr/splitting-a-string-into-a-vector-for-c%2B%2B
	std::stringstream ss(s);
	std::string tok;

	while(getline(ss, tok, ' '))
    {
        temp.push_back(tok);
    }

	return temp;

}
vector<string> playerInput()
{
	std::cout << ">";
	std::string sentence = ""; //place holder for input string

	getline(cin, sentence);

	std::vector<string> stringVector = split(sentence); // split the input into strings and store in vector

	return stringVector;

}

main()
{
    Dungeon d;  //create dungeon
    Player p;   //create player

    newGame(d, p);
    bool quit = false;
    while(!quit)
    {
        int choice = d.showMenu();
        if(choice ==  1)
        {
            d.setCurrentRoom(0);
            d.printCurLocation();

            std::vector<string> input;
            while(input.size() == 0)
            {
                input = playerInput();
            }
            d.sendParse(p, input);
            d.setCurrentRoom(2);
            d.printCurLocation();
            input.clear();
            while(input.size() == 0)
            {
                input = playerInput();
            }
            d.sendParse(p, input);
	    std::cout << "---------------------------------------------------------------" << std::endl;
	    std::cout << "~~~~~~~~~~~~End of game trial, thanks for playing.~~~~~~~~~~~~~" << std::endl;
	    std::cout << "---------------------------------------------------------------" << std::endl;
        //    exit(0);
        }
        else if(choice == 2)
        {
        Room myRoom = Room("one.txt", 0);
            myRoom.printAllData();
        }
        else
        {
            std::cout << "---------------------------------------------------------------" << std::endl;
	    std::cout << "~~~~~~~~~~~~ Good-Bye, thanks for playing.~~~~~~~~~~~~~" << std::endl;
	    std::cout << "---------------------------------------------------------------" << std::endl;
            quit = true;
            exit(0);
        }
    }

    return 0;
}
