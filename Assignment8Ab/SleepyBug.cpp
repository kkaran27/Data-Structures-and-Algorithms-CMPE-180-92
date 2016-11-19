/*
 * SleepyBug.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */
#include"SleepyBug.h"
#include<iostream>

using namespace std;

void SleepyBug::move(int dx)
{
	Bug::move(dx);
	moves++;
	if(moves % 4 == 0)
	{
		Bug::move(-dx);
	}
}



