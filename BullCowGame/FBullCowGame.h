#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a rich return value
	bool CheckGuessValidity(FString);
	BullCowCount SubmitGuess(FString);

// Mostly look at the public methods above ^^
private:
	// see constructor for initializations
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};