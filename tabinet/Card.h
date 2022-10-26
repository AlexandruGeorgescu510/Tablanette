#pragma once

#include <iostream>
#include <string>
#include <regex>

class Card
{
private:
	std::string value;
	std::string symbol;
public:
	std::string getValue() const;
	int getNumberValue(int type);
	std::string getSymbol() const;
	void setValue(std::string value);
	void setSymbol(std::string symbol);
	void showCard();
	bool cow();
	void initialise();
};

