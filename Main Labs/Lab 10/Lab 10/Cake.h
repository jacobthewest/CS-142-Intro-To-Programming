#pragma once
#include "BakedGood.h"

//THIS NEEDS TO BE AN ABSTRACT CLASS, SO DO I NEED TO CREATE A RANDOM VITURAL FUNCTION TO MAKE IT ABSTRACT?
//OR DO I NEED TO MAKE A TOSTR FUNCTION FOR IT TO BE BETTER?

class Cake : public BakedGood {
public:
protected:
	//Constructor
	Cake();
	Cake(string cakeFlavor, string frosting, bool bWantCreamCheese);
	//Getters
	virtual string GetCakeFlavor() const;
	virtual string GetFrosting() const;
	//Other functions
	virtual double DiscountedPrice(int iNumOfBakedGood) const = 0;
	//MUST HAVE A VIRTUAL FUNCTION HERE SO THIS IS AN ABSTRACT CLASS
	
	//Instance Variables
	string cakeFlavor;
	string frosting;
	bool wantCreamCheese;
private:
};

//Parent BakedGood

//Children: CupCake and LayerCake