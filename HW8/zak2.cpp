#include <iostream>
#include <string>
using namespace std;

// void getZak(int, int);

class Zak
{
	private:
//		const int COLS = students;
//		const int ROWS = quizzes;

		int students,
			quizzes;

	public:
//		void start();
//		string grades[students][quizzes];
		void sayHi();
		void numStudents();
		void numQuizzes();
//		void printGrades();
		void getZak();
};

int main()
{
	Zak grades;
	grades.sayHi();
	grades.numStudents();
	grades.numQuizzes();
//	grades.printGrades();
	grades.getZak();
	//string grades[students][quizzes];
	return 0;
}

void Zak::sayHi()
{
	cout << "\nWelcome to your grading program, Professor Zak!\n\n";
}

void Zak::numStudents()
{
	cout << "\nStudents? ";
	cin >> students;
}

void Zak::numQuizzes()
{
	cout << "\nQuizzes? ";
	cin >> quizzes;
}
/*
void Zak::printGrades()
{
	int i,
		j;

	for (i = 0; i < students; i++)
	{
		j = 0;
		cout << "Stud: " << i;
		for (j = 0; j < quizzes; j++)
		{
			cout << "Quiz: " << j;
		}
	}
}
*/
void Zak::getZak()
{
	int i;
//		j = 0;
	string** grades = nullptr;

	grades = new string*[students];
	for (i = 0; i < students; students++)
	{
		grades[i] = new string[quizzes];
	}

	cout << "We have " << students << " students, and " << quizzes << " quizzes.\n";
/*
	for (i = 0; i < students; i++)
	{
		cout << "What is student #" << i + 1 << "'s name? ";
		cin >> grades[i][j];

		cout << "What was their grade for quiz #...\n";
		for (j = 0; j < quizzes; j++)
		{
			cout << j + 1;
			cin >> grades[i][j];
		}
	}
*/
	for (i = 0; i < students; i++)
		delete [] grades[i];
	delete [] grades;
}
