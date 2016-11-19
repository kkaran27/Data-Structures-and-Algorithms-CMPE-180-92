/*
 * main.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: Karan
 */
#include <iostream>
using namespace std;

int main()
{
   cout << "Hours: ";
   int hours;
   cin >> hours;
   cout << "Minutes: ";
   int minutes;
   cin >> minutes;
   cout << "Minutes to add: ";
   int minutesToAdd;
   cin >> minutesToAdd;


   // Add minutesToAdd minutes to the given hours/minutes
   // and normalize hours/minutes to military time (so that
   // hours is between 0 and 23 and minutes between 0 and 59)

   if(minutesToAdd < 0)
   {
	   minutes += minutesToAdd;
	   cout << minutes;
	   while(minutes<0){
		   minutes+=60;
		   hours-=1;
	   }

   }else{
	   minutes+=minutesToAdd;

	   while(minutes>59){

		   minutes-=60;
		   hours+=1;
	   }
   }

   while(hours < 0){
	   hours+=24;
   }

   while(hours > 24){
	   hours -= 24;
   }


   cout << endl << "Result: " << hours << ":" << minutes << endl;
   return 0;
}



