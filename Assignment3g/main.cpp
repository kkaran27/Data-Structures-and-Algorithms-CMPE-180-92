/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include <string.h>
#include <stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
void splice(const char s[], const char t[], char r[], int rlen);

int main()
{
   const char* a = "Hello";
   const char* b = "World";
   char r[15];
   splice(a, b, r, sizeof(r));
   printf("%s\n", r);
   printf("Expected: HWeolrllod\n");
/*
   a = "Goodbye";
   splice(a, b, r, sizeof(r));
   printf("%s\n", r);
   printf("Expected: GWooordlbdye\n");

   b = "cruel world";
   splice(a, b, r, sizeof(r));
   printf("%s\n", r);
   printf("Expected: Gcoroudebly ew\n");*/
   return 0;
}



/**
   Compuute a string that interleaves the characters in strings s and t.
   If one string is longer than the other, append the suffix.
   For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
   Place the result into the character array r of size rlen.
   If the result does not fit, truncate it to rlen - 1 characters
   and a '\0' terminator.
*/
void splice(const char s[], const char t[], char r[], int rlen)
{
	int newStringLength;
	(strlen(s)<strlen(t)) ? (newStringLength = strlen(s)) : (newStringLength = strlen(t));
	int i, j=0;
	for(i=0; i < newStringLength; i++){
		while(r[j] != '\0'){
			j++;
		}
		r[j] = s[i];
		r[j+1] = t[i];
	}
	if(strlen(s) > strlen(t)){
		for(unsigned int k=i; k < strlen(s); k++){
			r[j]= s[k];
			j++;
		}
	}
	else{
		for(unsigned int k=i; k < strlen(t); k++){
			r[j]= t[k];
			j++;
		}
	}
}




