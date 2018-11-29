#include <iostream>
#include <string>
using namespace std;

int numStudents();
int numQuizzes();
void getStudentNames(int &);

int main()
{
	int students = numStudents();
	int student[students];
	
	int quizzes = numQuizzes();
	int quiz[quizzes];
	
	cout << "Students: " << students << "\n";
	cout << "Quizzes: " << quizzes << "\n";
	
	getStudentNames(students);
	
	return 0;
}

int numStudents()
{
	int students;
	
	cout << "\nStudents? ";
	cin >> students;
	
	return students;
}

int numQuizzes()
{
	int quizzes;
	
	cout << "\nQuizzes? ";
	cin >> quizzes;
	
	return quizzes;
}

void getStudentNames(int &students)
{
	string studentName[students];
	
	for (int i = 0; i < students; i++)
	{
		cout << "What is student #" << i + 1 << "'s name? ";
		cin >> studentName[i];
	}
	
	for (int i = 0; i < students; i++)
	{
		cout << "Student #" << i + 1 << ": " << studentName[i] << "\n";
	}
}

		