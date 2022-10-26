#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Card.h"
#include "Player.h"

class Tabinet
{
private:
		int numberOfPlayers;
		std::vector<Card> pack;
		std::vector<Card> tableCards;
		std::vector<Player> players;
		int last;
public:
	Tabinet(int nr);
	void run();
	void setPack();
	void shuffle();
	void firstHand(Player& p);
	void receiveCards(Player& p);
	void showTable();
	void playerTurn(Player& p, int indexp);
	bool sum(Card c, std::vector<Card> m);
	void calculateScore(Player& p);
	bool maxCards(Player p);
	
	

};

