/*
 * main.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: Karan
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   cout << "Enter n: ";
   int n;
   cin >> n;
   cout << endl;

   // Draw the following "x in a box" pattern. There are n asterisks
   // on each side. In this example, n is 8.
   // ********
   // **    **
   // * *  * *
   // *  **  *
   // *  **  *
   // * *  * *
   // **    **
   // ********

   char a[50][50];

   for(int k=0; k<n; k++){
	   for(int l=0;l<n;l++){
		   a[k][l] = '*';
	   }
   }

   for(int i=0; i<n; i++){
	   cout << endl;
	   for(int j=0;j<n;j++){
		   if(i == j || ((i+j) == n-1)  || i == 0 || i == n-1 || j==0 || j == n-1){
			   cout << a[i][j];
		   }else{
			   cout << " ";
		   }

	   }
   }

   return 0;
}




