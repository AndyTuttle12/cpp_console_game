#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a valid guess, increments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn
	MyCurrentTry++;
	// setup return variable
	BullCowCount BullCowCount;
	// loop all chars in guess
		// compare letters against hidden word 
	return BullCowCount;
}
