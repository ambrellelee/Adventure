# Adventure

A text-based dungeon game written in C++.

As a player you will use text commands to navigate through the fifteen dungeon rooms and complete various challenges to reach the end. You must also use text commands to interact with the features in the room and to take items with you to help on your journey through the dungeon.

Commands used in the game

Look - Obtains information on features and items in a room
\n Take - Adds an item to player's bag
\n Talk - Interacts with a NPC
\n Open
\n Drink / Eat - consumes food or drink to increase stamina
\n Fill - Adds water to player's flask
\n Use - Uses items from player's inventory
\n Go - Moves player to new rooms
\n Inventory - Displays items the player has in their bag
\n Attack - Attacks an enemy
\n Block - Blocks an attack from the enemy
\n Hint
\n Help - Displays possible commands to the player
\n Instructions - Displays instructions for the game
\n Savegame - Saves current game
\n Loadgame - Loads past game from stopping point

To compile and run
	g++ -c *.cpp
	g++ *.o -o main
	./main
