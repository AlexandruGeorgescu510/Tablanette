#include "Tabinet.h"
#include <sstream>
#include <cstring>
#include <algorithm>
#include <ctime> 

Tabinet::Tabinet(int numberOfPlayers)
{

	for (int index = 0; index < numberOfPlayers; index++)
	{
		Player p;
		p.setScore(0);
		players.push_back(p);
	}

	setPack();
}

void Tabinet::setPack()
{
	for (int index = 0; index < 52; index++)
	{
		Card c;
		pack.push_back(c);
	}
	std::string str;
	std::string val;
	for (int index = 0; index < 13; index++)
	{

		pack[index].setSymbol("heart");

		if (index == 0)
			pack[index].setValue("A");
		else if (index == 9)
			pack[index].setValue("10");
		else if (index == 10)
			pack[index].setValue("J");
		else if (index == 11)
			pack[index].setValue("Q");
		else if (index == 12)
			pack[index].setValue("K");
		else {
			str = std::to_string(index + 1);
			pack[index].setValue(str);
		}
	}

	for (int index = 0; index < 13; index++)
	{

		pack[index + 13].setSymbol("spade");
		if (index == 0)
			pack[index + 13].setValue("A");
		else if (index == 9)
			pack[index + 13].setValue("10");
		else if (index == 10)
			pack[index + 13].setValue("J");
		else if (index == 11)
			pack[index + 13].setValue("Q");
		else if (index == 12)
			pack[index + 13].setValue("K");
		else
		{
			str = std::to_string(index + 1);
			pack[index + 13].setValue(str);
		}
	}

	for (int index = 0; index < 13; index++)
	{

		pack[index + 26].setSymbol("club");
		if (index == 0)
			pack[index + 26].setValue("A");
		else if (index == 9)
			pack[index + 26].setValue("10");
		else if (index == 10)
			pack[index + 26].setValue("J");
		else if (index == 11)
			pack[index + 26].setValue("Q");
		else if (index == 12)
			pack[index + 26].setValue("K");
		else
		{
			str = std::to_string(index + 1);
			pack[index + 26].setValue(str);
		}
	}

	for (int index = 0; index < 13; index++)
	{

		pack[index + 39].setSymbol("diamond");
		if (index == 0)
			pack[index + 39].setValue("A");
		else if (index == 9)
			pack[index + 39].setValue("10");
		else if (index == 10)
			pack[index + 39].setValue("J");
		else if (index == 11)
			pack[index + 39].setValue("Q");
		else if (index == 12)
			pack[index + 39].setValue("K");
		else
		{
			str = std::to_string(index + 1);
			pack[index + 39].setValue(str);
		}
	}
}

void Tabinet::shuffle()
{

	for (int index = 0; index < pack.size(); index++)
	{
		int swap = rand() % pack.size();
		Card temp = pack[index];
		pack[index] = pack[swap];
		pack[swap] = temp;
	}


}

int random(int i)
{
	return std::rand() % i;
}


void Tabinet::firstHand(Player& p)
{
	int optiune = 0;
	std::cout << "<<<<<<<<<<<<<<<<<<<< PLAYER 0 >>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "You received these cards:" << std::endl;
	for (int index = 0; index < 4; index++)
	{
		pack[index].showCard();
	}
	std::cout << std::endl << "Do you wish to keep them?" << std::endl;
	std::cout << "1 - Yes \t 2 - No" << std::endl;
	std::cin >> optiune;
	while (optiune != 1 && optiune != 2)
	{
		std::cout << "Wrong input, type 1 or 2." << std::endl;
		std::cin >> optiune;
	}
	if (optiune == 1)
	{
		for (int index = 0; index < 6; index++)
		{
			Card c = Tabinet::pack[0];
			p.receiveCard(c);
			pack.erase(pack.begin());
		}
	}
	else {
		for (int index = 0; index < 4; index++)
		{
			Card c = Tabinet::pack[0];
			tableCards.push_back(c);
			pack.erase(pack.begin());
		}

		for (int index = 0; index < 6; index++)
		{
			Card c = Tabinet::pack[0];
			p.receiveCard(c);
			pack.erase(pack.begin());
		}
	}
}

void Tabinet::receiveCards(Player& p)
{
	for (int index = 0; index < 6; index++)
	{
		Card c = Tabinet::pack[0];
		p.receiveCard(c);
		pack.erase(pack.begin());

	}
}


