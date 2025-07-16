#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;
const int NUM_SUBJECTS = 5;
const int TOTAL_SEMESTERS = 4;

struct Student {
    string name;
    int rollNo;
    string department;
    string university;
    string city;
    string country;
    string contactNumber;

    float currentSemesterMarks[NUM_SUBJECTS];       // Marks in current semester
    string subjectStatus[NUM_SUBJECTS];              // Pass/Fail status
    float allSemesterMarks[TOTAL_SEMESTERS][NUM_SUBJECTS]; // All semester marks
};

// Function to input data for a single student
void inputStudent(Student& s) {
    cout << "\nEnter student details:\n";
    cout << "Name: ";
    getline(cin, s.name);

    cout << "Roll Number: ";
    cin >> s.rollNo;
    cin.ignore();

    cout << "Department: ";
    getline(cin, s.department);

    cout << "University: ";
    getline(cin, s.university);

    cout << "City: ";
    getline(cin, s.city);

    cout << "Country: ";
    getline(cin, s.country);

    cout << "Contact Number: ";
    getline(cin, s.contactNumber);

    // Current Semester Marks and Status
    cout << "\nEnter marks for current semester subjects (out of 100):\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> s.currentSemesterMarks[i];
        s.subjectStatus[i] = (s.currentSemesterMarks[i] >= 40) ? "Pass" : "Fail";
    }

    // All Semesters Marks
    cout << "\nEnter marks for " << TOTAL_SEMESTERS << " semesters (each with " << NUM_SUBJECTS << " subjects):\n";
    for (int sem = 0; sem < TOTAL_SEMESTERS; sem++) {
        cout << "Semester " << (sem + 1) << ":\n";
        for (int sub = 0; sub < NUM_SUBJECTS; sub++) {
            cout << "  Subject " << (sub + 1) << ": ";
            cin >> s.allSemesterMarks[sem][sub];
        }
    }
    cin.ignore(); // Clear buffer
}

// Function to display data of a single student
void displayStudent(const Student& s) {
    cout << "\n=== Student Information ===\n";
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNo << endl;
    cout << "Department: " << s.department << endl;
    cout << "University: " << s.university << endl;
    cout << "City: " << s.city << endl;
    cout << "Country: " << s.country << endl;
    cout << "Contact Number: " << s.contactNumber << endl;

    cout << "\nCurrent Semester Marks:\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Subject " << (i + 1) << ": " << s.currentSemesterMarks[i]
             << " (" << s.subjectStatus[i] << ")\n";
    }

    cout << "\nAll Semester Marks:\n";
    for (int sem = 0; sem < TOTAL_SEMESTERS; sem++) {
        cout << "Semester " << (sem + 1) << ": ";
        for (int sub = 0; sub < NUM_SUBJECTS; sub++) {
            cout << s.allSemesterMarks[sem][sub] << " ";
        }
        cout << endl;
    }
}

// Main program
int main() {
    Student students[MAX_STUDENTS];
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    if (numStudents > MAX_STUDENTS) {
        cout << "Limit exceeded! Max students allowed: " << MAX_STUDENTS << endl;
        return 1;
    }

    // Input all students
    for (int i = 0; i < numStudents; i++) {
        cout << "\n--- Student #" << (i + 1) << " ---";
        inputStudent(students[i]);
    }

    // Display all students
    for (int i = 0; i < numStudents; i++) {
        displayStudent(students[i]);
    }

    return 0;
}
