#include <iostream>
#include <string>
#include <unordered_map>

#include "Student.h"

Student::Student(){

}

Student::Student(string name) {
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