#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

void PrintGuess(std::string &Guess);

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

bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	cout << endl;
	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
