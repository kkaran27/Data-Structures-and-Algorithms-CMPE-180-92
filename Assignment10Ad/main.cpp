/*
 * main.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Karan
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void digitsHelper(string , string, vector<string>&);
vector<string> digitGroups(string);

int main()
{
	string str = "Union 76";
	vector<string> v;
	v = digitGroups(str);
	for(int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << endl;
	}
}

void digitsHelper(string str, string currentDigitGroup, vector<string>& digitGroups)
{
    if(str.length()==0)
    {
    	currentDigitGroup += "";
    }
    if((str.front() >= '0' && str.front() <= '9'))
    {
    	currentDigitGroup += str.front();
    	digitsHelper(str.substr(1), currentDigitGroup, digitGroups);

    }
    else
    {
    	if(currentDigitGroup != "")
    	{
    		digitGroups.push_back(currentDigitGroup);
    	}
    	currentDigitGroup = "";
    	if(str.length() != 0)
    	{
    		digitsHelper(str.substr(1), currentDigitGroup, digitGroups);
    	}
    }
}

/**
   Given a string, return a vector of all substrings consisting of
   digits contained in it. For example, if str is "I like 7 and 13",
   return a vector containing "7" and "13".
   Use a recursive helper method. Do not use loops.
   A digit is a character between '0' and '9' inclusive.

*/
vector<string> digitGroups(string str)
{
   vector<string> result;
   digitsHelper(str, "", result);
   return result;
}




