/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Karan
 */
#include<iostream>
#include<cmath>
struct Point
{
   double x;
   double y;
};

double distance(Point a, Point b);
Point midpoint(Point a, Point b);

using namespace std;


int main()
{
   Point p = { 1, 2 };
   Point q = { 4, 6 };
   cout << distance(p, q) << endl;
   cout << "Expected: 5" << endl;
   Point r = midpoint(p, q);
   cout << r.x << " " << r.y << endl;
   cout << "Expected: 2.5 4" << endl;
   Point o = { 0, 0 };
   cout << distance(p, o) << endl;
   cout << "Expected: " << sqrt(5) << endl;
   r = midpoint(p, o);
   cout << r.x << " " << r.y << endl;
   cout << "Expected: 0.5 1" << endl;

   return 0;
}






/**
   Compute the distance between two points.
   @param a, b two points
   @return the distance between them.
*/
double distance(Point a, Point b)
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, distance;
	x1 = a.x;
	y1 = a.y;
	x2 = b.x;
	y2 = b.y;
	distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	return distance;
}

/**
   Compute the midpoint between two points.
   @param a, b two points
   @return the point halfway between them.
*/
Point midpoint(Point a, Point b)
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0;
	Point mid_point;
	x1 = a.x;
	y1 = a.y;
	x2 = b.x;
	y2 = b.y;
	mid_point.x = (x1+x2)/2;
	mid_point.y = (y1+y2)/2;
	return mid_point;
}



