#include "roster.h" 

// default constructor
Roster::Roster(){
	indexes = 0;
	*classRosterArray = { nullptr };
	string degreePrograms[4] = {"SECURITY", "NETWORK", "SOFTWARE", "UNKNOWN"};
}

// copy constructor
Roster::Roster(const Roster& objToCopy) {
	Roster* school = new Roster;

	school->indexes = objToCopy.indexes;
	*school->classRosterArray = *objToCopy.classRosterArray;
	*school->degreePrograms = *objToCopy.degreePrograms;
}

// define Roster class destructor
Roster::~Roster() {

	// delete Student objects held in Roster class array
	for (int i = 0; i < indexes; ++i) {
		delete classRosterArray[i];
	}
	cout << "\n\nRoster deleted from memory\n";
}

// method to convert string input to an enum type
Degree Roster::translateDegree(string degreeType) {
	Degree enumDegreeType;
	if (degreeType == degreePrograms[0]) {
		enumDegreeType = SECURITY;
	}
	else if (degreeType == degreePrograms[1]) {
		enumDegreeType = NETWORK;
	}
	else if (degreeType == degreePrograms[2]) {
		enumDegreeType = SOFTWARE;
	}
	else {
		enumDegreeType = UNKNOWN;
	}

	return enumDegreeType;
}

// method to parse through and covert input data
void Roster::extractData(string line) {

	// declare temporary string variable
	string tempString;

	// acquire the end index of attribute on the string input
	int endIndex = line.find(",");

	// assign variable with the section of the string relative to the class member value
	string id = line.substr(0, endIndex);

	// assign the remaining string input to the temporary string
	tempString = line.substr(endIndex + 1);


	// acquire student first name from string input
	endIndex = tempString.find(",");
	string first = tempString.substr(0, endIndex);
	tempString = tempString.substr(endIndex + 1);

	// acquire student last name from string input
	endIndex = tempString.find(",");
	string last = tempString.substr(0, endIndex);
	tempString = tempString.substr(endIndex + 1);

	// acquire student email from string input
	endIndex = tempString.find(",");
	string email = tempString.substr(0, endIndex);
	tempString = tempString.substr(endIndex + 1);

	// acquire student age from string input
	endIndex = tempString.find(",");
	int age = stoi(tempString.substr(0, endIndex));
	tempString = tempString.substr(endIndex + 1);

	// acquire student course days to complete 1 from string input
	endIndex = tempString.find(",");
	int daysToComplete1 = stoi(tempString.substr(0, endIndex));
	tempString = tempString.substr(endIndex + 1);

	// acquire student course days to complete 2 from string input
	endIndex = tempString.find(",");
	int daysToComplete2 = stoi(tempString.substr(0, endIndex));
	tempString = tempString.substr(endIndex + 1);

	// acquire student course days to complete 3 from string input
	endIndex = tempString.find(",");
	int daysToComplete3 = stoi(tempString.substr(0, endIndex));
	tempString = tempString.substr(endIndex + 1);

	// acquire student degree type from string input
	endIndex = tempString.find(",");
	string dataForType = tempString.substr(0, endIndex);

	// translate string degree input to enum type
	Degree type = translateDegree(dataForType);

	// add a new Student object created from parsed data to class roster
	add(id, first, last, email,
		age, daysToComplete1, daysToComplete2, daysToComplete3, type);
	
}

// method definition to add student to student roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysToComplete1, int daysToComplete2, int daysToComplete3, Degree degreeprogram) {
	

	// create a pointer to new student object with input class member values
	Student* student = new Student(studentID, firstName, lastName, emailAddress,
		age, daysToComplete1, daysToComplete2, daysToComplete3, degreeprogram);

	// assign new student object to a roster index and increment the next open index value
	classRosterArray[indexes] = student;	
	++indexes;
}

// method definition to access a student pointer on the class roster array
Student* Roster::getRosterElement(int index) { return classRosterArray[index]; }

// function to remove a student from the class roster and delete their stored information from memory
void Roster::remove(string studentID) {
	// condition if id found or not found on the roster
	bool notFound = true;
	
	// iterate through roster
	for (int i = 0; i < indexes; ++i) {

		// check if id input matches a student id on the roster
		if (classRosterArray[i]->getStudentID() == studentID) {

			// assign found
			notFound = false;

			// delete student from class roster and call Student destructor
			delete classRosterArray[i];

			// assign the deleted object index with the last indexed object on the array
			classRosterArray[i] = classRosterArray[indexes - 1];

			// output message indicating which student Id was erased
			cout << "\nStudent with Id: " << studentID << " removed from the roster\n\n";

			// update remaining number of students on roster
			--indexes;

		}	
	}
	// message executed if input id not found on roster
	if (notFound) {
		cout << "\nStudent with Id: " << studentID << " not found\n";
	}
}

// method to get remaining indexes of students on the roster
int Roster::getRemainingNum() { return indexes; }

// method to print student on roster' information
void Roster::printAll() {

	// output message if there are no more students remaining on roster
	if (this->indexes == 0) {
		cout << "\nNothing to print\n";
		return;
	}

	// iterate through remaining students on the roster
	for (int i = 0; i < indexes; ++i) {
		classRosterArray[i]->print();
	}
}

// function to print average number of course days per student
void Roster::printAverageDaysInCourse(string id) {
	int sum = 0;
	double average;
	for (int i = 0; i < indexes; ++i) {
		if (classRosterArray[i]->getStudentID() == id) {
			for (int j = 0; j < Student::numDaySetsToComplete; ++j) {

				// add student's course days through accessing memory address
				sum += *(classRosterArray[i]->getDaysToComplete() + j);


			}
		}	
	}

	// set decimal to 1 place
	cout << fixed << setprecision(1);

	// cast average product for storage as a double type
	average = static_cast<double>(sum) / static_cast<double>(Student::numDaySetsToComplete);

	// output average information
	if (static_cast<int>(average * 10) % 10 == 0) {
		cout << "Student ID: " << id << ": Average number of days in courses: " << static_cast<int>(average) << endl;
	}
	else {
		cout << "Student ID: " << id << ": Average number of days in courses: " << average << endl;
	}
}

// function to output invalid emails
void Roster::printInvalidEmails() {

	cout << "\nInvalid emails:\n";

	for (int i = 0; i < indexes; ++i) {

		// check if student on roster email contains or does not contain characters
		if (classRosterArray[i]->getEmail().find(' ') != string::npos ||
			classRosterArray[i]->getEmail().find('.') == string::npos ||
			classRosterArray[i]->getEmail().find('@') == string::npos) {

			// output student email
			cout << classRosterArray[i]->getEmail() << endl;
		}
	}
	cout << endl;
}

// function to output students with the same degree program
void Roster::printByDegreeProgram(Degree degreeProgram) {
	
	cout << "\nStudents with the " << degreePrograms[degreeProgram] << " degree program:\n";

	for (int i = 0; i < indexes; ++i) {

		// check if student has the same degree program as input program
		if (classRosterArray[i]->getProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}