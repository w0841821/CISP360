#include <iostream>
#include <cctype>
using namespace std;

int gameMenu();
void playGame();
bool coinFlip();
void printBoard(char*);
void userMove(char*);
void compMove(char*);
bool checkWin(char*);

int main()
{
  srand(time(0));
  gameMenu();
  return 0;
}

int gameMenu()
{
  int menuPick;

  do
  {
    cout << "1. How to play.\n";
    cout << "2. Play!\n";
    cout << "3. Quit.\n";

    cin >> menuPick;

    if (menuPick == 1)
      // printRules();
      cout << "\n";
    else if (menuPick == 2)
      playGame();
    else if (menuPick == 3)
      cout << "Bye!\n";
    else
      cout << "Oops, that's not an option. Try again.\n";
  } while (menuPick != 3);

  return 0;
}

void playGame()
{
  // square[0] won't be used. Just trying to keep the board looking like a numpad.
  char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  system("clear");

  bool userFirst = coinFlip();
  bool userWins;
  bool gameOver;

  do {

    if (userFirst)
    {
      do {
        printBoard(square);
        userMove(square);
        printBoard(square);
        gameOver = checkWin(square);
        if (gameOver)
        {
          userWins = true;
          break;
        }
        compMove(square);
        gameOver = checkWin(square);
        if (gameOver)
          userWins = false;
      } while (!gameOver);
    }
    else
    {
      do {
        printBoard(square);
        compMove(square);
        printBoard(square);
        gameOver = checkWin(square);
        if (gameOver)
        {
          userWins = false;
          break;
        }
        userMove(square);
        gameOver = checkWin(square);
        if (gameOver)
          userWins = true;
      } while (!gameOver);
    }
  } while (!gameOver);

  if (userWins)
    cout << "User wins!\n";
  else
    cout << "Computer wins!\n";

// end PlayGame
}

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

void printBoard(char square[])
{
  for (int i = 1; i < 9; i = i + 3)
  {
    cout << "\n";
    cout << "  " << square[i] << "  |  " << square[i+1] << "  |  " << square[i+2] << "\n";
    if (i < 7)
      cout << "-----------------";
  }
  cout << "\n";
}

void userMove(char square[])
{
  int playerPick;
  char charPlayerPick;
  // char boardSymbol = 'X';
  cout << "It is the user's turn! Where would you like to play?\n";

  do {
    cin >> playerPick;
    charPlayerPick = '0' + playerPick;
    if (charPlayerPick == square[playerPick])
    {
      square[playerPick] = 'X';
      cout << "\nMarked " << playerPick << " as X.\n";
    }
    else
      cout << "\nAlready taken! Pick again.\n";
  } while (charPlayerPick == square[playerPick]);
}

void compMove(char square[])
{
  int compPick;
  char charCompPick;
  // char boardSymbol = 'O';
  bool compValid = true;
  do {
    compPick = (rand() % 9) + 1;
    charCompPick = '0' + compPick;
    if (charCompPick == square[compPick])
    {
      square[compPick] = 'O';
      cout << "The computer marked " << compPick << " as O.\n";
      compValid = true;
    }
    else
      compValid = false;
  } while(!compValid);
}
/*
char changeBoard()
{

}
*/
bool checkWin(char square[])
{
  // 1 2 3
  // 4 5 6
  // 7 8 9
  // check each row for matching symbols
  if (square[1] == square[2] && square[1] == square[3])
    return true;
  else if (square[4] == square[5] && square[4] == square[6])
    return true;
  else if (square[7] == square[8] && square[7] == square[9])
    return true;

  // check each column for matching symbols
  else if (square[1] == square[4] && square[1] == square[7])
    return true;
  else if (square[2] == square[5] && square[2] == square[8])
    return true;
  else if (square[3] == square[6] && square[3] == square[9])
    return true;

  // check the diagonals for matching symbols
  else if (square[1] == square[5] && square[1] == square[9])
    return true;
  else if (square[3] == square[5] && square[3] == square[7])
    return true;
  else
    return false;
}
/*
void checkTie()
{

}*/
