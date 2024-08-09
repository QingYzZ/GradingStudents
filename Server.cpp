#include <iostream>
#include <unordered_map>
#include <list>

#include "Server.h"
#include "Student.cpp"
#include "Student.h"
#include "Project.h"

#include "GRADING_STUDENTS_MACROS.h"

using namespace std;

Server::Server() {
	maxSubmission = DEFAULT_MAX_SUBMISSIONS;
	numOfStudents = 0;
}

Server::Server(int maxSubmission) {
	if (maxSubmission <= 0) {
		Server();
	} else {
		this->maxSubmission = maxSubmission;
		numOfStudents = 0;
	}
}

int Server::numStudents() {
	return numOfStudents;
}

int Server::addStudent(const string &name) {
	if (name.empty()) {
		return FAILURE;
	}
	numOfStudents++;
	Student new_student(name); /* create a new student */
	studentMap[name] = new_student; /* insert new_student with key name */
    return SUCCESS;
}

int Server::addSubmission(const string &projectName, const string &name, list<int> *testResults) {
	/* check parameters are valid */
	if (projectName.empty() || name.empty() || testResults->empty() || 
	studentMap[name].getSubmissionNumber() >= maxSubmission) {
		return FAILURE;
	}

	/* checking each test score so they are not negative using an iterator */
	int countTests = 0;
	for (list<int>::iterator it = testResults->begin(); it != testResults->end(); it++) {
        if (*it < 0) {
            return FAILURE;
        }
		/* also count the number of Tests*/
		countTests++;
    }

	/* checking if any test is missing */
	if (countTests < projectMap[projectName].getNumTests()) {
		return FAILURE;
	}

	int bestTotalScore = projectMap[projectName].getScore(true); /* this is getting the best total score */
	int currentTotalScore = getTotalScore(testResults);

	if(currentTotalScore >= bestTotalScore) { /* check if best scores list should be updated */
		projectMap[projectName].updateScores(testResults, true); /* update the best score list */
	}
	
	/* always update the current scores list */
	projectMap[projectName].updateScores(testResults, false);

	/* increase the number of submissions made by that student by 1*/
	studentMap[name].increaseSubmissionNumber(); 
	return SUCCESS;
}

int Server::getTotalScore(list<int> *testResults) {
	int total = 0;
	for(list<int>::const_iterator it = testResults->begin(); it != testResults->end(); it++) {
		total += *it;
	}
	return total;
}





