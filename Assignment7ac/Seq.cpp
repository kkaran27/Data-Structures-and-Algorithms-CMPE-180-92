/*
 * Seq.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */
#include <iostream>
#include "Seq.h"

/*
  A Seq is a sequence of Box objects. The constructor Seq(int length)
  constructs a sequence of Box objects of the given length, all
  constructed with the default constructor. Implement that constructor
  and the "big 3" memory management functions.
*/

Seq::Seq(int length)
{
	this->len = length;
	this->boxes = new Box[this->len];
}

Seq::Seq(const Seq& other)
{
	this->boxes = new Box[other.len];
	this->len = other.len;
	for(int i=0; i < other.len; i++)
	{
		boxes[i] = other.boxes[i];
	}
}

Seq& Seq::operator=(const Seq& other)
{

	delete[] this->boxes;
	this->boxes = new Box[other.len];
	this->len = other.len;
	for(int i=0; i < other.len; i++)
	{
		boxes[i] = other.boxes[i];
	}
	return *this;
}

Seq::~Seq()
{
	delete[] this->boxes;
}




