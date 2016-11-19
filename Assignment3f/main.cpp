/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include <string>
#include<iostream>
using namespace std;

string splice(string, string);

int main(){
	string result = splice("Hello","Goodbye");
	cout << result << endl;
}

/**
   Return a string that interleaves the characters in strings a and b.
   If one string is longer than the other, append the suffix.
   For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
*/
string splice(string a, string b)
{
	string newString, biggerString;
	int newStringLength = min(a.length(),b.length());
	int i;
	for(i=0; i < newStringLength; i++){
		newString.push_back(a.at(i));
		newString.push_back(b.at(i));
	}
	if(a.length() > b.length()){
		biggerString = a;
	}
	else{
		biggerString = b;
	}
	for(unsigned int j=i; j < biggerString.length(); j++){
		newString.push_back(biggerString.at(j));
	}
	return newString;
}




