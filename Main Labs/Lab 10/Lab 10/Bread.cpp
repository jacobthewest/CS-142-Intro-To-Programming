#include "Bread.h"

//Constructors
Bread::Bread() {
	breadVariety = "none";
	priceOfItem = 0.00;
}
Bread::Bread(string breadVariety) {
	this->breadVariety = breadVariety;
	this->priceOfItem = BASE_PRICE_OF_BREAD;
}

//Getters
string Bread::GetBreadVariety() const {
	return breadVariety;
}

//Other functions
string Bread::ToString() {
	ostringstream oss;
	oss.clear();
	oss << GetBreadVariety() << " bread " << BakedGood::ToString();
	return oss.str();
}
double Bread::DiscountedPrice(int iNumOfBakedGood) const {
	double dTotalCost = 0.00;

	for (int i = 1; i <= iNumOfBakedGood; ++i) {
		if ((i % NUMBER_OF_LOAVES_FOR_DISCOUNT) != 0) {
			//Will increment the cost each time the customer doesn't qualify for the discount because
			//they have too few items.
			dTotalCost += priceOfItem;
		}
	}
	return dTotalCost;
}