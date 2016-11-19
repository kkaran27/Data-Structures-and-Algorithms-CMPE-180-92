/*
 * QuickBug.h
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */

#ifndef QUICKBUG_H
#define QUICKBUG_H
#include "Bug.h"

/**
   A QuickBug moves twice as fast as a regular Bug.
*/
class QuickBug : public Bug
{
 public:
   virtual void move(int dx);
};
#endif

