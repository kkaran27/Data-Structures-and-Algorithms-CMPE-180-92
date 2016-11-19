/*
 * SleepyBug.h
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */

#ifndef SLEEPYBUG_H
#define SLEEPYBUG_H

#include "Bug.h"

/**
   A SleepyBug moves as fast as a regular bug, but after three calls
   to move it gets sleepy and ignores the next call to move.
*/
class SleepyBug : public Bug
{

 public:
   virtual void move(int dx);
 private:
   int moves;
};

#endif

