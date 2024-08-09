#include <string>
#include <unordered_map>
#include <list>

#include "Student.h"
#include "Project.h"
using namespace std;

class Server {
	
	public:
	Server();
	Server(int maxSubmission);

	int numStudents();
	int addStudent(const string &name);
	int addSubmission(const string &projectName, const string &name, list<int> *testResults);
	int getTotalScore(list<int> *testResults);
	int getBestScore(const string &projectName, const string &name);
	
	private:
	int numOfStudents;
	int maxSubmission;
	unordered_map<string, Student> studentMap;

};
