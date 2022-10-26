#include "Player.h"

std::vector<Card> Player::getHand() const
{
	return hand;
}

std::vector<Card> Player::getCollected() const
{
	return collected;
}

void Player::showHand()
{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Your hand: " << std::endl;
	for (int index = 0; index < hand.size(); index++)
	{
		hand[index].showCard();
	}
	std::cout << std::endl;
	for (int index = 0; index < hand.size(); index++)
	{
		std::cout << "    " << index << "\t ";
	}

	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

void Player::receiveCard(Card c)
{
	hand.push_back(c);
}

void Player::addTabla()
{
	tabla++;
}

void Player::cancelTabla()
{
	tabla--;
}

void Player::refreshHand(std::vector<Card> m)
{
	hand = m;
}

void Player::collect(Card c)
{
	collected.push_back(c);
}

int Player::getTabla() const
{
	return tabla;
}

void Player::setScore(int sco)
{
	score = sco;
}

int Player::getCollectedNumber() const
{
	return collected.size();
}

int Player::getScore() const
{
	return score;
}