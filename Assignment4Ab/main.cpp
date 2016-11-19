/*
 * main.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Karan
 */
//SOLUTION
/**
   Return a pointer to the first negative element in
   the given array which has length n. If there is no negative element,
   return a pointer past the last element.
*/
#include <iostream>

using namespace std;

int* firstneg(int* arr, int n);

int main()
{
   int a[] = { 1, 4, 9, -4, 8, -9, 0 };
   int* r = firstneg(a, sizeof(a) / sizeof(a[0]));
   cout << hex << r << endl;
   cout << "Expected: " << a + 3 << endl;

   int b[] = { 1, 4, 9, 0 };
   r = firstneg(b, sizeof(b) / sizeof(b[0]));
   cout << hex << r << endl;
   cout << "Expected: " << b + 4 << endl;

   r = firstneg(a, 0);
   cout << hex << r << endl;
   cout << "Expected: " << a << endl;

   return 0;
}




int* firstneg(int* arr, int n)
{
	int *ptr = arr;
	bool flag = false;
	for(int i=0; i<n; i++)
	{
		if(arr[i] < 0)
		{
			flag = true;
			ptr = &arr[i];
			break;
		}
	}
	if(flag == false)
	{
		ptr = &arr[n];
	}
	return ptr;
}




