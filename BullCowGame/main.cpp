#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for the application
int main()
{
	PrintIntro();

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}
	
	return 0;
}

// Introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}


string GetGuessAndPrintBack()
{
	// get a guess from the player
	cout << "Make your guess here: ";
	string Guess = "";
	getline(cin, Guess);
	// print the guess back to them
	cout << "Your guess is: " << Guess << endl;
	return Guess;
}