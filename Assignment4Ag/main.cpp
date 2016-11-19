/*
 * main.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: Karan
 */
#include <iostream>
#include <cstring>

using namespace std;

char** split(char* words);

int main()
{
   char words[] = "Hello Goodbye Bonjour Arrivederci";
   char** result = split(words);
   cout << result[0] << endl;
   cout << "Expected: " << "Hello" << endl;
   cout << result[1] << endl;
   cout << "Expected: " << "Goodbye" << endl;
   cout << result[2] << endl;
   cout << "Expected: " << "Bonjour" << endl;
   cout << result[3] << endl;
   cout << "Expected: " << "Arrivederci" << endl;

   char morewords[] = "Hello  Goodbye"; // Note two spaces
   result = split(morewords);
   cout << result[0] << endl;
   cout << "Expected: " << "Hello" << endl;
   cout << strlen(result[1]) << endl;
   cout << "Expected: " << 0 << endl;
   cout << result[2] << endl;
   cout << "Expected: " << "Goodbye" << endl;

   return 0;
}

/**
   Given a '\0'-terminated character array, split it by replacing
   each space in the character array with a '\0' and return a
   newly allocated array of char* pointers to the resulting strings.
*/
char** split(char* words)
{
   // count spaces
	int count=1, i=0, length, j=0;
	while(words[i] != '\0')
		{
			if(words[i] == ' ')
			{
				words[i] = '\0';
				count++;
			}
			i++;
			length=i;
		}
   // store results
   char** result = new char*[count];
   result[0] = words;
   for(int i=0; i < length; i++)
   {
	   if(words[i] == '\0')
	   {
		   j++;
		   result[j] = words + (i+1);
	   }
   }
   return result;
}



