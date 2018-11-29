//class definitions	
#include <iostream> //cin and cout statements
#include <ios>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

//----Constructors----//
//Default constructor
ItemToPurchase::ItemToPurchase() {
	this->itemName = "none";
	this->itemPrice = 0.00;
	this->itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string sName, double dPrice, int iQty) {
	this->itemName = sName;
	this->itemPrice = dPrice;
	this->itemQuantity = iQty;
}
ItemToPurchase::ItemToPurchase(string sItemName, string sItemDescription, double dItemPrice, int iItemQty) {
	this->itemName = sItemName;
	this->itemDescription = sItemDescription;
	this->itemPrice = dItemPrice;
	this->itemQuantity = iItemQty;
}

//Getters
string ItemToPurchase::GetName() const {
	return itemName;
}
double ItemToPurchase::GetPrice() const {
	return itemPrice;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}
string ItemToPurchase::GetDescription() const {
	return itemDescription;
}

//Setters
void ItemToPurchase::SetName(string sName) {
	this->itemName = sName;
}
void ItemToPurchase::SetPrice(double dPrice) {
	this->itemPrice = dPrice;
}void ItemToPurchase::SetQuantity(int iQty) {
	this->itemQuantity = iQty;
}
void ItemToPurchase::SetDescription(string sDescription) {
	this->itemDescription = sDescription;
}

//Other functions
void ItemToPurchase::PrintItemCost(ItemToPurchase oItem) {
	cout << fixed;
	cout << oItem.GetName() << oItem.GetQuantity() << " @ " << setprecision(2) << oItem.GetPrice() << " = " 
		<< setprecision(2) << oItem.GetPrice() * oItem.GetQuantity() << endl;
}
void ItemToPurchase::PrintItemDescription(ItemToPurchase oItem) {
	cout << oItem.GetName() << ", " << oItem.GetDescription() << endl;
}