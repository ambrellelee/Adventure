#include "Feature.hpp"

Feature::Feature(std::string newName, std::vector<std::string> newDesc)
{
	fName = newName;
	fDesc = newDesc;
}

Feature::Feature(std::string featName, std::vector<std::string> fDescs, std::vector<std::string> interactions, std::vector<bool> actions)
{
        fName = featName;
        fDesc = fDescs;
        interactionDesc = interactions;
        nextAction = actions;
        interactionNum = 0;
}


void Feature::setName(std::string name)
{
	fName = name;
}

void Feature::setFeatureDesc(std::string description)
{
	fDesc.push_back(description);
}

void Feature::setInteractionDesc(std::string iDesc)
{
	interactionDesc.push_back(iDesc);
}

std::string Feature::getName()
{
	return fName;
}

std::vector<std::string> Feature::getFeatureDesc()
{
	return fDesc;
}

std::vector<std::string> Feature::getInteractionDesc()
{
	return interactionDesc;
}
std::vector<bool> Feature::getActions()
{
	return nextAction;
}
