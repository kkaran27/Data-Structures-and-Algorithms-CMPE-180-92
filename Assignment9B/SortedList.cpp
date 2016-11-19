/*
 * SortedList.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: Karan
 */
#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/
void SortedList::prepend(int value)
{
	list<int> :: iterator it;

	it = data.begin();
	it = data.insert(it, value);


}

void SortedList::append(int value)
{
	data.push_back(value);
}

bool SortedList::find(int value) const
{
	bool found = false;
	list<int> :: const_iterator it;

		for(it = data.begin(); it != data.end(); it++)
		{
			if(*it == value)
			{
				found = true;
				break;
			}
		}

	return found;
}

int SortedList::get_value(int i) const
{
	list<int> :: const_iterator it;
	list<int> :: const_reverse_iterator it1;
	int count = 0;
	int value;
	int size = data.size();

	if (i <= size/2)
	{
		for (it = data.begin(); it != data.end(); it++)
		{
			if (i == count)
			{
				value = *it;
				break;
			}
			count++;
		}
	}
	else
	{
		count = size-1;
		for(it1 = data.crbegin(); it1 != data.crend(); it1++)
		{
			if(i == count)
			{
				value = *it1;
				break;
			}
			count--;
		}
	}

	return value;
}

void SortedList::clear()
{
	list<int> :: iterator it;
	it = data.begin();
	while(it != data.end())
	{
		it = data.erase(it);
	}
}

bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}




