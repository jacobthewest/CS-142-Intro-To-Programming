#pragma once
#include <string>
using namespace std;

class ItemToPurchase{
	public:
		//Constructors
		ItemToPurchase(); //Default Constructor
		ItemToPurchase(string sName, double dPrice, int iQty); //Overload constructor
		ItemToPurchase(string sItemName = "none", string sItemDescription = "none", double dItemPrice = 0.0,
			int iItemQty = 0);
		//Getters
		string GetName() const;
		double GetPrice() const;
		int GetQuantity() const;
		string GetDescription() const;
		//Setters	
		void SetName(string sName);
		void SetPrice(double dPrice);
		void SetQuantity(int iQty);
		void SetDescription(string sDescription);
		//Other functions
		void PrintItemCost(ItemToPurchase oItem);
		void PrintItemDescription(ItemToPurchase oItem);

	private:
		string itemName;
		double itemPrice;
		int itemQuantity;
		string itemDescription;
};