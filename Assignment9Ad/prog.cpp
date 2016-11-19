/*
 * prog.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Karan
 */
#include <list>
using namespace std;

/**
      Changes the given lists so that they "cross over" like this:

      a: 0 ... n-1 n ...
                  x
      b: 0 ... m-1 m ...

      For example, if a is [1, 2, 3, 4], b is [5, 6, 7],
      n is 2 and m is 1, then a becomes [1, 2, 6, 7] and
      b becomes [5, 3, 4].

      Use iterators.

      You may assume that n < a.size() and m < b.size().
   */
void crossOver(list<int>& a, int n, list<int>& b, int m)
{
	list<int> :: iterator it;
	int count = 0;
	list<int> values_from_a, values_from_b;
	for(it = a.begin(); it != a.end(); it++)
	{
		if(count >= n)
		{
			values_from_a.push_back(*it);
		}
		count ++;
	}
	count = 0;
	for(it = b.begin(); it != b.end(); it++)
	{
		if(count >= m)
		{
			values_from_b.push_back(*it);
		}
		count ++;
	}
	count = 0;
	for(it = a.begin(); it != a.end(); it++)
	{
		if(count == n)
		{
			a.splice(it, values_from_b);
			break;
		}
		count++;
	}
	while(it != a.end())
	{
		it = a.erase(it);
	}
	count = 0;
	for(it = b.begin(); it != b.end(); it ++)
	{
		if(count == m)
		{
			b.splice(it, values_from_a);
			break;
		}
		count++;
	}
	while(it != b.end())
	{
		it = b.erase(it);
	}
}




