// name
// date
// CISP360
//

#include <iostream>
using namespace std;

// prototypes
//string pickObject(string nameObject);
void a1(int&);
void a13(int&);
void a100(int&);
void a159(int&);
void a161(int&);
void a167(int&);
void a173(int&);
void a212(int&);
void a232(int&);
void a290(int&);

int main()
{
  int menuValue;

  a1(menuValue);

  return 0;
}

/*
void getMenuChoice(int& menuChoice)
{
  cout << "Which path is yours?\n";
  cin >> menuChoice;
}
*/

void a1(int& menuChoice)
{
  int menuValue;

  cout << "\nHere is A1.\n\n";

  cout << "1. Call A100\n";
  cout << "2. Call A167\n";

  do {
    cout << "Which path is yours?\n";
    cin >> menuChoice;
  } while(menuChoice != 1 && menuChoice != 2);

  if (menuChoice == 1)
    a100(menuValue);
  else
    a167(menuValue);

  // getMenuChoice(menuChoice);
/*
  cin >> menuChoice


  else
  {
    cout << "That's not a valid option. Try again.\n";
    cout << "Which path would you like to take?\n";
  }
  */
}

void a13(int& menuChoice)
{
  int menuValue;

  cout << "\nHere is A13.\n\n";

  cout << "1. Call A212.\n";
  cout << "2. Call A159.\n";
  cout << "3. Call A173.\n";

  do {
    cout << "Which path is yours?\n";
    cin >> menuChoice;
  } while(menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

  if (menuChoice == 1)
    a212(menuValue);
  else if (menuChoice == 2)
    a159(menuValue);
  else
    a173(menuValue);
}

void a100(int& menuChoice)
{
  int menuValue;

  cout << "Here is A100.\n\n";

  cout << "1. Continue to A232\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);

  a232(menuValue);
}

void a159(int& menuChoice)
{
  cout << "Here is A159.\n\n";

  cout << "1. Done.\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);
}

void a161(int& menuChoice)
{
  cout << "Here is A161.\n\n";

  cout << "1. Done.\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);
}

void a167(int& menuChoice)
{
  int menuValue;

  cout << "Here is A167.\n\n";

  cout << "1. Continue to A232\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);

  a232(menuValue);
}

void a173(int& menuChoice)
{
  cout << "Here is A173.\n\n";

  cout << "1. Done.\n";
  cout << "2. Done.\n";

  do {
    cout << "Which path is yours?\n";
    cin >> menuChoice;
  } while(menuChoice != 1 && menuChoice != 2);
}

void a212(int& menuChoice)
{
  int menuValue;

  cout << "Here is A212.\n\n";

  cout << "1. Call A161.\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);

  a161(menuValue);
}

void a232(int& menuChoice)
{
  int menuValue;

  cout << "Here is A232.\n\n";

  cout << "1. Call A13.\n";
  cout << "2. Call A290.\n";

  do {
    cout << "Which path is yours?\n";
    cin >> menuChoice;
  } while(menuChoice != 1 && menuChoice != 2);

  if (menuChoice == 1)
    a13(menuValue);
  else
    a290(menuValue);
}

void a290(int& menuChoice)
{
  int menuValue;

  cout << "Here is A290.\n\n";

  cout << "1. Call A161.\n";

  do {
    cout << "Only one path lies ahead.\n";
    cin >> menuChoice;
  } while(menuChoice != 1);

  a161(menuValue);
}
