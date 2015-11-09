// FractionClass.cpp : Defines the entry point for the console application.
#include "fraction_13eio.h"
#include <string>
using namespace std;

#define COMPILE_MYLIBRARY

	int Fraction::GCD(const int & numerator, const int & denominator) const
	{
		if ((abs(denominator) <= abs(numerator)) && (numerator % denominator == 0))
			return abs(denominator);
		else if (abs(numerator) < abs(denominator))
			return GCD(abs(denominator), abs(numerator));
		else
			return GCD(abs(denominator), abs(numerator)%abs(denominator));
	}

	Fraction::Fraction() :nmrtr(0), dnmntr(1)
	{
	}

	Fraction::Fraction(const int & numerator) : nmrtr(numerator), dnmntr(1)
	{
	}

	Fraction::Fraction(const int & numerator, const int & denominator)
	{
		
		if (denominator == 0 ) {
			throw FractionException("Illegal denominator!, Value undefined.");
		}
		else if (numerator == 0) {
			nmrtr = 0;
			dnmntr = 1;
		}
		else {
			int gcd = GCD(numerator, denominator);
			if (numerator == gcd) {
				nmrtr = 1;
				dnmntr = denominator / gcd;
				if ((nmrtr < 0) ^ (dnmntr < 0)) {
					if (dnmntr < 0) {
						dnmntr = -dnmntr;
						nmrtr = -nmrtr;
					}
				}
				else if ((nmrtr < 0) && (dnmntr < 0)) {
					nmrtr = -nmrtr;
					dnmntr = -dnmntr;
				}
			}
			else if (denominator == gcd) {
				nmrtr = numerator / gcd;
				dnmntr = 1;
				if ((nmrtr < 0) ^ (dnmntr < 0)) {
					if (dnmntr < 0) {
						dnmntr = -dnmntr;
						nmrtr = -nmrtr;
					}
				}
				else if ((nmrtr < 0) && (dnmntr < 0)) {
					nmrtr = -nmrtr;
					dnmntr = -dnmntr;
				}
			}
			else if (gcd == 1) {
				nmrtr = numerator;
				dnmntr = denominator;
				if ((nmrtr < 0) ^ (dnmntr < 0)) {
					if (dnmntr < 0) {
						dnmntr = -dnmntr;
						nmrtr = -nmrtr;
					}
				}
				else if ((nmrtr < 0) && (dnmntr < 0)) {
					nmrtr = -nmrtr;
					dnmntr = -dnmntr;
				}
			}
			else {
				nmrtr = numerator;
				dnmntr = denominator;
				while ((nmrtr%gcd == 0) && (dnmntr%gcd == 0)) {
					nmrtr = nmrtr / gcd;
					dnmntr = dnmntr / gcd;
				}
				if ((nmrtr < 0) ^ (dnmntr < 0)) {
					if (dnmntr < 0) {
						dnmntr = -dnmntr;
						nmrtr = -nmrtr;
					}
				}
				else if ((nmrtr < 0) && (dnmntr < 0)) {
					nmrtr = -nmrtr;
					dnmntr = -dnmntr;
				}
			}
		}

	}

	int Fraction::numerator() const
	{
		return nmrtr;
	}

	int Fraction::denominator() const
	{
		return dnmntr;
	}

	Fraction Fraction::operator-()
	{
		return Fraction(-nmrtr, dnmntr);
	}

	Fraction & Fraction::operator++()
	{
		nmrtr = nmrtr + dnmntr;
		return *this;
	}

	Fraction Fraction::operator++(int unused)
	{
		Fraction clone(nmrtr, dnmntr);
		nmrtr = nmrtr + dnmntr;
		return clone;
	}

	Fraction & Fraction::operator+=(const Fraction & rFraction)
	{
		Fraction newFraction = Fraction(nmrtr, dnmntr) + rFraction; //Sneaky ;)
		nmrtr = newFraction.nmrtr;
		dnmntr = newFraction.dnmntr;
		return *this;
	}

	Fraction operator+(const Fraction& lFraction, const Fraction& rFraction) {
		if (lFraction.dnmntr == rFraction.dnmntr)
			return Fraction(lFraction.nmrtr + rFraction.nmrtr, rFraction.dnmntr);
		else if (lFraction.dnmntr%rFraction.dnmntr == 0) {
			if (lFraction.dnmntr > rFraction.dnmntr) {
				int divisor = lFraction.dnmntr / rFraction.dnmntr;
				return Fraction(lFraction.nmrtr + rFraction.nmrtr*divisor, lFraction.dnmntr);
			}
			else {
				int divisor = rFraction.dnmntr / lFraction.dnmntr;
				return Fraction(lFraction.nmrtr*divisor + rFraction.nmrtr, rFraction.dnmntr);
			}
		}
		else
			return Fraction(lFraction.nmrtr*rFraction.dnmntr + rFraction.nmrtr*lFraction.dnmntr, lFraction.dnmntr*rFraction.dnmntr);
	}

	Fraction operator-(const Fraction& lFraction, const Fraction& rFraction) {
		if (lFraction.dnmntr == rFraction.dnmntr)
			return Fraction(lFraction.nmrtr - rFraction.nmrtr, rFraction.dnmntr);
		else if (lFraction.dnmntr%rFraction.dnmntr == 0) {
			if (lFraction.dnmntr > rFraction.dnmntr) {
				int divisor = lFraction.dnmntr / rFraction.dnmntr;
				return Fraction(lFraction.nmrtr - rFraction.nmrtr*divisor, lFraction.dnmntr);
			}
			else {
				int divisor = rFraction.dnmntr / lFraction.dnmntr;
				return Fraction(lFraction.nmrtr*divisor - rFraction.nmrtr, rFraction.dnmntr);
			}
		}
		else
			return Fraction(lFraction.nmrtr*rFraction.dnmntr - rFraction.nmrtr*lFraction.dnmntr, lFraction.dnmntr*rFraction.dnmntr);
	}
	Fraction operator*(const Fraction& lFraction, const Fraction& rFraction) {
		return Fraction(lFraction.nmrtr*rFraction.nmrtr, lFraction.dnmntr*rFraction.dnmntr);
	}
	Fraction operator/(const Fraction& lFraction, const Fraction& rFraction) {
		return lFraction*Fraction(rFraction.dnmntr, rFraction.nmrtr);
	}

	bool operator==(const Fraction& lFraction, const Fraction& rFraction) {
		if ((lFraction.nmrtr == rFraction.nmrtr) && (lFraction.dnmntr == rFraction.dnmntr))
			return true;
		else
			return false;
	}

	bool operator!=(const Fraction& lFraction, const Fraction& rFraction) {
		if ((lFraction.nmrtr != rFraction.nmrtr) || (lFraction.dnmntr != rFraction.dnmntr))
			return true;
		else
			return false;
	}

	bool operator>(const Fraction& lFraction, const Fraction& rFraction) {
		if (((float)lFraction.nmrtr / (float)lFraction.dnmntr) > ((float)rFraction.nmrtr / (float)rFraction.dnmntr))
			return true;
		else
			return false;
	}

	bool operator<(const Fraction& lFraction, const Fraction& rFraction) {
		if (((float)lFraction.nmrtr / (float)lFraction.dnmntr) < ((float)rFraction.nmrtr / (float)rFraction.dnmntr))
			return true;
		else
			return false;
	}
	bool operator>=(const Fraction& lFraction, const Fraction& rFraction) {
		if (lFraction > rFraction)
			return true;
		else if (lFraction == rFraction)
			return true;
		else
			return false;
	}

	bool operator<=(const Fraction& lFraction, const Fraction& rFraction) {
		if (lFraction < rFraction)
			return true;
		else if (lFraction == rFraction)
			return true;
		else
			return false;
	}

	ostream& operator<<(ostream& out, const Fraction& fraction) {
		out << fraction.nmrtr << "/" << fraction.dnmntr << endl;
		return out;
	}

	istream& operator>>(istream& in, Fraction& fraction) {
		string input;
		in >> input;
		if (in) {
			size_t found = input.find('/');
			if (found == std::string::npos) {
				try {
					int numerator = atoi(input.c_str());
					fraction.nmrtr = numerator;
					fraction.dnmntr = 1;
				}
				catch (exception& e) {
					throw FractionException("This is not a valid fraction!");
				}
			}
			else {
				string numerator = input.substr(0, found);
				string denominator = input.substr(found + 1);
				try {
					int num = atoi(numerator.c_str());
					int den = atoi(denominator.c_str());
					Fraction newFraction = Fraction(num, den);
					fraction.nmrtr = newFraction.nmrtr;
					fraction.dnmntr = newFraction.dnmntr;
				}
				catch (exception& e) {
					throw FractionException("This is not a valid fraction!");
				}
			}
		}
		return in;
	}

	FractionException::FractionException(const string & message) :message(message)
	{
	}

	string & FractionException::what()
	{
		return message;
	}


