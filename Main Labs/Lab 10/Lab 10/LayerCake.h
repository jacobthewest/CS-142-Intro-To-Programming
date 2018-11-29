#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Cake.h"

class LayerCake : public Cake {
public:
	//Constructor
	LayerCake();
	LayerCake(string cakeFlavor, string frosting, int numberOfLayers, bool bWantCreamCheese);
	//Other functions
	string ToString();
	double DiscountedPrice(int iNumOfBakedGood) const;
	int GetNumLayers() const;
protected:
private:
	int numberOfLayers;
	const double BASE_PRICE_OF_LAYER_CAKE = 9.00;	
	const double COST_OF_ADDING_CREAM_CHEESE_PER_LAYER = 1.00;	
	const double COST_OF_EXTRA_CAKE_LAYER = 3.00;
	const int NUMBER_OF_INITIALLY_FREE_LAYERS = 1;
	const int NUMBER_OF_LAYERED_CAKES_NEEDED_FOR_DISCOUNT = 3;
	const double DISCOUNT_AMOUNT_PER_LAYERED_CAKE = 2.00;
};

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