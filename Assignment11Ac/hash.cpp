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
   Implement the algorithm for inserting an element in a hash table
   with linear probing. The probing sequence simply visits

   h, h + 1, h + 2, ...,

   reduced modulo the table size n.

   If the element is present or the table is full, do not modify the table.

   For simplicity, you store integers in the table. Use the given
   hashCode function for hashing them.
*/

void insert(vector<int>& table, int element)
{
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




