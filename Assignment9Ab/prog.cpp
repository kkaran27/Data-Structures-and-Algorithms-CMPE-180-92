/*
 * prog.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Karan
 */
#include <list>
#include <iostream>
using namespace std;

/**
   Remove the odd elements of the linked list.
   Use an iterator.
*/
void removeOdd(list<int>& lst)
{
	list<int> :: iterator it;
	for(it = lst.begin(); it != lst.end(); it++)
	{
		if(*it % 2 == 1)
		{
			it = lst.erase(it);
			it--;
		}
	}
}




