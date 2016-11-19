/*
 * main.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Karan
 */
#include <iostream>
#include<sstream>
#include<iomanip>

using namespace std;

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
      Sends this time in hh:mm format to the given output stream.
      Returns out for chaining.
   */
   friend ostream& operator<<(ostream& out, Time t);

 private:
   int minutesSinceMidnight;
};

int main()
{
   Time t1(9, 15);
   Time t2(10, 0);
   Time t3(23, 59);
   cout << "t1: " << t1 << endl;
   cout << "Expected: 09:15" << endl;
   cout << "t2: " << t2 << endl;
   cout << "Expected: 10:00" << endl;
   cout << "t3: " << t3 << endl;
   cout << "Expected: 23:59" << endl;
   stringstream sout;
   sout << "t1: " << t1 << endl;
   cout << sout.str();
   cout << "Expected: 09:15" << endl;

   return 0;
}


/*
  Implement the << operator!
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

ostream& operator << (ostream& out, Time t)
{
	out << setfill('0') << setw(2) << t.getHours() << ":" << setfill('0') << setw(2) << t.getMinutes();
	return out;
}



