#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <ios>
#include <math.h> 
using namespace std;

/************************************************************************
HEADER

Jacob West, Section 3, jacobthewest@gmail.com
I WAS ABLE TO MAKE THIS CODE WORK BY CHANGING ONLY THE 3 COSNTANT VALUES AS OUTLINED

//----------------Test Case 1:--------//
--Input:
	hey there
	4
	-1
	1
	5
	5
--Output:
	Welcome to the Plinko simulator! Enter 4 to see options.
	
	Enter your selection now:

	Invalid selection. Enter 4 to see options.
	Enter your selection now:
	
	Menu: Please select one of the following options:

	1 - Drop a single chip into one slot
	2 - Drop multiple chips into one slot
	3 - Drop multiple chips into each slot
	4 - Show the options menu
	5 - Quit the program

	Enter your selection now:

	Invalid selection. Enter 4 to see options.
	Enter your selection now:

	* ** Drop a single chip ***

	Which slot do you want to drop the chip in(0 - 8) ?
	*** Dropping chip into slot 5***
	Path: [5.0, 4.5, 4.0, 4.5, 5.0, 4.5, 4.0, 4.5, 4.0, 4.5, 5.0, 4.5, 5.0]
	Winnings: $0.00
	Enter your selection now:

	Goodbye!

//----------------Test Case 2:--------//
--Input:
	2
	f
	4
	90 and chicken
	5
	5
--Output: 
	Welcome to the Plinko simulator! Enter 4 to see options.

	Enter your selection now: 

	*** Drop multiple chips ***

	How many chips do you want to drop (>0)?Invalid number of chips.
	How many chips do you want to drop (>0)?
	Which slot do you want to drop the chip in(0 - 8) ?

	Invalid slot.
	Which slot do you want to drop the chip in(0 - 8) ?
	Total winnings on 4 chips: $10100.00
	Average winnings per chip : $2525.00
	Enter your selection now: 

	Goodbye!

	//----------------Test Case 3:--------//
--Input:
	3
	o
	5
	P
	5
--Output:
	Welcome to the Plinko simulator! Enter 4 to see options.

	Enter your selection now:
	
	*** Sequentially drop multiple chips ***

	How many chips do you want to drop (>0)?Invalid number of chips.
	How many chips do you want to drop (>0)?

	Total winnings on slot 0 chips: 10700.00
	Average winnings per chip : 2140.00

	Total winnings on slot 1 chips: 3100.00
	Average winnings per chip : 620.00

	Total winnings on slot 2 chips: 20500.00
	Average winnings per chip : 4100.00

	Total winnings on slot 3 chips: 12000.00
	Average winnings per chip : 2400.00

	Total winnings on slot 4 chips: 2000.00
	Average winnings per chip : 400.00

	Total winnings on slot 5 chips: 31000.00
	Average winnings per chip : 6200.00

	Total winnings on slot 6 chips: 3600.00
	Average winnings per chip : 720.00

	Total winnings on slot 7 chips: 2100.00
	Average winnings per chip : 420.00

	Total winnings on slot 8 chips: 11500.00
	Average winnings per chip : 2300.00
	Enter your selection now:

	Invalid selection. Enter 4 to see options.
	Enter your selection now:
	
	Goodbye!

************************************************************************/

//Function Declarations
double ComputeWinnings(int slot);
double DropASingleChip(double dCurrentPosition, bool bPrintPath);
void DropMultipleChips(int iNumChips, double dSlot, bool bDropMultipleChipsInOnlyOneSlot, 
	int iPositionInForLoopForDroppingMultipleChipsInMultipleSlots);
void GetMenuOption();
int GetSlot();
int GetNumChips();
int ErrorCheckTheSelection();
int main();

//Magic Numbers

/*
const int NUMBER_OF_ROWS_IN_PLINKO = 18;
const int NUMBER_OF_SLOTS = 7;
const double ARRAY_OF_WINNINGS_PER_SLOT[NUMBER_OF_SLOTS] =
{ 300.00, 200.00, -600.42, 20000.00, 0.01, 800.00, -1400.00 };
*/



const int NUMBER_OF_ROWS_IN_PLINKO = 12;
const int NUMBER_OF_SLOTS = 9;
const double ARRAY_OF_WINNINGS_PER_SLOT[NUMBER_OF_SLOTS] =
{ 100.00, 500.00, 1000.00, 0.00, 10000.00, 0.00, 1000.00, 500.00, 100.00 };


//Global Variables that are NOT magic numbers

const int DROP_SINGLE_CHIP_IN_ONE_SLOT = 1;
const int DROP_MULTIPLE_CHIPS_IN_ONE_SLOT = 2;
const int DROP_MULTIPLE_CHIPS_INTO_EACH_SLOT = 3;
const int SHOW_OPTIONS_MENU = 4;
const int QUIT_PROGRAM = 5;
const int SLOT_FURTHEST_LEFT = 0;
const int SLOT_FURTHEST_RIGHT = NUMBER_OF_SLOTS - 1;
double dWinnings = 0.0;
double dSlot;
double dCurrentPosition;
int iNumChips = 0;
int iSelection;
bool bPrintPath = false;


