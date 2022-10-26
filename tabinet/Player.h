#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Card.h"

class Player
{
private:
	std::vector<Card> hand;
	std::vector<Card> collected;
	int tabla;
	int score;
public:
	std::vector<Card> getHand()  const;
	std::vector<Card> getCollected()  const;
	int getTabla() const;
	int getScore() const;
	int getCollectedNumber() const;
	void setScore(int points);
	void showHand();
	void receiveCard(Card c);
	void addTabla();
	void cancelTabla();
	void refreshHand(std::vector<Card> m);
	void collect(Card c);
	

};

