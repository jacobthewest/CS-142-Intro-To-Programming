/***********************************
HEADER
Jacob West, Section 3, jacobthewest@gmail.com

TEST CASE 1
--Input--
	DJ Baby Bach Choi
	June 6, 2018
	options
	add
	Bottle
	This will feed the beast
	2.50
	2
	add
	Spin Table
	To mix the beats yo!
	259.99
	1
	add
	Swag Rag
	To wipe the sweat from the Bach Choi's face while he is spinning sick records
	1.50
	11
	descriptions
	cart
	quit
--Output--
	MENU
	add - Add item to cart
	remove - Remove item from cart
	change - Change item quantity
	descriptions - Output items' descriptions
	cart - Output shopping cart
	options - Print the options menu
	quit - Quit

	Enter the item name : Bottle
	Enter the item description : This will feed the beast
	Enter the item price : 2.50
	Enter the item quantity : 2


	Enter the item name : Spin Table
	Enter the item description : To mix the beats yo!
	Enter the item price : 259.99
	Enter the item quantity : 1


	Enter the item name : Swag Rag
	Enter the item description : To wipe the sweat from the Bach Choi's face while he is spinning sick records
	Enter the item price : 1.50
	Enter the item quantity : 11


	DJ Baby Bach Choi's Shopping Cart - June 6, 2018
	Item Descriptions
	Bottle : This will feed the beast
	Spin Table : To mix the beats yo!
	Swag Rag : To wipe the sweat from the Bach Choi's face while he is spinning sick records


	DJ Baby Bach Choi's Shopping Cart - June 6, 2018
	Number of Items : 14

	Bottle 2 @ $2.50 = $5.00
	Spin Table 1 @ $259.99 = $259.99
	Swag Rag 11 @ $1.50 = $16.50

	Total: $281.49

	Goodbye.
TEST CASE 2
--Input--
	DJ Baby Bach Choi
	June 6, 2018
	options
	add
	Bottle
	This will feed the beast
	2.50
	2
	add
	Spin Table
	To mix the beats yo!
	259.99
	1
	add
	Swag Rag
	To wipe the sweat from the Bach Choi's face while he is spinning sick records
	1.50
	11
	change
	;lakdsf
	4
	change
	Swag Rag
	2
	quit
--Output--
	MENU
	add - Add item to cart
	remove - Remove item from cart
	change - Change item quantity
	descriptions - Output items' descriptions
	cart - Output shopping cart
	options - Print the options menu
	quit - Quit

	Enter the item name : Bottle
	Enter the item description : This will feed the beast
	Enter the item price : 2.50
	Enter the item quantity : 2


	Enter option : add
	Enter the item name : Spin Table
	Enter the item description : To mix the beats yo!
	Enter the item price : 259.99
	Enter the item quantity : 1


	Enter the item name : Swag Rag
	Enter the item description : To wipe the sweat from the Bach Choi's face while he is spinning sick records
	Enter the item price : 1.50
	Enter the item quantity : 11


	Enter option : change
	Enter the item name : ;lakdsf
	Enter the new quantity : 4
	Item not found in cart. Nothing modified.


	Enter the item name : Swag Rag
	Enter the new quantity : 2

	Goodbye.
TEST CASE 3
--Input--
	DJ Baby Bach Choi
	June 6, 2018
	options
	add
	Bottle
	This will feed the beast
	2.50
	2
	add
	Spin Table
	To mix the beats yo!
	259.99
	1
	add
	Swag Rag
	To wipe the sweat from the Bach Choi's face while he is spinning sick records
	1.50
	11
	remove
	;lakdsf
	remove
	Swag Rag
	quit
--Output--
	MENU
	add - Add item to cart
	remove - Remove item from cart
	change - Change item quantity
	descriptions - Output items' descriptions
	cart - Output shopping cart
	options - Print the options menu
	quit - Quit

	Enter the item name : Bottle
	Enter the item description : This will feed the beast
	Enter the item price : 2.50
	Enter the item quantity : 2


	Enter the item name : Spin Table
	Enter the item description : To mix the beats yo!
	Enter the item price : 259.99
	Enter the item quantity : 1


	Enter the item name : Swag Rag
	Enter the item description : To wipe the sweat from the Bach Choi's face while he is spinning sick records
	Enter the item price : 1.50
	Enter the item quantity : 11


	Enter name of the item to remove : ;lakdsf
	Item not found in cart. Nothing removed.
	Enter option : remove
	Enter name of the item to remove : Swag Rag
	Enter option : quit

	Goodbye.
***********************************/

#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

//Global Variables
const string ADD_ITEM = "add";
const string REMOVE_ITEM = "remove";
const string CHANGE_ITEM_QUANTITY = "change";
const string OUTPUT_ITEM_DESCRIPTIONS = "descriptions";
const string OUTPUT_CART = "cart";
const string PRINT_OPTIONS_MENU = "options";
const string QUIT_PROGRAM = "quit";
string sChoice;
double dItemPrice;
int iItemQty;

