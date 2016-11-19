/*
 * prog.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Karan
 */
#include <list>
using namespace std;

/**
   Swap neighboring elements of this linked list. If the
   length is odd, leave the last element unchanged.
*/
void swapNeighbors(list<int>& lst)
{
	list<int> :: iterator it;
	for(it = lst.begin(); it != lst.end(); it++)
	{
		int temp = *it;
		*it = *(++it);
		*(it) = temp;
		it++;
		if(++it == lst.end())
		{
			break;
		}
		else
		{
			it--;
			it--;
		}
	}
}




