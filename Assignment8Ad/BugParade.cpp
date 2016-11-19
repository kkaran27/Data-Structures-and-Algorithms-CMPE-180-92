/*
 * BugParade.cpp
 *
 *  Created on: Oct 21, 2016
 *      Author: Karan
 */
#include"BugParade.h"
#include <iostream>

using namespace std;

void BugParade::add(Bug* bug)
{
	bugs.push_back(bug);
}

vector<int> BugParade::moveAll(int distance)
{
	vector<int> v;
	for(int i=0; i<bugs.size(); i++)
	{
		bugs[i]->move(distance);
		v.push_back(bugs[i]->getPosition());
	}
	return v;
}



