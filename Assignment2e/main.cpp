/*
 * main.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: Karan
 */
/**
   We have three t-shirts in sizes small, medium, and large.
   Write a function that takes the weights of three people
   and sets them so that the first parameter becomes
   the weight of the person who should get the small shirt
   (i.e. the lightest one), the second one becomes the weight
   of the person who should get the medium one (i.e. the
   second-lightest one), and the third parameter becomes
   the weight of the person who should get the largest one.
*/
#include <iostream>
using namespace std;

void smlShirts(int& first, int& second, int& third)
{
	int w[3] = {first, second, third};
	int temp;

	for(int i=0; i<3; i++){
		for(int j=0; j < 3-i-1; j++){
			if(w[j] > w[j+1]){
				temp = w[j];
				w[j] = w[j+1];
				w[j+1] = temp;
			}
		}
	}
	first = w[0];
	second = w[1];
	third = w[2];
}

int main() {
	int w1 = 110, w2 = 100, w3 = 120;
	smlShirts(w1, w2, w3);
	cout << w1 << endl;
	cout << w2 << endl;
	cout << w3 << endl;
}





