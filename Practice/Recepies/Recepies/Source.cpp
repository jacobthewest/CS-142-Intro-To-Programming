#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Functions go here
void addRecepie(string nameOfRecepie, string ingredient1, string ingredient2, string ingredient3, int time) {

}


//Int main goes here
int main() {
	int iSelection = 1;
	string name;
	string ingredient1;
	string ingredient2;
	string ingredient3;
	int time;
	vector<string> recepieNames();
	vector<int> recepieTime();
	vector<vector<string>> recepieIngredients();

	do {
		if (iSelection == 1) {
			cout << "---Add a recepie---" << endl;
			cout << "Enter name of recepie: ";
			getline(cin, name);
			cout << endl;
			cout << "Enter ingredient 1: ";
			getline(cin, ingredient1);
			cout << endl;
			cout << "Enter ingredient 2: ";
			getline(cin, ingredient2);
			cout << endl;
			cout << "Enter ingredient 3: ";
			getline(cin, ingredient3);
			cout << endl;
			cout << "Enter time: ";
			cin >> time;
			cout << endl;

			//call add recepie function
			addRecepie(name, ingredient1, ingredient2, ingredient3, time);
		}

		cout << endl << "Enter your selection: " << endl;
		cin >> iSelection;
	} while (iSelection != 4);

	cout << "Goodbye!" << endl;
	system("pause");

	//Type 1 to add a recepie
	//Type 2 to quit
}