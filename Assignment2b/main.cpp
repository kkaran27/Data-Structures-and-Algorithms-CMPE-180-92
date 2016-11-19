/*
 * main.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: Karan
 */
/*
   Implement a function called surfaceArea that computes the surface
   area of a box. Choose appropriate types for the parameters and
   the return value.
   @param a, b, c the side lengths
   @return the surface area
*/
#include <iostream>
using namespace std;

double surfaceArea(double a, double b, double c)
{
	int area = 2*(a*b + b*c + a*c);
	return area;
}

int main(){
	double length, breadth, height, area;
	cout << "Enter the length, breadth and height respectively" << endl;
	cin >> length >> breadth >> height;
	area = surfaceArea(length, breadth, height);
	cout << "The area of the box is: " << area << endl;
}


