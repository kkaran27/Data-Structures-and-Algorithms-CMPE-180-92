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
   vector<int> table1 = { 10, 20, 32, 42, 54, EMPTY, EMPTY, EMPTY, EMPTY, 99 };
   remove(table1, 54);
   print(table1);
   cout << "Expected: 10, 20, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
   remove(table1, 10);
   print(table1);
   cout << "Expected: 20, EMPTY, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
   remove(table1, 9);
   print(table1);
   cout << "Expected: 20, EMPTY, 32, 42, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 99" << endl;
   vector<int> table2 = { 10, 20, 32, 42, 50, 55, 52, EMPTY, EMPTY, 99 };
   remove(table2, 32);
   print(table2);
   cout << "Expected: 10, 20, 42, 50, 52, 55, EMPTY, EMPTY, EMPTY, 99" << endl;

   return 0;
}







