/*
 * main.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Karan
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int main(){
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;
    int empty_line_count=0;
    int hiphen_count=0;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail()){
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

    /***** Complete this program. *****/

    if (input.is_open()){

       while ( getline (input,line) ){

    	 line_count++;
    	 character_count += line.length();
    	 if(line.length() == 0){
    	     empty_line_count++;
    	 }

    	 for(unsigned int i=0; i<line.length(); i++){
    		 if(line.at(i) == ' '){
    			 space_count++;
    		 }
    		 if((line.at(i) > 32 && line.at(i) < 65) || (line.at(i) > 90 && line.at(i) < 97) || (line.at(i) > 122 && line.at(i) < 127)){
    			 punctuation_count++;
    		 }
    		 if(line.at(i) > 64 && line.at(i) < 91){
    			 upper_count++;
    		 }
    		 if(line.at(i) > 96 && line.at(i) < 123){
    			 lower_count++;
    		 }
    		 if(line.at(i)== '-') {
    			 if(line.at(i+1) != '-') {
    				 hiphen_count++;
    			 }
    		 }
    		 word_count = hiphen_count + space_count + line_count - empty_line_count;
    	 }

       }

       input.close();
     }


    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;
}
