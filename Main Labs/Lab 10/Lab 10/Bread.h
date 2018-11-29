#pragma once

#include "BakedGood.h"

class Bread : public BakedGood {
public:
	//Constructor
	Bread();
	Bread(string breadVariety);
	//Getters
	string GetBreadVariety() const;
	//Other functions
	string ToString();
	double DiscountedPrice(int iNumOfBakedGood) const;
protected:
private:
	string breadVariety;
	const double BASE_PRICE_OF_BREAD = 4.50;
	const int NUMBER_OF_LOAVES_FOR_DISCOUNT = 3;
};

//Parent: BakedGood

/*
Bread, LayerCake and CupCake should at least each have the following virtual member functions
(you can name them what you want):

ToString: Returns a string containing the basic description and base price of the object.
While there are only three broad classes of objects (Bread, LayerCake, CupCake), there are lots
of different variations of baked goods (white bread, wheat bread, 3-layer spice cupcake with vanilla frosting,
Chocolate cupcake with cream-cheese frosting and red sprinkles, etc.) You do NOT have a class for each baked good,
just for the three broad classes.
DiscountedPrice: Takes as parameter the total number of a particular baked good and returns the discounted total
price for that baked good.
*/