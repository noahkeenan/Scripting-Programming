#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "roster.h"

using namespace std;

// B: Modified student data table with my information.
Roster::Roster() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Noah,Keenan,nkeena3@wgu.edu,23,66,19,34,SOFTWARE"
	};

	classRosterArray = new Student[5];

	for (int i = 0; i < numStudents; ++i) {
		istringstream iss(studentData[i]);
		string token;
		vector<string> tokens;
		while (getline(iss, token, ',')) {
			tokens.push_back(token);
		}

		string studentID = tokens[0];
		string firstName = tokens[1];
		string lastName = tokens[2];
		string emailAddress = tokens[3];
		int age = stoi(tokens[4]);
		int daysInCourse1 = stoi(tokens[5]);
		int daysInCourse2 = stoi(tokens[6]);
		int daysInCourse3 = stoi(tokens[7]);
		string type = tokens[8];

		DegreeProgram dp;
		if (type == "NETWORK") {
			dp = DegreeProgram::NETWORK;
		} else if (type == "SECURITY") {
			dp = DegreeProgram::SECURITY;
		} else if (type == "SOFTWARE") {
			dp = DegreeProgram::SOFTWARE;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
	}

	this->lastIndex = 0;
}

Roster::~Roster() {
	cout << "Roster destructor has been invoked" << endl;
	delete[] classRosterArray;
}

//E2A: PARSED DATA
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, 
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type) {
	Student* s = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, type);
	classRosterArray[lastIndex++] = *s;
	cout << endl << "Student added!" << endl;
}

void Roster::remove(string studentID) {
	cout << endl;
	bool found = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() == studentID) {
			cout << "Deleting: " << classRosterArray[i].GetStudentId() << endl;
			classRosterArray[i].SetStudentId("invalid");
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Unable to locate student" << endl;
	}
}

void Roster::printAll() {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() != "invalid") {
			cout << "   ";
			classRosterArray[i].print();
		}
	}
}

void Roster::printInvalidEmails() {
	cout << endl << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArray[i].GetEmailAddress();
		if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
			cout << "\t" << email << endl;
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetStudentId() == studentID) {
			cout << "Student-ID: " << classRosterArray[i].GetStudentId();
			int* tempDays = classRosterArray[i].GetDaysInCourse();
			int avgDays = 0;
			for (int j = 0; j < 3; ++j) {
				avgDays += tempDays[j];
			}
			cout << "\tAverage Days to Complete Course: " << avgDays / 3 << endl << endl;
			return;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	int numberMatches = 0;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i].GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			classRosterArray[i].print();
		}
	}
}

Student Roster::findStudent(int index) {
	return classRosterArray[index];
}
