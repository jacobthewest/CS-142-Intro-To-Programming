#include "LayerCake.h"	

//Constructors
LayerCake::LayerCake() {
	numberOfLayers = 0;
	priceOfItem = 0.00;
}
LayerCake::LayerCake(string cakeFlavor, string frosting, int numberOfLayers, bool bWantCreamCheese) {
	this->cakeFlavor = cakeFlavor;
	this->frosting = frosting;
	this->numberOfLayers = numberOfLayers;
	this->wantCreamCheese = bWantCreamCheese;
	if (bWantCreamCheese) {
		//They do want cream cheese
		this->priceOfItem = BASE_PRICE_OF_LAYER_CAKE + ((numberOfLayers - NUMBER_OF_INITIALLY_FREE_LAYERS)
			* COST_OF_EXTRA_CAKE_LAYER) + (numberOfLayers * COST_OF_ADDING_CREAM_CHEESE_PER_LAYER);
	}
	else {
		//They do NOT want cream cheese
		this->priceOfItem = BASE_PRICE_OF_LAYER_CAKE + ((numberOfLayers - NUMBER_OF_INITIALLY_FREE_LAYERS)
			* COST_OF_EXTRA_CAKE_LAYER);
	}
}
//Getters
int LayerCake::GetNumLayers() const {
	return numberOfLayers;
}

//Other functions
string LayerCake::ToString() {
	ostringstream oss;
	oss.clear();
	if (wantCreamCheese) {
		//This is a creamCheese frosted layer cake
		oss << GetNumLayers() << " - layer " << GetCakeFlavor() << " cake with cream-cheese frosting "
			<< BakedGood::ToString();
	}
	else {
		oss << GetNumLayers() << " - layer " << GetCakeFlavor() << " cake with " << GetFrosting() << " frosting "
			<< BakedGood::ToString();
	}
	return oss.str();
}

double LayerCake::DiscountedPrice(int iNumOfBakedGood) const {
	double dTotalCost;
	if (iNumOfBakedGood >= NUMBER_OF_LAYERED_CAKES_NEEDED_FOR_DISCOUNT) {
		dTotalCost = iNumOfBakedGood * (priceOfItem - DISCOUNT_AMOUNT_PER_LAYERED_CAKE);
	}
	else {
		dTotalCost = priceOfItem * iNumOfBakedGood;
	}
	return dTotalCost;
}