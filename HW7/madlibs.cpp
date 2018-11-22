//

// Specification C1 - Random Word
// Randomly select one of these words for VERB2: comb, paint, remove.

// Specification C2 - Random Float
// Generate a random float 1.0 to 15.0 inclusive. Display only 1 number after the decimal point.

// Specification C3 - Word Menu
// Display a simple menu for the client and allow them to only select one of the following words: breakfast, fishes, copper coins.

// Specification B1 - Phrase Validation
// FAMOUS PERSON and 2 WORD OCCUPATION require a word phrase. This assignment assumes this is just two words separated with a space. The input validation for this is to just check to see if the string has a space in it.

//Specification B2 - Maximum Word Size Validation
// NOUN1 can only be a maximum of 15 letters long.

// Specification B3 - Range Validation
// VERB5 must be between 4 and 20 characters in length.

// Specification B4 – Simple Menu
// Create a simple menu 1 - Explain Mad Libs, 2 - Start Mad Libs, 3 -Quit. Only allow valid choices.

// Specification A1 - Main Game Loop
// Use a DO - WHILE to run the game until the client decides to quit. Just prompt at the end of the game if the human want’s to play again (y/n).

// Specification A2 - C Style String
// Do not use a C++ style string for NOUN8, use a C Style string instead.

// Specification A3 - Smallest Word
// Prompt the client for 2 words. Select the smallest and use that for VERB3.

#include <iostream>
#include <string>
using namespace std;

void getWords();
void printMadlib();

int main()
{
  getWords();
  printMadlib();
  return 0;
}

void getWords()
{
	string timespan,
		adjective[2],
		noun[8],
		verb[7],
		occupation,
		person;
	int integer;
	float floatNum;
	char letter;

  cout << "Give me a time-span.\n";
  cin >> timespan;

	cout << "Give me a noun.\n";
  cin >> noun[0];

	cout << "Give me a verb.\n";
  cin >> verb[0];

  cout << "Give me a verb.\n";
  cin >> verb[1];

  cout << "Give me a noun (plural or singular).\n";
  cin >> noun[1];

  cout << "Give me a noun.\n";
  cin >> noun[2];

	cout << "Give me a verb ending in \"ing\" (eg: running, walking).\n";
  cin >> verb[2];

	cout << "Give me a two-word occupation.\n";
  cin.ignore();
  getline(cin, occupation);

  cout << "Give me a noun.\n";
  cin >> noun[3];

  cout << "Give me a noun.\n";
  cin >> noun[4];

	cout << "Give me a famous person (first and last name).\n";
  cin.ignore();
  getline(cin, person);

  cout << "Give me an adjective.\n";
  cin >> adjective[0];

  cout << "Give me a verb.\n";
  cin >> verb[3];

  cout << "Give me a noun.\n";
  cin >> noun[5];

  cout << "Give me a plural noun.\n";
  cin >> noun[6];

  cout << "Give me an adjective.\n";
  cin >> adjective[1];

  cout << "Give me a plural noun.\n";
  cin >> noun[7];

  cout << "Give me a verb with preposition (eg: waiting for, going with, smells of, based on).\n";
  cin.ignore();
  getline(cin, verb[5]);

	cout << "Give me an integer.\n";
  cin >> integer;

	cout << "Give me a verb.\n";
  cin >> verb[6];

	cout << "Give me a floating number (eg: 4.1).\n";
  cin >> floatNum;

	cout << "Give me a single letter.\n";
	cin >> letter;
}

void printMadlib()
{
  cout << "  A Day In The Life Of a College Student\n";
  cout << "  ======================================\n\n";
  cout << "Every " << timespan << ", I wake up and get off my " << noun[0] << ". I don't\n";
  cout << "always have time to " << verb[0] << " a shower, but I always make sure\n";
  cout << "to " << verb[1] << " my hair. Once that‘s done I get some " << noun[1] ",\n";
  cout << "and then it‘s off to my first " << noun[2] << ". I often\n";
  cout << "get caught " << verb[2] << " in class. No one likes it\n";
  cout << "when the " << occupation << " gives a surprise " << noun[3] << ". My second\n";
  cout << "class is " << noun[4] << " Theory. Dr. " << person << " is incredibly\n";
  cout << adjective[0] << ", but I never " << verb[3] << " her because of her thick " << noun[5] << ".\n";
  cout << "Her " << noun[6] << ", however, are really " << adjective[1] << ". After\n";
  cout << "lunch, I have no more " << noun[7] << " and I‘m free to " << verb[4] << "\n";
  cout << "my friends. This is right around " << integer << " O’clock.\n";
  cout << "Before I go to bed I " << verb[5] << " a little bit, in my room, " << floatNum << " " << letter << ".\n";
}
