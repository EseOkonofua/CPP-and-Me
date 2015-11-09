#pragma once
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <SDKDDKVer.h>

using namespace std;

//Header guard 
#ifndef fraction_13eio_H
#define fraction_13eio_H

#ifdef COMPILE_MYLIBRARY  
	#define MYLIBRARY_EXPORT __declspec(dllexport) 
#else  
	#define MYLIBRARY_EXPORT __declspec(dllimport) 
#endif


	//return_type operator,operator_symbol(parameters);  .....
	//Fraction class
class MYLIBRARY_EXPORT Fraction {
	int nmrtr; //numerator value
	int dnmntr; // denominator value 
	int GCD(const int& numerator, const int& denominator) const; //Helper function to find the greatest common denominator of 2 values used to normalize values;
public:
	Fraction(); //Default constructor 
	Fraction(const int& numerator); // 1 Parameter constructor...Whole Number
	Fraction(const int& numerator, const int& denominator); //Numerator/Denominator constructor 
	int numerator() const; //getter 
	int denominator() const; //getter 

	//Unary negation
	Fraction operator-();

	//Binary operators 
	friend Fraction MYLIBRARY_EXPORT operator+(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction MYLIBRARY_EXPORT operator-(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction MYLIBRARY_EXPORT operator*(const Fraction& lFraction, const Fraction& rFraction);
	friend Fraction MYLIBRARY_EXPORT operator/(const Fraction& lFraction, const Fraction& rFraction);

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
	friend istream& operator>>(istream& in, Fraction& fraction);
};

class MYLIBRARY_EXPORT FractionException { //Exception class to catch 0 denominator fractions
	string message;
public:
	FractionException(const string& message);
	string& what();
};

#endif