/*
 * Tester.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: Karan
 */
#include <iostream>
#include "hash.h"

using namespace std;

void print(const vector<int>& table)
{
   for (int i = 0; i < table.size(); i++) {
      if (table[i] == EMPTY) cout << "EMPTY";
      else cout << table[i];
      if (i < table.size() - 1) cout << ", ";
      else cout << endl;
   }
}

int main()
{
   vector<int> table1 = { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
   insert(table1, 42);
   print(table1);
   cout << "Expected: EMPTY, EMPTY, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY" << endl;

   vector<int> table2 = { EMPTY, EMPTY, 52, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };
   insert(table2, 42);
   print(table2);
   cout << "Expected: EMPTY, EMPTY, 52, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY" << endl;

vector<int> table3 = { EMPTY, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89 };
   insert(table3, 42);
   print(table3);
   cout << "Expected: 42, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
   insert(table3, 42);
   print(table3);
   cout << "Expected: 42, EMPTY, 52, 43, 53, 63, 66, 74, 88, 89" << endl;
   insert(table3, 41);
   print(table3);
   cout << "Expected: 42, 41, 52, 43, 53, 63, 66, 74, 88, 89" << endl;

   insert(table3, 40);
   print(table3);
   cout << "Expected: 42, 41, 52, 43, 53, 63, 66, 74, 88, 89" << endl;

   return 0;
}







