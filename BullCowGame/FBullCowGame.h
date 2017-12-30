#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a rich return value
	bool CheckGuessValidity(std::string);
	// provide a method for counting bulls & cows and increasing try number

// Mostly look at the public methods above ^^
private:
	// see constructor for initializations
	int MyCurrentTry;
	int MyMaxTries;
};