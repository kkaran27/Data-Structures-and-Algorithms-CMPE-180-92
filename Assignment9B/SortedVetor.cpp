/*
 * SortedVetor.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: Karan
 */
#include <iostream>
#include <iterator>
#include "SortedVector.h"
#include<vector>
#include<algorithm>

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/
void SortedVector::prepend(int value)
{
		vector<int> :: iterator it;

		it = data.begin();
		it = data.insert(it, value);

}

void SortedVector::append(int value)
{
	data.push_back(value);
}
bool SortedVector::find(int value) const
{
	bool found = false;
	vector<int> :: const_iterator it;
	it = std::find(data.begin(), data.end(), value);
	if(it != data.end())
	{
		found = true;
	}
	return found;
}
int SortedVector::get_value(int i) const
{
	return data.at(i);
}

void SortedVector::clear()
{
	vector<int> :: iterator it;
	it = data.begin();
	while(it != data.end())
	{
		it = data.erase(it);
	}
}
bool SortedVector::check()
{
    if (data.size() == 0) return true;

    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}




