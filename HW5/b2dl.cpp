#include <iostream>
#include <string>
using namespace std;

// declare prototypes
void sayHi();
string generalMenu();
string raiseItAll(string menuSelection);
bool checkA1(string &);
void a1();
void afterA1(string menuSelection);
void a100();
void a167();

// start the book!
int main()
{
  // program greeting
  sayHi();
  a1();
}

void sayHi()
{
  cout << "Welcome to Butler to the Dark Lord, a text adventure!\n\n";
}

string generalMenu()
{
  string menuSelection;
  cout << "Enter your choice by number or first word.\n";
  cin >> menuSelection;
  return menuSelection;
}

string raiseItAll(string menuSelection)
{
	for (int count = 0; count <= static_cast<int>(menuSelection.length()); count ++)
		menuSelection[count] = toupper(menuSelection[count]);
	return menuSelection;
}

bool checkA1(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "2" || checkIt == "IT'S" || checkIt == "SURELY")
    acceptSelection = true;
  return acceptSelection;
}

void a1()
{
  bool acceptSelection;
  string menuSelection;
  cout << "Here is the story for A1.\n";
  cout << "1/It's is A100, 2/Surely is A167.\n";
  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA1(menuSelection);
  } while (!acceptSelection);
  afterA1(menuSelection);
}

void afterA1(string menuSelection)
{
  if (menuSelection == "1" || menuSelection == "IT'S")
    a100();
  else
    a167();
}

void a100()
{
  cout << "a100\n";
}

void a167()
{
  cout << "a167\n";
}
