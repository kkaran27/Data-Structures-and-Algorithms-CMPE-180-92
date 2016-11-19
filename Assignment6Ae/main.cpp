/*
 * main.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Karan
 */
//SOLUTION

class Path
{
 public:
   /**
      Constructs a path of points (x0, y0), (x1, y1), (x2, y2),
      ... of length n. Initially, all coordinates are zero.
   */
   Path(int n);

   /**
      Gets the ith x-coordinate.
   */
   int getX(int i);
   /**
      Gets the ith y-coordinate.
   */
   int getY(int i);

   /**
      Sets the ith point to the given x- and y-coordinate.
   */
   void set(int i, int x, int y);

   /**
      Gets the number of points in this path.
   */
   int getLength();

   Path& operator=(const Path& rhs);

 private:
   int* xy;
   int length;
};

#include <iostream>
using namespace std;

int main()
{
   Path p(4);
   p.set(0, 3, 1);
   p.set(1, 4, 1);
   p.set(2, 5, 9);
   p.set(3, 2, 6);
   cout << p.getX(2) << " " << p.getY(2) << endl;
   cout << "Expected: 5 9" << endl;
   Path q(1);
   q = p;
   cout << q.getX(0) << " " << q.getY(0) << endl;
   cout << "Expected: 3 1" << endl;
   p.set(2, 9, 7);
   cout << p.getX(2) << " " << p.getY(2) << endl;
   cout << "Expected: 9 7" << endl;
   cout << q.getX(2) << " " << q.getY(2) << endl;
   cout << "Expected: 5 9" << endl;

   return 0;
}

/*
   Implement the assignment operator!
*/

Path::Path(int n)
 {
	length = n;
	xy = new int[2 * length];
	for (int i = 0; i < 2*length; i++)
	{
		xy[i] = 0;
	}
}

int Path::getX(int i)
{
   if (0 <= i && i < length)
      return xy[2 * i];
   else
      return 0;
}

int Path::getY(int i)
{
   if (0 <= i && i < length)
      return xy[2 * i + 1];
   else
      return 0;
}

void Path::set(int i, int x, int y)
{
   if (0 <= i && i < length)
   {
      xy[2 * i] = x;
      xy[2 * i + 1] = y;
   }
}

int Path::getLength()
{
   return length;
}

Path& Path::operator=(const Path& rhs)
{
	this->length = rhs.length;
	int *temp = new int[2*length];

	for(int i=0; i < 2*length; i++)
	{
		temp[i] = rhs.xy[i];
	}
	this->xy = temp;
	return *this;
}




