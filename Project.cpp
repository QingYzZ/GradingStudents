#include <iostream>
#include <list>

#include "GRADING_STUDENTS_MACROS.h"
#include "Project.h"


Project::Project() {
	numTests = MIN_TESTS;
	name = "DEFAULT PROJECT NAME";
	numSubmissions = 0;
}

Project::Project(const string &name, int numTests) {
	if (name.empty() || numTests < MIN_TESTS) {
		Project();
	} else {
		Project();
		this->name = name;
		this->numTests = numTests;
	}
}

int Project::modifyTestsNumber(int desireNumTests) {
	this->numTests = desireNumTests;
	return SUCCESS;
}

/* return current total score or best total score */
int Project::getScore(bool ifBest) {
	list<int> const *toProcess;
	int total = 0;

	if (ifBest) {
		toProcess = &currentBestScores;
	} else {
		toProcess = &currentScores;
	}

	for (list<int>::const_iterator it = toProcess->begin(); it != toProcess->end(); it++) {
		total += *it;
	}

	return total;
}

int Project::updateScores(list<int> *testScores, bool ifBest) {
	if (testScores == nullptr) {
		return FAILURE;
	}

	if (ifBest) {
		currentBestScores = *testScores;
	}else {
		currentScores = *testScores;
	}
	return SUCCESS;
}
