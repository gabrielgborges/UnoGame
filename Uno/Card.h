#pragma once
#include "CardColor.h"
#include "CardType.h"
#include <xmemory>
#include <string>

struct Card 
{
public:
	Card(int number, CardColor color, CardType type) 
		: Number(number), Color(color), Type(type) { };

	Card(const Card& other) : Number(other.Number), Color(other.Color), Type(other.Type)
	{ };

	bool operator==(const Card& other) const
	{
		return other.Color == Color && other.Type == Type && other.Number == Number;
	}

	std::string CardDisplay() {
		std::string cardDisplay;
		switch (Color)
		{
		case BLUE:
			cardDisplay = "\033[1m\033[34m";
			break;
		case YELLOW:
			cardDisplay = "\033[1m\033[33m";
			break;
		case RED:
			cardDisplay = "\033[1m\033[31m";
			break;
		case GREEN:
			cardDisplay = "\033[1m\033[32m";
			break;
		default:
			break;
		}
		
		switch (Type)
		{
		case STANDARD:
			cardDisplay += std::to_string(Number);
			break;
		case REVERSE:
			cardDisplay += "Reverse";
			break;
		case SKIP:
			cardDisplay += "Skip";
			break;
		case PLUS_TWO:
			cardDisplay += "Plus two";
			break;
		case DISCARD_PLUS_TWO:
			cardDisplay += "Discard plus two";
		default:
			cardDisplay += "unknown";
			break;
		}
		return cardDisplay += "\033[37m";

	}

	inline bool IsPlayableWith(Card card) {
		bool collorIsEqual = card.Color == Color;
		bool typeIsEqual = card.Type == Type && Type != STANDARD;
		bool numberIsEqual = card.Type == STANDARD && Type == STANDARD && card.Number == Number;

		return collorIsEqual || typeIsEqual || numberIsEqual;
	}

	int Number;
	CardColor Color;
	CardType Type;
};

struct CardComparator
{
	bool operator()(const Card& A, const Card& B) const
	{
		return A.Color == B.Color && A.Type == B.Type && A.Number == B.Number;
	}

	std::size_t operator()(const Card& card) const {
		std::hash<int> intHasher;
		std::hash<CardColor> colorHasher;
		std::hash<CardType> typeHasher;

		// Combine the hashes of members using the 'combine' function
		return combine(intHasher(card.Number), colorHasher(card.Color), typeHasher(card.Type));
	}
private:
	// Hash combining function
	static std::size_t combine(std::size_t h1, std::size_t h2, std::size_t h3) {
		return h1 ^ (h2 << 1) ^ (h3 << 2);
	}
};