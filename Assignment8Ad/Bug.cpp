/*
 * Bug.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */
#include "Bug.h"

Bug::Bug(int initialX)
{
   x = initialX;
}

int Bug::getPosition() const
{
   return x;
}

void Bug::move(int amount)
{
   x = x + amount;
}




