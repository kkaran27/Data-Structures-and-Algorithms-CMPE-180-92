/*
 * main.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Karan
 */
class Time
{
 public:
   /**
      Constructs a time with the given hours (0...23) and minutes
      (0...59)
   */
   Time(int hours, int minutes);

   int getHours();
   int getMinutes();

   /**
      Yields the difference between time a and b in minutes
   */
   friend int operator-(Time a, Time b);
 private:
   int minutesSinceMidnight;
};


#include <iostream>

using namespace std;

#include "time.h"

int main()
{
   Time t1(9, 15);
   Time t2(10, 0);
   cout << t2 - t1 << endl;
   cout << "Expected: 45" << endl;
   cout << t1 - t2 << endl;
   cout << "Expected: -45" << endl;
   Time t3(23, 59);
   cout << t3 - t1 << endl;
   cout << "Expected: 884" << endl;
   cout << t1 - t3 << endl;
   cout << "Expected: -884" << endl;

   return 0;
}


/**
   Implement operator- as a non-member!
*/


Time::Time(int hours, int minutes)
{
   minutesSinceMidnight = hours * 60 + minutes;
}

int Time::getHours()
{
   return minutesSinceMidnight / 60;
}

int Time::getMinutes()
{
   return minutesSinceMidnight % 60;
}
int operator-(Time a, Time b)
{
	int difference;
	difference = (a.getHours() - b.getHours())*60;
	difference += a.getMinutes() - b.getMinutes();

	return difference;
}



