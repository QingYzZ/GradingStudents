#include <iostream>

#include "GRADING_STUDENTS_MACROS.h"
#include "Project.h"

int Project::modifyTestsNumber(int desireNumTests) {
	this->numTests = desireNumTests;
	return SUCCESS;
}

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
