#include "Dungeon.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Room.hpp"
#include "Parser.hpp"
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

int main()
{
    Dungeon d;  //create dungeon
    Player p;   //create player
    Parser par; //create parser
    d.playGame();
    bool quit = false;
    //for testing, load player inventory with every item needed to interact
 //   Item tempItem = Item("coins", "", "", 0, 0, 0, 0, 0);
  //  p.addToBag(tempItem);
    while(!quit)
    {
        int choice = d.showMenu();
        if(choice ==  1)
        {
            std::system("clear");
            bool backToMenu = false;
            d.setCurrentRoom(0);
            d.printCurLocation();

            std::vector<string> input;
            while(!backToMenu)
            {
                if(d.finishCheck() == true)
                {
                    backToMenu = true;
                }
               else if(p.gameOver ==true)
			{
				backToMenu = true;
			} 
			else
                {
                    input.clear();
                    while(input.size() == 0)
                    {
                        input = playerInput();
                    }
                    if(input[0] == "menu")
                    {
                        backToMenu = true;
                    }
                    else if(input[0] == "go" && p.endCheck() == true)
                    {
                        std::cout << "You ran out of stamina to continue traveling..." << endl;
                        backToMenu = true;
                    }
                    else
                    {
                        par.parser(d, p, input);
                    }
                }
            }
        }
        else
        {
            quit = true;
            exit(0);
        }
    }

    return 0;
}
