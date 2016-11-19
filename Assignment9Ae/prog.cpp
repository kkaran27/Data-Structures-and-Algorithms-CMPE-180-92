/*
 * prog.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Karan
 */
#include <vector>
#include <map>
#include <iostream>
using namespace std;

/**
   Makes a map associating letters with the number of words
   starting with that letter.
   @param words a vector of strings
   @return the map

*/
map<string, int> startingLetterFrequency(vector<string> words)
{
	int count=1;
	map<string, int> freq;
	map<string, int> :: iterator it;
	for(int i=0; i<words.size(); i++)
	{
		string s;
		for(int j=i+1; j<words.size(); j++)
		{
			if(words[i][0] == words[j][0])
			{
				count++;
			}
		}

		s.push_back(words[i][0]);
		freq[s] = count;



	}
	return freq;
}




