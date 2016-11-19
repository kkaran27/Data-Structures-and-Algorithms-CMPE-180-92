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
   Remove the elements at position 1, 3, 5, 7, ..., of the
   linked list (where 0 is the starting position).
   Use an iterator.
*/
void removeOddPositions(list<int>& lst)
{
	list<int> :: iterator it;
	int counter = 0;
	for(it = lst.begin(); it != lst.end(); it++)
	{
		if(counter%2 == 1)
		{
			it=lst.erase(it);
			it--;
		}
		counter++;
	}
}




