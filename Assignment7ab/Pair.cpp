/*
 * Pair.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */
#include <iostream>
using namespace std;

/**
   Implement the constructor to initialize two Box values,
   and do the right thing in the "big 3".

   Note that the Box::show method prints a count of ALL Box
   objects that have been created and not yet destroyed.
*/

#include "Pair.h"

Pair::Pair(int v1, int v2)
{
	this->first = new Box(v1);
	this->second = new Box(v2);
}


// copy constructor

Pair::Pair(const Pair& other)
{
	this->first = new Box(other.first->value());
	this->second = new Box(other.second->value());
}

// operator=

Pair& Pair::operator=(const Pair& other)
{
	if(this->first != nullptr)
	{
		delete this->first;
	}
	if(this->second != nullptr)
	{
		delete this->second;
	}

	this->first = new Box(other.first->value());
	this->second = new Box(other.second->value());
	return *this;
}

// destructor

Pair::~Pair()
{
	delete this->first;
	delete this->second;
}

