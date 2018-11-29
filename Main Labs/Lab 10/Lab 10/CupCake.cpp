#include "CupCake.h"

//Constructors
CupCake::CupCake() {
	sprinklesColor = "none";
	priceOfItem = 0.00;
}
CupCake::CupCake(string cakeFlavor, string frosting, string sprinklesColor, bool bWantCreamChese) {
	this->cakeFlavor = cakeFlavor;
	this->frosting = frosting;
	this->sprinklesColor = sprinklesColor;
	this->wantCreamCheese = bWantCreamChese;

	if (bWantCreamChese) {
		//They do want cream cheese
		this->priceOfItem = BASE_PRICE_OF_CUP_CAKE + COST_OF_ADDING_CREAM_CHEESE_FROSTING;
	}
	else {
		//They do NOT want cream cheese
		this->priceOfItem = BASE_PRICE_OF_CUP_CAKE;
	}
}

//Getters
string CupCake::GetSprinklesColor() const {
	return sprinklesColor;
}

//Other functions
string CupCake::ToString() {
	ostringstream oss;
	oss.clear();
	if (wantCreamCheese) {
		//This is a creamCheese frosted cupcake
		oss << GetCakeFlavor() << " cupcake with cream-cheese frosting and " << GetSprinklesColor() <<
			" sprinkles" << BakedGood::ToString();
	}
	else {
		oss << GetCakeFlavor() << " cupcake with " << GetFrosting() << " frosting and " << GetSprinklesColor() <<
			" sprinkles" << BakedGood::ToString();
	}

	return oss.str();
}
double CupCake::DiscountedPrice(int iNumOfBakedGood) const {
	double dTotalCost = 0.00;
	//Qualify for lower discount
	if (iNumOfBakedGood >= QUANTITY_FOR_LOWER_DISOUNT && iNumOfBakedGood < QUANTITY_FOR_HIGHER_DISOUNT) {
		dTotalCost = iNumOfBakedGood * (priceOfItem - LOWER_DISCOUNT_PER_CUPCAKE);
	}
	//Qualify for higher discount
	else if (iNumOfBakedGood >= QUANTITY_FOR_HIGHER_DISOUNT) {
		dTotalCost = iNumOfBakedGood * (priceOfItem - HIGHER_DISCOUNT_PER_CUPCAKE);
	}
	else {
		dTotalCost = iNumOfBakedGood * priceOfItem;
	}
	return dTotalCost;
}