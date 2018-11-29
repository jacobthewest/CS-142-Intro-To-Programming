#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
	Student(string initialName = "No Name") {
		name = initialName;
	}
	virtual void ToStr() const{
		cout << name << " is an undergraduate student." << endl;
	}
	// Enter definition for a virtual ToStr member function here.

protected:
	string name;
};

class GradStudent : public Student {
public:
	GradStudent(string initialname, string researchArea) {
		this->name = initialname;
		this->researchArea = researchArea;
	}
	// Enter definition for a paramteriezed contructor function here that sets both data members.
	void ToStr() const {
		cout << name << " is a graduate student researching the area of " << researchArea << "." << endl;
	}
	// Enter definition for a virtual ToStr member function here.

private:
	string researchArea;
};

int main() {
	string usrOption;
	string inpName;
	string inpResearch;
	vector<Student*> classMembers;

	do {
		cout << "Option: ";
		cin >> usrOption;
		cout << endl;
		if (usrOption == "print") {
			for (unsigned int i = 0; i < classMembers.size(); ++i) {
				classMembers.at(i)->ToStr();
			}
			// Enter code here to print each member pointed to from classMembers using their 
			//respective ToStr member functions.			}
		}

		else if (usrOption == "add") {
			cout << "Name: ";
			cin >> inpName;
			cout << endl;
			cout << "If grad student enter a one word research area, else enter \"NO\": ";
			cin >> inpResearch;
			cout << endl;

			if (inpResearch == "NO") {
				//Not a grad student
				//Call Student constructor
				classMembers.push_back(new Student(inpName));
			}
			else {
				//IS a grad student
				//Call Grad Stduent constructor
				classMembers.push_back(new GradStudent(inpName, inpResearch));
			}
			// Enter code here to create new objects (using new) for either a Student or a GradStudent
			// and add the pointer to the classMember vector.
		}
	} while (usrOption != "quit");
	return 0;
}