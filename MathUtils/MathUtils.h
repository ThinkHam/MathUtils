#pragma once

#include <stdexcept>
#include <cmath>

namespace MathUtils {
	// Simplification
	int GCD(int num1, int num2)
	{
		if (num2 == 0)
		{
			return num1;
		}
		else
		{
			int mod_result = (num1 % num2);
			return MathUtils::GCD(num2, mod_result);
		}
	};
}

class Fraction
{

private:
	int _numerator;
	int _denominator;

public:

	Fraction(int numerator, int denominator)
	{
		try
		{
			setNumerator(numerator);
			setDenominator(denominator);
			simplify();
		}
		catch (const std::invalid_argument)
		{
			throw;
		};
	};

	// Getters / Setters
	void setNumerator(int numerator)
	{
		_numerator = numerator;
	};
	void setDenominator(int denominator)
	{
		if (denominator == (double)0)
		{
			throw std::invalid_argument("Cannot divide by zero");
		};
		_denominator = denominator;
	};
	int getNumerator() { return _numerator; };;
	int getDenominator() { return _denominator; };;

	//Misc
	void simplify()
	{
		int gcd = MathUtils::GCD(getNumerator(), getDenominator());
		setNumerator(getNumerator() / gcd);
		setDenominator(getDenominator() / gcd);
	};

};
//Overloading
Fraction operator+(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.getNumerator() + f2.getNumerator(), f1.getDenominator() + f2.getDenominator());
}
Fraction operator-(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.getNumerator() - f2.getNumerator(), f1.getDenominator() - f2.getDenominator());
}
Fraction operator*(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.getNumerator() * f2.getNumerator(), f1.getDenominator() * f2.getDenominator());
}
Fraction operator/(Fraction& f1, Fraction& f2)
{
	return Fraction(f1.getNumerator() * f2.getDenominator(), f2.getDenominator() * f1.getNumerator());
}