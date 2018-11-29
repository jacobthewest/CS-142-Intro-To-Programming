#include <iostream>
#include <string>
#include <fstream>  
using namespace std;

const int GRID_SIZE = 9;
const int MIN_POSITION = 1;
const int MID_POSITION = 4;
const int MAX_POSITION = 7;

//checks if just one row is valid (broken down into as small a piece as possible)
bool checkOneRowValid(char sudokuGridIn[][GRID_SIZE], int rowNum) {
	string allVals = "";
	for (int j = 0; j<GRID_SIZE; j++) { //go through each position in the row
		char currentChar = sudokuGridIn[rowNum][j];
		//check to see if the current character doesn't exist as part of the string allVals OR if it's an x
		if (allVals.find(currentChar) == string::npos || currentChar == 'x') {
			allVals += currentChar;    //add to the string of all the values
		}
		else {    //if it isn't, that means we've found a duplicate number
			return false;
		}
	}
	return true;
}

//go through each row to check if they're valid
bool checkIfRowsValid(char sudokuGridIn[][GRID_SIZE]) {
	for (int i = 0; i<GRID_SIZE; i++) {
		bool currentRowValid = checkOneRowValid(sudokuGridIn, i);
		if (!currentRowValid) {   //if we find one that's invalid, we know that not all can be valid
			return false;
		}
	}
	return true;

}
bool checkOneColumnValid(char sudokuGridIn[][GRID_SIZE], int colNum) {
	string allVals = "";
	for (int i = 0; i<GRID_SIZE; i++) {
		char currentChar = sudokuGridIn[i][colNum];
		if (allVals.find(currentChar) == string::npos || currentChar == 'x') {
			allVals += currentChar;
		}
		else {
			return false;
		}
	}
	return true;
}
bool checkIfColumnsValid(char sudokuGridIn[][GRID_SIZE]) {
	for (int i = 0; i<GRID_SIZE; i++) {
		bool currentColumnValid = checkOneColumnValid(sudokuGridIn, i);
		if (!currentColumnValid) {
			return false;
		}
	}
	return true;
}

//checks if one 3x3 grid is valid
bool checkOneSquareValid(char sudokuGridIn[][GRID_SIZE], int x, int y) {
	//arrays that can be used to determine all the x,y positions of the grid (based off the center point)   
	int xDiffs[GRID_SIZE] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
	int yDiffs[GRID_SIZE] = { -1, 0, 1, -1, 0, 1, -1, 0 ,1 };

	string allVals = "";
	for (int i = 0; i<GRID_SIZE; i++) {
		//calculate the current x and y based off of the xDiffs and yDiffs arrays
		int currX = x + xDiffs[i];
		int currY = y + yDiffs[i];
		char currentChar = sudokuGridIn[currX][currY];
		//same as with rows and columns to determine if the character hasn't been found in the string we're building
		if (allVals.find(currentChar) == string::npos || currentChar == 'x') {
			allVals += currentChar;
		}
		else {
			return false;
		}
	}
	return true;
}

bool checkIfSquaresValid(char sudokuGridIn[][GRID_SIZE]) {
	//arrays representing all the possible center positions of the 3x3 grids - combinations of 1,4,7
	//1,1; 1,4; 1,7; 4,1; 4,4; 4,7; 7,1; 7,4; 7,7
	int xPos[GRID_SIZE] = { MIN_POSITION, MIN_POSITION, MIN_POSITION,
		MID_POSITION, MID_POSITION, MID_POSITION,
		MAX_POSITION, MAX_POSITION, MAX_POSITION };
	int yPos[GRID_SIZE] = { MIN_POSITION, MID_POSITION, MAX_POSITION,
		MIN_POSITION, MID_POSITION, MAX_POSITION,
		MIN_POSITION, MID_POSITION, MAX_POSITION };

	for (int i = 0; i<GRID_SIZE; i++) {
		bool currentSquareValid = checkOneSquareValid(sudokuGridIn, xPos[i], yPos[i]);
		if (!currentSquareValid) {
			return false;
		}
	}
	return true;
}

void printGrid(char sudokuGridIn[][GRID_SIZE]) {
	for (int i = 0; i<GRID_SIZE; i++) {
		for (int j = 0; j<GRID_SIZE; j++) {
			cout << sudokuGridIn[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ifstream inFileStream;
	char sudokuGrid[GRID_SIZE][GRID_SIZE];

	string userInput;
	cout << "Please enter a file name of a Sudoku grid to read in.  Type quit to exit. " << endl;
	cin >> userInput;

	while (userInput != "quit") {
		do {
			string fileName = userInput;
			inFileStream.open(fileName); // This actually creates the input stream and ties it to the input file
		} while (!inFileStream.is_open()); // Checks if stream was succssfully created. Fails if file not found

										   //read file into grid
		for (int i = 0; i<GRID_SIZE; i++) {
			for (int j = 0; j<GRID_SIZE; j++) {
				inFileStream >> sudokuGrid[i][j];
			}
		}

		printGrid(sudokuGrid);

		cout << "The file was read in and stored in a 2D character array." << endl;
		inFileStream.close(); // Closing files when done is good practice. 	  

							  //check rows
		bool rowsValid = checkIfRowsValid(sudokuGrid);
		if (rowsValid) {
			cout << "All rows are valid." << endl;
		}
		else {
			cout << "One or more rows are not valid." << endl;
		}

		//check columns
		bool columnsValid = checkIfColumnsValid(sudokuGrid);
		if (columnsValid) {
			cout << "All columns are valid." << endl;
		}
		else {
			cout << "One or more columns are not valid." << endl;
		}

		//check squares
		bool squaresValid = checkIfSquaresValid(sudokuGrid);
		if (squaresValid) {
			cout << "All 3x3 grids are valid." << endl;
		}
		else {
			cout << "One or more 3x3 grids are not valid." << endl;
		}

		//check entire board
		if (rowsValid && columnsValid && squaresValid) {
			cout << "Sudoku board is valid." << endl;
		}
		else {
			cout << "Sudoku board is invalid." << endl;
		}

		cout << "Please enter a file name of a Sudoku grid to read in.  Type quit to exit. " << endl;
		cin >> userInput;
	}

	return 0;
}