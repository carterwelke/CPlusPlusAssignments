#pragma once

#include "Card.h";
#include <vector>;

class Deck
{
public:
	Deck(); // constructor initializes deck
	void shuffle(); // shuffles cards in deck
	Card * dealCard(); // deals cards in deck
	Card * getCard(size_t); //gets a card from the deck
	bool moreCards() const; // are there any more cards left

private:
	std::vector< Card * > deck; // represents deck of cards
	size_t currentCard; // index of next card to be dealt
}; // end class DeckOfCards