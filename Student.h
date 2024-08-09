#include <string>

using namespace std;

class Student {

	public:
	Student();
	Student(string name);


	private:
	string name;
	int gpa, numSubmissions, numTests;
};