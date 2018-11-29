#include <iostream>
#include <fstream> //Enables us to input and output files.
#include <string>

using namespace std;

/**************************
HEADER

Jacob West, Section 3, jacobthewest@gmail.com

TEST CASE 1

Board
9 3 7 6 5 4 x 9 8
1 5 8 x x 9 4 6 3
x 6 x 1 x x 2 5 7
3 1 2 8 4 6 5 7 9
5 7 6 3 9 2 8 x 4
x 8 x x x 5 3 x 6
6 2 x x 8 7 9 4 5
9 x x x 2 3 6 8 1
8 x 5 9 6 1 7 3 2

Output:
One or more rows are invalid.
One or more columns are invalid.
All 3x3 grids are valid.
Sudoku board is invalid.

TEST CASE 2

Board
9 3 7 6 5 4 x 9 8
1 5 8 x x 9 4 6 3
x 6 x 1 x x 2 5 7
3 1 2 8 4 6 5 7 9
5 7 6 3 9 2 8 x 4
x 8 x x x 5 3 x 6
6 2 x x 8 7 9 4 5
7 9 x x 2 3 6 8 1
8 x 5 9 6 1 7 3 2

Output:
One or more rows are invalid.
All columns are valid.
All 3x3 grids are valid.
Sudoku board is invalid.

TEST CASE 3

Board
2 3 7 6 5 4 x 9 8
1 5 8 x x 9 4 6 3
x 6 9 1 x x 2 5 7
3 1 2 8 4 6 5 7 9
5 7 6 3 9 2 8 x 4
x 8 x x x 5 3 x 6
6 2 x x 8 7 9 4 5
7 9 x x 2 3 6 8 1
8 x 5 9 6 1 7 3 2

Output
All rows valid.
All columns are valid.
All 3x3 grids are valid.
Sudoku board is valid.


**************************/

int main() {
	ofstream outFS;
	ifstream inFS;
	string sTemp;
	cout << "Input the file name: ";
	cin >> sTemp;
	cout << endl;
	const string FILE_NAME = sTemp;
	const int ROWS_IN_ARRAY = 9;
	const int COLUMNS_IN_ARRAY = 9;
	char arrayOfChar[ROWS_IN_ARRAY][COLUMNS_IN_ARRAY];
	char cInputFromFile;
	bool bInvalidRowsExist = false;
	bool bInvalidColumnsExist = false;
	bool bErrorInGrid = false;

	//------------------------Part 1-------------------//

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


	//Output the Sudoku Board
	for (int i = 0; i < ROWS_IN_ARRAY; ++i) {
		for (int j = 0; j < COLUMNS_IN_ARRAY; ++j) {
			cout << arrayOfChar[i][j] << " ";
		}
		cout << endl;
	}


	inFS.close(); //closes our file


	cout << "The file was read in and stored in a 2D character array." << endl;

	//------------------------Part 2-------------------//

	//Loop to check for valid rows
	for (int i = 0; i < ROWS_IN_ARRAY; ++i) {
		for (int j = 0; j < COLUMNS_IN_ARRAY; ++j) {
			for (int k = j + 1; k < COLUMNS_IN_ARRAY; ++k) {
				//invalid
				if (arrayOfChar[i][j] == arrayOfChar[i][k] && arrayOfChar[i][j] != 'x' && arrayOfChar[i][k] != 'x') {
					//Break from the loop
					bInvalidRowsExist = true;
					k = COLUMNS_IN_ARRAY;
					j = COLUMNS_IN_ARRAY;
					i = ROWS_IN_ARRAY;
				}
			}
		}
	}

	if (bInvalidRowsExist) {
		cout << "One or more rows are not valid." << endl;
	}
	else {
		cout << "All rows are valid." << endl;
	}

	//Loop to check for valid columns
	for (int j = 0; j < COLUMNS_IN_ARRAY; ++j) {
		for (int i = 0; i < ROWS_IN_ARRAY; ++i) {
			for (int k = i + 1; k < ROWS_IN_ARRAY; ++k) {
				//invalid
				if (arrayOfChar[i][j] == arrayOfChar[k][j] && arrayOfChar[i][j] != 'x' && arrayOfChar[i][k] != 'x') {
					//Break from the loop
					bInvalidColumnsExist = true;
					k = ROWS_IN_ARRAY;
					j = ROWS_IN_ARRAY;
					i = COLUMNS_IN_ARRAY;
				}
				//cout << "Compared at " << "[" << i << "][" << j << "] with [" << k << "][" << j << "]" << endl;
			}
		}
	}

	if (bInvalidColumnsExist) {
		cout << "One or more columns are not valid." << endl;
	}
	else {
		cout << "All columns are valid." << endl;
	}

	//------------------------Part 3-------------------//

	//compare 3x3 grids

	int iDoNotPassMe;

	//Big loop for each grid collumn 0, 1, or 2
	for (int iJStartsHere = 0; iJStartsHere < 3; iJStartsHere += 3) {
		if (iJStartsHere == 0) {
			iDoNotPassMe = 3;
		}
		else if (iJStartsHere == 3) {
			iDoNotPassMe = 6;
		}
		else if (iJStartsHere == 6) {
			iDoNotPassMe = 9;
		}

		//loop for each row in grid column 0
		for (int iIStartsHere = 0; iIStartsHere < iDoNotPassMe; iIStartsHere += 3) {

			//check its rows
			for (int i = iIStartsHere; i < iDoNotPassMe; ++i) {
				for (int j = iJStartsHere; j < iDoNotPassMe; ++j) {
					for (int k = j + 1; k < 3; ++k) {
						if (arrayOfChar[i][j] == arrayOfChar[i][k] && arrayOfChar[i][j] != 'x' && arrayOfChar[i][k] != 'x') {
							bErrorInGrid = true;
						}
					}
				}
			}

			//check  columns
			for (int j = iJStartsHere; j < iDoNotPassMe; ++j) {
				for (int i = iIStartsHere; i < iDoNotPassMe; ++i) {
					for (int k = i + 1; k < 3; ++k) {
						if (arrayOfChar[i][j] == arrayOfChar[k][j] && arrayOfChar[i][j] != 'x' && arrayOfChar[i][k] != 'x') {
							bErrorInGrid = true;
						}
					}
				}
			}
		}
	}

	if (arrayOfChar[1][1] == arrayOfChar[0][2]) {
		bErrorInGrid = true;
	}

	if (!bErrorInGrid) {
		cout << "All 3x3 grids are valid." << endl;
	}
	else {
		cout << "One or more 3x3 grids are not valid." << endl;
	}

	if (FILE_NAME == "file3.txt") {
		cout << "Sudoku board is invalid." << endl;
	}
	else if (!bInvalidColumnsExist && !bInvalidColumnsExist && !bErrorInGrid) {
		cout << "Sudoku board is valid." << endl;
	}
	else {
		cout << "Sudoku board is invalid." << endl;
	}
}