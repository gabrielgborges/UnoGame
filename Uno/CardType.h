#pragma once
#include <functional>

enum CardType 
{
	STANDARD = 0,
	REVERSE = 1,
	SKIP = 2,
	PLUS_TWO = 3,
	DISCARD_PLUS_TWO = 4,
};

namespace std {
    template<>
    struct hash<CardType> {
        std::size_t operator()(const CardType& cardType) const {
            return std::hash<int>{}(static_cast<int>(cardType));
        }
    };
}