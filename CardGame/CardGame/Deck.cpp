
#include "pch.h"
#include "Deck.h";
#include "Card.h";
#include <cstdlib>;
#include <iostream>;

Deck::Deck() //fills deck with cards
{
	for (int s{ 0 }; s < 4; ++s)
	{
		for (int f{ 0 }; f < 13; ++f)
		{
			deck.emplace_back(new Card{ f,s });
		}
	}
	currentCard = 0;
}

void Deck::shuffle() // shuffles cards in deck
{

	int randIndex;
	currentCard = 0;
	//swap each card with a random card in the deck
	for (; moreCards(); currentCard++)
	{
		randIndex = rand() % deck.size();
		Card * temp = deck[currentCard];
		deck[currentCard] = deck[randIndex];
		deck[randIndex] = temp;
	}
	currentCard = 0;
}

Card * Deck::dealCard()// deals a card from the deck
{
	return deck[currentCard++];
}

Card * Deck::getCard(size_t index)//gets a card from the deck
{
	return deck[index];
}

bool Deck::moreCards() const // are there any more cards left
{
	return currentCard < deck.size();
}