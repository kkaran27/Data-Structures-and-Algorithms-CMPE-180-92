/*
 * hash.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: Karan
 */
#include "hash.h"

int hashCode(int x, int n)
{
   if (x >= 0) return x % n; else return -x % n;
}

/**
   Implement an algorithm for removing an element from a hash table
   with linear probing. If the element is absent, do not modify the table.
   Your textbook has two options for implementing removal, neither of
   which is attractive. Instead, do the following: If you remove
   table[h], then visit the remainder of the probing sequence
   until you get EMPTY. Collect all elements that aren't at the natural
   position and replace them with EMPTY. Then insert them again.
*/
void remove(vector<int>& table, int element)
{
   int h = hashCode(element, table.size());
   bool flag = false;
   vector<int> elements;
   int i;
   for(i = h; i < table.size(); i++)
   {
	   if(table[i] == element)
	   {
		   table[i] = EMPTY;
		   flag = true;
		   break;
	   }
   }
   if(flag == true)
   {

	   for(int j = i+1; j < table.size(); j++)
	   {
		   if(table[j] == EMPTY)
		   {
			   break;
		   }
		   if(table[j]%table.size() != j)
		   {
			   elements.push_back(table[j]);
			   table[j] = EMPTY;
		   }
	   }
   	}
   for(int i = 0; i < elements.size(); i++)
   {
	   insert(table, elements[i]);
   }
}

void insert(vector<int>& table, int element)
{
   // from previous problem
	int h = hashCode(element, table.size());
	   bool flag = false;
	   for(int i = h; i < table.size(); i++)
	   {
		   if(table[i] == h)
		   {
			   flag = true;
			   break;
		   }
		   if(table[i] == EMPTY)
		   {
			   table[i] = element;
			   flag = true;
			   break;
		   }
	   }
	   if(flag == false)
	   {
		   for(int i=0; i < h; i++)
		   {
			   if(table[i]==h)
			   {
				   break;
			   }
			   if(table[i] == EMPTY)
			   {
				   table[i] = element;
				   break;
			   }
		   }

	   }
}




