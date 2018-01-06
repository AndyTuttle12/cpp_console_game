#pragma once
#include "FBullCowGame.h"
#include <map>

// to make syntax more like Unreal Engine 4
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() { FBullCowGame::Reset(); } // default constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planets"; // this must be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // If the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess isn't the right length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup map
	for (auto Letter : Word) // loop for all letters in Word
	{	
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we don't have an isogram
		} else {
			LetterSeen[Letter] = true; // add the letter to the map
		}	
	}
	return true; // for example where /0 is entered (string escape char)
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word) // loop for all letters in Word
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	// loop all chars in hidden word
	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		// compare letters against guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match
			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				if (HWChar == GChar) { // if they are in the same place
					BullCowCount.Bulls++; // increment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}	
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}
