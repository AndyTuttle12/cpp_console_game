/* This is the console executable that makes use of the BullCow class.
 This acts as the view in an MVC pattern, and is responsible for all
 user interaction. For game logic, see the FBullCowGame class.
*/

#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax more like Unreal Engine 4
using FText = std::string;
using int32 = int;

// function prototypes outside a class
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game (re-using across plays)

// the entry point for the application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);
	return 0; // exit the application
}

void PrintIntro()
{                                                  
	std::cout << "\n\n    ___      _ _      __        ___               \n";
	std::cout << "   | _ )_  _| | |___ / _|___   / __|_____ __ _____\n";
	std::cout << "   | _ \\ || | | (_-< > _|_ _| | (__/ _ \\ V  V (_-<\n";
	std::cout << "   |___/\\_,_|_|_/__/ \\_____|   \\___\\___/\\_/\\_//__/\n";

	std::cout << "\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// plays a single game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is not run
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		
		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();
	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations! You Won!\n";
	}
	else
	{
		std::cout << "Sorry! Better luck next time!\n";
	}
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ": Make your guess here: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please do not repeat letters. This should be an isogram.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please write your guess in all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		
	} while (Status != EGuessStatus::OK); // keep lopping until there are no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
