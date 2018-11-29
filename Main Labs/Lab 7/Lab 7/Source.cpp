#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/***************************************
HEADER:

Jacob West, Section 3, jacobthewest@gmail.com

***NOTE*** 
For the test cases, I did my best to show only what the program would output differently from the user input,
I didn't want to show the repeated output that guides the user through the program because I wanted to make
it easier for you to grade. I hope I helped:) Please comment and let me know if that actually does help
so I can know if I should keep doing it in the future. Thanks for grading this!

TEST CASE 1
	Input:
		hello
		add
		Taco Bell
		add
		McDonalds
		add
		Wendy's
		add
		McDonalds
		shuffle
		display
		remove
		Wendy's
		display
		quit
	Output:
		Invalid selection
		Please select one of the following options:

		quit - Quit the program
		display - Display all restaurants
		add - Add a restaurant
		remove - Remove a restaurant
		cut - "Cut" the list of restaurants
		shuffle - "Shuffle" the list of restaurants
		battle - Begin the tournament
		options - Print the options menu

		Taco Bell has been added. 
		McDonalds has been added.
		Wendy's has been added.
		That restaurant is already on the list, you can not add it again.
		The current tournament size(3) is not a power of two(2, 4, 8...).
		A shuffle is not possible. Please add or remove restaurants.
		Here are the current restaurants:
			"Taco Bell"
			"McDonalds"
			"Wendy's"
		Wendy's has been removed.
		Here are the current restaurants:
			"Taco Bell"
			"McDonalds"
		Goodbye!
TEST CASE 2
	Input:
		add
		Zupas
		add
		BBQ Diner
		add
		Arby's
		add
		Carl's Jr.	
		display
		cut 
		30
		3
		display
		shuffle
		display
	Output:
		Zupas has been added.
		BBQ Diner has been added.
		Arby's has been added.
		Enter your selection: 
		Carl's Jr. has been added.
		Here are the current restaurants:
			"Zupas"
			"BBQ Diner"
			"Arby's"
			"Carl's Jr.	"
		The cut number must be between 0 and 4
		Here are the current restaurants:
			"Carl's Jr.	"
			"Zupas"
			"BBQ Diner"
			"Arby's"
		Here are the current restaurants:
			"BBQ Diner"
			"Carl's Jr.	"
			"Arby's"
			"Zupas"
		Goodbye!
TEST CASE 3
	Input:
		add
		1
		add
		2
		add
		3
		add
		4
		options
		battle
		1
		Chicken Squeeze
		2
		1
		quit
	Output:
		1 has been added.
		2 has been added.
		3 has been added.
		4 has been added.

		Please select one of the following options:

		quit - Quit the program
		display - Display all restaurants
		add - Add a restaurant
		remove - Remove a restaurant
		cut - "Cut" the list of restaurants
		shuffle - "Shuffle" the list of restaurants
		battle - Begin the tournament
		options - Print the options menu

		Round:1

		Type "1" if you prefer 1 or
		type "2" if you prefer 2
		Choice: 
		Type "1" if you prefer 3 or
		type "2" if you prefer 4
		Choice: 
		Invalid choice
		Type "1" if you prefer 3 or
		type "2" if you prefer 4
		Choice: 
		Round:2

		Type "1" if you prefer 1 or
		type "2" if you prefer 4
		Choice: 
		The winning restaurant is 1.
		Goodbye!

****************************************/

void displayMenu();
string checkSelection(string sSelection);
void addRestaurant();
void displayRestaurants();
bool Find(string sSearch, vector<string> listOfRestaurants);
void removeRestaurant();
void cutTheRestaurants();
void shuffleTheRestaurants();
bool checkPowerOf2();
void battleTheRestaurants();
string errorCheckBattleInput(int i, vector<string>& restaurantBattleOld);

//Global Variables
string sSelection;
const string QUIT_PROGRAM = "quit";
const string DISPLAY_RESTAURANTS = "display";
const string ADD_A_RESTAURANT = "add";
const string REMOVE_A_RESTAURANT = "remove";
const string CUT_THE_LIST_OF_RESTAURANTS = "cut";
const string SHUFFLE_THE_LIST_OF_RESTAURANTS = "shuffle";
const string BEGIN_THE_TOURNAMENT = "battle";
const string PRINT_THE_OPTIONS_MENU = "options";
vector<string> listOfRestaurants;
const int RESTAURANT_ONE = 1;
const int RESTAURANT_TWO = 2;


