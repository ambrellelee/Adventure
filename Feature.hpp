#ifndef FEATURE_HPP
#define FEATURE_HPP
#include <string>
#include <iostream>
#include <vector>

class Feature
{
	private:
		std::string fName;
		std::vector<std::string> fDesc;			//vector of feature descriptions
		std::vector<std::string> interactionDesc;	//vector of interaction descriptions for each feature
		size_t interactionNum;					//keeps track of which interactions are valid at any given time
		size_t lookingNum;						
		std::vector<bool> nextAction;				

	public:
		Feature(std::string, std::vector<std::string>);
		Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions);
		
		//get and set methods
		void setName(std::string);
		std::string getName();
		void setFeatureDesc(std::string);
		std::vector<std::string> getFeatureDesc();
		void setInteractionDesc(std::string);
		std::vector<std::string> getInteractionDesc();
		void setInteractionNum();
		std::vector<bool> getActions();
		size_t getinteractionNum();
		size_t getLookingNum();
		
		//Feature functionality methods
		//bool canUse(std::string);
};

#endif
