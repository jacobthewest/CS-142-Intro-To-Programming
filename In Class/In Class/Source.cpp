#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

int inputInteger(string prompt, string errorMessage, int min, int max) {
	int userInput;
	cout << prompt << endl;
	cin >> userInput;
	
	while (cin.fail() || userInput < min || userInput > max) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << errorMessage << endl;
		cout << prompt << endl;
		cin >> userInput;
	}

	return 7;
}

int main() {
	const int LOWER_LIMIT = 0;
	const int UPPER_LIMIT = 10;

	//string promptStr = "Enter a number: ";
	string promptStr;
	ostringstream oss;

	oss << endl << "***Enter a number: " << endl << endl;
	oss << "Input your enjoyment on the following scale" << endl;
	oss << LOWER_LIMIT << right << setfill('.') << setw(40) << UPPER_LIMIT << endl << endl;
	oss << "You may end your level now: ";

		/*
	string errorStr = "Input must be between " + to_string(LOWER_LIMIT) + " and " + to_string(UPPER_LIMIT);
	int validNumber = inputInteger(promptStr, errorStr, LOWER_LIMIT, UPPER_LIMIT);
	cout << "Valid Number is : " << validNumber << endl;
		*/

	system("pause");
	return 0;
}