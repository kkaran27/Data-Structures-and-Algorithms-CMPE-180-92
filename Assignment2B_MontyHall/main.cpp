/*
 * main.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Karan
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

void simulate(int sequence, int& win1, int& win2);
Door hideCar();       //To return the door behind which the car is hidden
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);    //To return the door that Monty opens
Door makeFirstChoice();                  //To return the door selected by the contestant
Door makeSecondChoice(Door firstDoor, Door openedDoor); // To return the door if switched by the contestant.
Door randomDoor();        //To return a random door
Door randomDoorNot(Door aDoor, Door anotherDoor);         //To return a door which is not one of the arguments
void printHeader();


int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));  // seed the random number generator
    printHeader();

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}

/*This function calls several other functions to hide the car, select a door for the first time,
the door that Monty opens and the second choice. Also, it calculates how many times the
contestant wins if he stays with the first choice and also for the second choice and their ratio.*/

void simulate(int sequence, int& win1, int& win2){
	string winFirst = "", winSecond = "";
	Door carBehindDoor = hideCar();
	Door firstChoiceDoor = makeFirstChoice();
	Door openedDoor = openDoor(firstChoiceDoor, carBehindDoor);
	Door secondChoiceDoor = makeSecondChoice(firstChoiceDoor, openedDoor);


		if(secondChoiceDoor == carBehindDoor){
			win2 ++;
			winSecond = "Yes";
		}else{
			win1 ++;
			winFirst = "Yes";
		}

	cout << setw(4) << sequence
		 << setw(15) << carBehindDoor
		 << setw(15) << firstChoiceDoor
		 << setw(15) << openedDoor
		 << setw(15) << secondChoiceDoor
		 << setw(15) << winFirst
		 << setw(15) << winSecond << endl;
}

Door hideCar(){
	Door carBehindDoor = randomDoor();
	return carBehindDoor;
}

Door openDoor(Door firstChoiceDoor, Door carBehindDoor){
	Door openDoor;
	openDoor = randomDoorNot(firstChoiceDoor, carBehindDoor);
	return openDoor;
}

Door makeFirstChoice(){
	Door doorChoice = randomDoor();
	return doorChoice;
}

Door makeSecondChoice(Door firstDoor, Door openedDoor){
	Door secondChoiceDoor = randomDoor();
	while(secondChoiceDoor == openedDoor || secondChoiceDoor == firstDoor){
		secondChoiceDoor = randomDoor();
	}
	return secondChoiceDoor;
}

Door randomDoor(){
	Door doorChoice = rand()%3 + 1;
	return doorChoice;
}

Door randomDoorNot(Door aDoor, Door anotherDoor){
	Door openDoor = randomDoor();
	if(aDoor == anotherDoor){
		while(openDoor == aDoor){
			openDoor = randomDoor();
		}
	}
	while(openDoor == aDoor || openDoor == anotherDoor){
				openDoor = randomDoor();
			}
	return openDoor;
}

void printHeader(){
	cout << setw(4) << "#"
		 << setw(15) << "Car here"
		 << setw(15) << "First choice"
		 << setw(15) << "Opened door"
		 << setw(15) << "Second choice"
		 << setw(15) << "Win first"
		 << setw(15) << "Win second" << endl;
}
