/*
 * prog.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Karan
 */
#include <vector>
#include <map>
#include <set>
using namespace std;

/**
  Makes a map associating letters with the words
  starting with that letter.
  @param words an array of strings
  @return the map
*/
map<string, set<string>> wordsByStartingLetter(vector<string> words)
{

		map<string, set<string>> startingWith;
		set<string> :: iterator it;
		for(int i=0; i<words.size(); i++)
		{
			string s;
			s.push_back(words[i][0]);
			startingWith[s].insert(words[i]);
			for(int j=i+1; j<words.size(); j++)
			{

				if(words[i][0] == words[j][0])
				{
					startingWith[s].insert(words[j]);
				}
			}
		}
		return startingWith;

}




