# Adventure

A text-based dungeon game written in C++.

As a player you will use text commands to navigate through the fifteen dungeon rooms and complete various challenges to reach the end. You must also use text commands to interact with the features in the room and to take items with you to help on your journey through the dungeon.

Primary commands used in the game

Look - Obtains information on features and items in a room
Take - Adds an item to player's bag 
Talk - Interacts with a NPC
Open 
Drink / Eat - consumes food or drink to increase stamina
Fill - Adds water to player's flask
Use - Uses items from player's inventory
Go - Moves player to new rooms
Inventory - Displays items the player has in their bag
Attack - Attacks an enemy
Block - Blocks an attack from the enemy
Help - Displays possible commands to the player
Instructions - Displays instructions for the game
Savegame - Saves current game
Loadgame - Loads past game from stopping point

To compile and run
	g++ -c *.cpp
	g++ *.o -o main
	./main
