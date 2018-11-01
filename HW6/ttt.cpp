#include <iostream>
using namespace std;

// Create an empty Tic_Tac_Toe board
// Display the Game Instructions
// Determine who goes first
// Display the board
// While nobody has won and it’s not a tie
  // If it’s the human’s turn
    // Get the human’s move
    // Update the board with the human’s move
  // Otherwise
    // Calculate the computer’s move
    // Update the board with the computer’s move
  // Display the board
  // Switch turns
// Congratulate the winner or declare a tie

void startMenu();
void instructions();
bool coinFlip();
void board();

int main()
{
  startMenu();
  return 0;
}

// Specification B1 - Start Menu
void startMenu()
{
  int menuSelect;
  do {

  cout << "\n\n";
  cout << "1. How to play.\n";
  cout << "2. Play!\n";
  cout << "3. Quit.\n\n";

  cin >> menuSelect;

//Specification B2 - Valid Menu Choices
  if (menuSelect == 1)
  {
    instructions();
  }
  else if (menuSelect == 2)
  {
    cout << "Let's play!!\n";
    board();
  }
  else if (menuSelect == 3)
  {
    break;
  }
  else
    cout << "\nOops, that wasn't an option. Try again.\n\n";

// Specification A1 - Main Game Loop
  } while (menuSelect != 3);

}

void instructions()
{
  cout << "\nInstructions!\n";
  cout << "Player 1 (the user) will use X, while Player 2 (the computer) will use O.\n";
  cout << "Get three symbols in a row, column, or diagonally, and you win!\n";
}

// Specification C1 - Random Start
bool coinFlip()
{
  bool userFirst;
  int whoGoesFirst = (rand() % 2);

  if (whoGoesFirst == 0)
  {
    cout << "The user will go first!\n";
    userFirst = true;
  }
  else
  {
    cout << "The computer will go first!\n";
    userFirst = false;
  }

  return userFirst;
}

void board()
{
  char boardSymbol;
  bool userFirst = coinFlip();
  if (userFirst)
    boardSymbol = 'X';
  else
    boardSymbol = 'O';
  cout << "First symbol is " << boardSymbol << "\n";
  //do {
  char square[] = {'7', '8', '9', '4', '5', '6', '1', '2', '3'};

/*
  cout << "\n\n";
  cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2];
  cout << "\n-----------------\n";
  cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5];
  cout << "\n-----------------\n";
  cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8];
  cout << "\n";
  */

  for (int i = 0; i < 9; i=i+3)
  {
    cout << "\n";
    cout << "  " << square[i] << "  |  " << square[i+1] << "  |  " << square[i+2] << "\n";
      if (i < 6)
        cout << "-----------------";
      //while (int j < 6)
      //{
        //cout << "\n-----------------\n";
        //break;
      //}
  }

  //} while (quitGame !)
}

// Specification C2 - Simple Display
// Display in a 2D table X, O and empty spaces.

// Specification C3 - AI
// Comment the start of your AI code which determines where the computer will go during its turn.

// Specification C4 - Decide Winner
// Each move, check to see if somebody wins. If not, keep playing. If so, declare winner and end game.

// Specification B3 - Pretty Display
// Create a nicer display, with lines for the various boxes. Show the number inside the grid of valid moves, and X, and O of spots already taken. Stack this specification with specification C2 in your code (ie have both in your code - easier to give you the right grade.).

// Specification B4 – Valid Move
// Only allow the various players to make valid moves. This is more advanced input validation.

// Specification A2 - Simple Prompt
// Just prompt at the end of the game if the human wants to play again (y/n).

// Specification A3 - Keep Score
// Keep track of how many times the human and computer win. Display this information when the player quits for the day.

// Specification A4 - Play by play
// Keep track of the moves each player made during a game. Display this at the end of the game.

// Specification A? - <>
// Replace either A3 or A4 with one feature of your own choosing. This is optional, you can code A3 and A4.
