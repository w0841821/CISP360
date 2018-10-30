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

int main()
{
  startMenu();
  return 0;
}

// Specification C1 - Random Start
// Determine which player will start the game - randomly. Make sure
// you tell the client who’s starting.

// Specification C2 - Simple Display
// Display in a 2D table X, O and empty spaces.

// Specification C3 - AI
// Comment the start of your AI code which determines where the
// computer will go during its turn.

// Specification C4 - Decide Winner
// Each move, check to see if somebody wins. If not, keep playing. If
// so, declare winner and end game.

// Specification B1 - Start Menu
// Create a simple menu, 1 - Explain Game, 2 - Play, 3 - Quit. This menu will run once every time the program runs. Don’t go into excruciating detail explaining the game.

void startMenu()
{
  char menuSelect;

  cout << "1. How to play.\n";
  cout << "2. Play!\n";
  cout << "3. Quit.\n\n";

  cin >> menuSelect;
}

//Specification B2 - Valid Menu Choices
// Filter the input for valid numbers. Re-prompt incorrect entries.

// Specification B3 - Pretty Display
// Create a nicer display, with lines for the various boxes. Show the number inside the grid of valid moves, and X, and O of spots already taken. Stack this specification with specification C2 in your code (ie have both in your code - easier to give you the right grade.).

// Specification B4 – Valid Move
// Only allow the various players to make valid moves. This is more advanced input validation.

// Specification A1 - Main Game Loop
// Use a DO - WHILE to run the game until the client decides to quit.

// Specification A2 - Simple Prompt
// Just prompt at the end of the game if the human wants to play again (y/n).

// Specification A3 - Keep Score
// Keep track of how many times the human and computer win. Display this information when the player quits for the day.

// Specification A4 - Play by play
// Keep track of the moves each player made during a game. Display this at the end of the game.

// Specification A? - <>
// Replace either A3 or A4 with one feature of your own choosing. This is optional, you can code A3 and A4.
