#include <iostream>
#include <string>
#include <unordered_map>

#include "Student.hpp"

using namespace std;


Student::Student(){
	gpa = -1.0;
	name = "DEFAULT STUDENT NAME";
}

Student::Student(string name) {
	gpa = -1.0;
	this->name = name;
}

/* return the current total score, return success */
int Student::checkScore(const string &projectName, bool ifBest) {
	return projectMap[projectName].getScore(ifBest);
}

/* update the current test scores list, return success */
int Student::updateScore(const string &projectName, list<int> *testResults, bool ifBest) {
	return projectMap[projectName].updateScores(testResults, ifBest);
}

/* increase the number of submission, return success */
int Student::increaseSubmissionNumber(const string &projectName) {
	projectMap[projectName].increaseSubmissions();
	return SUCCESS;
}

/* return number of submissions */
int Student::getSubmissionNumber(const string &projectName) {
	return projectMap[projectName].getSubmissionNumber();
}

int Student::addProject(string &projectName, int numTests) {
	if (projectName.empty() || numTests < MIN_TESTS) {
		return FAILURE;
	}

	Project new_project(projectName, numTests);
	projectMap[projectName] = new_project;
	return SUCCESS;
}

bool Student::findProject(const string &projectName) {
	if (projectMap.find(projectName) == projectMap.end()) {
		return false; /* not found */
	} else {
		return true; /* found */
	}
}

