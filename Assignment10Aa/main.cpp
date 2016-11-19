/*
 * main.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Karan
 */
#include <string>
#include<iostream>

using namespace std;

bool allSame(string str);

/**
   Return true if the given string contains identical
   characters or is empty. Use recursion. Do not use loops.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
int main()
{
	string str = "HHHo";
	bool b = allSame(str);
	cout << b << endl;
}
bool allSame(string str)
{
	if(str.length() <= 1)
	{
		return true;
	}
	char first = str.at(0);
	size_t found = str.substr(1).find(first);
	if(found != std::string::npos)
	{
		return allSame(str.substr(1));
	}
	else
	{
		return false;
	}

}




