// ttt.cpp
// Erroll Abrahamian, CISP 360
// 11-11-2018

#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

void sayHi();
int gameMenu();
void printRules();
void playGame();
bool coinFlip();
void userStarts(int*);
void compStarts(int*);
bool playAgain();
void printBoard(char*);
void userMove(char*);
void compMove(char*);
int checkWin(char*);
void printMoves();

int main()
{
  srand(time(0));
  // program greeting
  sayHi();
  gameMenu();
  return 0;
}

void sayHi()
{
    cout << "\nWelcome to Tic Tac Toe!\n\n";
}

// Specification B1 - Start Menu
int gameMenu()
{
    int menuPick;

    do {
        cout << "\n1. How to play.\n";
        cout << "2. Play!\n";
        cout << "3. Quit.\n";

        cin >> menuPick;

        if (menuPick == 1)
            printRules();
        else if (menuPick == 2)
            playGame();
        else if (menuPick == 3)
            cout << "\nBye!\n\n";
        //Specification B2 - Valid Menu Choices
        else
            cout << "Oops, that's not an option. Try again.\n";
    } while(menuPick != 3);

    return 0;
}

void printRules()
{
    cout << "\nThe board is a 3x3 grid.\n";
    cout << "The user will use X, and the computer will use O for their marks.\n";
    cout << "The first to have 3 marks in a row, column, or diagonal, wins!\n\n";
}

void playGame()
{
    int userRecord[] = {0, 0, 0};
    bool goingAgain;

    do {
        ofstream movesList;
        movesList.open("moves.txt");
        // movesList << "Game start!" << endl;
        movesList.close();
        // Specification C1 - Random Start
        bool userFirst = coinFlip();
        system("clear");
        cout << "\nGametime!\n\n";
        if (userFirst)
        {
            cout << "The user goes first!\n\n";
            userStarts(userRecord);
        }
        else
        {
            cout << "The computer goes first!\n\n";
            compStarts(userRecord);
        }
        // Specification A1 - Main Game Loop
        goingAgain = playAgain();
    } while(goingAgain);

    // Specification A3 - Keep Score
    cout << "\nThe user won " << userRecord[0] << ".\n";
    cout << "The computer won " << userRecord[1] << ".\n";
    if ((userRecord[2] == 1))
      cout << "There was 1 tie.\n";
    else
      cout << "There were " << userRecord[2] << " ties.\n";
}

bool coinFlip()
{
    bool userFirst;

    // generate a random 0 or 1 to determine who goes first
    int theFlip = (rand() % 2);
    if (theFlip == 0)
        userFirst = true;
    else
        userFirst = false;
    return userFirst;
}

void userStarts(int userRecord[])
{
    // square[0] won't be used. Just trying to keep the game board looking like a number pad.
    char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int gameOver;
    bool userWins;
    bool tieGame;

    do {
        // prints a blank board to start, then fills in moves
        printBoard(square);

        // get the user's move
        userMove(square);

        // Specification C4 - Decide Winner
        gameOver = checkWin(square);
        if (gameOver == 1)
        {
            userWins = true;
            break;
        }
        else if (gameOver == -1)
        {
            tieGame = true;
            break;
        }

        // now the computer's turn
        compMove(square);
        gameOver = checkWin(square);
        if (gameOver == 1)
            userWins = false;
        else if (gameOver == -1)
            tieGame = true;
    } while(gameOver == 0); // as long as there is no win or tie, keep looping

    if (userWins)
    {
        cout << "User wins!\n\n";
        printMoves();
        // add 1 to the "win"
        userRecord[0] = userRecord[0] + 1;
    }
    else if (tieGame)
    {
        cout << "It was a tie!\n\n";
        printMoves();
        // add 1 to the "tie"
        userRecord[2] = userRecord[2] + 1;
    }
    else
    {
        cout << "Computer wins!\n\n";
        printMoves();
        // add 1 to the "loss"
        userRecord[1] = userRecord[1] + 1;
    }
}

