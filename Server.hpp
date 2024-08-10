#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
#include <unordered_map>
#include <list>

#include "Student.hpp"
#include "Project.hpp"
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
	bool findProject(const string &projectName, const string &studentName);
	
	private:
	int numOfStudents;
	int maxSubmission;
	unordered_map<string, Student> studentMap;

};

#endif
