#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using std::string;

class Student {
public:
    Student();
    Student(string studentId, string firstName, string lastName, string emailAddress, int age,
            int dIC1, int dIC2, int dIC3, DegreeProgram type);
    ~Student();

    string GetStudentId();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram();

    void SetStudentId(string studentId);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysCourseComplete(int* daysInCourse);

    void print();

private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* daysInCourse;
    DegreeProgram degreeProgram;
};

#endif // STUDENT_H
