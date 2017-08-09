#ifndef PARSER_HPP
#define PARSER_HPP

#include"Dungeon.hpp"
#include"Player.hpp"
#include"Inventory.hpp"
#include "Feature.hpp"
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

class Parser
{
	private:
		//create vector to hold strings from player input
		typedef std::vector<std::string> playerString;

	public:

		void parser(Dungeon& curDungeon, Player& curPlayer, playerString& curSentence);
		bool verbInSentence(playerString& curSentence, std::string stringToCompare);

		//perform the verbs
		void findNextDungeon(playerString& curSentence, Dungeon& curDungeon, Player& curPlayer);
		void searchItemToUse(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void takeItemInDungeon(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void openObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void talkToNPC(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void askNPC(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void drinkSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void dropSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void lookAtStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void fillObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void crossObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void unlockObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void sneakSomewhere(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void attackSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void ringObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void blockSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void touchSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void pull(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void illuminate(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void push(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void read(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void removeing(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);       ///////  <<<<<----- do this one in room 13
		void payBribe(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);         ////// <<<<<< --- do this one in room 15

};





#endif
