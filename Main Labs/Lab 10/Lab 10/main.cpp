/******************************************
HEADER:
Jacob West, Section 3, jacobthewest@gmail.com

TEST CASE 1: Tests the invoice for same orders that show up later as well
	Input:
		Bread Grain 4
		Cupcake Funfetti lemon pink 5
		Bread Grain 2
		Cupcake Funfetti lemon pink 4
		Cupcake Chocolate vanilla blue 1
	Output:
		Invoice:
		Baked Good                                                                   Quantity    Total
		Grain bread ($4.50)																	6    18.00
		Funfetti cupcake with lemon frosting and pink sprinkles($1.95)                      9    13.95
		Chocolate cupcake with vanilla frosting and blue sprinkles($1.95)                   1     1.95
		Totals                                                                             16    33.90
TEST CASE 2: Test for the good bye part of the program and test for the monetary output
	Input:
		done
	Output:
		Invoice:
		Baked Good                                                                   Quantity    Total
		Totals                                                                             0     0.00
		Good bye
TEST CASE 3: Tests order confirmations and invoices for cream-cheese vs normal frosting
	Input:
		Cupcake Funfetti cream-cheese pink 1
		Layer-cake Spice cream-cheese 3 2
		Cupcake Funfetti vanilla pink 1
		Layer-cake Spice chocolate 3 2
	Output:
		Order Confirmations:
		Funfetti cupcake with cream-cheese frosting and pink sprinkles($2.15)
		3 - layer Spice cake with cream-cheese frosting ($18.00)
		3 - layer Spice cake with cream-cheese frosting ($18.00)
		Funfetti cupcake with vanilla frosting and pink sprinkles($1.95)
		3 - layer Spice cake with chocolate frosting ($15.00)
		3 - layer Spice cake with chocolate frosting ($15.00)

		Invoice:
		Baked Good                                                                   Quantity    Total
		Funfetti cupcake with cream-cheese frosting and pink sprinkles($2.15)				1     2.15
		3 - layer Spice cake with cream-cheese frosting ($18.00)                            2    36.00
		Funfetti cupcake with vanilla frosting and pink sprinkles($1.95)                    1     1.95
		3 - layer Spice cake with chocolate frosting ($15.00)                               2    30.00
		Totals																				6    70.10

******************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"


int main() {
	vector<BakedGood*> listofBakedGoodPointers;

	cout << "**Bread and Cakes Bakery**" << endl << endl;

	//----------------------------------------------Part 1---------------------------------------------//

	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	string sOrder;
	string sClassOfOrder;
	string sCakeFlavor;
	string sFrosting;
	string sSprinklesColor;
	string sBreadVariety;
	string sSkipThisWord;
	int iNumberOfCakeLayers;
	int iQuantity;
	bool bWantCreamCheese = false;

	//Collect sub orders
	do {
		cout << "Sub-order: ";
		cin >> sClassOfOrder;
		if (sClassOfOrder == "Bread") {
			cin >> sBreadVariety;
			cin >> iQuantity;
			
			//Create the object
			for (int i = 0; i < iQuantity; ++i) {
				listofBakedGoodPointers.push_back(new Bread(sBreadVariety));
			}
		}
		else if (sClassOfOrder == "Layer-cake") {
			cin >> sCakeFlavor;
			cin >> sSkipThisWord;
			//Check for cream cheese frosting
			if (sSkipThisWord == "cream-cheese") {
				//We found cream cheese
				bWantCreamCheese = true;
			}
			else {
				sFrosting = sSkipThisWord;
			}
			cin >> iNumberOfCakeLayers;
			cin >> iQuantity;
			//Create the object
			for (int i = 0; i < iQuantity; ++i) {
				listofBakedGoodPointers.push_back(new LayerCake(sCakeFlavor, sFrosting, iNumberOfCakeLayers, 
					bWantCreamCheese));
				//Just missing a bool for the cream cheese
			}
		}
		else if (sClassOfOrder == "Cupcake") {
			cin >> sCakeFlavor;
			cin >> sSkipThisWord;
			//Check for cream cheese frosting
			if (sSkipThisWord == "cream-cheese") {
				//We found cream cheese
				bWantCreamCheese = true;
				sFrosting = "cream-cheese";
			}
			else {
				sFrosting = sSkipThisWord;
			}
			cin >> sSprinklesColor;
			cin >> iQuantity;
			//Create the object
			for (int i = 0; i < iQuantity; ++i) {
				listofBakedGoodPointers.push_back(new CupCake(sCakeFlavor, sFrosting, sSprinklesColor, bWantCreamCheese));
			}
		}
		cout << endl;

		bWantCreamCheese = false;
	} while (sClassOfOrder != "done");

	//----------------------------------------------Part 2---------------------------------------------//
	
	
	cout << "Order Confirmations:" << endl;

	for (unsigned int i = 0; i < listofBakedGoodPointers.size(); ++i) {
		cout << listofBakedGoodPointers.at(i)->ToString() << endl;
	}
	cout << endl;


	//----------------------------------------------Part 3---------------------------------------------//

	cout << "Invoice:" << endl;
	cout << "Baked Good" << setw(75) << "Quantity" << setw(9) << "Total" << endl;

	int iQuantityTotal = 0;
	double dOverallCost = 0.00;
	vector<BakedGood*> tempVector = listofBakedGoodPointers;
	//Loop to get the count of all of the unique items
	for (unsigned int i = 0; i < listofBakedGoodPointers.size(); ++i) {
		int iQtyCounter = 1;
		int iSizeOfVector = listofBakedGoodPointers.size();
		
		for (unsigned int j = i + 1; j < listofBakedGoodPointers.size();) {
			if (listofBakedGoodPointers.at(i)->ToString() == listofBakedGoodPointers.at(j)->ToString()) {
				delete listofBakedGoodPointers.at(j);
				listofBakedGoodPointers.erase(listofBakedGoodPointers.begin() + j);
				iQtyCounter++;
				//We won't increment j yet becuase the after deleting a point in the vector 
				//the vector will resize and by keeping j the same we will automatically
				//be accessing the next item in the vector
			}
			else {
				//The next item in the list does not equal the current item in the list, so we should increment j now
				j++;
			}
		}
		//We have searched the entire vector for similar objects, now we will print this part of the invoice.
		cout << listofBakedGoodPointers.at(i)->ToString() << "\t\t\t\t\t" << iQtyCounter << setw(9)
			<< fixed << setprecision(2) << listofBakedGoodPointers.at(i)->DiscountedPrice(iQtyCounter) << endl;
		iQuantityTotal += iQtyCounter;
		dOverallCost += listofBakedGoodPointers.at(i)->DiscountedPrice(iQtyCounter);
	}
	cout << "Totals" << setw(75) << iQuantityTotal << setw(9) << fixed << setprecision(2) << dOverallCost << endl;
	cout << "Good bye" << endl;
	//system("pause");

	return 0;
}