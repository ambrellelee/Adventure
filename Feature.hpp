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
		size_t interactionNum;
		size_t lookingNum;
		std::vector<bool> nextAction;		
		std::vector<std::vector<std::string> > verbs;


	public:
		Feature(std::string, std::vector<std::string>);
		Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions);
		Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions, std::vector<std::vector<std::string> > fVerbs);
		void setName(std::string);
		void setFeatureDesc(std::string);
		void setInteractionDesc(std::string);
		std::string getName();
		std::vector<std::string> getFeatureDesc();
		std::vector<std::string> getInteractionDesc();
		std::vector<bool> getActions();
		std::vector<std::vector<std::string> > getVerbs();
		void setInteractionNum();
		size_t getinteractionNum();
		size_t getLookingNum();
		size_t getExactLookingNum();
		void setExactInteractionNum(size_t intNumValue);
		void setExactLookingNum(size_t lookNumValue);

};

#endif
