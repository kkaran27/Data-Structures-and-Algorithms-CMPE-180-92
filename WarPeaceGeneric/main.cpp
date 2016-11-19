/*
 * main.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Karan
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Names to search for.
const string MAKAR  = "Makar Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string BORIS  = "Boris Drubetskoy";

const string MAK = "Makar";
const string JOS = "Joseph";
const string BOR = "Boris";
const string ALE = "Alexeevich";
const string BAZ = "Bazdeev";
const string DRU = "Drubetskoy";

const string INPUT_FILE_NAME = "WarAndPeace.txt";

void print_header();

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    string line;
    int line_count=0;
    vector<string> names;
    names.push_back(MAKAR);
    names.push_back(JOSEPH);
    names.push_back(BORIS);

    vector<string> split_first_names;
    split_first_names.push_back(MAK);
    split_first_names.push_back(JOS);
    split_first_names.push_back(BOR);

    vector<string> split_last_names;
    split_last_names.push_back(ALE);
    split_last_names.push_back(BAZ);
    split_last_names.push_back(DRU);

    if (input.fail())
    {
    	cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    if(input.is_open())
    {
    	print_header();
    	while(getline(input,line))
    	{
    		line_count++;
    		int char_pos;
    		for(int i=0; i < names.size(); i++)
    		{
    			char_pos = line.find(names.at(i));
    			if(char_pos != string :: npos)
    			{
    				cout << setw(8) << line_count << setw(12) << char_pos+1 << setw(30) << names.at(i) << endl;
    			}
    		}

    		for(int i=0; i < split_first_names.size(); i++)
    		{
    			int split_char_pos = line.find(split_first_names.at(i));
    			if((split_char_pos != string :: npos) && (line[split_char_pos + (split_first_names).at(i).size()] == '\0'))
    			{
    				getline(input,line);

    				int split_char_pos_l = line.find(split_last_names.at(i));
    				if((split_char_pos_l != string :: npos) && (split_char_pos_l == 0))
    				{
    					cout << setw(8) << line_count << setw(12) << split_char_pos+1 << setw(30) << names.at(i) << endl;
    				}
    				line_count++;
    			}
    		}

    	}
    }
}

void print_header()
{
	cout << setw(8) << "LINE" << setw(12) << "POSITION" << setw(20) << "NAME" << endl;
}


