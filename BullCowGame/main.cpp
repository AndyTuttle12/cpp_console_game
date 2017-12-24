#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

void PrintGuess(std::string &Guess);

// the entry point for the application
int main()
{
	PrintIntro();
	PlayGame();
	return 0; // exit the application
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

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		string Guess = GetGuess();
		// Print the guess
		cout << "Your guess is: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess()
{
	// get a guess from the player
	cout << "Make your guess here: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}
