#include <string>
#include "roster.h"

int main() {
	// declare and initialize counter variable
	int i = 0;

	// output header message
	cout << "\nC-867\n" << "Scripting and Programming Applications\n"
		<< "C++\n" << "003619914\n" << "Patrick Abonado\n\n";

	// create roster object
	Roster classRoster;

	// student data array
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Patrick,Abonado,pabonad@wgu.edu,41,60,60,60,SOFTWARE" };

	// add students from data set to the roster
	for (i = 0; i < Roster::numStudents; ++i) {
		classRoster.extractData(studentData[i]);
	}

	// output all students' information on the roster
	classRoster.printAll();

	// output all invalid emails
	classRoster.printInvalidEmails();

	// print each student's average days in courses
	for (i = 0; i < classRoster.getRemainingNum(); ++i) {
		classRoster.printAverageDaysInCourse(classRoster.getRosterElement(i)->getStudentID());
	}

	// print student information with the software degree program
	classRoster.printByDegreeProgram(SOFTWARE);

	// remove student with Id A3 from the roster
	classRoster.remove("A3");
	
	// output all remaining students
	classRoster.printAll();

	// attempt to remove student with Id A3
	classRoster.remove("A3");

	return 0;
}