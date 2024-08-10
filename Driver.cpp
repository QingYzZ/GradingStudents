#include <iostream>
#include <string>

#include "GRADING_STUDENTS_MACROS.hpp"
#include "Server.hpp"

using namespace std;

int test1() {
	string inputName = "John S";
	Student* new_student = new Student(inputName);
	string name = new_student->getName();
	cout << "This is the studentname: " << name << endl;

	return SUCCESS;
}

int main() {
	test1();
	return 0;
}
