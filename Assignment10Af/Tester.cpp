/*
 * Tester.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Karan
 */
#include <iostream>
#include "list.h"

using namespace std;

string toString(const List& lst);

inline NEList operator+=(string h, const List& t) { return NEList(h, t); }

EList nil;

int main()
{
   cout << toString(NEList("Mary", NEList("had", NEList("a", NEList("little", NEList("lamb", EList())))))) << endl;
   cout << "Expected: Mary,had,a,little,lamb" << endl;
   cout << toString("Its" += "fleece" += "was" += "white" += "as" += "snow" += nil) << endl;
   cout << "Expected: Its,fleece,was,white,as,snow" << endl;
   cout << toString("Fred" += "Wilma" += nil) << endl;
   cout << "Expected: Fred,Wilma" << endl;
   cout << toString("Fred" += nil);
   cout << "Expected: Fred" << endl;
   cout << toString(nil);
   cout << "Expected: Fred" << endl;
   return 0;
}




