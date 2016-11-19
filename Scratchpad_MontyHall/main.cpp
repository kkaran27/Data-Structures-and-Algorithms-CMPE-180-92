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

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void simulate(int sequence, int& win1, int& win2);
Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstDoor, Door openedDoor);

Door randomDoor();
Door randomDoorNot(Door aDoor, Door anotherDoor);
Door chooseRemainingDoor(Door firstDoor, Door openedDoor);
void printHeader();

/**
 * Main
 */
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

/***** Complete this program. ****/

void simulate(int sequence, int& win1, int& win2){
	//cout << "Car Behind Door" << endl;
	Door carBehindDoor = hideCar();
	//cout << carBehindDoor << endl;

	//cout << "First choice" << endl;
	Door firstChoiceDoor = makeFirstChoice();
	//cout << firstChoiceDoor << endl;

	Door openedDoor = openDoor(firstChoiceDoor, carBehindDoor);
	//cout << "Opened door: " << openedDoor << endl;

	Door secondChoiceDoor = makeSecondChoice(firstChoiceDoor, openedDoor);
	//cout << "Second choice: " << secondChoiceDoor << endl;

	if(secondChoiceDoor == firstChoiceDoor){
		if(secondChoiceDoor == carBehindDoor){
			win1 ++;
		}
		else{
			win2 ++;
		}
	}else{
		if(secondChoiceDoor == carBehindDoor){
			win2 ++;
		}else{
			win1 ++;
		}
	}
	cout << setw(4) << sequence << "    " << carBehindDoor << "    " << firstChoiceDoor << "    " << openedDoor << "    " << secondChoiceDoor << "    " << "Win first" << "    " << "Win second" << endl;
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
	while(secondChoiceDoor == openedDoor){
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

Door chooseRemainingDoor(Door firstDoor, Door openedDoor){
	return 0;
}

void printHeader(){
	cout << setw(4) << "#" << "    " << "Car here" << "    " << "First choice" << "    " << "Opened door" << "    " << "Second choice" << "    " << "Win first" << "    " << "Win second" << endl;
}
