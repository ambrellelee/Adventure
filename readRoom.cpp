#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>
//#include "Room.hpp"

using std::string;
using std::vector;
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 2)
		cout << "USAGE: " << argv[0] << "[directoryName]" << endl;

	fstream inputFile;
	string line;
	string fullMessage = "";
	string directory;
	string fileName;
	string fullPath;
	//DIR *dp;
	//struct dirent *dirp;
	//struct stat fileStatus;

	vector<string> roomDescriptions;
	int numRoomDescriptions;

	directory = argv[1];
	//dp = opendir(dir.c_str());
	fullPath = directory + "/" + "one.txt";

	inputFile.open(fullPath.c_str(), ios::in);
	if (!inputFile)
	{
		cout << "ERROR: Could not open file: " << fullPath << endl;
		cout << "Ending program" << endl;
	}

	getline(inputFile, line);

	stringstream numEntries(line);
	numEntries >> numRoomDescriptions;
	cout << numRoomDescriptions << endl;
	getline(inputFile, line);
	getline(inputFile, line);
	//cout << line << endl;
	
	for (int i = 0; i < numRoomDescriptions; i++) 
	{
		while (inputFile && line != "@@") 
		{
			fullMessage = fullMessage + line + "\n";
			getline(inputFile, line);
			
		}
		//	cout << fullMessage << endl;
			getline (inputFile, line);
			roomDescriptions.push_back(fullMessage);
			fullMessage = "";
		
	}

	for (int i = 0; i < roomDescriptions.size(); i++) {
		cout << roomDescriptions[i];
	}
	return 0;
}
