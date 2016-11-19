/*
 * main.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Karan
 */
/**
   Computes the average of all positive elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all positive elements in a, or 0 if there are none.
*/
double avgpos(int a[], int alen)
{
	double average, sum;
	int j=0;
	for(int i=0; i < alen; i++){
		if(a[i] > 0){
			sum += a[i];
			j++;
		}
	}
	if(j != 0){
		average = sum/j;
	}
	else{
		average = 0;
	}
	return average;
}





