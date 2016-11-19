/*
 * main.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Karan
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int altSum(vector<int>);
int altSumHelper(vector<int> v);

int main()
{
	vector<int> v;
	for(int i = 1; i < 6 ; i++)
	{
		v.push_back(i);
	}
	int sum = altSum(v);
	cout << sum;
}

int altSumHelper(vector<int> v)
{
	if (v.size() == 0) {
		return 0;
	}
	int first = v[0];
	v.erase(v.begin());
	int second = 0;
	if (v.size() != 0) {
		second = v[0];
		v.erase(v.begin());
	}
	return first - second + altSumHelper(v);
}

/**
   Given a vector of integers, return the alternating sum
   v[0] - v[1] + v[2] - v[3] + ...
   If the vector is empty, the alternating sum is zero.
   Use a recursive helper method. Do not use loops.

*/
int altSum(vector<int> v)
{
	return altSumHelper(v);
}



