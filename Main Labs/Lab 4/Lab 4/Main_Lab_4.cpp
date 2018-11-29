#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <ios>
using namespace std;

/************************************************************************
	HEADER

	David Knight, Section 3, davidpknight3@gmail.com
	Jacob West, Section 3, jacobthewest@gmail.com
	We did this lab exclusively in Visual Studio
	We did proper pair programming

	Test Case 1:
		Input: 
			1
			3
			3
			-1
		Output: 
			Path: [3.0, 3.5, 3.0, 3.5, 3.0, 3.5, 4.0, 3.5, 3.0, 3.5, 4.0, 4.5, 4.0]
			Winnings: $10000.00
			Enter your selection now : 
			Menu: Please select one of the following options:

			1 - Drop a single chip into one slot
			2 - Drop multiple chips into one slot
			3 - Show the options menu
			4 - Quit the program

			Invalid selection.Enter 3 to see options.

			Enter your selection now :

	Test Case 2:
		Input:
			2
			3
			5
		Output: Total winnings on 3 chips: $1000.00
		Average winnings per chip : $333.33
		Enter your selection now :

	Test Case 3:
		Input:
			2
			-5
			4
		Output:
			Invalid number of chips.
			Enter your selection now :
			Goodbye!

************************************************************************/

int main() {

	//Declare Variables

	int iSelection;
	double dSlot;
	double dCurrentPosition;
	const int DROP_SINGLE_CHIP_IN_ONE_SLOT = 1;
	const int DROP_MULTIPLE_CHIPS_IN_ONE_SLOT = 2;
	const int SHOW_OPTIONS_MENU = 3;
	const int QUIT_PROGRAM = 4;
	const int NUMBER_OF_ROWS_IN_PLINKO = 12;	
	const int SEED_VALUE = 42;
	bool bWeAreInTheProgram = true;
	double dWinnings = 0.0;
	double dAvgWinnings = 0.0;
	double dTempWinnings = 0.0;
	int iNumChips = 0;


	srand(SEED_VALUE);
	//-------------------------------------Part 1-----------------------------------//

	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl << endl;
	cout << endl;
	
	while (bWeAreInTheProgram == true) {
		//Re-initialize prevous value calculations
		dWinnings = 0.00;

		cout << "Enter your selection now : ";
		cin >> iSelection;
		cout << endl;

		//Check for invalid input
		while (iSelection < DROP_SINGLE_CHIP_IN_ONE_SLOT || iSelection > QUIT_PROGRAM) {
			cout << "Invalid selection.Enter 3 to see options." << endl << endl;

			cout << "Enter your selection now : ";

			cin >> iSelection;
			cout << endl;
		}

		//----------------------------Option 1--------------------------//
		if (iSelection == DROP_SINGLE_CHIP_IN_ONE_SLOT) {
			cout << "* ** Drop a single chip ***" << endl;
			cout << endl;
			cout << "Which slot do you want to drop the chip in(0 - 8) ?" << endl;
			cin >> dSlot;
			dCurrentPosition = dSlot;

			if (dSlot >= 0 && dSlot <= 8) {

				//Simulate the chip drop
				cout << fixed;
				cout << "*** Dropping chip into slot " << setprecision(0) << dSlot << "***" << endl;
				cout << "Path: [" << setprecision(1) << dSlot << ", ";
				for (int i = 0; i < NUMBER_OF_ROWS_IN_PLINKO; ++i) {
					if (dCurrentPosition == 8.0) {
						dCurrentPosition = dCurrentPosition - 0.5;
						if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
							cout << setprecision(1) << dCurrentPosition << "]" << endl;
						}
						else {
							cout << setprecision(1) << dCurrentPosition << ", ";
						}
					}
					else if (dCurrentPosition == 0.0) {
						dCurrentPosition = dCurrentPosition + 0.5;
						if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
							cout << setprecision(1) << dCurrentPosition << "]" << endl;
						}
						else {
							cout << setprecision(1) << dCurrentPosition << ", ";
						}
					}
					else {
						if (rand() % 2 == 1) {
							dCurrentPosition += 0.5;
							if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
								cout << setprecision(1) << dCurrentPosition << "]" << endl;
							}
							else {
								cout << setprecision(1) << dCurrentPosition << ", ";
							}
						}
						else {
							dCurrentPosition -= 0.5;
							if (i == NUMBER_OF_ROWS_IN_PLINKO - 1) {
								cout << setprecision(1) << dCurrentPosition << "]" << endl;
							}
							else {
								cout << setprecision(1) << dCurrentPosition << ", ";
							}
						}
					}
				}

				// calculate winnings
				if (dCurrentPosition == 0.0 || dCurrentPosition == 8.0) {
					dWinnings = 100;
				}
				else if (dCurrentPosition == 1.0 || dCurrentPosition == 7.0) {
					dWinnings = 500;
				}
				else if (dCurrentPosition == 2.0 || dCurrentPosition == 6.0) {
					dWinnings = 1000;
				}
				else if (dCurrentPosition == 3.0 || dCurrentPosition == 5.0) {
					dWinnings = 0;
				}
				else {
					dWinnings = 10000;
				}
				cout << fixed;
				cout << "Winnings: $" << setprecision(2) << dWinnings << endl;
			}
			else {
				cout << "Invalid slot." << endl;
			}
		}
	

		//----------------------------Option 2--------------------------//
		if (iSelection == DROP_MULTIPLE_CHIPS_IN_ONE_SLOT) {
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			cout << "How many chips do you want to drop (>0)?";
			cin >> iNumChips;
			cout << endl;
			if (iNumChips <= 0) {
				cout << "Invalid number of chips." << endl;
			}
			else {
				cout << "Which slot do you want to drop the chip in(0 - 8) ?" << endl;
				cin >> dSlot;
				dCurrentPosition = dSlot;
				dTempWinnings = 0.00;

				if (dSlot >= 0 && dSlot <= 8) {

					//Simulate the chip drop
					cout << fixed;
					for (int i = 0; i < iNumChips; ++i) {
						dCurrentPosition = dSlot;
						for (int i = 0; i < NUMBER_OF_ROWS_IN_PLINKO; ++i) {
							if (dCurrentPosition == 8.0) {
								dCurrentPosition = dCurrentPosition - 0.5;
							}
							else if (dCurrentPosition == 0.0) {
								dCurrentPosition = dCurrentPosition + 0.5;
							}
							else {
								if (rand() % 2 == 1) {
									dCurrentPosition += 0.5;
								}
								else {
									dCurrentPosition -= 0.5;
								}
							}
						}

						// calculate winnings
						if (dCurrentPosition == 0.0 || dCurrentPosition == 8.0) {
							dTempWinnings = 100;
						}
						else if (dCurrentPosition == 1.0 || dCurrentPosition == 7.0) {
							dTempWinnings = 500;
						}
						else if (dCurrentPosition == 2.0 || dCurrentPosition == 6.0) {
							dTempWinnings = 1000;
						}
						else if (dCurrentPosition == 3.0 || dCurrentPosition == 5.0) {
							dTempWinnings = 0;
						}
						else {
							dTempWinnings = 10000;
						}

						dWinnings += dTempWinnings;
					}
					cout << fixed;
					cout << "Total winnings on " << iNumChips << " chips: $" << setprecision(2) << dWinnings << endl;
					cout << "Average winnings per chip : $" << setprecision(2) << dWinnings / iNumChips << endl;
				}
				else {
					cout << "Invalid slot." << endl;
				}
				
				

			}
		}
		
		//----------------------------Option 3--------------------------//
		if (iSelection == SHOW_OPTIONS_MENU) {
			cout << "Menu: Please select one of the following options:\n" << endl;
			cout << DROP_SINGLE_CHIP_IN_ONE_SLOT << " - Drop a single chip into one slot" << endl;
			cout << DROP_MULTIPLE_CHIPS_IN_ONE_SLOT << " - Drop multiple chips into one slot" << endl;
			cout << SHOW_OPTIONS_MENU << " - Show the options menu" << endl;
			cout << QUIT_PROGRAM << " - Quit the program" << endl;
			cout << endl;
		}
		if (iSelection == QUIT_PROGRAM) {
			break;
		}
	}
	cout << "Goodbye!" << endl;
}