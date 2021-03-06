/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;


vector<int> rot(const vector<int>& a);

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
   vector<int> result = rot(values);
   print(result);
   cout << "Expected: {1, 4, 1, 5, 9, 2, 6, 3}" << endl;

   // Don't expect to change values
   print(values);
   cout << "Expected: {3, 1, 4, 1, 5, 9, 2, 6}" << endl;

   values = { 1, -1 };
   result = rot(values);
   print(result);
   cout << "Expected: {-1, 1}" << endl;

   values = { 42 };
   result = rot(values);
   print(result);
   cout << "Expected: {42}" << endl;

   values = { };
   result = rot(values);
   print(result);
   cout << "Expected: {}" << endl;
   return 0;
}

/**
   Rotates a vector one position to the left.
   Returns the rotated vector without modifying the
   original.
   @param a a vector of integers
   @return the rotated vector. For example, if a is {3, 1, 4, 1, 5, 9}
   then a vector {1, 4, 1, 5, 9, 3} is returned.
*/

vector<int> rot(const vector<int>& a)
{
	vector<int> temp;
	for(unsigned int i=0; i<a.size(); i++){
		if(i != a.size()-1){
			temp.push_back(a.at(i+1));
		}
		else{
			temp.push_back(a.at(0));
		}
	}
	return temp;
}




