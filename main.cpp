#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;

int main() {
    //F1: Print out my info
    cout << "C867-Scripting & Programming: Applications\n"
         << "Language:  C++\n"
         << "Student ID: 012119454\n"
         << "Name:      Noah Keenan\n";

    //F2: Created class roster
    Roster* studentRoster = new Roster();

    studentRoster->printAll();
    studentRoster->printInvalidEmails();

    for (int i = 0; i < 5; ++i) { //F4: Loop thru array
        Student s = studentRoster->findStudent(i);
        studentRoster->printAverageDaysInCourse(s.GetStudentId());
    }

     cout << "Displaying all software students:" << endl;
    studentRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    

    studentRoster->remove("A3");
    studentRoster->printAll();
    studentRoster->remove("A3");

    for (char exitSign = 'a'; exitSign != 'e'; ) {
        cout << "\npress 'e' to exit...";
        cin >> exitSign;
        cout << endl << endl;
    }

    delete studentRoster; // F5: Free allocated memory
    return 0;
}
