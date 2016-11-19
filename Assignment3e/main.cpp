/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include<iostream>
#include <vector>
using namespace std;

vector<vector<int>> allRot(const vector<int>& a);
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

   vector<int> values = { 3, 1, 4, 1};
   vector<vector<int>> result = allRot(values);
   /*print(result);
   //cout << "Expected: {1, 4, 1, 5, 9, 2, 6, 3}" << endl;

   // Don't expect to change values
   print(values);
   //cout << "Expected: {3, 1, 4, 1, 5, 9, 2, 6}" << endl;

   values = { 1, -1 };
   result = rot(values);
   print(result);
   cout << "Expected: {-1, 1}" << endl;

   values = { 42 };
   result = rot(values);
   print(result);
   cout << "Expected: {42}" << endl;*/

  /* values = { };
   result = rot(values);
   print(result);
   cout << "Expected: {}" << endl;*/
   return 0;
}

/**
   Computes all rotations of a given vector.
   @param a a vector of integers
   @return a vector of all rotations, first by 0, then by
   one, two, and so on, up to n - 1, where n is the size
   of the vector. For example, if a is {1, 7, 2, 9}
   then an array {{1, 7, 2, 9}, {7, 2, 9, 1}, {2, 9, 1, 7}, {9, 1, 7, 2}} is returned.
*/
vector<vector<int>> allRot(const vector<int>& a)
{
	vector<vector<int>> temp;
	vector<int> rotated = a;
	if(a.size() != 0){
		temp.push_back(rotated);
		for(unsigned int i=0; i < a.size()-1; i++){
			rotated = rot(rotated);
			cout << endl;
			temp.push_back(rotated);
		}
	}
	return temp;
}


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