void Tabinet::showTable()
{
	std::cout << "-------------------- The Board --------------------" << std::endl;

	for (auto Card : tableCards)
	{
		Card.showCard();
	}
	std::cout << std::endl;
	for (int index = 0; index < tableCards.size(); index++)
	{
		std::cout << "    " << index << "\t ";
	}

	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

bool Tabinet::sum(Card c, std::vector<Card> vec)
{

	int suma;
	int rezultat;

	if (vec.size() == 1)
	{
		if (c.getNumberValue(2) == vec[0].getNumberValue(2))
			return true;
	}

	suma = 0;
	rezultat = 0;
	for (int index = 0; index < vec.size(); index++)                                    //caz 1 + caz 2
	{
		suma = suma + vec[index].getNumberValue(1);
	}
	rezultat = c.getNumberValue(2);
	if (suma == rezultat)
		return true;


	suma = 0;
	rezultat = 0;
	for (int index = 0; index < vec.size(); index++)                                    //caz 2 + caz 2
	{
		suma = suma + vec[index].getNumberValue(2);
	}
	rezultat = c.getNumberValue(2);
	if (suma == rezultat)
		return true;


	return false;

}

void Tabinet::playerTurn(Player& p, int indexp)
{
	if (p.getHand().empty())
		return;
	int option = 0;
	int numar = 0;
	int aux = 0;
	bool oktabla = false;
	bool okturn = false;
	std::vector<Card> hand = p.getHand();
	Card c;
	std::vector<Card> forTaking;
	std::cout << "<<<<<<<<<<<<<<<<<<<< PLAYER " << indexp << ">>>>>>>>>>>>>>>>>>>>" << std::endl;
	showTable();
	p.showHand();
	std::cout << "You have colected " << p.getCollectedNumber() << " cards" << " and " << p.getTabla() << " tabla" << std::endl;
	bool success = false;
	do {
		std::cout << " 1 - Take one or more cards" << std::endl;
		std::cout << " 2 - Drop a card" << std::endl;
		std::cin >> option;
		while (option != 1 && option != 2)
		{
			std::cout << "Wrong input, type 1 or 2." << std::endl;
			std::cin >> option;
		}

		if (option == 1)
		{
			while (okturn == 0)
			{
				oktabla = false;
				int indexc = -1;
				c.initialise();
				forTaking.clear();
				std::cout << "Pick a card to collect cards from the board (index)" << std::endl;
				std::cout << "For return type -1 " << std::endl;
				std::cin >> indexc;
				if (indexc == -1)
				{
					break;
				}
				while (indexc > 5 || indexc < 0)
				{
					std::cout << "Wrong index." << std::endl;
					std::cin >> indexc;
				}
				c = hand[indexc];
				
				std::cout << "Type how many cards you want to collect, then, type their indexes one by one. For tabla type 0." << std::endl;
				std::cin >> numar;

				if (numar < 1 && numar > 5)
				{
					std::cout << "Wrong input." << std::endl;
					std::cin >> numar;
				}

				if (numar > 0)
				{
					if (numar == 1)
					{
						
						std::cin >> aux;
						while (aux >= tableCards.size())
						{
							std::cout << "Wrong index, try again!" << std::endl;
							std::cin >> aux;
						}
						forTaking.push_back(tableCards[aux]);
					}
					else {
						for (int index = 0; index < numar; index++)
						{
							std::cin >> aux;
							while (aux >= tableCards.size())
							{
								std::cout << "Wrong index, try again!" << std::endl;
								std::cin >> aux;
							}
							forTaking.push_back(tableCards[aux]);
						}
					}
				}
				else {
					oktabla = true;
				}

				if (oktabla == true)
				{
					for (int index = 0; index < tableCards.size(); index++)
					{
						forTaking.push_back(tableCards[index]);
					}
					okturn = sum(c, forTaking);
				}
				else {
					okturn = sum(c, forTaking);
				}

				if (okturn == true)
				{
					last = indexp;
					if (oktabla)
					{
						p.addTabla();
					}
					p.collect(hand[indexc]);
					hand.erase(hand.begin() + indexc);
					if (forTaking.size() == 1)
					{
						for (int index2 = 0; index2 < tableCards.size(); index2++)
							if (forTaking[0].getValue() == tableCards[index2].getValue() && forTaking[0].getSymbol() == tableCards[index2].getSymbol())
							{
								p.collect(forTaking[0]);
								tableCards.erase(tableCards.begin() + index2);
								forTaking.erase(forTaking.begin());
								break;
							}
					}
					else {
						bool okluat = true;
						while (!forTaking.empty())
						{
							for (int index2 = 0; index2 < tableCards.size(); index2++)
								if (okluat == true)
								{
									if (forTaking[0].getValue() == tableCards[index2].getValue() && forTaking[0].getSymbol() == tableCards[index2].getSymbol())
									{
										p.collect(forTaking[0]);
										tableCards.erase(tableCards.begin() + index2);
										forTaking.erase(forTaking.begin());
										if (forTaking.empty())
											okluat = false;
									}
								}
						}
					}
					success = true;
					std::cout << "Succesfuly played your hand" << std::endl;
				}
			}

		}
		else {
			int indexc2 = -1;
			while (okturn == false)
			{
				std::cout << "Choose the index of the card you want to drop: " << std::endl;
				std::cout << "For return type -1 " << std::endl;
				std::cin >> indexc2;
				if (indexc2 == -1)
				{
					break;
				}
				while (hand.size() < indexc2 || indexc2 < -1)
				{
					std::cout << "Wrong input. Type a valid index." << std::endl;
					std::cin >> indexc2;
				}
				tableCards.push_back(hand[indexc2]);
				hand.erase(hand.begin() + indexc2);
				okturn = true;
				success = true;
				std::cout << "Succesfuly played your hand" << std::endl;
			}
			p.refreshHand(hand);
		}
	} while (success == false);

}


bool Tabinet::maxCards(Player p)
{
	for (int index = 0; index < players.size(); index++)
		if (p.getCollectedNumber() < players[index].getCollectedNumber())
			return false;

	return true;
}

void Tabinet::calculateScore(Player& p)
{
	int points = 0;
	std::vector<Card> collected = p.getCollected();

	for (int index = 0; index < collected.size(); index++)
	{
		if (collected[index].cow())
		{
			points = points + 2;
		}
		else {
			int temp = collected[index].getNumberValue(1);
			if (temp == 10 || temp == 12 || temp == 13 || temp == 14 || temp == 1)
				points++;
		}

		if (collected[index].getSymbol() == "club" && collected[index].cow() == false)
		{
			points++;
		}
	}

	points = points + p.getTabla();

	if (maxCards(p) == true)
	{
		points = points + 3;
	}
	p.setScore(points);

}


void Tabinet::run()
{
	auto ok = true;
	int winningIndex = 0;
	std::srand(unsigned(std::time(0)));
	std::cout << "There will be " << players.size() << " players" << std::endl;


	std::random_shuffle(pack.begin(), pack.end() - 1);

	firstHand(players[0]);
	for (int index = 1; index < players.size(); index++)
	{
		receiveCards(players[index]);
	}
	if (tableCards.empty())
	{
		for (int index = 0; index < 4; index++)
		{
			Card c = Tabinet::pack[0];
			tableCards.push_back(c);
			pack.erase(pack.begin());
		}
	}
	while (!pack.empty())
	{

		ok = true;

		for (auto pl : players)
		{
			if (!pl.getHand().empty())
				ok = false;
		}

		if (ok == true)
		{
			if (pack.size() / 6 >= numberOfPlayers)
				for (int index = 0; index < players.size(); index++)
				{
					receiveCards(players[index]);
				}
			else {
				while (pack.size() > 0)
				{
					for (int index = 0; index < players.size(); index++)
					{
						players[index].receiveCard(pack[0]);
						pack.erase(pack.begin());
						if (pack.empty())
						{
							break;
						}
					}
				}
			}
		}
		for (int index = 0; index < players.size(); index++)
		{
			playerTurn(players[index], index);
		}
	}
	ok = true;
	for (int index = 0; index < players.size(); index++)
	{
		if (players[index].getHand().empty())
			ok = false;
	}

	while (ok == true)
	{

		for (int index = 0; index < players.size(); index++)
		{
			playerTurn(players[index], index);
		}

		for (int index = 0; index < players.size(); index++)
		{
			if (players[index].getHand().empty())
				ok = false;
		}
	}

	if (!tableCards.empty())
	{
		for (int index = 0; index < tableCards.size(); index++)
			players[last].collect(tableCards[index]);
	}

	for (int index = 0; index < players.size(); index++)
	{
		calculateScore(players[index]);
	}

	std::cout << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << "=========================GAME OVER=========================" << std::endl;
	std::cout << "===========================================================" << std::endl;
	std::cout << std::endl;

	for (int index = 0; index < players.size(); index++)
	{
		if (players[winningIndex].getScore() < players[index].getScore())
		{
			winningIndex = index;
		}
	}

	for (int index = 0; index < players.size(); index++)
	{
		std::cout << "PLAYER " << index << " has " << players[index].getScore() << " points" << std::endl;
	}
	std::cout << "The winner is PLAYER " << winningIndex << std::endl;
	std::cout << "CONGRATULATIONS! " << std::endl;
	std::cout << "===========================================================" << std::endl;

}