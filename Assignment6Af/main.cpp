/*
 * main.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Karan
 */
#include <algorithm>
#include <sstream>
using namespace std;

/*
  Override the & and + operators!
*/

#include <string>

using namespace std;

/*
  A half-open interval [a, b) = { x | a <= x < b }
*/
class Interval
{
 public:
   /**
     Constructs An empty interval.
   */
   Interval();
   /**
      Constructs an interval [xmin, xmax)
   */
   Interval(int xmin, int xmax);

   /**
      Checks if this interval is empty.
   */
   bool isEmpty() const;

   /**
      Yields a string representation of this interval.
   */
   string toString() const;


   /**
      The intersection of a and b. If the intersection is empty,
      return [0, 0).
   */
   friend Interval operator&(const Interval& a, const Interval& b);

   /**
      The smallest interval holding both a and b. (Not the union--that
      might not be an interval.)
      If a or b is empty, return the other.
   */
   friend Interval operator+(const Interval& a, const Interval& b);
 private:
   int xmin;
   int xmax;
};

#include <iostream>

using namespace std;


int main()
{
   Interval r(1, 4);
   Interval s(2, 5);
   Interval t = r & s;
   cout << t.toString() << endl;
   cout << "Expected: [2, 4)" << endl;

   r = Interval(1, 2);
   s = Interval(3, 4);
   t = r & s;
   cout << t.toString() << endl;
   cout << "Expected: [0, 0)" << endl;

   t = r + s;
   cout << t.toString() << endl;
   cout << "Expected: [1, 4)" << endl;

   t = (r & s) + r;
   cout << t.toString() << endl;
   cout << "Expected: [1, 2)" << endl;

   t = s + (r & s);
   cout << t.toString() << endl;
   cout << "Expected: [3, 4)" << endl;

   return 0;
}


Interval::Interval()
{
   xmin = 0;
   xmax = 0;
}

Interval::Interval(int xmin, int xmax)
{
   this->xmin = xmin;
   this->xmax = xmax;
}

bool Interval::isEmpty() const
{
   return xmin >= xmax;
}

string Interval::toString() const
{
   stringstream sout;
   sout << "[" << xmin << ", " << xmax << ")";
   return sout.str();
}

Interval operator+(const Interval& a, const Interval& b)
{
	Interval temp;
	if(a.isEmpty())
	{
		return b;
	}
	if(b.isEmpty())
	{
		return a;
	}
	a.xmin < b.xmin ? temp.xmin = a.xmin : temp.xmin = b.xmin;
	a.xmax > b.xmax ? temp.xmax = a.xmax : temp.xmax = b.xmax;


	return temp;
}

Interval operator&(const Interval& a, const Interval& b)
{
	Interval temp;
	if(a.isEmpty())
	{
		return b;
	}
	if(b.isEmpty())
	{
		return a;
	}
	if(a.xmax >= b.xmin)
	{
		a.xmin > b.xmin ? temp.xmin = a.xmin : temp.xmin = b.xmin;
		a.xmax < b.xmax ? temp.xmax = a.xmax : temp.xmax = b.xmax;
	}
	else
	{
		temp.xmin = 0;
		temp.xmax = 0;
	}
	return temp;
}





