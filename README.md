# Adventure

A text-based dungeon game written in C++.

As a player you will use text commands to navigate through the fifteen dungeon rooms and complete various challenges to reach the end. You must also use text commands to interact with the features in the room and to take items with you to help on your journey through the dungeon.

Commands used in the game

Look - Obtains information on features and items in a room
Take - Adds an item to player's bag 
Use - Uses items from player's inventory
Go - Moves player to new rooms
Inventory - Displays items the player has in their bag
Help
Savegame - Saves current game
Loadgame - Loads past game from stopping point

To compile and run
	g++ -c *.cpp
	g++ *.o -o main
	./main
