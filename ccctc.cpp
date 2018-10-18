/* 
Prompt for the object to calculate the temperature for. Note: This is NOT a menu! The client is expected to enter the proper words.

Ask for the temperature of the object in Fahrenheit. Check to see if it’s in the proper range.

Create a menu of valid temperature scales to select from. Selecting the scale option will immediately display the converted temperature.
Include an option to calculate the temperature for ALL the options.

Re-prompt if incorrect data was entered. Keep re-prompting until the client get’s it right.

cat 86-102 F
cot 54-80 F
cap 72-88 F

// Specification C1 – Only Valid Words
We only want to accept valid words cat, cap, cot no matter how
they are spelled (ie Cat, CAT, caT all Ok too).

// Specification C2 – Temp Scale Menu
This menu shows us what temperatures we can convert to. This
can be a numeric menu.

// Specification C3 – Valid Scale Menu Check
Only allow valid menu options to be entered. Give the client feed-
back if it’s wrong and re-prompt.

// Specification B1 – Floats for Temps
Allow the client to enter a decimal temperature.

// Specification B2 – Valid Temps Only
Make sure the user can input the temperatures only within a valid range. If out of range, tell them (too high, too low) and re-prompt.
Temperatures must be valid floats with in the proper range. We can accept an error of less than 0.2 degrees.
Example: a valid temperature for a cat will be 102.2, but 102.3 will not.

// Specification B3 – Fancy Output
Restrict output to 3 significant digits, always. Have the temperatures line up on the decimals. I want to see xx.xx0 as well as yy.123 output

// Specification A1 – Sophisticated Word Check
Your validation check can only test against 3 lowercase words: cat, cot, cop. Yet, somehow, you must still address the issue of our
client entering any combination of upper and lower case letters.

// Specification A2 – Another Thing
Add another thing (dog as well as cat, etcetera). Modify the program to process it correctly.

// Specification A3 – Another Temperature Scale
Add another temperature scale. You will be amazed at how many other scales there are out there.

// Specification A?? - <Brief Description>
Replace either A2 or A3 with a feature of your own devising. This can be a technique you want to try out, something from a chapter
we haven’t covered yet or an extension of what’s already here. The choice is yours. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// prototypes
string pickObject(string nameObject);
string lowerItAll(string nameObject);
bool checkObject(string nameObject);
bool checkTemp(string nameObject);
void runTemps(string nameObject, float tempObject);
void tempMenu();
int getTempScale();

string nameObject;
bool acceptObject,
	acceptTemp;
float tempObject;
int tempScale;

int main()
{
	// Loop until client enters a valid object
	do
	{
		// Get the object we're dealing with
		nameObject = pickObject(nameObject);

		// Convert it to all lowercase for ease of checking
		nameObject = lowerItAll(nameObject);

		// Check that we are using a valid object, and print the temperature range also
		acceptObject = checkObject(nameObject);
	} while (!acceptObject);

	// Loop until client enters a valid temperature
	do
	{
		cout << "What is the " << nameObject << "'s temperature in Fahrenheit?\n";
		cin >> tempObject;

		// Check that the temperature is within range
		acceptTemp = checkTemp(nameObject);
	} while (!acceptTemp);

	tempMenu();
	tempScale = getTempScale();

	switch (tempScale)
	{
		case 1:
		case 2:
		case 3:
		case 4:
	}

	runTemps(nameObject, tempObject);

	return 0;
}

// Get the object we're dealing with
string pickObject(string nameObject)
{
	cout << "Are we dealing with the: cap, cat, cot, or lizard?\n";
	cin >> nameObject;
	return nameObject;
}

// function to convert to lowercase, so picky to code!
string lowerItAll(string nameObject)
{
	for (int count = 0; count <= static_cast<int>(nameObject.length()); count ++)
		nameObject[count] = tolower(nameObject[count]);

	return nameObject;
}

// Check that we are using a valid object, and print the temperature range also
bool checkObject(string nameObject)
{
	if (nameObject == "cap")
	{
		cout << "\nThe correct temperature range for the cap is 72 to 88 degrees F.\n";
		acceptObject = true;
	}
	else if (nameObject == "cat")
	{
		cout << "\nThe correct temperature range for the cat is 86 to 102 degrees F.\n";
		acceptObject = true;
	}
	else if (nameObject == "cot")
	{
		cout << "\nThe correct temperature range for the cot is 54 to 80 degrees F.\n";
		acceptObject = true;
	}
	else if (nameObject == "lizard")
	{
		cout << "\nThe correct temperature range for the lizard is 75 to 95 degrees F.\n";
		acceptObject = true;
	}
	else
	{
		cout << "\nThat's not a valid entry. Try again.\n";
		acceptObject = false;
	}
	return acceptObject;
}

// Check that the temperature is within range
bool checkTemp(string nameObject)
{
	if (nameObject == "cap")
	{
		if (tempObject >= 72 && tempObject <= 88)
			acceptTemp = true;
		else
		{
			acceptTemp = false;
			cout << "\nThat's not a temperature within range (72-88). Try again.\n";
		}
	}
	else if (nameObject == "cat")
	{
		if (tempObject >= 86 && tempObject <= 102)
			acceptTemp = true;
		else
		{
			acceptTemp = false;
			cout << "\nThat's not a temperature within range (86-102). Try again.\n";
		}
	}
	else if (nameObject == "cot")
	{
		if (tempObject >= 54 && tempObject <= 80)
			acceptTemp = true;
		else
		{
			acceptTemp = false;
			cout << "\nThat's not a temperature within range (54-80). Try again.\n";
		}
	}
	else
	{
		if (tempObject >= 75 && tempObject <= 95)
			acceptTemp = true;
		else
		{
			acceptTemp = false;
			cout << "\nThat's not a temperature within range (75-95). Try again.\n";
		}
	}
	return acceptTemp;
}

void tempMenu()
{
	cout << "\nWhich temperature scale would you like to convert to?\n";
	cout << "1. Celsius\n";
	cout << "2. Kelvin\n";
	cout << "3. Rankine\n";
	cout << "4. All of the above\n";
}

int getTempScale()
{
	cin >> tempScale;
	while (tempScale < 1 || tempScale >4)
	{
		cout << "That's not a valid selection. Try again.\n";
		cin >> tempScale;
	}
	cout << fixed << setprecision(3);
	cout << left << setw(20) << "\nTemperature Scale" << right << setw(12) << "Temperature\n";
	cout << "-------------------------------\n";
	return tempScale;
}

void runTemps(string nameObject, float tempObject)
{
	cout << nameObject << " and " << tempObject;
}