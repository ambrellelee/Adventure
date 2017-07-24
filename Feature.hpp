#ifndef FEATURE_HPP
#define FEATURE_HPP
#include <string>
#include <iostream>
#include <vector>

class Feature
{
	private:
		std::string fName;
		std::vector<std::string> fDesc;	
		std::vector<std::string> interactionDesc;		
		int interactionNum;
		std::vector<bool> nextAction;		

	public:
		Feature(std::string, std::vector<std::string>);
		Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions);
		void setName(std::string);
		void setFeatureDesc(std::string);
		void setInteractionDesc(std::string);
		std::string getName();
		std::vector<std::string> getFeatureDesc();
		std::vector<std::string> getInteractionDesc();
		std::vector<bool> getActions();
};

#endif