int main() {
	
	//bool to keep us in the menu loop until the user enters quit and forces us out.
	bool bWeAreInTheMenu = true;

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;

	while (bWeAreInTheMenu) {
		cout << "Enter your selection: ";
		cin >> sSelection;
		cout << endl;
		sSelection = checkSelection(sSelection);

		//If statement train for each menu option
		if (sSelection == QUIT_PROGRAM) {
			bWeAreInTheMenu = false;
		}
		else if (sSelection == DISPLAY_RESTAURANTS) {
			displayRestaurants();
		}
		else if (sSelection == ADD_A_RESTAURANT) {
			addRestaurant();
		}
		else if (sSelection == REMOVE_A_RESTAURANT) {
			removeRestaurant();
		}
		else if (sSelection == CUT_THE_LIST_OF_RESTAURANTS) {
			cutTheRestaurants();
		}
		else if (sSelection == SHUFFLE_THE_LIST_OF_RESTAURANTS) {
			shuffleTheRestaurants();
		}
		else if (sSelection == BEGIN_THE_TOURNAMENT) {
			battleTheRestaurants();
		}
		else if (sSelection == PRINT_THE_OPTIONS_MENU) {
			cout << endl;
			displayMenu();
			cout << endl;
		}		
	}
	cout << "Goodbye!" << endl;
}

