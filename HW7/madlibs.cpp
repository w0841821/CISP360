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

// Specification A? - <>
// Replace A3 with one feature of your own choosing. This is optional, you can code A3 if you wish and skip this.

#include <iostream>
using namespace std;

void getWords();

int main()
{
  getWords();
  return 0;
}

void getWords()
{
  cout << "Give me a time-span.\n";
  cin >> timespan >> endl;
  cout << "Give me a noun.\n";
  cin >> noun1 >> endl;
  cout << "Give me a verb.\n";
  cin >> verb1 >> endl;
  cout << "Give me a verb.\n";
  cin >> verb2 >> endl;
  cout << "Give me a noun.\n";
  cin >> noun2 (plural or singular) >> endl;
  cout << "Give me a noun.\n";
  cin >> noun3 >> endl;
  cout << "Give me a verb.\n";
  cin >> verb3 ending in ing  >> endl;
  cout << "Give me a two-word occupation.\n";
  cin >> 2 word occupation >> endl;
  cout << "Give me a noun.\n";
  cin >> noun4 >> endl;
  cout << "Give me a noun.\n";
  cin >> noun5 >> endl;
  cout << "Give me a famous person.\n";
  cin >> famous person >> endl;
  cout << "Give me an adjective.\n";
  cin >> adjective1 >> endl;
  cout << "Give me a verb.\n";
  cin >> verb4 >> endl;
  cout << "Give me a noun.\n";
  cin >> noun6 >> endl;
  cout << "Give me a noun.\n";
  cin >> noun7 plural >> endl;
  cout << "Give me an adjective.\n";
  cin >> adjective2 >> endl;
  cout << "Give me a noun.\n";
  cin >> noun8 plural >> endl;
  cout << "Give me a verb.\n";
  cin >> verb preposition >> endl;
  cout << "Give me an integer.\n";
  cin >> integer >> endl;
  cout << "Give me a verb.\n";
  cin >> verb5 >> endl;
  cin >> float letter >> endl;
}
