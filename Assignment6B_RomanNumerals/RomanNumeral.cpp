/*
 * RomanNumeral.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: Karan
 */
#include<iostream>
#include "RomanNumeral.h"
using namespace std;

/**
 * Default constructor.
 */
RomanNumeral::RomanNumeral() : roman(""), decimal(0)
{
}

//Parametric Constructor to initialize Roman
RomanNumeral::RomanNumeral(string roman)
{
	this->decimal = 0;
	this->roman = roman;
}

//Parametric Constructor to initialize decimal
RomanNumeral::RomanNumeral(int decimal)
{
	this->decimal = decimal;
	this->roman = "";
}

//Accessors for Roman and decimal
int RomanNumeral::getDecimal() const
{
	if(this->decimal == 0)
	{

	}
	return decimal;
}

const string& RomanNumeral::getRoman() const
{
	return roman;
}

//Function that converts decimal to roman and sets the member roman of the object
void RomanNumeral::toRoman()
{
	int temp_decimal = this->decimal;
	string decimal_convert = "";
	if(temp_decimal >= 1000)
	{
		int no_of_thousands = temp_decimal/1000;
		for(int i=1; i <= no_of_thousands; i++)
		{
			decimal_convert += "M";
		}
		temp_decimal %= 1000;
	}
	if(temp_decimal >= 100)
	{
		int no_of_hundreds = temp_decimal/100;
		if(no_of_hundreds == 4)
		{
			decimal_convert += "CD";
		}
		else if(no_of_hundreds == 9)
		{
			decimal_convert += "CM";
		}
		else if(no_of_hundreds>=1 && no_of_hundreds <=3)
		{
			for(int i=1; i <= no_of_hundreds; i++)
			{
				decimal_convert += "C";
			}
		}
		else if(no_of_hundreds == 5)
		{
			decimal_convert += "D";
		}
		else if(no_of_hundreds >=6 && no_of_hundreds <=8)
		{
			decimal_convert += "D";
			for(int i=6; i <= no_of_hundreds; i++)
			{
				decimal_convert += "C";
			}
		}
		temp_decimal %= 100;
	}
	if(temp_decimal >= 10)
	{
		int no_of_tens = temp_decimal/10;
		if(no_of_tens == 4)
		{
			decimal_convert += "XL";
		}
		else if(no_of_tens == 9)
		{
			decimal_convert += "XC";
		}
		else if(no_of_tens >= 1 && no_of_tens <=3)
		{
			for(int i=1; i <= no_of_tens; i++)
			{
				decimal_convert += "X";
			}
		}
		else if(no_of_tens == 5)
		{
			decimal_convert += "L";
		}
		else if(no_of_tens >= 6 && no_of_tens <= 8)
		{
			decimal_convert += "L";
			for(int i=6; i <= no_of_tens; i++)
			{
				decimal_convert += "X";
			}
		}
		temp_decimal %= 10;
	}
	if(temp_decimal >= 1)
	{
		int no_of_units = temp_decimal;
		if(no_of_units == 4)
		{
			decimal_convert += "IV";
		}
		else if(no_of_units == 9)
		{
			decimal_convert += "IX";
		}
		else if(no_of_units >= 1 && no_of_units <= 3)
		{
			for(int i=1; i <= no_of_units; i++)
			{
				decimal_convert += "I";
			}
		}
		else if(no_of_units == 5)
		{
			decimal_convert += "V";
		}
		else if(no_of_units >=6 && no_of_units <=8)
		{
			decimal_convert += "V";
			for(int i=6; i <= no_of_units; i++)
			{
				decimal_convert += "I";
			}
		}
	}

	this->roman = decimal_convert;

}

//Fumction that converts roman to decimal and sets the member decimal of the object
void RomanNumeral::toDecimal()
{
	string temp_roman = this->roman;
	int sum=0;
	for(unsigned int i=0; i < temp_roman.length(); i++)
	{
		if(temp_roman[i] == 'M')
		{
			sum += 1000;
		}
		else if (temp_roman[i] == 'D')
		{
			sum += 500;
		}
		else if(temp_roman[i] == 'C')
		{
			if(temp_roman[i+1] == 'M')
			{
				sum += 900;
				i++;
			}
			else if(temp_roman[i+1] == 'D')
			{
				sum += 400;
				i++;
			}
			else
			{
				sum += 100;
			}
		}
		else if(temp_roman[i] == 'L')
		{
			sum += 50;
		}
		else if(temp_roman[i] == 'X')
		{
			if(temp_roman[i+1] == 'L')
			{
				sum +=40;
				i++;
			}
			else if(temp_roman[i+1] == 'C')
			{
				sum += 90;
				i++;
			}
			else
			{
				sum += 10;
			}
		}
		else if(temp_roman[i] == 'V')
		{
			sum += 5;
		}
		else if(temp_roman[i] == 'I')
		{
			if(temp_roman[i+1] == 'X')
			{
				sum += 9;
				i++;
			}
			else if(temp_roman[i+1] == 'V')
			{
				sum += 4;
				i++;
			}
			else
			{
				sum += 1;
			}
		}
	}
	this->decimal = sum;
}

//Overloading + operator for addition
RomanNumeral operator+(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral result;
	if(a.decimal == 0)
	{
		a.toDecimal();
	}
	if(b.decimal == 0)
	{
		b.toDecimal();
	}
	result.decimal = a.decimal + b.decimal;
	return result;
}

//Overloading - operator for subtraction
RomanNumeral operator -(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral result;
	if (a.decimal == 0)
	{
		a.toDecimal();
	}
	if (b.decimal == 0)
	{
		b.toDecimal();
	}
	result.decimal = a.decimal - b.decimal;
	return result;
}

//Overloading * operator for multiplication
RomanNumeral operator *(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral result;
	if (a.decimal == 0)
	{
		a.toDecimal();
	}
	if (b.decimal == 0)
	{
		b.toDecimal();
	}
	result.decimal = a.decimal*b.decimal;
	return result;
}

//Overloading / operator for division
RomanNumeral operator /(RomanNumeral a, RomanNumeral b)
{
	RomanNumeral result;
	if (a.decimal == 0)
	{
		a.toDecimal();
	}
	if (b.decimal == 0)
	{
		b.toDecimal();
	}
	result.decimal = a.decimal/b.decimal;
	return result;
}

//Overloading the equal check operator
bool operator ==(RomanNumeral& a, RomanNumeral& b)
{
	return (a.decimal == b.decimal);
}

//Overloading the not equal check operator
bool operator !=(RomanNumeral& a, RomanNumeral& b)
{
	return (a.decimal != b.decimal);
}

//Overloading the output stream operator
ostream& operator <<(ostream& out,  RomanNumeral& r)
{
	if(r.decimal == 0)
	{
		r.toDecimal();
	}
	if(r.roman == "")
	{
		r.toRoman();
	}
	out << "[" << r.decimal << ":" << r.roman << "]";
	return out;
}

//Overloading the input stream operator
istream& operator >>(istream& ins, RomanNumeral& r)
{
	string op;
	ins >> op;
	r.roman = op;
	r.toDecimal();
	return ins;
}

