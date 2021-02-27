// CardGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Deck.h";
#include "Card.h";
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Carter Welke\tCIST004A\n";

	Deck deck{};
	deck.shuffle();
	
	//p = player, c = computer
	int	pWins{ 0 }, cWins{ 0 };
	size_t pNum;
	Card *pCard;
	Card *cCard;
	
	while (((pWins-cWins) < 2) && ((cWins - pWins) < 2))
	{
		cout << endl << "Current Win count is: " << endl;
		cout << "Player: " << pWins << " Computer: " << cWins << endl;

		//get input(range checked)
		do
		{
			cout << endl << "Enter a number between 0 and 51: ";
			cin >> pNum;
		}while(pNum < 0 || pNum > 51);

		pCard = deck.getCard(pNum);
		cout << "Your selected card is: " << static_cast<string>(*pCard) << endl;

		cCard = deck.dealCard();
		cout << "The computer's card is: " << static_cast<string>(*cCard) << endl;

		if (*pCard > *cCard)
		{
			cout << "You win this round!" << endl;
			++pWins;
		}
		if (*pCard < *cCard)
		{
			cout << "You lose this round!" << endl;
			++cWins;
		}
		if (*pCard == *cCard)
		{
			cout << "It's a Tie! No points!" << endl;
		}
		
		deck.shuffle();

	}

	if (pWins > cWins)
	{
		cout << endl << "You win the game " << pWins << " to " << cWins << endl;
	}
	else
	{
		cout << endl << "You lose the game " << cWins << " to " << pWins << endl;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
