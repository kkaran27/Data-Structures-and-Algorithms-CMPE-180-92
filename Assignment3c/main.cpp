/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include <vector>
using namespace std;

/**
   Swaps the second and second-to-last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 2, 4, 1, 5, 9, 1, 6}.
   If the array has length < 2, do nothing.
   @param a a vector of integers
*/
#include <iostream>
#include <vector>
using namespace std;

void swap2(vector<int>& a);

void print(const vector<int>& v)
{
   cout << "{";
   for (unsigned int i = 0; i < v.size(); i++)
   {
      cout << v[i];
      if (i < v.size() - 1) cout << ", ";
   }
   cout << "}" << endl;
}

int main()
{
   vector<int> values = { 3, 1, 4, 1, 5, 9, 2, 6 };
   cout << "Second value: " << values.at(1) << endl;
   cout << "Second last value: " << values.at(values.size()-2) << endl;
   swap2(values);
   print(values);
   cout << "Expected: {3, 2, 4, 1, 5, 9, 1, 6}" << endl;

   vector<int> values2 = { 1, -2, 3, -4, 5, -6 };
   swap2(values2);
   print(values2);
   cout << "Expected: {1, 5, 3, -4, -2, -6}" << endl;

   vector<int> values3 = { 1, 2 };
   swap2(values3);
   print(values3);
   cout << "Expected: {2, 1}" << endl;

   vector<int> values4 = { 1 };
   swap2(values4);
   print(values4);
   cout << "Expected: {1}" << endl;

   vector<int> values5 = {};
   swap2(values5);
   print(values5);
   cout << "Expected: {}" << endl;

   return 0;
}

void swap2(vector<int>& a)
{
	int temp;
	if(a.size() >= 2){
		temp = a.at(1);
		a.at(1) = a.at(a.size()-2);
		a.at(a.size()-2) = temp;
	}
}




