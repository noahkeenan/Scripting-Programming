#include <string>
#include <iostream>
#include "student.h"

using namespace std;

//D1: Created student class with all necessary variables
Student::Student() : studentId(""), firstName(""), lastName(""), emailAddress(""), age(0), daysInCourse(new int[3]) {}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int dIC1, int dIC2, int dIC3, DegreeProgram type) 
    : studentId(studentId), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), daysInCourse(new int[3]), degreeProgram(type) {
    daysInCourse[0] = dIC1;
    daysInCourse[1] = dIC2;
    daysInCourse[2] = dIC3;
}

Student::~Student() {
    delete[] daysInCourse;
}

// D2A: Created accessors for each variable
string Student::GetStudentId() { return studentId; }

string Student::GetFirstName() { return firstName; }

string Student::GetLastName() { return lastName; }

string Student::GetEmailAddress() { return emailAddress; }

int Student::GetAge() { return age; }

int* Student::GetDaysInCourse() { return daysInCourse; }

DegreeProgram Student::GetDegreeProgram() { return degreeProgram; }

// D2B: Created mutators for each variable
void Student::SetStudentId(string studentId) { this->studentId = studentId; }

void Student::SetFirstName(string firstName) { this->firstName = firstName; }

void Student::SetLastName(string lastName) { this->lastName = lastName; }

void Student::SetEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }

void Student::SetAge(int age) { this->age = age; }
//D2D: Parameter constructor
void Student::SetDaysCourseComplete(int* dIC) {
    daysInCourse[0] = dIC[0];
    daysInCourse[1] = dIC[1];
    daysInCourse[2] = dIC[2];
}

//D2E: Print specific data
void Student::print() {
    int* tempdays = GetDaysInCourse();
    string dPStr = "Software";
    if (GetDegreeProgram() == DegreeProgram::NETWORK) dPStr = "Network";
    if (GetDegreeProgram() == DegreeProgram::SECURITY) dPStr = "Security";
    
    cout << "\t Student ID: " << GetStudentId()
         << "\t First Name: " << GetFirstName()
         << "\t Last Name: " << GetLastName()
         << "\t Student Age: " << GetAge();
    
    cout << "\t Days In Course: {" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}";
    cout << "\t Degree Program: " << dPStr << "." << endl;
}