#include "Feature.hpp"

Feature::Feature(std::string newName, std::vector<std::string> newDesc)
{
	fName = newName;
	fDesc = newDesc;
}

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

// 2d vector 
std::vector<std::vector<std::string> > Feature::getVerbs()
 {
         return verbs;
 }


size_t Feature::getExactLookingNum()
{
        return lookingNum;
}

void Feature::setExactInteractionNum(size_t intNumValue)
{
        interactionNum = intNumValue;
}

void Feature::setExactLookingNum(size_t lookNumValue)
{
        lookingNum = lookNumValue;
}

