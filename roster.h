#pragma once

#include "student.h"

class Roster {
public:

	// declare constructors
	Roster();
	Roster(const Roster& objToCopy);
	~Roster();

	// declare member functions
	void extractData(string element);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysToComplete1, int daysToComplete2, int daysToComplete3, Degree degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	Student* getRosterElement(int index);
	int getRemainingNum();
	Degree translateDegree(string degreeType);
	

public:

	// declare and initialize total students in roster
	int static const numStudents = 5;

private:

	// declare and initialize class variables
	int indexes = 0;
	Student* classRosterArray[numStudents];
	string degreePrograms[4] = { "SECURITY", "NETWORK", "SOFTWARE", "UNKNOWN" };
};