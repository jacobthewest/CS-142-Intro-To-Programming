#pragma once

#include "Cake.h"

class CupCake : public Cake {
public:
	//Constructor
	CupCake();
	CupCake(string cakeFlavor, string frosting, string sprinklesColor, bool bWantCreamCheese);
	//Getters
	string GetSprinklesColor() const;
	//Other functions
	string ToString();
	double DiscountedPrice(int iNumOfBakedGood) const;
protected:
private:
	string sprinklesColor;
	const double BASE_PRICE_OF_CUP_CAKE = 1.95;
	const double COST_OF_ADDING_CREAM_CHEESE_FROSTING = 0.20;
	const int QUANTITY_FOR_LOWER_DISOUNT = 2;
	const int QUANTITY_FOR_HIGHER_DISOUNT = 4;
	const double LOWER_DISCOUNT_PER_CUPCAKE = .30;
	const double HIGHER_DISCOUNT_PER_CUPCAKE = .40;
};