int main() {

	//Declare Variables
	bool bWeAreInTheProgram = true;
	const int SEED_VALUE = 42;
	bool bDropMultipleChipsInOnlyOneSlot = false;

	srand(SEED_VALUE);
	//-------------------------------------Part 1-----------------------------------//

	cout << "Welcome to the Plinko simulator! Enter " << SHOW_OPTIONS_MENU << " to see options." << endl << endl;
	cout << endl;
	iSelection = ErrorCheckTheSelection();
	cout << endl;

	while (bWeAreInTheProgram == true) {
		//Re-initialize prevous value calculations
		dWinnings = 0.00;

		//----------------------------Option 1--------------------------//
		if (iSelection == DROP_SINGLE_CHIP_IN_ONE_SLOT) {
			cout << "* ** Drop a single chip ***" << endl;
			cout << endl;
			dSlot = GetSlot();
			dCurrentPosition = dSlot;
			bPrintPath = true;
			DropASingleChip(dCurrentPosition, bPrintPath);
			bPrintPath = false;
		}
		//----------------------------Option 2--------------------------//
		if (iSelection == DROP_MULTIPLE_CHIPS_IN_ONE_SLOT) {
			bDropMultipleChipsInOnlyOneSlot = true;
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			iNumChips = GetNumChips();
			dSlot = GetSlot();
			DropMultipleChips(iNumChips, dSlot, bDropMultipleChipsInOnlyOneSlot, 0);
			bDropMultipleChipsInOnlyOneSlot = false;
		}
		//----------------------------Option 3--------------------------//
		if (iSelection == DROP_MULTIPLE_CHIPS_INTO_EACH_SLOT) {
			cout << "*** Sequentially drop multiple chips ***" << endl << endl;
			iNumChips = GetNumChips();
			for (int i = 0; i < NUMBER_OF_SLOTS; ++i) {
				cout << endl;
				DropMultipleChips(iNumChips, static_cast<double>(i), bDropMultipleChipsInOnlyOneSlot, i);
			}
		}
		//----------------------------Option 4--------------------------//
		if (iSelection == SHOW_OPTIONS_MENU) {
			GetMenuOption();
		}

		//----------------------------Option 5--------------------------//
		if (iSelection == QUIT_PROGRAM) {
			break;
		}
		iSelection = ErrorCheckTheSelection();
		cout << endl;
	}
	cout << "Goodbye!" << endl;
}// End of int main()

 //---------FUNCTIONS---------//
