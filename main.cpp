#include "Dungeon.hpp"
#include "Player.hpp"
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
    d.setCurrentRoom(0);
    d.printCurLocation();

    std::vector<string> input;
    while(input.size() == 0)
    {
        input = playerInput();
    }
    d.sendParse(p, input);
    d.setCurrentRoom(1);
    d.printCurLocation();
    input.clear();
    while(input.size() == 0)
    {
        input = playerInput();
    }
    d.sendParse(p, input);

    return 0;
}
