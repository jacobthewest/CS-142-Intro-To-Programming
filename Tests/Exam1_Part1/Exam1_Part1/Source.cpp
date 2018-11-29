#include <iostream>
#include <fstream>//for file output and input

using namespace std;

/****************************************************
HEADER:



********************************************/

int main() {
	ofstream outFS; 
	ifstream inFS;
	const string FILE_NAME = "file2.txt";
	const int ROWS_IN_ARRAY = 9;
	const int COLUMNS_IN_ARRAY = 9;
	char arrayOfChar[ROWS_IN_ARRAY][COLUMNS_IN_ARRAY];
	char cInputFromFile;
	
	//Input the file
	cout << "Opening the file" << endl;
	inFS.open(FILE_NAME);

	if (!inFS.is_open()) {
		cout << "Could not open the file" << endl;
		return 1;
	}

	while (!inFS.eof()) {
			for (int i = 0; i < ROWS_IN_ARRAY; ++i) {
				for (int j = 0; j < COLUMNS_IN_ARRAY; ++j) {
					inFS >> cInputFromFile;
					if (!inFS.fail()) {
						arrayOfChar[i][j] = cInputFromFile;
					}/*
					else {
						cout << "fail on arrayOfChar[" << i << "][" << j << "]" << endl;
						cout << "cInputFromFile is " << cInputFromFile << endl;
					} */
				}
			}
	}
	
	
	/* SHOWS WHAT WAS INPUT INTO OUR ARRAY. THE VALUES STORED THERE.
	for (int i = 0; i < ROWS_IN_ARRAY; ++i) {
		for (int j = 0; j < COLUMNS_IN_ARRAY; ++j) {
			cout << arrayOfChar[i][j] << " ";
		}
		cout << endl;
	} */
	

	inFS.close(); //closes our file

	
	cout << "The file was read in and stored in a 2D character array." << endl;
	
	//system("pause");
	
}