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
   cout << "Hours of first time: ";
   int hours1;
   cin >> hours1;
   cout << "Minutes of first time: ";
   int minutes1;
   cin >> minutes1;
   cout << "Hours of second time: ";
   int hours2;
   cin >> hours2;
   cout << "Minutes of second time: ";
   int minutes2;
   cin >> minutes2;
   cout << endl;

   if(hours1>hours2 || ((hours1 == hours2) && (minutes1 > minutes2))){
	   cout << "After";
   } else if(hours1 == hours2 && minutes1 == minutes2){
	   cout << "Same";
   } else{
	   cout << "Before";
   }



   // If the first time comes before the second time, print BEFORE
   // If the first time comes after the second time, print AFTER
   // If they are the same time, print SAME;


   return 0;
}




