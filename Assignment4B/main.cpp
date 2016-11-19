/*
 * main.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: Karan
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

/**
 * Main.
 */
void read_file(ifstream&);

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    /***** Complete this program. *****/

    if(input.is_open())
    {
    	read_file(input);
    }
}


void read_file(ifstream& input)
{
	string subject, line, first_name, last_name, student_name;
	input >> subject;
	cout << "TEST SCORES for " << subject << endl << endl;
	int number_of_students, k=0, number_of_scores;
	input >> number_of_students;
	//cout << number_of_students << endl;
	string* student_names = new string[number_of_students + 1];
	int** total_scores = new int*[number_of_students];
	int* scores;
	while(getline(input, line))
	{

		input >> first_name;
		input >> last_name;
		student_name = first_name + " " + last_name;
		student_names[k] = student_name;
		//cout << student_names[k] << endl;

		//cout << student_name << endl;
		input >> number_of_scores;
		scores = new int[number_of_scores];
		for(int i=0; i<number_of_scores; i++)
		{
			input >> scores[i];
		}
		scores[number_of_scores] = -1;
		total_scores[k] = scores;
		k++;
		//cout << number_of_scores << endl;
	}

	for(int i = 0; i < number_of_students; i++)
	{
		cout << student_names[i] << endl;
		int j=0;
		while(total_scores[i][j] != -1)
		{
			cout << "\t" << total_scores[i][j];
			j++;
		}
		if(j==0)
		{
			cout <<"\t" << "(none)";
		}
		cout << endl << endl;
	}

}

