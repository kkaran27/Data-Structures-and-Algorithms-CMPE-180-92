/*
 * Tester.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: Karan
 */
#include <iostream>
#include <vector>

using namespace std;

void insert(vector<vector<int>>& table, int element);

void print(const vector<vector<int>>& table)
{
   for (int i = 0; i < table.size(); i++) {
      for (int j = 0; j < table[i].size(); j++) {
         cout << table[i][j] << " ";
      }
      if (i < table.size() - 1) cout << "| ";
      else cout << endl;
   }
}

int main()
{
   vector<vector<int>> table1(10);
   insert(table1, 42);
   print(table1);
   cout << "Expected:  | | 42 | | | | | | |" << endl;
   insert(table1, 52);
   print(table1);
   cout << "Expected:  | | 42 52 | | | | | | |" << endl;
   insert(table1, 43);
   print(table1);
   cout << "Expected:  | | 42 52 | 43 | | | | | |" << endl;
   insert(table1, 43);
   print(table1);
   cout << "Expected:  | | 42 52 | 43 | | | | | |" << endl;
   return 0;
}







