
#include "pch.h"
# include "Card.h";

const std::string Card::faces[]{ "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

const std::string Card::suits[]{ "Clubs", "Diamonds", "Hearts", "Spades" };


Card::Card(int f, int s)
	: face{ f }, suit{ s }
{}

int Card::getFace()
{
	return face;
}

int Card::getSuit()
{
	return suit;
}

std::string Card::toString()
{
	return faces[face] + " of " + suits[suit];
}

bool Card::operator < (const Card & rightCard)
{
	if (this->face != rightCard.face)
	{
		return this->face < rightCard.face;
	}
	return this->suit < rightCard.suit;
}

bool Card::operator > (const Card & rightCard)
{
	if (this->face != rightCard.face)
	{
		return this->face > rightCard.face;
	}
	return this->suit > rightCard.suit;
}

bool Card::operator == (const Card& rightCard)
{
	return (this->face == rightCard.face) && (this->suit == rightCard.suit);
}

Card::operator std::string() const
{
	return faces[face] + " of " + suits[suit];
}
