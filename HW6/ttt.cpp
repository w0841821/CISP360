#include <iostream>
#include <cctype>
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
char playerMove(char*);
char compMove(char*);
//void checkGameOver();

int main()
{
  srand(time(0));
  startMenu();
  return 0;
}

// Specification B1 - Start Menu
void startMenu()
{
  int menuSelect;
  do {

  cout << "\n";
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
    system("clear");
    cout << "Let's play!!\n\n";
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
    userFirst = true;
  else
    userFirst = false;

  return userFirst;
}

void board()
{
//  char playAgain;
  char boardSymbol;
//  do {
    bool userFirst = coinFlip();
    if (userFirst)
    {
      boardSymbol = 'X';
      cout << "The user goes first, using " << boardSymbol << ", followed by the computer!\n\n";
    }
    else
    {
      boardSymbol = 'O';
      cout << "The computer goes first, using " << boardSymbol << ", followed by the user!\n\n";
    }

    char square[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < 9; i=i+3)
    {
      cout << "\n";
      cout << "  " << square[i] << "  |  " << square[i+1] << "  |  " << square[i+2] << "\n";
      if (i < 6)
        cout << "-----------------";
    }

    if (userFirst)
    {
      playerMove(square);
      for (int i = 0; i < 9; i=i+3)
      {
        cout << "\n";
        cout << "  " << square[i] << "  |  " << square[i+1] << "  |  " << square[i+2] << "\n";
        if (i < 6)
          cout << "-----------------";
      }
    }
    else
    {
      compMove(square);
      for (int i = 0; i < 9; i=i+3)
      {
        cout << "\n";
        cout << "  " << square[i] << "  |  " << square[i+1] << "  |  " << square[i+2] << "\n";
        if (i < 6)
          cout << "-----------------";
      }
    }

/*
    int playerPick;
    //do {

      //bool validPlayerPick = true;
      cout << "It is the user's turn! Where would you like to play?\n";
      cin >> playerPick;

      char charPlayerPick = '0' + playerPick;
      if (charPlayerPick == square[playerPick-1])
      {
        square[playerPick-1] = boardSymbol;
        cout << "Marked square " << playerPick << " as " << square[playerPick-1] << "\n";
        for (int i = 0; i < 9; i++)
          cout << square[i] << "\n";
      }
      else
        cout << "Didn't work.\n";

  // play by play
  // Human vs CPU wins
    do {
      cout << "\nWould you like to play again? (y/n)\n";
      cin >> playAgain;
      if (toupper(playAgain) != 'Y' && toupper(playAgain) != 'N')
        cout << "\nOops, that wasn't an option. Try again.\n\n";
    } while(toupper(playAgain) != 'Y' && toupper(playAgain) != 'N');


*/

  //checkGameOver();

//  } while (toupper(playAgain) != 'N');
}

char playerMove(char square[])
{
  int playerPick;

  cout << "It is the user's turn! Where would you like to play?\n";
  cin >> playerPick;

  char charPlayerPick = '0' + playerPick;
  if (charPlayerPick == square[playerPick-1])
  {
    square[playerPick-1] = 'X';
    cout << "Marked square " << playerPick << " as " << square[playerPick-1] << "\n";
    for (int i = 0; i < 9; i++)
      cout << square[i] << "\n";
  }
  else
    cout << "Didn't work.\n";
  return square[playerPick-1];
}

char compMove(char square[])
{
  bool compValid = true;
  int compPick;
  do {
    compPick = (rand() % 9) + 1;
    char charCompPick = '0' + compPick;
    if (charCompPick == square[compPick-1])
    {
      square[compPick-1] = 'O';
      cout << "Marked square " << compPick << " as " << square[compPick-1] << "\n";
      for (int i = 0; i < 9; i++)
        cout << square[i] << "\n";
      compValid = true;
    }
    else
    {
      compValid = false;
      cout << "WHY WONT YOU WORK";
    }

  } while(!compValid);
  return square[compPick-1];
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
