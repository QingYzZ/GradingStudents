#include <string>
#include <unordered_map>

#include "GRADING_STUDENTS_MACROS.h"
#include "Project.h"


using namespace std;

class Student {

	public:
	Student();
	Student(string name);

	int increaseSubmissionNumber(const string &projectName);
	int getSubmissionNumber(const string &projectName);
	int getNumTests(const string &projectName) { return projectMap[projectName].getNumTests();}
	int checkScore(const string &projectName, bool ifBest);
	int updateScore(const string &projectName, list<int> *testResults, bool ifBest);
	int addProject(string &projectName, int numTests);

	private:
	string name;
	int gpa;
	unordered_map<string, Project> projectMap; /* <projectName, ProjectObject> */
};