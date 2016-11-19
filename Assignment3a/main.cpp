/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
#include <iostream>
using namespace std;


/*
  Read numbers from standard input and print the average of
  all positive numbers, with two digits after the decimal point.

  The end of input is indicated by a number 0. For example,
  if the input is

  1 2 4 -3 5 -6 0

  then you print "Average: 3.00". If there are no positive elements,
  print "Average: 0.00".
*/

int main()
{
	int num[50], i=0, sum=0, k=0;
	double average=0.00;
	do{
		cin >> num[i];
		i++;
	}while(num[i-1] != 0);

	for(int j=0 ; j < i; j++){
		if(num[j] > 0){
			sum += num[j];
			k++;
		}
	}

	if(k != 0){
		average = sum/k;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "Average: " << average;
	}
	else
	{
		cout << "Average: 0.00";
	}

   return 0;


}




