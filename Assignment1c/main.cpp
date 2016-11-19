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
   cout << "a: ";
   int a;
   cin >> a;
   cout << "b: ";
   int b;
   cin >> b;
   // Print the highest power of a that is <= b.
   // For example, if a is 10 and b is 123, then you print 100
   // You may assume that a and b are positive.

   int result;

   if(a>b){
	   cout << endl << "Result: " << "1" << endl;
   }
   else{
	   result = a;
	   while(result<=b){
		   result *= a;
		   if(result > b){
			   result /= a;
			   break;
		   }

	   }
   cout << endl << "Result: " << result << endl;
   }
   return 0;
}




