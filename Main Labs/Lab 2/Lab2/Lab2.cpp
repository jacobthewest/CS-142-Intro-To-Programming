// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

#include <iostream>
	using namespace std;

	/*
	Header
	Jacob West, section 3, jacobthewest@gmail.com
	Test case 1:
	Input: Number of people: 25, Tip%: 15%
	Expected output: Number of Pizzas: 9, Total Cost: $125.89
	*/

	int main() {


		//Declare Variables
		const double PI = 3.14159265;
		const int LARGE_PIZZA_DIAMETER = 20;
		const int MEDIUM_PIZZA_DIAMETER = 16;
		const int SMALL_PIZZA_DIAMETER = 12;
		const double LARGE_PIZZA_PRICE = 14.68;
		const double MEDIUM_PIZZA_PRICE = 11.48;
		const double SMALL_PIZZA_PRICE = 7.28;
		const int PEOPLE_PER_LARGE_PIZZA = 7;
		const int PEOPLE_PER_MEDIUM_PIZZA = 3;
		const int PEOPLE_PER_SMALL_PIZZA = 1;
		int iNumGuests = 0;
		int iNumLargePizzas = 0;
		int iNumMediumPizzas = 0;
		int iNumSmallPizzas = 0;
		int iRemainingPeopleToBeFed = 0;
		int iTotalSquareAreaOfPizza = 0;

		//----------------------------------------Part 1--------------------------------------//

		//Get number of guests attending the event
		cout << "Please enter the number of guests: ";
		cin >> iNumGuests;
		cout << endl;

		//Determine and report the number of large, medium, and small pizzas you need to order.
		iNumLargePizzas = iNumGuests / PEOPLE_PER_LARGE_PIZZA;
		iNumMediumPizzas = (iNumGuests - (iNumLargePizzas * PEOPLE_PER_LARGE_PIZZA)) / PEOPLE_PER_MEDIUM_PIZZA;
		iNumSmallPizzas = (iNumGuests - ((iNumLargePizzas * PEOPLE_PER_LARGE_PIZZA) + (iNumMediumPizzas * PEOPLE_PER_MEDIUM_PIZZA))) / PEOPLE_PER_SMALL_PIZZA;

		//Output the number of pizzas needed
		cout << iNumLargePizzas << " large pizzas, " << iNumMediumPizzas << " medium pizzas, and " << iNumSmallPizzas << " small pizzas will be needed." << endl;

		//----------------------------------------Part 2--------------------------------------//

		iTotalSquareAreaOfPizza = (iNumLargePizzas * LARGE_PIZZA_DIAMETER) + (iNumMediumPizzas * MEDIUM_PIZZA_DIAMETER) + (iNumSmallPizzas * SMALL_PIZZA_DIAMETER);
		cout << iTotalSquareAreaOfPizza;

		/*
		Compute and report the total area of pizza (in square inches) you need to purchase. Do not round these values.
		Compute and report the total area of pizza (in square inches) each guest can eat. Do not round these values.

		//A total of 13735 square inches of pizza will be purchased (45.3302 per guest).
		*/

	}


    return 0;
}

