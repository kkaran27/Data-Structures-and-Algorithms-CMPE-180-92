/*
 * main.cpp
 *
 *  Created on: Sep 3, 2016
 *      Author: Karan
 */
/**
   Return the nth digit from the back (that is, the factor of pow(10, n)
   in the decimal representation of the given number).
   @param num a number
   @param n the power of 10 for which we want the digit
   @return the nth digit
   E.g. nthDigit(1729, 1) is 2 since 1729 = 9*pow(10, 0) + 2*pow(10,1) + ...
   Hint: Keep dividing by 10
*/
#include<iostream>
using namespace std;

int nthDigit(int , int);

int main(){

	int number, digit_pos, digit;
	cout << "Enter a number" << endl;
	cin >> number;
	cout << "Enter the digit number to be obtained" << endl;
	cin >> digit_pos;
	digit = nthDigit(number, digit_pos);
	cout << "The digit is: " << digit << endl;
}

int nthDigit(int num, int n)
{
	int digit;
	for(int i = 0; i <= n; i++){
		digit = num%10;
		num = num/10;
	}
	return digit;
}




