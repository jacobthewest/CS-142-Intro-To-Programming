#include <iostream>
#include <ios> //for fixed number formatting
#include <iomanip> //For setprecision function
#include <fstream> //For file in and file out things
#include <math.h> //For fabs() absolute value function
using namespace std;

/***********************************************
	HEADER

	Jacob West, section 3, jacobthewest@gmail.com
	Lab 5

	Values of array cells at positions [1][0], [1][1], [1,2],  [2][1], [2][2] 
		FIRST ITERATION:			   0.000,  25.000, 25.000, 0.000,  0.000
		SECOND ITERATION:              0.000,  31.250, 37.500, 6.250,  6.250

	I have successfully created the graph in excel using the file I created and 
		populated with output with my program running in VS.

***********************************************/

int main() {
	const int WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE = 10;
	const double FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS = 100.00;
	const double FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS = 0.00;
	const double INTERIOR_STARTING_TEMPERATURE = 0.00;
	const string OUTPUT_FILE_NAME = "Hotplate.csv";
	const string INPUT_FILE_NAME = "Inputplate.txt";
	const int WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE = 9;
	const int NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL = 3;
	const int NUMBER_OF_TIMES_TO_LOOP_AFTER_INPUTTING_FILE = 3;
	const double MAX_CHANGE_IN_DEGREES_FOR_STABLE_HOTPLATE = 0.1;
	double oldArray[WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE][WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE];
	double newArray[WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE][WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE];

	cout << fixed;

	//------------------------------------Part 1----------------------------------//

	cout << "Hotplate simulator" << endl << endl;
	cout << "Printing initial plate..." << endl;

	//Populate The Hotplate Array

	//i loop works on the rows
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		//j loop works on the columns
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			//this if formats for the first and last columns
			if (j == 0 || j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				oldArray[i][j] = FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS;
				//last column
				if (j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL) 
						<< oldArray[i][j];
				}
				//first column
				else {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL) 
						<< oldArray[i][j] << ",";
				}
			}
			//this else if formats for first and last rows
			else if (i == 0 || i == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1){
				oldArray[i][j] = FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS;
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL) 
					<< oldArray[i][j] << ",";
			}
			//this else formats for all inside values that are not in the first or last rows/columns
			else {
				oldArray[i][j] = INTERIOR_STARTING_TEMPERATURE;
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL) 
					<< oldArray[i][j] << ",";
			}
		}
		cout << endl;
	}
	cout << endl;
	//--------------------------------------Part 2----------------------------------------//

	//----Output our first hotplate after the first calculation---//

	//Calculates the new inner values for our hot plate's first new temperature
	//loop to target all rows that ARE NOT the first and last row
	for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
		//loop to target all of the columns that ARE NOT the first and last column
		for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
			newArray[i][j] = ((/*North*/oldArray[i - 1][j] + /*East*/oldArray[i][j + 1] + /*West*/oldArray[i][j - 1] + /*South*/oldArray[i + 1][j]) / 4);
			
		}
	}

	//Outputs the entire hotplate with its first new temperature
	
	cout << "Printing plate after one iteration..." << endl;

	//i loop works on the rows
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		//j loop works on the columns
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			//this if formats for the first and last columns
			if (j == 0 || j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS;
				//last column
				if (j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j];
				}
				//first column
				else {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j] << ",";
				}
			}
			//this else if formats for first and last rows
			else if (i == 0 || i == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS;
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
			//this else formats for all inside values that are not in the first or last rows/columns
			else {
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
		}
		cout << endl;
	}
	cout << endl;

	//--------------------------------------Part 3----------------------------------------//

	//---What is below is going to take us to the stable hotplate value---//
	
	double dMaxDifference = MAX_CHANGE_IN_DEGREES_FOR_STABLE_HOTPLATE + 1; //forces us to enter the while loop that 
		//runs until the hotplate stabilizes and the differences between the old and new values are <=  
		//the MAX_CHANGE_IN_DEGREES_FOR_STABLE_HOTPLATE.

	while (dMaxDifference > MAX_CHANGE_IN_DEGREES_FOR_STABLE_HOTPLATE) {

		//---Calculate the values of the new array---//

		//loop to target all rows that ARE NOT the first and last row
		for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
			//loop to target all of the columns that ARE NOT the first and last column
			for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
				newArray[i][j] = ((/*North*/oldArray[i - 1][j] + /*East*/oldArray[i][j + 1] + /*West*/oldArray[i][j - 1] + /*South*/oldArray[i + 1][j]) / 4);
			}
		}

		//---Find the max difference in the values to know when the hotplate has stabilized---//
		dMaxDifference = 0.0;
		//loop to target all rows that ARE NOT the first and last row
		for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
			//loop to target all of the columns that ARE NOT the first and last column
			for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
				if (fabs(oldArray[i][j] - newArray[i][j]) > dMaxDifference) {
					dMaxDifference = fabs(oldArray[i][j] - newArray[i][j]);
				}				
			}
		}

		//---Copy the newArray into oldArray for the next iteration---//
		
		//loop to target all rows that ARE NOT the first and last row
		for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
			//loop to target all of the columns that ARE NOT the first and last column
			for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
				oldArray[i][j] = newArray[i][j];
			}
		}
	}

	//Output the stable hotplate 

	cout << "Printing final plate..." << endl;

	//i loop works on the rows
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		//j loop works on the columns
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			//this if formats for the first and last columns
			if (j == 0 || j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS;
				//last column
				if (j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j];
				}
				//first column
				else {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j] << ",";
				}
			}
			//this else if formats for first and last rows
			else if (i == 0 || i == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS;
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
			//this else formats for all inside values that are not in the first or last rows/columns
			else {
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
		}
		cout << endl;
	}
	cout << endl;

	//--------------------------------------Part 4----------------------------------------//
	ofstream outFS; //output file stream
	ifstream inFS; //input file stream
	outFS << fixed; //Fixed has been declared only in our cout, but not yet in outFS.

	outFS.open(OUTPUT_FILE_NAME); //open the Hotplate.csv to write to it
	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl;

	//-----------Write to Hotplate.csv-----------//

	//i loop works on the rows
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		//j loop works on the columns
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			//this if formats for the first and last columns
			if (j == 0 || j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS;
				//last column
				if (j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
					outFS << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j];
				}
				//first column
				else {
					outFS << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j] << ",";
				}
			}
			//this else if formats for first and last rows
			else if (i == 0 || i == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS;
				outFS << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
			//this else formats for all inside values that are not in the first or last rows/columns
			else {
				outFS << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
		}
		outFS << endl;
	}

	outFS.close(); //Close Hotplate.csv becuase we are done with it now
	cout << endl;

	//--------------------------------------Part 5----------------------------------------//

	inFS.open(INPUT_FILE_NAME); //Open input file

	//Input initial array from the input file
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			inFS >> oldArray[i][j];
		}
	}

	inFS.close(); //Close input file

	//Iterate through the loop 3 times
	for (int i = 0; i < NUMBER_OF_TIMES_TO_LOOP_AFTER_INPUTTING_FILE; ++i) {
		//---Calculate the inner values of the new array ---//

		//loop to target all rows that ARE NOT the first and last row
		for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
			//loop to target all of the columns that ARE NOT the first and last column
			for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
				newArray[i][j] = ((/*North*/oldArray[i - 1][j] + /*East*/oldArray[i][j + 1] + /*West*/oldArray[i][j - 1] + /*South*/oldArray[i + 1][j]) / 4);
			}
		}

		//---Copy the newArray into oldArray for the next iteration---//

		//loop to target all rows that ARE NOT the first and last row
		for (int i = 1; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++i) {
			//loop to target all of the columns that ARE NOT the first and last column
			for (int j = 1; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1; ++j) {
				oldArray[i][j] = newArray[i][j];
			}
		}
	}

	//We have now iterated through our loop 3 times. We will now display the array after 3 iterations with the edge temperatures
	cout << "Printing input plate after " << NUMBER_OF_TIMES_TO_LOOP_AFTER_INPUTTING_FILE << " updates..." << endl;

	//i loop works on the rows
	for (int i = 0; i < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++i) {
		//j loop works on the columns
		for (int j = 0; j < WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE; ++j) {
			//this if formats for the first and last columns
			if (j == 0 || j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_LEFT_AND_RIGHT_BORDER_ROWS;
				//last column
				if (j == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j];
				}
				//first column
				else {
					cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
						<< newArray[i][j] << ",";
				}
			}
			//this else if formats for first and last rows
			else if (i == 0 || i == WIDTH_AND_HEIGHT_DIMMENSION_OF_THE_HOT_PLATE - 1) {
				newArray[i][j] = FIXED_TEMPERATURE_FOR_TOP_AND_BOTTOM_BORDER_ROWS;
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
			//this else formats for all inside values that are not in the first or last rows/columns
			else {
				cout << setw(WIDTH_BETWEEN_NUMBERS_IN_HOT_PLATE) << setprecision(NUMBER_OF_DECIMALS_TO_SHOW_AFTER_DECIMAL)
					<< newArray[i][j] << ",";
			}
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}