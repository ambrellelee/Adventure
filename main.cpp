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

    /*

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

*/

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
