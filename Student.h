#include <string>

#include "GRADING_STUDENTS_MACROS.h"

using namespace std;

class Student {

	public:
	Student();
	Student(string name);

	int increaseSubmissionNumber() { numSubmissions++; return SUCCESS; }
	int getSubmissionNumber() { return numSubmissions;}

	private:
	string name;
	int gpa, numSubmissions, numTests;
};