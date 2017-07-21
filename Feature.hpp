#ifndef FEATURE_HPP
#define FEATURE_HPP
#include <string.h>
#include <iostream>

class Feature
{
	private:
		std::string fName;
		std::vector<std::string> fDesc;	

	public:
		Feature(std::string, std::vector<std::string>);
		void setName(std::string);
		void setFeatureDesc(std::string);
		std::string getName();
		std::vector<std::string> getFeatureDesc();
};

#endif
