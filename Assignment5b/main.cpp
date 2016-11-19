/*
 * main.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Karan
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class WidgetReport
{
    /***** Complete this class. *****/

public:
    WidgetReport(ifstream& in);  // constructor
    void print();

    int get_count() const;
    void set_count(int count);
    int get_dept() const;
    void set_dept(int dept);
    int get_empid() const;
    void set_empid(int empid);
    const string& get_name() const;
    void set_name(const string& name);
    int get_plant() const;
    void set_plant(int plant);
    int get_state() const;
    void set_state(int state);

private:
    ifstream& input;  // reference to the input stream
    int state, plant, dept, empid;
    string name;
	int count;

};

const string INPUT_FILE_NAME = "widgets.txt";

int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Generate and print the Widget Report.
    /***** Complete this main. *****/
    WidgetReport widget_report(input);
    widget_report.print();
    //cout << widget_report.get_state() << endl;

    input.close();
    return 0;
}

/***** Put member function definitions after the main. *****/
WidgetReport :: WidgetReport(ifstream& in) : input(in), state(1), plant(0), dept(0), empid(0), name(" "), count(0)
{

}

int WidgetReport::get_count() const
{
	return count;
}

void WidgetReport::set_count(int count) {
	this->count = count;
}

int WidgetReport::get_dept() const {
	return dept;
}

void WidgetReport::set_dept(int dept) {
	this->dept = dept;
}

int WidgetReport::get_empid() const {
	return empid;
}

void WidgetReport::set_empid(int empid) {
	this->empid = empid;
}

const string& WidgetReport::get_name() const {
	return name;
}

void WidgetReport::set_name(const string& name) {
	this->name = name;
}

int WidgetReport::get_plant() const {
	return plant;
}

void WidgetReport::set_plant(int plant) {
	this->plant = plant;
}

int WidgetReport::get_state() const {
	return state;
}

void WidgetReport::set_state(int state) {
	this->state = state;
}

void WidgetReport::print()
{
	string line, first_name, last_name;
	int state=-1, plant, dept, empid, count, state_count=0, plant_count=0, dept_count=0, total_count=0;
	cout << setw(8) << "STATE"
		 << setw(8)	<< "PLANT"
		 << setw(8)	<< "DEPT"
		 << setw(8)	<< "EMPID"
		 << setw(8)	<< "COUNT"
		 << setw(10) << "NAME" << endl << endl;
	if(input.is_open())
	{
		getline(input, line);
		input >> state;
		set_state(state);
		input >> plant;
		set_plant(plant);
		input >> dept;
		set_dept(dept);
		input >> empid;
		set_empid(empid);
		input >> first_name;
		input >> last_name;
		name = first_name + " " + last_name;
		set_name(name);
		input >> count;
		set_count(count);
		state_count += get_count();
		plant_count += get_count();
		dept_count += get_count();
		total_count += get_count();
		cout << setw(8) << get_state()
			 << setw(8)	<< get_plant()
			 << setw(8)	<< get_dept()
			 << setw(8)	<< get_empid()
			 << setw(8)	<< get_count()
			 << setw(20) << get_name() << endl;

		while(getline(input, line))
		{
			state=-1;
			bool state_changed = false;
			bool plant_changed = false;

			input >> state;
			if(state !=-1)
			{
				if(state != get_state())
				{
					cout <<endl << setw(40)<< dept_count << setw(20) << "TOTAL FOR DEPT " << setw(4) << get_dept() << setw(4) << "*" << endl;
					cout << setw(40)<< plant_count << setw(20) << "TOTAL FOR PLANT " << setw(4) << get_plant() << setw(4) << "**" << endl;
					cout << setw(40) << state_count << setw(20) << "TOTAL FOR STATE " << setw(4) << get_state()<< setw(4) << "***" << endl << endl;
					state_count = 0;
					plant_count = 0;
					dept_count = 0;
					state_changed = true;
				}
				set_state(state);
				input >> plant;
				if((plant != get_plant()) && (state_changed == false))
				{
					cout << endl << setw(40) << dept_count << setw(20) << "TOTAL FOR DEPT " << setw(4) << get_dept() << setw(4) << "*" << endl;
					cout << setw(40) << plant_count << setw(20) << "TOTAL FOR PLANT " << setw(4) << get_plant() << setw(4) << "**" << endl << endl;
					plant_count = 0;
					dept_count = 0;
					plant_changed = true;
				}
				set_plant(plant);
				input >> dept;
				if((dept != get_dept()) && (state_changed == false) && (plant_changed == false))
				{
					cout << endl << setw(40) << dept_count << setw(20) << "TOTAL FOR DEPT " << setw(4) << get_dept() << setw(4) << "*" << endl << endl;
					dept_count = 0;
				}
				set_dept(dept);
				input >> empid;
				set_empid(empid);
				input >> first_name;
				input >> last_name;
				name = first_name + " " + last_name;
				set_name(name);
				input >> count;
				set_count(count);
				state_count += get_count();
				plant_count += get_count();
				dept_count += get_count();
				total_count += get_count();
				cout << setw(8) << get_state()
				     << setw(8)	<< get_plant()
					 << setw(8)	<< get_dept()
					 << setw(8)	<< get_empid()
					 << setw(8)	<< get_count()
					 << setw(20) << get_name() << endl;
			}
		}
		cout <<endl << setw(40)<< dept_count << setw(20) << "TOTAL FOR DEPT " << setw(4) << get_dept() << setw(4) << "*" << endl;
		cout << setw(40)<< plant_count << setw(20) << "TOTAL FOR PLANT " << setw(4) << get_plant() << setw(4) << "**" << endl;
		cout << setw(40) << state_count << setw(20) << "TOTAL FOR STATE " << setw(4) << get_state()<< setw(4) << "***" << endl << endl;

		cout << setw(40) << total_count << setw(20) << "GRAND TOTAL" << setw(8) << "****" << endl;
	}
}
