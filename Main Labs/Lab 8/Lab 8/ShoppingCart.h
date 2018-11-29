#pragma once
#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
	//Constructors
	ShoppingCart();
	ShoppingCart(string sCustomerName, string sDateOfCart);
	//Getters
	string GetCustomerName() const;
	string GetDateOfCartCreation() const;
	int GetTotalQuantityOfAllItems() const;
	double GetTotalCostOfAllItems() const;
	//Other functions
	void UpdateQuantityOfItem(string sItemName);
	void AddItemToCart(ItemToPurchase oItem);
	void RemoveItemFromCart(string sItemName);
	void PrintTotalNumberAndCostOfItems() const;
	void PrintDescriptionOfItems() const;
	

private:
	string customerName;
	string dateOfCart;
	vector<ItemToPurchase> listOfItems;
};	