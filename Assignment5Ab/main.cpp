/*
 * main.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Karan
 */
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
 public:
   Point(double xvalue, double yvalue);
   double get_x();
   double get_y();
   double distance(Point other);
   Point midpoint(Point other);
 private:
   double x;
   double y;
};

Point::Point(double xvalue, double yvalue)
{
   x = xvalue;
   y = yvalue;
}

double Point::get_x() { return x; }
double Point::get_y() { return y; }

/**
   Compute the distance between this point and another point.
   @param other the other point
   @return the distance between them.
*/
double Point::distance(Point other)
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, distance;
	x1 = this->x;
	x2 = other.x;
	y1 = this->y;
	y2 = other.y;
	distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	return distance;
}

/**
   Compute the midpoint between this point and another point.
   @param other the other point
   @return the point halfway between them.
*/
Point Point::midpoint(Point other)
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, x = 0.0, y = 0.0;
	Point mid_point(x,y);
	x1 = this->x;
	x2 = other.x;
	y1 = this->y;
	y2 = other.y;
	mid_point.x = (x1 + x2) / 2;
	mid_point.y = (y1 + y2) / 2;
	return mid_point;
}


int main()
{
   Point p(1, 2);
   Point q(4, 6);
   cout << p.distance(q) << endl;
   cout << "Expected: 5" << endl;
   Point r = p.midpoint(q);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 2.5 4" << endl;
   Point o(0, 0);
   cout << p.distance(o) << endl;
   cout << "Expected: " << sqrt(5) << endl;
   r = p.midpoint(o);
   cout << r.get_x() << " " << r.get_y() << endl;
   cout << "Expected: 0.5 1" << endl;

   return 0;
}






