/*
 * Runner.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: Karan
 */
#include <iostream>
#include "Trace.h"

using namespace std;

Trace fun(Trace t)
{
   Trace r = t;
   return r;
}

int main()
{
   Trace t("Fred");
   Trace u("Wilma");
   u = fun(t);
   return 0;
}




