// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> scores;
};

void addStudent(vector<Student>& s)
{
    Student st;
    int n;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, st.name);

    cout << "Enter ID: ";
    cin >> st.id;

    cout << "How many scores? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double score;
        cout << "Score " << i + 1 << ": ";
        cin >> score;
        st.scores.push_back(score);
    }

    s.push_back(st);
}

void displayStudents(vector<Student> s)
{
    if (s.size() == 0)
    {
        cout << "No students.\n";
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        double sum = 0;

        cout << "\nName: " << s[i].name << endl;
        cout << "ID: " << s[i].id << endl;
        cout << "Scores: ";

        for (int j = 0; j < s[i].scores.size(); j++)
        {
            cout << s[i].scores[j] << " ";
            sum += s[i].scores[j];
        }

        cout << "\nAverage: "
             << fixed << setprecision(2)
             << sum / s[i].scores.size() << endl;
    }
}

void averageStudent(vector<Student> s)
{
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].id == id)
        {
            double sum = 0;

            for (int j = 0; j < s[i].scores.size(); j++)
            {
                sum += s[i].scores[j];
            }

            cout << "Average = "
                 << fixed << setprecision(2)
                 << sum / s[i].scores.size() << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

int main()
{
    vector<Student> students;
    int choice;

    while (choice != 4)
    {
        cout << "\n1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Average Score\n";
        cout << "4. Quit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent(students);
        else if (choice == 2)
            displayStudents(students);
        else if (choice == 3)
            averageStudent(students);
        else if (choice == 4)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice!\n";
    }

    return 0;
}