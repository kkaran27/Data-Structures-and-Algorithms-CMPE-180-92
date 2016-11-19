/*
 * RomanNumeral.h
 *
 *  Created on: Oct 6, 2016
 *      Author: Karan
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include<iostream>
using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(string roman);
    RomanNumeral(int value);

    /***** Complete this class. *****/

	int getDecimal() const;
	const string& getRoman() const;

	//Comments about what these functions do in CPP file

	friend ostream& operator<<(ostream& out, RomanNumeral& r);
	friend istream& operator>>(istream& ins, RomanNumeral& r);
	friend RomanNumeral operator+(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator-(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator*(RomanNumeral a, RomanNumeral b);
	friend RomanNumeral operator/(RomanNumeral a, RomanNumeral b);
	friend bool operator==(RomanNumeral& a, RomanNumeral& b);
	friend bool operator!=(RomanNumeral& a, RomanNumeral& b);

private:
    string roman;      // Roman numeral as a string
    int    decimal;    // decimal value of the Roman numeral
    void toRoman();    // calculate string from decimal value
    void toDecimal();  // calculate decimal value from string
};


#endif /* ROMANNUMERAL_H_ */
