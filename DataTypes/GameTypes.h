/*
	
	file: GameTypes.h
	programmer: Daylan Kelting
	date created: 12-14-15
	date last modified: 12-14-15
	description: Contains types used by the game parts of our
		Holdem program.
	
*/

#include "BasicTypes.h"

typedef enum Suit
{
	Clubs = 0,
	Diamonds = 1,
	Hearts = 2,
	Spades = 3
};

typedef enum CardFace
{
	Two = 0,
	Three = 1,
	Four = 2,
	Five = 3,
	Six = 4,
	Seven = 5,
	Eight = 6,
	Nine = 7,
	Ten = 8,
	Jack = 9,
	Queen = 10,
	King = 11,
	Ace = 12
};

typedef enum Hand
{
	HighCard = 0,
	OnePair = 1,
	TwoPair = 2,
	ThreeKind = 3,
	Straight = 4,
	Flush = 5,
	FullHouse = 6,
	FourKind = 7,
	StraightFlush = 8,
	RoyalFlush = 900
};

typedef enum PlayerAction
{
	Fold = 0,
	CallCheck = 1,
	RaiseBet = 2
};

typedef struct Bet
{
	PlayerAction action;
	int betAmount;
	bool ALL_IN;
};

/*
	
	type: Card
	description: structure representing a single card.
	fields:
		cardID: Integer representing exactly what card this is.
			0-51. Cards are organized such that their IDs are equivalent to their scores
			in a high card situation. This is so we cannot have ties and so it is easy
			to score cards just off of their ID.
			Suit = cardID % 4
			FaceID = cardID / 4
		suit: what suit is this card?
		face: what is on the face of this card?
*/
typedef struct Card
{
	int cardID;
	Suit suit;
	CardFace face;
};

/*

	type: Player
	description: structure holding player information.
	
*/
typedef struct Player
{
	int money;
	bool hasBusted;
	string name;

	PlayerRoundInfo roundInfo;
};

typedef struct PlayerRoundInfo
{
	int playerBet;
	Card cards[2];
};

typedef struct GlobalRoundInfo
{
	Card communityCards[5];
	int globalPot;
	int globalBet;
};

typedef struct ServerRoundInfo
{
	int numBusted;
	int numPlayers;

	GlobalRoundInfo roundInfo;
};