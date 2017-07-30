#ifndef PARSER_HPP
#define PARSER_HPP

#include "Dungeon.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
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
		/*
		const std::string goTo = "go";
		const std::string useItem = "use";
		const std::string take = "take";
		const std::string openChest = "open";
		const std::string talk = "talk";
		const std::string drink = "drink";
		const std::string drop = "drop";
		const std::string look = "look";
		const std::string help = "help";
		const std::string inventory = "inventory";
		const std::string fills = "fill";
		const std::string moves = "move";
		const std::string cross = "cross";
		const std::string unlock = "unlock";
		const std::string investigate = "investigate";
		const std::string smell = "smell";
		const std::string sneak = "sneak";
		const std::string attack = "attack";
		const std::string ring = "ring";
		const std::string say = "say";
		const std::string block = "block";
		const std::string touch = "touch";
		const std::string quit = "exit";
*/
	public:

		void parser(Dungeon& curDungeon, Player& curPlayer, playerString& curSentence);
		bool verbInSentence(playerString& curSentence, std::string stringToCompare);

		//perform the verbs
		void findNextDungeon(playerString& curSentence, Dungeon& curDungeon, Player& curPlayer);
		void searchItemToUse(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void takeItemInDungeon(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void openObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void talkToNPC(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void drinkSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void dropSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void lookAtStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void fillObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void moveStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void crossObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void unlockObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void investigateStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void smellStuff(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void sneakSomewhere(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void attackSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void ringObject(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void saySomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void blockSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);
		void touchSomething(playerString& curSentence, Player& curPlayer, Dungeon& curDungeon);

};





#endif
