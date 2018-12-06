// Specification C4 - GPA Advice
// Provide a letter grade and comment on how the student is doing.

//Specification B2 - Drop Lowest
// Professor Zak will drop the lowest 3 test scores from the GPA calculation, but only if there are 4 tests or more.

// Specification B3 - Signify Dropped
// Include the dropped tests when printing out all the test scores for the student, but signify if the test was dropped by displaying "DROPPED" next to the score.

// Specification A1 - Main Student Loop
// Up to this point, you can code this so you need to rerun it for each student. Now, expand the program and allow Professor Zak to enter the number of students in her class. She will then enter all the data during one program run. Generate the outputs as earlier for each student.

// Specification A3 - Class Stats
//Compute the overall score for the class for each test.

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <functional>
using namespace std;

class Zak
{
private:
  int i,
    j,
    k,
    students,
    quizzes;
  string* names;
  int** grades;

public:
  void sayHi();
  void getStudents();
  void getQuizzes();
  void gradeArray();
  void getNames();
  void getGrades();
  void printStudentGrades();
  void deleteArray();
};

int main() {
	Zak grades;

  grades.sayHi();
  grades.getStudents();
  grades.getQuizzes();
  grades.gradeArray();
  grades.getNames();
  grades.getGrades();
  grades.printStudentGrades();
  grades.deleteArray();

  return 0;
}

void Zak::sayHi()
{
  system("clear");

// program greeting
  cout << "Hello Professor Zak! It must be time to enter some grades!\n\n";
}

// get the number of students
// Specification A2 - Number of Students Prompt
void Zak::getStudents()
{
  cout << "\nHow many students are there? ";
  cin >> students;
}

// get the number of quizzes
void Zak::getQuizzes()
{
  cout << "How many quizzes did they take? ";
  cin >> quizzes;
}

// initialize a string array for names
// initialize an int array for grades (student by quiz)

// Specification B1 - Pseudo Dynamic Array
void Zak::gradeArray()
{
// 1D array
  names = new string[students];

// 2D array
  grades = new int*[students];

  for (i = 0; i < students; i++)
    grades[i] = new int[quizzes];
}

void Zak::getNames()
{
  int spaces;
  string studentName;
  cout << "\n";
  cin.ignore();
  for (i = 0; i < students; i++)
  {
    spaces = 0;

// Specification C2 - Student Name
    cout << "Enter student " << i + 1 << "'s first and last name: ";
    do {
      getline(cin, studentName);

      for (j = 0; j < static_cast<int>(studentName.length()); j++)
      {
        if (studentName[j] == ' ')
          spaces++;
      }

      if (spaces != 1)
      {
        cout << "\nShouldn't there be a space between first and last names?\n";
        cout << "What's student " << i + 1 << "'s first and last name? ";
      }
    } while(spaces != 1);
    names[i] = studentName;

//    cout << "Enter student " << i + 1 << "'s name: ";
  //  cin >> names[i];
  }
}

// input grades for each student and quiz
void Zak::getGrades()
{
  for(i = 0; i < students; i++)
  {
    cout << "\nEnter grades for " << names[i] << ".\n";
    for(j = 0; j < quizzes; j++)
    {
      cout << "Quiz #" << j + 1 << " ";
      do {
        cin >> grades[i][j];

// Specification C3 - Grade Input Validation
        if (grades[i][j] < 0 || grades[i][j] > 100)
          cout << "\nShouldn't the grade be from 0 to 100? Try again.\n";
      } while(grades[i][j] < 0 || grades[i][j] > 100);
    }
  }
}

// Display the number of tests, the score for each test and the average grade for the class for each student.
// Specification C1 - Student Summary
void Zak::printStudentGrades()
{
  float totalpoints;
  float average;

  // temp array to sort quiz numbers
  int* tempQuiz = new int[quizzes];

  // temp array to sort quiz scores
  int* tempSort = new int[quizzes];
  int temp;
  int flag = 1;

  // iterate thru every student
  for (i = 0; i < students; i++)
  {
    totalpoints = 0;

    // print student name and number of quizzes
    cout << "\n" << names[i] << " (" << quizzes << " quizzes):\n";
    for (j = 0; j < quizzes; j++)
    {
      tempQuiz[j] = j;
      tempSort[j] = grades[i][j];
    }

    // not the prettiest, but sorting two separate arrays works
    // one array is quiz number, one is quiz score
    // Specification B4 – Sorted Output
    for (int x = 0; x < quizzes && flag; x++)
    {
      for (int y = 0; y < quizzes; y++)
      {
        if (tempSort[y+1] > tempSort[y])
        {
          temp = tempSort[y];
          tempSort[y] = tempSort[y+1];
          tempSort[y+1] = temp;

          temp = tempQuiz[y];
          tempQuiz[y] = tempQuiz[y+1];
          tempQuiz[y+1] = temp;
        }
      }
    }


    for (int x = 0; x < quizzes; x++)
    {
      cout << "Quiz #" << tempQuiz[x] + 1 << ": " << tempSort[x] << "\t";
      totalpoints += tempSort[x];
    }
/*
      cout << "Quiz " << j + 1 << ": " << grades[i][j] << "\t";
      totalpoints += grades[i][j];
    } */
    average = totalpoints / quizzes;
    cout << "Average: " << average << "\n";
  }
  delete[] tempSort;
}

void Zak::deleteArray()
{
  for (i = 0; i < students; i++)
  {
    delete[] grades[i];
  }

  delete[] grades;

  delete[] names;
}
