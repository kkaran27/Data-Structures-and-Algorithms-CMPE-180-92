/*
 * Trace.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */

/*
In the constructor, copy constructor, assignment operator, destructor
print messages "Constructing ...", "Copying ...", "Assigning ... to ...", "Destroying ...", and do what else is necessary.
 */

#include <iostream>
#include "Trace.h"

using namespace std;

Trace::Trace(string s)
{
	this->str = s;
	cout << "Constructing " << this->str << endl;
}
Trace::Trace(const Trace& other)
{
	cout << "Copying " << other.str <<endl;
	this->str = other.str;
}
Trace& Trace::operator=(const Trace& other)
{
	cout << "Assigning " << this->str << " to " << other.str << endl;

	this->str = other.str;
	return *this;
}
Trace::~Trace()
{
	cout << "Destroying " << this->str << endl;
}




