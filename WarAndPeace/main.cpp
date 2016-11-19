/*
 * main.cpp
 *
 *  Created on: Sep 15, 2016
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

const string INPUT_FILE_NAME = "WarAndPeace.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    string line;


    int line_count = 0;

    vector<int> lineVector;
    vector<int> charVector;
    vector<string> nameVector;

    vector<int> splitLineVectorForMakar;
    vector<int> splitLineVectorForAlexeevich;
    vector<int> splitLineVectorForJoseph;
    vector<int> splitLineVectorForBazdeev;
    vector<int> splitLineVectorForBoris;
    vector<int> splitLineVectorForDrubetskoy;

    vector<int> splitLineCharacterPositionForJoseph;
    vector<int> splitLineCharacterPositionForMakar;
    vector<int> splitLineCharacterPositionForBoris;


    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    if(input.is_open()){
    	while(getline(input, line)){
    		line_count++;
    		int m_position = line.find(MAKAR);
    		if(m_position != string::npos){
    			cout << setw(8) << line_count << setw(8) << m_position+1 << setw(24) << MAKAR << endl;
    			lineVector.push_back(line_count);
    			charVector.push_back(m_position+1);
    			nameVector.push_back(MAKAR);
    		}

    		int j_position = line.find(JOSEPH);
    		if(j_position != string::npos){
    			cout << setw(8) << line_count << setw(8) << j_position+1 << setw(24) << JOSEPH << endl;
    			lineVector.push_back(line_count);
    			charVector.push_back(j_position+1);
    			nameVector.push_back(JOSEPH);
    		}
    		int b_position = line.find(BORIS);
    		if(b_position != string::npos){
    		    cout << setw(8) << line_count << setw(8) << b_position+1 << setw(24) << BORIS << endl;
    		    lineVector.push_back(line_count);
    		    charVector.push_back(b_position+1);
       			nameVector.push_back(BORIS);
    		}


    		//Split check for Makar Alexeevich
    		int split_position_m = line.find("Makar");
    		if((split_position_m != string::npos)&& (line[split_position_m + 5] == '\0')){
    			splitLineVectorForMakar.push_back(line_count);
    			splitLineCharacterPositionForMakar.push_back(split_position_m + 1);
    		}
    		int split_position_a = line.find("Alexeevich");
    		if((split_position_a != string::npos) && split_position_a == 0){
    			splitLineVectorForAlexeevich.push_back(line_count);
    			//splitLineCharacterPositionForMakar.push_back(split_position_a + 1);
    		}

    		//Split check for Joseph Bazdeev
    		int split_position_j = line.find("Joseph");
    		if((split_position_j != string::npos)&& (line[split_position_j + 6] == '\0')){
    		    splitLineVectorForJoseph.push_back(line_count);
    		    splitLineCharacterPositionForJoseph.push_back(split_position_j + 1);
    		}
    		int split_position_b = line.find("Bazdeev");
    		if((split_position_b != string::npos) && split_position_b == 0){
    			splitLineVectorForBazdeev.push_back(line_count);
    			//splitLineCharacterPositionForJoseph.push_back(split_position_b + 1);
    		}


    		//Split check for Boris Drubetskoy
    		int split_position_bo = line.find("Boris");
    		if((split_position_bo != string::npos)&& (line[split_position_bo + 5] == '\0')){
    			splitLineVectorForBoris.push_back(line_count);
    		    splitLineCharacterPositionForBoris.push_back(split_position_bo + 1);
    		}
       		int split_position_d = line.find("Drubetskoy");
       		if((split_position_d != string::npos) && split_position_d == 0){
    		    splitLineVectorForDrubetskoy.push_back(line_count);
    		    //splitLineCharacterPositionForBoris.push_back(split_position_d + 1);
    		 }

    	}

    	// Printing found names splitted across lines

    	for(int i=0; i<splitLineVectorForMakar.size()-1; i++){
    		for(int j=0; j<splitLineVectorForAlexeevich.size()-1;j++){
    			if(splitLineVectorForMakar.at(i) == splitLineVectorForAlexeevich.at(j)-1){
    				cout << splitLineVectorForMakar.at(i) <<" " << splitLineCharacterPositionForMakar.at(i) << " "<< "Makar Alexeevich" << endl;
    				lineVector.push_back(splitLineVectorForMakar.at(i));
    				charVector.push_back(splitLineCharacterPositionForMakar.at(i));
    				nameVector.push_back(MAKAR);
    			}
    		}
    	}
    	for(int i=0; i<splitLineVectorForJoseph.size()-1; i++){
    		//cout << splitLineVectorForJoseph.at(i) << endl;
    		for(int j=0; j<splitLineVectorForBazdeev.size()-1; j++){
    			if(splitLineVectorForJoseph.at(i) == splitLineVectorForBazdeev.at(j)-1){
    				cout << splitLineVectorForJoseph.at(i) <<" " << splitLineCharacterPositionForJoseph.at(i) << " "<< "Joseph Bazdeev" << endl;
    				lineVector.push_back(splitLineVectorForJoseph.at(i));
    				charVector.push_back(splitLineCharacterPositionForJoseph.at(i));
    				nameVector.push_back(JOSEPH);
    			}
    		}
    	}
    	for(int i=0; i<splitLineVectorForBoris.size()-1; i++){
    		//cout << splitLineVectorForBoris.at(i) << endl;
    		for(int j=0; j<splitLineVectorForDrubetskoy.size()-1; j++){

    			if(splitLineVectorForBoris.at(i) == splitLineVectorForDrubetskoy.at(j)-1){
    				cout << splitLineVectorForBoris.at(i) <<" " << splitLineCharacterPositionForBoris.at(i) << " "<< "Boris Drubetskoy" << endl;
    				lineVector.push_back(splitLineVectorForBoris.at(i));
    				charVector.push_back(splitLineCharacterPositionForBoris.at(i));
    				nameVector.push_back(BORIS);
    			}
    		}
       	}
    	cout << " *****************************************************  " << endl;
    	cout << setw(8) << "LINE" << setw(12) << "POSITION" << setw(12) << "NAME" << endl;
    	for(int i=0; i < lineVector.size(); i++){
    		cout << setw(8) << lineVector.at(i) << setw(12) << charVector.at(i) << setw(24) << nameVector.at(i) << endl;
    	}
    }
}
