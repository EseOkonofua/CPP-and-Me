#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

//Header guard 
#ifndef fraction_13eio_H
#define fraction_13eio_H


//return_type operator,operator_symbol(parameters);  .....
//Fraction class
class Fraction {
	int nmrtr; //numerator value
	int dnmntr; // denominator value 
	int GCD(const int& numerator,const int& denominator) const; //Helper function to find the greatest common denominator of 2 values
public:
	Fraction(); //Default constructor 
	Fraction(const int& numerator); // 1 Parameter constructor...Whole Number
	Fraction(const int& numerator,const int& denominator); //Numerator/Denominator constructor 
	int numerator() const; //getter 
	int denominator() const; //getter 
	

	//Unary negation
	Fraction operator-(const Fraction& fraction);

//Binary operators 
	friend Fraction operator+(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction operator-(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction operator*(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction operator/(const Fraction& lFraction, const Fraction& rFraction);

	//Pre Increment
	Fraction& operator++();
	//Post Increment
	Fraction operator++(int unused);

	//+= operator
	Fraction& operator+=(const Fraction& rFraction);

	//comparison operators
	friend bool operator==(const Fraction& lFraction, const Fraction& rFraction);
	friend bool operator!=(const Fraction& lFraction, const Fraction& rFraction);
	friend bool operator>(const Fraction& lFraction, const Fraction& rFraction);
	friend bool operator<(const Fraction& lFraction, const Fraction& rFraction);
	friend bool operator>=(const Fraction& lFraction, const Fraction& rFraction);
	friend bool operator<=(const Fraction& lFraction, const Fraction& rFraction);

	//cout 
	friend ostream& operator<<(ostream& out, const Fraction& fraction);
	//cin
	friend ostream& operator>>(ostream& in, const Fraction& fraction);
};








#endif