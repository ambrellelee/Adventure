#include "Feature.hpp"

Feature::Feature(std::string newName, std::vector<std::string> newDesc)
{
	fName = newName;
	fDesc = newDesc;
}

/***********************************
 Newly added feature 2d vector 8/7
 ***********************************/
Feature::Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions, std::vector<std::vector<std::string> > fVerbs)
{
        fName = featName;
        fDesc = fDescs;
        interactionDesc = interactions;
        nextAction = actions;
        interactionNum = 0;
        verbs = fVerbs;
        lookingNum=0;
}
/**************************************/

void Feature::setName(std::string name)
{
	fName = name;
}

std::string Feature::getName()
{
	return fName;
}

void Feature::setFeatureDesc(std::string description)
{
	fDesc.push_back(description);
}

std::vector<std::string> Feature::getFeatureDesc()
{
	return fDesc;
}

void Feature::setInteractionDesc(std::string iDesc)
{
	interactionDesc.push_back(iDesc);
}

std::vector<std::string> Feature::getInteractionDesc()
{
	return interactionDesc;
}
std::vector<bool> Feature::getActions()
{
	return nextAction;
}

void Feature::setInteractionNum()
{
    ++interactionNum;
}
size_t Feature::getinteractionNum()
{
    return interactionNum;
}
size_t Feature::getLookingNum()
{

    if(lookingNum > fDesc.size())
    {
        lookingNum = 0;
    }
    ++lookingNum;
    return lookingNum-1;
}

/***********************************
 Newly added feature 2d vector 8/7
 ***********************************/
std::vector<std::vector<std::string> > Feature::getVerbs()
 {
         return verbs;
 }
/***********************************/
