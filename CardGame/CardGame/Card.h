#pragma once

#include <string>;

class Card
{
public:
	Card(int, int);
	int getFace();
	int getSuit();
	std::string toString();

	bool operator > (const Card&);
	bool operator < (const Card&);
	bool operator == (const Card&);

	operator std::string() const;

private:
	int face;
	int suit;
	static const std::string faces[];
	static const std::string suits[];
};