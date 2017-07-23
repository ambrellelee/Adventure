#include "Feature.hpp"

Feature::Feature(std::string newName, std::vector<std::string> newDesc)
{
	fName = newName;
	fDesc = newDesc;
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