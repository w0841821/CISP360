// name
// date
// CISP360
//

#include <iostream>
using namespace std;

// prototypes
void a1();
void a13();
void a100();
void a159();
void a161();
void a167();
void a173();
void a212();
void a232();
void a290();

int main()
{
  a1();
  return 0;
}

void a1()
{
  int choiceA1;

  cout << "\nHere is A1.\n\n";

  cout << "1. Call A100\n";
  cout << "2. Call A167\n";

  do {
    cout << "\nWhich path is yours?\n";
    cin >> choiceA1;
  } while(choiceA1 != 1 && choiceA1 != 2);

  if (choiceA1 == 1)
    a100();
  else
    a167();
}

void a13()
{
  int choiceA13;

  cout << "\nHere is A13.\n\n";

  cout << "1. Call A212.\n";
  cout << "2. Call A159.\n";
  cout << "3. Call A173.\n";

  do {
    cout << "Which path is yours?\n";
    cin >> choiceA13;
  } while(choiceA13 != 1 && choiceA13 != 2 && choiceA13 != 3);

  if (choiceA13 == 1)
    a212();
  else if (choiceA13 == 2)
    a159();
  else
    a173();
}

void a100()
{
  int choiceA100;

  cout << "\nHere is A100.\n\n";

  cout << "1. Continue to A232\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA100;
  } while(choiceA100 != 1);

  a232();
}

void a159()
{
  int choiceA159;

  cout << "Here is A159.\n\n";

  cout << "1. Done.\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA159;
  } while(choiceA159 != 1);

  cout << "\nThe end.";
}

void a161()
{
  int choiceA161;

  cout << "Here is A161.\n\n";

  cout << "1. Done.\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA161;
  } while(choiceA161 != 1);

  cout << "\nThe end.";
}

void a167()
{
  int choiceA167;

  cout << "\nHere is A167.\n\n";

  cout << "1. Continue to A232\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA167;
  } while(choiceA167 != 1);

  a232();
}

void a173()
{
  int choiceA173;

  cout << "Here is A173.\n\n";

  cout << "1. Done.\n";
  cout << "2. Done.\n";

  do {
    cout << "\nWhich path is yours?\n";
    cin >> choiceA173;
  } while(choiceA173 != 1 && choiceA173 != 2);

  cout << "\nThe end.";
}

void a212()
{
  int choiceA212;

  cout << "Here is A212.\n\n";

  cout << "1. Call A161.\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA212;
  } while(choiceA212 != 1);

  a161();
}

void a232()
{
  int choiceA232;

  cout << "\nHere is A232.\n\n";

  cout << "1. Call A13.\n";
  cout << "2. Call A290.\n";

  do {
    cout << "\nWhich path is yours?\n";
    cin >> choiceA232;
  } while(choiceA232 != 1 && choiceA232 != 2);

  if (choiceA232 == 1)
    a13();
  else
    a290();
}

void a290()
{
  int choiceA290;

  cout << "Here is A290.\n\n";

  cout << "1. Call A161.\n";

  do {
    cout << "\nOnly one path lies ahead.\n";
    cin >> choiceA290;
  } while(choiceA290 != 1);

  a161();
}
