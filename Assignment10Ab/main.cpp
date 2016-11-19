/*
 * main.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Karan
 */
#include <string>
#include <iostream>

using namespace std;
string mesh(string a, string b);

/**
   Mesh two strings by alternating characters from them. If one string
   runs out before the other, just pick from the longer one.
   For example, mesh("Fred", "Wilma") is "FWrieldma".
   Use recursion. Do not use loops.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
int main()
{
	string a = "Karan";
	string b = "Nikita";
	string meshed = mesh(a,b);
	cout << meshed << endl;
}
string mesh(string a, string b)
{
	string r;
	if(a.length() == 0)
	{
		return b;
	}
	if(b.length() == 0)
	{
		return a;
	}
	return std::string() + a.front() + b.front() + mesh(a.substr(1) , b.substr(1));

}




