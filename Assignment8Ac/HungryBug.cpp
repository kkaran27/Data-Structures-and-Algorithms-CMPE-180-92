/*
 * HungryBug.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */
#include"HungryBug.h"
#include<iostream>
using namespace std;

HungryBug :: HungryBug(int initialFoodUnits)
{
	food = initialFoodUnits;
}

void HungryBug :: eat(int foodUnits)
{
	food += foodUnits;
}

void HungryBug::move(int dx)
{

	if(food != 0)
	{
		Bug :: move(dx);
	}
	food--;

}