void compStarts(int userRecord[])
{
    char square[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int gameOver;
    bool userWins;
    bool tieGame;

    do {
        // no point printing a blank board for the computer
        // get the computer's move
        compMove(square);
        gameOver = checkWin(square);
        if (gameOver == 1)
        {
            userWins = false;
            break;
        }
        else if (gameOver == -1)
        {
            tieGame = true;
            break;
        }

        // now the user's turn
        printBoard(square);
        userMove(square);
        gameOver = checkWin(square);
        if (gameOver == 1)
            userWins = true;
        else if (gameOver == -1)
            tieGame = true;
    } while(gameOver == 0);

    if (userWins)
    {
        cout << "User wins!\n\n";
        printMoves();
        userRecord[0] = userRecord[0] + 1;
    }
    else if (tieGame)
    {
        cout << "It was a tie!\n\n";
        printMoves();
        userRecord[2] = userRecord[2] + 1;
    }
    else
    {
        cout << "Computer wins!\n\n";
        printMoves();
        userRecord[1] = userRecord[1] + 1;
    }
}

// Specification C2 - Simple Display
// Specification B3 - Pretty Display
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
    bool userValid;

    cout << "It is the user's turn! Where would you like to play?\n";

    do {
      cin >> playerPick;
      charPlayerPick = '0' + playerPick;
      // Specification B4 – Valid Move
      if (charPlayerPick == square[playerPick])
      {
        square[playerPick] = 'X';
        cout << "\nMarked " << playerPick << " as X.\n";
        ofstream movesList;
        movesList.open("moves.txt", ios::app);
        movesList << "Player marked " << playerPick << " as X." << endl;
        movesList.close();
        userValid = true;
      }
      else
      {
        cout << "\nAlready taken! Pick again.\n";
        userValid = false;
      }
    } while (!userValid);
}

// Specification C3 - AI
void compMove(char square[])
{
    int compPick;
    char charCompPick;
    bool compValid;

    do {
      compPick = (rand() % 9) + 1;
      charCompPick = '0' + compPick;
      if (charCompPick == square[compPick])
      {
        square[compPick] = 'O';
        cout << "The computer marked " << compPick << " as O.\n";
        ofstream movesList;
        movesList.open("moves.txt", ios::app);
        movesList << "Computer marked " << compPick << " as X." << endl;
        movesList.close();
        compValid = true;
      }
      else
        compValid = false;
    } while(!compValid);
}

int checkWin(char square[])
{
  // 1 2 3
  // 4 5 6
  // 7 8 9
  // check each row for matching symbols
  if (square[1] == square[2] && square[1] == square[3])
    return 1;
  else if (square[4] == square[5] && square[4] == square[6])
    return 1;
  else if (square[7] == square[8] && square[7] == square[9])
    return 1;

  // check each column for matching symbols
  else if (square[1] == square[4] && square[1] == square[7])
    return 1;
  else if (square[2] == square[5] && square[2] == square[8])
    return 1;
  else if (square[3] == square[6] && square[3] == square[9])
    return 1;

  // check the diagonals for matching symbols
  else if (square[1] == square[5] && square[1] == square[9])
    return 1;
  else if (square[3] == square[5] && square[3] == square[7])
    return 1;

  // check if all squares are changed, meaning a tie
  else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
    return -1;
  else
    return 0;
  // 1 for a win, -1 for a tie, or return good ol 0 to keep going
}

bool playAgain()
{
    char playAgain;
    bool goingAgain;

    // Specification A2 - Simple Prompt
    cout << "Play again? (y/n)\n";
    do {
        cin >> playAgain;
        if (toupper(playAgain) == 'Y')
            goingAgain = true;
        else if (toupper(playAgain) == 'N')
            goingAgain = false;
        else
            cout << "\nNot a valid entry. Play again? (y/n)\n";
    } while((toupper(playAgain) != 'N') && (toupper(playAgain) != 'Y'));

    return goingAgain;
}

// Specification A4 - Play by play
void printMoves()
{
    ifstream movesList;
    movesList.open("moves.txt");
    string line;
    while (getline(movesList, line))
    {
        cout << line << endl;
    }
    cout << "\n";
}
