#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;


class Roster {
public:
     Roster();
   ~Roster();
    //E3A-F: Print functions
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, 
             int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student findStudent(int index);

private:
    int lastIndex;
    int maxSize;
    Student* classRosterArray;
};

#endif // ROSTER_H
