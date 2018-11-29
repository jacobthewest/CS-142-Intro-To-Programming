#include "BakedGood.h"

//Constructor
BakedGood::BakedGood() {
	priceOfItem = 0.00;
}

//Other functions
string BakedGood::ToString() {
	ostringstream outSS;
	outSS.clear();
	outSS << "($" << fixed << setprecision(2) << priceOfItem << ")";
	return outSS.str();
}