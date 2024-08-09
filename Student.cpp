#include <iostream>
#include <string>

#include "Student.h"

Student::Student(){

}

Student::Student(string name) {
	this->name = name;
}

int Student::checkScore(const string &projectName, bool ifBest) {
	return projectMap[projectName].getScore(ifBest);
}

int Student::updateScore(const string &projectName, list<int> *testResults, bool ifBest) {
	return projectMap[projectName].updateScores(testResults, ifBest);
}

int Student::increaseSubmissionNumber(const string &projectName) {
	projectMap[projectName].increaseSubmissions();
	return SUCCESS;
}

int 