void displayMenu() {
	cout << "Please select one of the following options:" << endl << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
}
string checkSelection(string sSelection) {
	

	// || sSelection != QUIT_PROGRAM || sSelection != ADD_A_RESTAURANT || sSelection != CUT_THE_LIST_OF_RESTAURANTS
	//|| sSelection != SHUFFLE_THE_LIST_OF_RESTAURANTS || sSelection != BEGIN_THE_TOURNAMENT || sSelection != PRINT_THE_OPTIONS_MENU

	//handles string input that does not equal one of the options
	if (!cin.fail()) {

		if (sSelection == QUIT_PROGRAM || sSelection == ADD_A_RESTAURANT || sSelection == CUT_THE_LIST_OF_RESTAURANTS
			|| sSelection == SHUFFLE_THE_LIST_OF_RESTAURANTS || sSelection == BEGIN_THE_TOURNAMENT || sSelection == PRINT_THE_OPTIONS_MENU 
			|| sSelection == DISPLAY_RESTAURANTS || sSelection == REMOVE_A_RESTAURANT) {
			//Do nothing
		}
		else {
			do {
				cout << "Invalid selection" << endl;
				displayMenu();
				cout << endl << "Enter your selection: ";
				cin >> sSelection;
			} while (cin.fail() || !(sSelection == QUIT_PROGRAM || sSelection == ADD_A_RESTAURANT || sSelection == CUT_THE_LIST_OF_RESTAURANTS
				|| sSelection == SHUFFLE_THE_LIST_OF_RESTAURANTS || sSelection == BEGIN_THE_TOURNAMENT || sSelection == PRINT_THE_OPTIONS_MENU 
				|| sSelection == DISPLAY_RESTAURANTS || sSelection == REMOVE_A_RESTAURANT));
		}
	}
	//handles non string input that is entered the first time
	else {
		while (cin.fail()) {
			// This means if the cin crashes (because they put a
			// string for an int or something).
			cin.clear(); //This will clear the fail flag
			cin.ignore(1000, '\n'); // This will ignore all input until the leftover “new line” so
									// it isn’t pushed into your variable.
			cout << "Invalid selection" << endl;
			cout << "Please select one of the following options:" << endl << endl;
			displayMenu();
			cout << endl << endl << "Enter your selection: ";
			cin >> sSelection;
			cout << endl;
		}
	}
	return sSelection;
}
void addRestaurant() {
	string restaurantName;
	cout << "What is the name of the restaurant you want to add? ";
	cin.ignore();
	getline(cin, restaurantName);
	cout << endl;
	while (cin.fail()) {
		cout << "Invalid input." << endl;
		cout << "What is the name of the restaurant you want to add ?";
		getline(cin, restaurantName);
		cout << endl;
	}
	bool bRestaurantAlreadyExists = Find(restaurantName, listOfRestaurants);
	if (bRestaurantAlreadyExists) {
		cout << endl << "That restaurant is already on the list, you can not add it again." << endl;
	}
	else {
		listOfRestaurants.push_back(restaurantName);
		cout << listOfRestaurants[listOfRestaurants.size() - 1] << " has been added." << endl;
	}
}
void displayRestaurants() {
	cout << "Here are the current restaurants:" << endl;
	for (unsigned int i = 0; i < listOfRestaurants.size(); ++i) {
		cout << "\t\"" << listOfRestaurants[i] << "\"" << endl;
	}
}
bool Find(string sSearch, vector<string> listOfRestaurants) {
	bool bWeFoundAnExistingRestaurant = false;
	int iPosition;	
	if (find(listOfRestaurants.begin(), listOfRestaurants.end(), sSearch) != listOfRestaurants.end()) {
		bWeFoundAnExistingRestaurant = true;
	}

	return bWeFoundAnExistingRestaurant;
}
void removeRestaurant() {
	string sRemoveThisRestaurant;
	bool bRestaurantExists = false;
	int iRemoveIndex;

	cout << "What is the name of the restaurant you want to remove?";
	cin.ignore(10000, '\n');
	getline(cin, sRemoveThisRestaurant);
	cout << endl;

	//Does the restaurant exist in the vector?
	bRestaurantExists = Find(sRemoveThisRestaurant, listOfRestaurants);
	if (bRestaurantExists) {
		for (unsigned int i = 0; i < listOfRestaurants.size(); ++i) {

			//compare searched name for a match in the vector
			if (listOfRestaurants[i] == sRemoveThisRestaurant) {
				iRemoveIndex = i;
			}
		}

		//remove the restaurant from the list
		cout << listOfRestaurants[iRemoveIndex] << " has been removed." << endl;
		listOfRestaurants.erase(listOfRestaurants.begin() + iRemoveIndex);			
	}
	else {
		cout << "That restaurant is not on the list, you can not remove it." << endl;
	}
}
void cutTheRestaurants() {
	int iCutNum = 0;
	bool bWeHaveANumberInRange = false;
	vector<string> tempVector;

	while (!bWeHaveANumberInRange) {
		cout << "How many restaurants should be taken from the top and put on the bottom? ";
		cin >> iCutNum;

		if (cin.fail() || iCutNum < 0 || iCutNum > listOfRestaurants.size()) {
			// This means if the cin crashes (because they put a
			// string for an int or something).
			cin.clear(); //This will clear the fail flag
			cin.ignore(1000, '\n'); // This will ignore all input until the leftover “new line” so
									// it isn’t pushed into your variable.
			cout << endl << "The cut number must be between " << 0 << " and " << listOfRestaurants.size() << endl;
		}
		else {
			bWeHaveANumberInRange = true;
		}		
	}
	
	//Put cut values in a temporary vector
	for (int i = 0; i < iCutNum; ++i) {
		tempVector.push_back(listOfRestaurants[0]);
		listOfRestaurants.erase(listOfRestaurants.begin() + 0);
	}

	//for loop to copy cut values stored in temporary vector to the end of the listOfRestaurants vector
	for (int i = 0; i < iCutNum; ++i) {
		listOfRestaurants.push_back(tempVector[i]);
	}
}
void shuffleTheRestaurants() {	
	int n = listOfRestaurants.size();
	vector<string> tempHalf(n / 2);
	bool bIsAPowerOf2 = checkPowerOf2();

	//shuffle the deck if the size of the vector is a power of 2
	if (bIsAPowerOf2) {

		//----copy back half of listOfRestaurants to a temporary array---//
		//counter for our tempHalf vector to insert value from listOfRestaurants into the right position
		int j = 0;
		for (unsigned int i = n / 2; i < n; ++i) {
			tempHalf.at(j) = listOfRestaurants[i];
			j++;
		}

		//erase second half of the listOfRestaurants array
		for (unsigned int i = n / 2; i < n; ++i) {
			listOfRestaurants.erase(listOfRestaurants.begin() + (n / 2)); //this will constantly delete the position 
																		  //immediately after the halfway point as the
																		  //vector is compressed after each iteration
		}		

		//--loop to shuffle the restaurants--//
		//counter for the position in the temporary vector
		int iTempCounter = 0;
		for (unsigned int i = 0; i < n; i += 2) {
			
			//add every other index element
			listOfRestaurants.insert(listOfRestaurants.begin() + i, tempHalf[iTempCounter]); 

			//Keep this independent of the increment in the for loop
			iTempCounter++;
		}

		/*
			//FIXME: This is to output the new values of our listOfRestaurants to see what we have now
			for (int i = 0; i < n; i++)
			{
				cout << listOfRestaurants[i] << endl;
			}		
		*/
	}
	//deck is not a power of 2
	else {
		cout << "The current tournament size(" << listOfRestaurants.size() << ") is not a power of two(2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}
	
	
}
bool checkPowerOf2() {
	int n = listOfRestaurants.size();
	bool bIsAPowerOf2;
	//set bIsAPowerOf2 if listOfRestaurants has zero or more elements
	//src = http://www.graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
	if (n == 0) {
		//for an empty vector
		bIsAPowerOf2 = false;
	}
	else {
		//for a vector that has >= 0 elements
		bIsAPowerOf2 = (n & (n - 1)) == 0;
	}

	return bIsAPowerOf2;
}
void battleTheRestaurants() {
	bool bIsAPowerOf2 = checkPowerOf2();
	vector<string> restaurantBattleOld = listOfRestaurants;
	int iSize = restaurantBattleOld.size();
	vector<string> restaurantBattleNew(iSize / 2);
	int roundCounter = 1;

	if (bIsAPowerOf2) {
		//The battle begins...	

		while (iSize >= 1) {
			cout << "Round:" << roundCounter << endl << endl;
			//compare two restaurants
			int iCounterForRestaurantBattleNew = 0;
			for (unsigned int i = 1; i <= restaurantBattleOld.size(); i+=2) {
				string sChosenRestaurant = errorCheckBattleInput(i, restaurantBattleOld); //iChoice is what restaurant they chose. 
																	 //Now store the winning restaurant accordingly.
				restaurantBattleNew.at(iCounterForRestaurantBattleNew) = sChosenRestaurant;
				iCounterForRestaurantBattleNew++;
			}
			//The winning restaurants have been added, now we need to make the old vector equal to the new vector and
			//resize the new array to be half of its size.

			iSize = restaurantBattleNew.size() / 2; //Makes our size half that of the old vector
			restaurantBattleOld = restaurantBattleNew; //they are now equal to each other in size and values
			if (iSize > 0) {
				restaurantBattleNew.resize(iSize); //The new vector is now half the size of the old vector only if we do not have a champion
			}
			roundCounter++;
		}
		cout << "The winning restaurant is " << restaurantBattleNew.at(0) <<"." << endl;
	}
	else {
		//The battle can't happen. Bummer, dude.
		cout << "The current tournament size (" << listOfRestaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
}
string errorCheckBattleInput(int i, vector<string>& restaurantBattleOld) {
	int iChoice;
	string chosenRestaurant;

		cout << "Type \"1\" if you prefer " << /*restaurantBattleOld.at(i - 1)*/ restaurantBattleOld.at(i - 1) << " or" << endl;
		cout << "type \"2\" if you prefer " << /*restaurantBattleOld.at(restaurantBattleOld.size() - i)*/ restaurantBattleOld.at(i) << endl;
		cout << "Choice: ";
		cin >> iChoice;
		cout << endl;

		while (cin.fail() || iChoice < RESTAURANT_ONE || iChoice > RESTAURANT_TWO) {
			cout << "Invalid choice" << endl;
			cout << "Type \"1\" if you prefer " << /*restaurantBattleOld.at(i - 1)*/ restaurantBattleOld.at(i - 1) << " or" << endl;
			cout << "type \"2\" if you prefer " << /*restaurantBattleOld.at(restaurantBattleOld.size() - i)*/ restaurantBattleOld.at(i) << endl;
			cout << "Choice: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> iChoice;
			cout << endl;
		}

	if (iChoice == RESTAURANT_ONE) {
		chosenRestaurant = restaurantBattleOld.at(i - 1);
	}
	else {
		chosenRestaurant = restaurantBattleOld.at(i);
	}

	return chosenRestaurant;
}

