// Specification C1 - Student Summary
// Display the number of tests, the score for each test and the average grade for the class for each student.

// Specification C2 - Student Name
// Allow name to accept first plus last name (ie 2 words).

// Specification C3 - Grade Input Validation
// Range test the input data for the grades (0 to 100 points possible).

// Specification C4 - GPA Advice
// Provide a letter grade and comment on how the student is doing.

// Specification B1 - Pseudo Dynamic Array
// Prompt Professor Zak for the number of quizzes at the start of the program and then create the appropriately sized array.

//Specification B2 - Drop Lowest
// Professor Zak will drop the lowest 3 test scores from the GPA calculation, but only if there are 4 tests or more.

// Specification B3 - Signify Dropped
// Include the dropped tests when printing out all the test scores for the student, but signify if the test was dropped by displaying "DROPPED" next to the score.

// Specification B4 – Sorted Output
// Sort the output scores from highest to lowest score. Put this specification comment right above your sorting code.

// Specification A1 - Main Student Loop
// Up to this point, you can code this so you need to rerun it for each student. Now, expand the program and allow Professor Zak to enter the number of students in her class. She will then enter all the data during one program run. Generate the outputs as earlier for each student.

// Ask Professor Zak to enter the number of students in her class. This will drive the main student loop.

// Specification A3 - Class Stats
//Compute the overall score for the class for each test.

#include <iostream>
#include <string>
using namespace std;

class Zak
{
private:
  int i,
  j,
  students,
  quizzes;
  string** grades;

public:
  void sayHi();
  void getStudents();
  void getQuizzes();
  void allocateArray();
  void getGrades();
  void printGrades();
  void deleteArray();
};

int main() {
	Zak grades;

  grades.sayHi();
  grades.getStudents();
  grades.getQuizzes();
  grades.allocateArray();
  grades.getGrades();
  grades.printGrades();
  grades.deleteArray();

  return 0;
}

void Zak::sayHi()
{
  system("clear");

// program greeting
  cout << "Hello Professor Zak! It must be time to enter some grades!\n\n";
}

// Specification A2 - Number of Students Prompt
void Zak::getStudents()
{
  cout << "\nStudents? ";
  cin >> students;
}

void Zak::getQuizzes()
{
  cout << "\nQuizzes? ";
  cin >> quizzes;
}

void Zak::allocateArray()
{
  grades = new string*[students];
  for(i = 0; i < students; i++)
    grades[i] = new string[quizzes];
}

void Zak::getGrades()
{
  for(i = 0; i < students; i++)
  {
    cout << "Enter for student #" << i << "\n";
    for(j = 0; j < quizzes; j++)
    {
      cout << "\nQuiz #" << j << " ";
      cin >> grades[i][j];
    }
  }
}

void Zak::printGrades()
{
  for (i = 0; i < students; i++)
  {
    cout << "Student #" << i << "\n";
    for (j = 0; j < quizzes; j++)
    {
      cout << "Quiz #" << j << "\n";
      cout << grades[i][j] << "\n";
    }
  }
}

void Zak::deleteArray()
{
  for (i = 0; i < students; i++)
  {
    delete[] grades[i];
  }

  delete[] grades;
}
