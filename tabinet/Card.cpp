#include "Card.h"



std::string Card::getValue() const
{
	return value;
}

int Card::getNumberValue(int type) 
{
	std::string value = getValue();

	if (type == 1)
	{
		if (value == "A")
			return 1;
	}
	else if (type == 2)
	{
		if (value == "A")
			return 11;
	}

	if (value[0] >= '2' && value[0] <= '9')
	{
		int number = stoi(value);
		return number;
	}

	if (value == "10")
		return 10;
	if (value == "J")
		return 12;
	if (value == "Q")
		return 13;
	if (value == "K")
		return 14;
}

std::string Card::getSymbol() const
{
	return symbol;
}

void Card::setValue(std::string val)
{
	value = val;
}

void Card::setSymbol(std::string sym)
{
	symbol = sym;
}

void Card::showCard()
{
	std::cout << value << "-" << symbol << " ";
}

bool Card::cow()
{
	std::regex a("(diamond)");
	std::regex b("(club)");
	if ((regex_match(symbol, a) && value=="10") || ((regex_match(symbol, b) && value=="2")))
		return true;
	else return false;
}

void Card::initialise()
{
	symbol = "";
	value = "";
}