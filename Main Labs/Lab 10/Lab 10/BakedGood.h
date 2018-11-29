#pragma once
#include <iostream>
#include <string>
#include <sstream> //For ostringsteam
#include <ios> //For fixed formatting after the decimal point
#include <iomanip> //for setprecision()
using namespace std;

class BakedGood {
public:
	//Constructor
	BakedGood();
	//Other functions
	virtual double DiscountedPrice(int iNumOfBakedGood) const = 0;
	virtual string ToString();
protected:
	double priceOfItem;
private:
};