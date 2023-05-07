#pragma once

#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:

	// declare class object constructors
	Student();
	Student(string studentID, string firstName, string lastName, string email,
		int age, int courseDays1, int courseDays2, int courseDays3, Degree degreeType);
	Student(const Student& origObject);

	// declare class object destructor
	~Student();

	// declare accessor and mutator functions
	void setStudentID(string id);
	string getStudentID();

	void setFirstName(string first);
	string getFirstName();

	void setLastName(string last);
	string getLastName();

	void setEmail(string email);
	string getEmail();

	void setAge(int age);
	int getAge();

	void setCourseDays1(int day1);
	int getCourseDays1();

	void setCourseDays2(int day2);
	int getCourseDays2();

	void setCourseDays3(int day3);
	int getCourseDays3();

	void setDaysToComplete(int days);
	int* getDaysToComplete();

	void setProgram(Degree degreeType);
	Degree getProgram();
	void printDegreeType();

	// declare object print method
	void print();

public:

	// create and assign number of values for days to complete array
	const static int numDaySetsToComplete = 3;


private:

	// declare object attribute variables
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int courseDays1;
	int courseDays2;
	int courseDays3;
	int daysToCompleteCounter = 0;
	int daysToComplete[numDaySetsToComplete];
	Degree enumDegreeType;
};