//Functions for main.cpp
void PrintOptionsMenu() {
	cout << "MENU" << endl;
	cout << ADD_ITEM << " - Add item to cart" << endl;
	cout << REMOVE_ITEM << " - Remove item from cart" << endl;
	cout << CHANGE_ITEM_QUANTITY << " - Change item quantity" << endl;
	cout << OUTPUT_ITEM_DESCRIPTIONS << " - Output items' descriptions" << endl;
	cout << OUTPUT_CART << " - Output shopping cart" << endl;
	cout << PRINT_OPTIONS_MENU << " - Print the options menu" << endl;
	cout << QUIT_PROGRAM << " - Quit" << endl << endl;
}
string ErrorCheckAndReturnOption() {
	cin >> sChoice;
	while (cin.fail() || !(sChoice == ADD_ITEM || sChoice == REMOVE_ITEM || sChoice == CHANGE_ITEM_QUANTITY
		|| sChoice == OUTPUT_ITEM_DESCRIPTIONS || sChoice == OUTPUT_CART || sChoice == PRINT_OPTIONS_MENU 
		|| sChoice == QUIT_PROGRAM)) {
		PrintOptionsMenu();
		cout << "Enter option: " << endl;
		cin.clear(); //This will clear the fail flag
		cin.ignore(1000, '\n'); //This will ignore all input until the leftover “new line” so
			// it isn’t pushed into your variable.
		cin >> sChoice;
	}
	return sChoice;
}
double ErrorCheckAndReturnPrice() {
	cin >> dItemPrice;
	while (cin.fail()) {
		cout << "Invalid input. Try again: ";
		cin.clear(); //This will clear the fail flag
		cin.ignore(1000, '\n'); //This will ignore all input until the leftover “new line” so
								// it isn’t pushed into your variable.
		cin >> dItemPrice;
		cout << endl;
	}
	return dItemPrice;
}

int ErrorCheckAndReturnQuantity() {
	cin >> iItemQty;
	while (cin.fail()) {
		cout << "Invalid input. Try again: ";
		cin.clear(); //This will clear the fail flag
		cin.ignore(1000, '\n'); //This will ignore all input until the leftover “new line” so
								// it isn’t pushed into your variable.
		cin >> iItemQty;
		cout << endl;
	}
	return iItemQty;
}

int main() {
	string sCustomerName;
	string sDate;
	string sItemName;
	string sItemDescription;
	bool bWeAreInTheProgram = true;

	
	cout << "Enter Customer\'s Name: ";
	getline(cin, sCustomerName);
	cout << endl;
	cout << "Enter Today\'s Date: ";
	getline(cin, sDate);
	cout << endl;
	ShoppingCart oCustomer(sCustomerName, sDate);
	

	while (bWeAreInTheProgram) {
		cout << "Enter option : ";
		sChoice = ErrorCheckAndReturnOption();
		cout << endl;

		if (sChoice == ADD_ITEM) {
			cin.ignore();
			cout << "Enter the item name : ";			
			//cout << flush;
			getline(cin, sItemName);
			cout << endl;
			cout << "Enter the item description : ";
			getline(cin, sItemDescription);
			cout << endl;
			cout << "Enter the item price : ";
			dItemPrice = ErrorCheckAndReturnPrice();
			cout << endl;
			cout << "Enter the item quantity : ";
			iItemQty = ErrorCheckAndReturnQuantity();
			cout << endl << endl;

			ItemToPurchase oItem(sItemName, sItemDescription, dItemPrice, iItemQty);
			oCustomer.AddItemToCart(oItem);
		}
		else if (sChoice == REMOVE_ITEM) {
			cout << "Enter name of the item to remove : ";
			cin.ignore();
			getline(cin, sItemName);
			cout << endl;
			oCustomer.RemoveItemFromCart(sItemName);
		}
		else if (sChoice == CHANGE_ITEM_QUANTITY) {
			cout << "Enter the item name : ";
			cin.ignore();
			getline(cin, sItemName);
			cout << endl;
			oCustomer.UpdateQuantityOfItem(sItemName);
		}
		else if (sChoice == OUTPUT_ITEM_DESCRIPTIONS) {
			oCustomer.PrintDescriptionOfItems();
		}
		else if (sChoice == OUTPUT_CART) {
			oCustomer.PrintTotalNumberAndCostOfItems();
		}
		else if (sChoice == PRINT_OPTIONS_MENU) {
			PrintOptionsMenu();
		}
		else if (sChoice == QUIT_PROGRAM) {
			bWeAreInTheProgram = false;
		}
	}
	cout << "Goodbye." << endl;
	return 0;
}

