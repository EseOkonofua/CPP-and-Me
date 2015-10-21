// FractionClass.cpp : Defines the entry point for the console application.

#include "stdafx.h" //Visual studio standard Ignore :)
#include "fraction_13eio.h"
#include <string>
using namespace std;



int main() {



	return 0;

}

int Fraction::GCD(const int & numerator, const int & denominator) const
{
	return 0;
}

Fraction::Fraction():nmrtr(0),dnmntr(1)
{
}

Fraction::Fraction(const int & numerator): nmrtr(numerator), dnmntr(1)
{
}

Fraction::Fraction(const int & numerator, const int & denominator): nmrtr(numerator), dnmntr(denominator)
{
}

int Fraction::numerator() const
{
	return nmrtr;
}

int Fraction::denominator() const
{
	return dnmntr;
}
