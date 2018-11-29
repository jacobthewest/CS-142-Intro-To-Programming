#include "Cake.h"

//Constructors
Cake::Cake() {
	cakeFlavor = "none";
	frosting = "none";
}
Cake::Cake(string cakeFlavor, string frosting, bool bWantCreamCheese) {
	this->cakeFlavor = cakeFlavor;
	this->frosting = frosting;
	this->wantCreamCheese = bWantCreamCheese;
}

//Getters
string Cake::GetCakeFlavor() const {
	return cakeFlavor;
}
string Cake::GetFrosting() const {
	return frosting;
}