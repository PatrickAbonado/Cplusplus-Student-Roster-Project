#pragma once

#include "student.h"

// initialize default constructor
Student::Student() {
	studentID = "none";
	firstName = "none";
	lastName = "none";
	email = "none";
	age = 0;
	courseDays1 = 0;
	courseDays2 = 0;
	courseDays3 = 0;
	daysToComplete[0] = courseDays1;
	daysToComplete[1] = courseDays2;
	daysToComplete[2] = courseDays3;
	enumDegreeType = UNKNOWN;
}

// constructor that assigns attributes with argument values
Student::Student(string studentID, string firstName, string lastName, string email,
	int age, int courseDays1, int courseDays2, int courseDays3, Degree degreeType) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->courseDays1 = courseDays1;
	this->courseDays2 = courseDays2;
	this->courseDays3 = courseDays3;
	this->daysToComplete[0] = courseDays1;
	this->daysToComplete[1] = courseDays2;
	this->daysToComplete[2] = courseDays3;
	this->enumDegreeType = degreeType;
}

// copy constructor
Student::Student(const Student& origObject) {
	Student* student = new Student;
	student->studentID = origObject.studentID;
	student->firstName = origObject.firstName;
	student->lastName = origObject.lastName;
	student->email = origObject.email;
	student->age = origObject.age;
	student->courseDays1 = origObject.courseDays1;
	student->courseDays2 = origObject.courseDays2;
	student->courseDays3 = origObject.courseDays3;
	student->daysToComplete[0] = origObject.courseDays1;
	student->daysToComplete[1] = origObject.courseDays2;
	student->daysToComplete[2] = origObject.courseDays3;
	student->enumDegreeType = origObject.enumDegreeType;
}

// message output when destructor called
Student::~Student() {
	cout << "\nStudent with Id: " << studentID << " deleted from memory\n";
}

// mutator and accessor method definitions
void Student::setStudentID(string id) { this->studentID = id; }
string Student::getStudentID() { return studentID; }

void Student::setFirstName(string first) { this->firstName = first; }
string Student::getFirstName() { return firstName; }

void Student::setLastName(string last) { this->lastName = last; }
string Student::getLastName() { return lastName; }

void Student::setEmail(string email) { this->email = email; }
string Student::getEmail() { return email; }

void Student::setAge(int age) { this->age = age; }
int Student::getAge() { return age; }

void Student::setCourseDays1(int day1) { this->courseDays1 = day1; }
int Student::getCourseDays1() { return courseDays1; }

void Student::setCourseDays2(int day2) { this->courseDays1 = day2; }
int Student::getCourseDays2() { return courseDays2; }

void Student::setCourseDays3(int day3) { this->courseDays1 = day3; }
int Student::getCourseDays3() { return courseDays3; }

void Student::setDaysToComplete(int days) {

	// reset counter if counter is greater than 2
	if (daysToCompleteCounter > 2) {
		daysToCompleteCounter = 0;
	}

	// assign course days totals to index in days to complete array
	this->daysToComplete[daysToCompleteCounter] = days;

	++daysToCompleteCounter;
	
}

int* Student::getDaysToComplete() { return daysToComplete; }

void Student::setProgram(Degree degreeType) { this->enumDegreeType = degreeType; }
Degree Student::getProgram() { return enumDegreeType; }

// method to print object enum degree type
void Student::printDegreeType() {
	switch (enumDegreeType) {
	case SECURITY:
		cout << "SECURITY";
		break;
	case NETWORK:
		cout << "NETWORK";
		break;
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
	default:
		cout << "UNKNOWN";
	}
}

// method to print student information
void Student::print() {
	cout << "Student ID: " << studentID << setw(29) <<  "Full Name: " << firstName << " " << lastName
		<< "\nAge: " << age << setw(32) << "Email: " << email << "\nDegree Type:  ";
	printDegreeType();

	cout << "\t\tDays To Complete : ";

	// iterate to print out array values
	for (int i = 0; i < numDaySetsToComplete; ++i) {
		if (i < numDaySetsToComplete - 1) {
				cout << daysToComplete[i] << ", ";
		}
		else {
				cout << daysToComplete[i];
		}
	}

	cout << endl << endl;

}