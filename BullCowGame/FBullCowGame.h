#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO make a rich return value
	FBullCowCount SubmitGuess(FString);

// Mostly look at the public methods above ^^
private:
	// see constructor for initializations
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};