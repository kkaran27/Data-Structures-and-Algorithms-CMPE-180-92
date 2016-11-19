/*
 * QuickBug.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */
/*
  Look at QuickBug.h and then complete the implementation.
*/
#include<iostream>
#include"QuickBug.h"
using namespace std;

void QuickBug :: move(int dx)
{
	Bug::move(2 * dx);
}


