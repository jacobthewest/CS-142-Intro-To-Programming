#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
public:
	Student(string name = "not intialized", double GPA = 0.0);
	void SetName(string studentName);
	void SetGPA(double personName);
	string ToString() const;
	void Add(string sName, double dGPA, vector<Student*> &studentVector);
	void Drop(int iIndex, vector<Student*> &studentVector);
	void Print(vector<Student*> &student) const;
	string GetName() const;
	double GetGPA() const;
private:
	string name;
	double GPA;
};

//Default constructor
Student::Student(string initialName, double initialGPA) {
	name = initialName;
	GPA = initialGPA;
}

void Student::SetName(string inputName) {
	name = inputName;
}

void Student::SetGPA(double newGPA) {
	GPA = newGPA;
}
//Getters
string Student::GetName() const {
	return name;
}
double Student::GetGPA() const {
	return GPA;
}

string Student::ToString() const {
	ostringstream oss;
	oss << fixed;
	string sOutput;
	oss << name << " has a GPA of " << setprecision(1) << GPA << endl;
	return oss.str();
}
void Student::Add(string sName, double dGPA, vector<Student*> &studentVector) {
	Student* oStud = new Student(sName, dGPA);
	studentVector.push_back(oStud);
}
void Student::Drop(int iIndex, vector<Student*> &studentVector) {
	delete studentVector.at(iIndex); //Free up the actual memory asssociated with the pointer at iIndex
	studentVector.erase(studentVector.begin() + iIndex); //Deletes the pointer in the vector
}
void Student::Print(vector<Student*> &studentsVector) const {
	cout << fixed;
	for (unsigned int i = 0; i < studentsVector.size(); ++i) {
		cout << i << ": " << studentsVector.at(i)->GetName() << " has a GPA of " << setprecision(1) << studentsVector.at(i)->GetGPA() << endl;
	}
	cout << endl;
}

//Global variables
const string ADD = "add";
const string DROP = "drop";
const string PRINT = "print";
const string QUIT = "quit";

int main() {
	//Declare variables
	vector<Student*> studentsVector;
	bool bWeAreInTheProgram = true;
	string sChoice;
	string sName;
	double dGPA;
	int iIndex;
	Student oStud;

	while (bWeAreInTheProgram) {
		cout << "Enter Option : ";
		cin >> sChoice;
		cout << endl;

		if (sChoice == ADD) {
			//Get student information
			cout << "Student name : ";
			cin.ignore();
			cin >> sName;
			cout << endl;
			cout << sName << "'s GPA: ";
			cin >> dGPA;
			cout << endl;
			oStud.Add(sName, dGPA, studentsVector);
			//Create a new student
		}
		else if (sChoice == DROP) {
			cout << "Index of student to drop: ";
			cin.ignore();
			cin >> iIndex;
			cout << endl;
			oStud.Drop(iIndex, studentsVector);
		}
		else if (sChoice == PRINT) {
			oStud.Print(studentsVector);
		}
		else if (sChoice == QUIT) {
			bWeAreInTheProgram = false;
		}
	}

	return 0;
}