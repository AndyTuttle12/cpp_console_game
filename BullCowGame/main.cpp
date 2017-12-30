#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

void PrintGuess(std::string &Guess);

FBullCowGame BCGame; // instantiate a new game

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

// Introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from for to while once validating tries
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess(); // TODO check for valid guesses
		// submit valid guess to the game
		// print number of bulls and cows
		std::cout << "Your guess is: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarize game
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	// get a guess from the player
	std::cout << "Try " << CurrentTry << ": Make your guess here: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