double ComputeWinnings(int slot) { 
	double dWinnings = 0.00;
	dWinnings = ARRAY_OF_WINNINGS_PER_SLOT[slot];
	return dWinnings;
}
double DropASingleChip(double dCurrentPosition, bool bPrintPath) {
	if (dCurrentPosition >= SLOT_FURTHEST_LEFT && dCurrentPosition <= SLOT_FURTHEST_RIGHT) {

		//Simulate the chip drop
		if (bPrintPath) {
			cout << fixed;
			cout << "*** Dropping chip into slot " << setprecision(0) << dCurrentPosition << "***" << endl;
			cout << "Path: [" << setprecision(1) << dCurrentPosition << ", ";
		}
		for (int i = 0; i < NUMBER_OF_ROWS_IN_PLINKO; ++i) {
			if (dCurrentPosition == SLOT_FURTHEST_RIGHT) {
				dCurrentPosition = dCurrentPosition - 0.5;
				if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
					if (bPrintPath) {
						cout << setprecision(1) << dCurrentPosition << "]" << endl;
					}
				}
				else {
					if (bPrintPath) {
						cout << setprecision(1) << dCurrentPosition << ", ";
					}
				}
			}
			else if (dCurrentPosition == SLOT_FURTHEST_LEFT) {
				dCurrentPosition = dCurrentPosition + 0.5;
				if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
					if (bPrintPath) {
						cout << setprecision(1) << dCurrentPosition << "]" << endl;
					}
				}
				else {
					if (bPrintPath) {
						cout << setprecision(1) << dCurrentPosition << ", ";
					}
				}
			}
			else {
				if (rand() % 2 == 1) {
					dCurrentPosition += 0.5;
					if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
						if (bPrintPath) {
							cout << setprecision(1) << dCurrentPosition << "]" << endl;
						}
					}
					else {
						if (bPrintPath) {
							cout << setprecision(1) << dCurrentPosition << ", ";
						}
					}
				}
				else {
					dCurrentPosition -= 0.5;
					if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
						if (bPrintPath) {
							cout << setprecision(1) << dCurrentPosition << "]" << endl;
						}
					}
					else {
						if (bPrintPath) {
							cout << setprecision(1) << dCurrentPosition << ", ";
						}
					}
				}
			}
		}

		if (bPrintPath) {
			cout << fixed;
			cout << "Winnings: $" << setprecision(2) << ComputeWinnings(static_cast<int>(dCurrentPosition)) << endl;
		}
			//for the DropMultipleChips function we need to return the position of the chip
			return dCurrentPosition;
	}
	else {
		cout << "Invalid slot." << endl;
	}
}
void DropMultipleChips(int iNumChips, double dSlot, bool bDropMultipleChipsInOnlyOneSlot, int iPositionInForLoopForDroppingMultipleChipsInMultipleSlots) {
	double dTempWinnings = 0.00;
	dCurrentPosition = dSlot;
	dWinnings = 0.00;
	

	if (dSlot >= SLOT_FURTHEST_LEFT && dSlot <= SLOT_FURTHEST_RIGHT) {

		//Simulate the chip drop
		cout << fixed;
		for (int i = 0; i < iNumChips; ++i) {
			//Find the final point of the chip
			dCurrentPosition = dSlot;
			dCurrentPosition = DropASingleChip(dCurrentPosition, bPrintPath);

			// calculate winnings
			dTempWinnings = ComputeWinnings(static_cast<int>(dCurrentPosition));
			dWinnings += dTempWinnings;
		}
		cout << fixed;
		if (bDropMultipleChipsInOnlyOneSlot) {
			cout << "Total winnings on " << iNumChips << " chips: $" << setprecision(2) << dWinnings << endl;
			cout << "Average winnings per chip : $" << setprecision(2) << dWinnings / iNumChips << endl;
		}
		else {
			cout << "Total winnings on slot " << iPositionInForLoopForDroppingMultipleChipsInMultipleSlots << " chips: " << setprecision(2) << dWinnings << endl;
			cout << "Average winnings per chip : " << setprecision(2) << dWinnings / iNumChips << endl;
		}
	}
	else {
		cout << "Invalid slot." << endl;
	}
}
void GetMenuOption() {
	cout << "Menu: Please select one of the following options:\n" << endl;
	cout << DROP_SINGLE_CHIP_IN_ONE_SLOT << " - Drop a single chip into one slot" << endl;
	cout << DROP_MULTIPLE_CHIPS_IN_ONE_SLOT << " - Drop multiple chips into one slot" << endl;
	cout << DROP_MULTIPLE_CHIPS_INTO_EACH_SLOT << " - Drop multiple chips into each slot" << endl;
	cout << SHOW_OPTIONS_MENU << " - Show the options menu" << endl;
	cout << QUIT_PROGRAM << " - Quit the program" << endl;
	cout << endl;
}
int ErrorCheckTheSelection() {
	cout << "Enter your selection now: " << endl;
	cin >> iSelection;
	if (cin.fail() || iSelection < DROP_SINGLE_CHIP_IN_ONE_SLOT || iSelection > QUIT_PROGRAM) {
		do {
			// This means if the cin crashes (because they put a
			// string for an int or something).
			cin.clear(); //This will clear the fail flag
			cin.ignore(1000, '\n'); // This will ignore all input until the leftover “new line” so
									// it isn’t pushed into your variable.a
			cout << endl << "Invalid selection. Enter " << SHOW_OPTIONS_MENU << " to see options." << endl;
			cout << "Enter your selection now: " << endl;
			cin >> iSelection;
		} while (cin.fail() || iSelection < DROP_SINGLE_CHIP_IN_ONE_SLOT || iSelection > QUIT_PROGRAM);
	}
	cout << endl;
	return iSelection;
}
int GetSlot() {
	cout << "Which slot do you want to drop the chip in(" << SLOT_FURTHEST_LEFT << " - " << SLOT_FURTHEST_RIGHT << ") ?" << endl;
	cin >> dSlot;
	while (cin.fail() || dSlot < SLOT_FURTHEST_LEFT || dSlot > SLOT_FURTHEST_RIGHT) { // This means if the cin crashes (because they put a
						 // string for an int or something).
		cin.clear(); //This will clear the fail flag
		cin.ignore(1000, '\n'); // This will ignore all input until the leftover “new line” so
								// it isn’t pushed into your variable.
		cout << endl << "Invalid slot." << endl;
		cout << "Which slot do you want to drop the chip in(" << SLOT_FURTHEST_LEFT << " - " << SLOT_FURTHEST_RIGHT << ") ?" << endl;
		cin >> dSlot;
	}
	return static_cast<int>(dSlot);	
}
int GetNumChips() {
	cout << "How many chips do you want to drop (>0)?";
	cin >> iNumChips;
	while (cin.fail() || iNumChips <= 0) { // This means if the cin crashes (because they put a
																					  // string for an int or something).
		cin.clear(); //This will clear the fail flag
		cin.ignore(1000, '\n'); // This will ignore all input until the leftover “new line” so
								// it isn’t pushed into your variable.
		cout << "Invalid number of chips." << endl;
		cout << "How many chips do you want to drop (>0)?";
		cin >> iNumChips;
		cout << endl;
	}
	return static_cast<int>(iNumChips);
}