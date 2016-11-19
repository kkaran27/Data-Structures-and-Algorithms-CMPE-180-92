/*
 * main.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: Karan
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   cout << "Enter values, -1 when done: ";
   int result;
   // Read in numbers from cin. Stop when a value of -1 is entered.
   // Print the input that is closest to 100. If there are multiple
   // inputs that have the same minimal distance 100,
   // print the first one.
   // If no input was provided (other than the -1 sentinel),
   // print -1
   int values[10] ,i=0, count=0;
   while(1){
	   cin >> values[i];
	   count++;
	   if(values[i] == -1){
		   break;
	   }
	   i++;


   }
   if(count==1){

	   cout << "-1";
   }

   for(int j=0; j<count+1; j++){
	   if((abs(100-values[j]) < abs(100-values[j+1])) || (abs(100-values[j]) == abs(100-values[j+1])) ){
		   int temp = values[j];
		   values[j] = values[j+1];
		   values[j+1] = temp;
		   result = values[j+1];
	   }
   }

   if(count != 1){
	   cout << endl << "Result: " << result << endl;
   }
   return 0;
}




