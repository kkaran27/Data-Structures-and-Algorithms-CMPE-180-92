/*
 * Pair.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */
#include <iostream>
using namespace std;

/**
   In this implementation of the Pair class, you will NOT COPY
   Box objects. Instead, when copying Pair objects, copy the pointers
   and increment the refcount of the box whose pointer you copied,
   so that the refcount always tells you how many pointers point
   to it. If the refcount goes to zero, delete the Box object.

   Note that the Pair(int v1, int v2) constructor also shares
   the Box object if v1 equals v2.
*/

#include "Pair.h"

Pair::Pair(int v1, int v2)
{
   first = new Box(v1);
   if (v1 == v2)
      second = first;
   else
      second = new Box(v2);
   first->refcount++;
   second->refcount++;
}

Pair::Pair(const Pair& other)
{
	this->first = other.first;
	other.first->refcount++;
	this->second = other.second;
	other.second->refcount++;

}

Pair& Pair::operator=(const Pair& other)
{
	this->first->refcount--;
	if(this->first->refcount == 0)
	{
		delete this->first;
	}
	this->first = other.first;
	other.first->refcount++;

	this->second->refcount--;
	if(this->second->refcount == 0)
	{
		delete this->second;
	}
	this->second = other.second;
	other.second->refcount++;

	return *this;
}


Pair::~Pair()
{
	if(first->_objects != 0 && first != second)
	{
		delete first;
	}
	if(first != second && second->_objects != 0)
	{
		delete second;
	}
	if(first == second && first->_objects !=0)
	{
		delete first;
	}
	/*if(first != nullptr && first->_objects !=0)
	{
		if(second != nullptr)
		{
			if(first != second)
			{
				delete second;
			}
		}
		delete first;
	}*/



}




