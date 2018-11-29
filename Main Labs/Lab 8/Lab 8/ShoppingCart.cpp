//class definitions	
#include <iostream> //cin and cout statements
#include <iomanip>
#include <ios>
using namespace std;

#include "ShoppingCart.h"

//Definitions go here

//----Constructors-----//
ShoppingCart::ShoppingCart() {
	this->customerName = "none";
	this->dateOfCart = "January 1, 2016";
};
ShoppingCart::ShoppingCart(string sCustomerName, string sDateOfCart) {
	this->customerName = sCustomerName;
	this->dateOfCart = sDateOfCart;
};

//-----Getters--------//
string ShoppingCart::GetCustomerName() const{
	return customerName;
}
string ShoppingCart::GetDateOfCartCreation() const {
	return dateOfCart;
}
int ShoppingCart::GetTotalQuantityOfAllItems() const {
	int iTotalQty = 0;
	//Get the quantity and add it to our running total
	for (unsigned int i = 0; i < listOfItems.size(); ++i) {
		iTotalQty += listOfItems.at(i).GetQuantity();
	}

	return iTotalQty;
}
double ShoppingCart::GetTotalCostOfAllItems() const {
	double dTotalCost = 0.00;

	for (unsigned int i = 0; i < listOfItems.size(); i++) {
		dTotalCost += (listOfItems.at(i).GetPrice() * listOfItems.at(i).GetQuantity());
	}

	return dTotalCost;
}

//Other Functions
void ShoppingCart::AddItemToCart(ItemToPurchase oItem) {

	string sName = oItem.GetName();
	bool bItemAlreadyExists = false;

	//loop to filter through listOfItems to see if the Item already exists
	for (unsigned int i = 0; i < listOfItems.size(); ++i) {
		
		if (listOfItems.at(i).GetName() == sName) {
			cout << "Item is already in cart. Nothing added." << endl << endl;
			bItemAlreadyExists = true;
			i = listOfItems.size(); //forces us to quit the loop
		}
	}
	//Adds the item to the list if it doesn't already exist
	if (!bItemAlreadyExists) {
		listOfItems.push_back(oItem);
		cout << endl << endl;
	}
}
void ShoppingCart::RemoveItemFromCart(string sItemName) {
	int iLocationOfItem;
	bool bItemExists = true;
	//loop to remoe an item from the cart if it exists
	for (unsigned int i = 0; i < listOfItems.size(); ++i) {
		//if we haven't found it and we are at the end of listOfItems...
		if (listOfItems.at(i).GetName() != sItemName && i == listOfItems.size() - 1) {
			cout << "Item not found in cart. Nothing removed." << endl;
			bItemExists = false;
		}
		else if (listOfItems.at(i).GetName() == sItemName) {
			iLocationOfItem = i;
			i = listOfItems.size(); //forces us to quit the loop
		}
	}
	
	//Removes the object because we found it
	if (bItemExists) {
		listOfItems.erase(listOfItems.begin() + iLocationOfItem); //This is resizing the array to 1
	}
}
void ShoppingCart::UpdateQuantityOfItem(string sItemName) {
	int iItemQty;
	int iLocationOfItem;
	bool bItemExists = true;
	cout << "Enter the new quantity : ";
	cin >> iItemQty;
	cout << endl;
	//loop to see if the item exists
	for (unsigned int i = 0; i < listOfItems.size(); ++i) {
		//if we haven't found it and we are at the end of listOfItems...
		if (listOfItems.at(i).GetName() != sItemName && i == listOfItems.size() - 1) {
			cout << "Item not found in cart. Nothing modified." << endl;
			bItemExists = false;
		}
		else if(listOfItems.at(i).GetName() == sItemName) {
			iLocationOfItem = i;
			i = listOfItems.size(); //forces us to quit the loop
		}
	}
	//Updates the quantity because we found it
	if(bItemExists) {
		listOfItems.at(iLocationOfItem).SetQuantity(iItemQty); //officially set/update the item quantity instance variable
	}
}
void ShoppingCart::PrintTotalNumberAndCostOfItems() const {
	cout << fixed;
	cout << customerName << "\'s Shopping Cart - " << GetDateOfCartCreation() << endl;

	if (listOfItems.size() == 0) {
		cout << "Shopping cart is empty." << endl << endl;
	}
	else {
		cout << "Number of Items : " << GetTotalQuantityOfAllItems() << endl << endl;

		for (unsigned int i = 0; i < listOfItems.size(); ++i) {
			cout << listOfItems.at(i).GetName() << " " << listOfItems.at(i).GetQuantity() << " @ $" << setprecision(2) << listOfItems.at(i).GetPrice()
				<< " = $" << setprecision(2) << (listOfItems.at(i).GetQuantity() * listOfItems.at(i).GetPrice()) << endl;
		}
		cout << endl << "Total: $" << setprecision(2) << GetTotalCostOfAllItems() << endl << endl;
	}
}
void ShoppingCart::PrintDescriptionOfItems() const {
	cout << customerName << "\'s Shopping Cart - " << GetDateOfCartCreation() << endl;
	if (listOfItems.size() == 0) {
		cout << "Shopping cart is empty." << endl << endl;
	}
	else {
		cout << "Item Descriptions" << endl;
		//for loop to print all of the items and their descriptions
		for (unsigned int i = 0; i < listOfItems.size(); ++i) {
			cout << listOfItems.at(i).GetName() << " : " << listOfItems.at(i).GetDescription() << endl;
		}
		cout << endl;
	}
}