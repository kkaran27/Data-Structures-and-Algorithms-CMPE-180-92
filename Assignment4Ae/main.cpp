/*
 * main.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: Karan
 */
#include <iostream>

using namespace std;

char* longest(char** words, int n);

int main()
{
   char words[] = "Hello\0Goodbye\0Bonjour\0Arrivederci";
   char* starts[] = { words, words + 6, words + 14, words + 22 };
   char* result = longest(starts, 4);
   cout << result << endl;
   cout << "Expected: " << starts[3] << endl;

   result = longest(starts, 3);
   cout << result << endl;
   cout << "Expected: " << starts[1] << endl;

   result = longest(starts, 1);
   cout << result << endl;
   cout << "Expected: " << starts[0] << endl;

   return 0;
}

/**
   Given an array of strings of length n > 0, return the longest
   string. If there are multiple strings of the same maximum length,
   return the first one.
*/
char* longest(char** words, int n)
{
	int length=0, j=0, max_length_index = 0;
	for(int i=0; i < n; i++)
	{
		while(words[i][j] != '\0')
		{
			j++;
		}
		if(j > length)
		{
			length = j;
			max_length_index = i;
		}
	}
	char* arr = new char[j];
	for(int k = 0; k < length; k++)
	{
		arr[k] = words[max_length_index][k];
	}

	return arr;
}



