#include "stdafx.h"
#include "ComplexNum.h"

StandartComplex::StandartComplex() : Re(0), Im(0) {}

StandartComplex::StandartComplex(double re) : Re(re), Im(0) {}

StandartComplex::StandartComplex(double re, double im) : Re(re), Im(im) {}

StandartComplex::~StandartComplex() {}

StandartComplex::StandartComplex(const StandartComplex&& in)
{
	Re = in.Re;
	Im = in.Im;
}

StandartComplex StandartComplex::operator-()
{
	return StandartComplex(-Re, -Im);
}

StandartComplex StandartComplex::operator+()
{	
	return *this;
}

StandartComplex StandartComplex::operator--()
{
	Re--;
	Im--;
	return *this;
}

StandartComplex StandartComplex::operator++()
{
	Re++;
	Im++;
	return *this;
}

StandartComplex& StandartComplex::operator--(int)
{
	Re--;
	Im--;
	return *this;
}

StandartComplex& StandartComplex::operator++(int)
{
	Re++;
	Im++;
	return *this;
}

bool operator==(const StandartComplex& left_in, const StandartComplex& right_in)
{
	return ((abs(left_in.Re - right_in.Re) < COMPLEX_EPS) && (abs(left_in.Im - right_in.Im) < COMPLEX_EPS));
}

bool operator!=(const StandartComplex& left_in, const StandartComplex& right_in)
{
	return !(left_in == right_in);
}
// + //
StandartComplex StandartComplex::operator+(const StandartComplex& in)
{
	return StandartComplex(Re + in.Re, Im + in.Im);
}

StandartComplex StandartComplex::operator+(const double& right_in)
{
	return StandartComplex(Re + right_in, Im);
}

StandartComplex operator+(const double& left_in, const StandartComplex& right_in)
{
	return StandartComplex(left_in + right_in.Re, right_in.Im);
}
// - //
StandartComplex StandartComplex::operator-(const StandartComplex& in)
{
	return StandartComplex(Re - in.Re, Im - in.Im);
}

StandartComplex StandartComplex::operator-(const double& right_in)
{
	return StandartComplex(Re - right_in, Im);
}

StandartComplex operator-(const double& left_in, const StandartComplex& right_in)
{
	return StandartComplex(left_in - right_in.Re, right_in.Im);
}
// * //
StandartComplex StandartComplex::operator*(const StandartComplex& in)
{
	return StandartComplex((this->Re * in.Re - Im * in.Im), (this->Re * in.Im + Im * in.Re));
}

StandartComplex StandartComplex::operator*(const double& right_in)
{
	return StandartComplex(Re * right_in, Im * right_in);
}

StandartComplex operator*(const double& left_in, const StandartComplex& right_in)
{
	return StandartComplex(left_in * right_in.Re, left_in * right_in.Im);
}
// / //
StandartComplex StandartComplex::operator/(const StandartComplex& in)
{
	double cd = in.Im*in.Im + in.Re*in.Re;
	return StandartComplex((this->Re * in.Re + Im * in.Im) / cd, (-this->Re * in.Im + Im * in.Re) / cd);
}

StandartComplex StandartComplex::operator/(const double& right_in)
{
	return StandartComplex(Re / right_in, Im / right_in);
}

StandartComplex operator/(const double& left_in, const StandartComplex& right_in)
{
	return StandartComplex(StandartComplex(left_in) / right_in);
}

// = //

StandartComplex& StandartComplex::operator+=(const StandartComplex& in)
{
	Re += in.Re;
	Im += in.Im;
	return *this;
}

StandartComplex& StandartComplex::operator-=(const StandartComplex& in)
{
	Re -= in.Re;
	Im -= in.Im;
	return *this;
}

StandartComplex& StandartComplex::operator=(const StandartComplex&& in)
{
	Re = in.Re;
	Im = in.Im;
	return *this;
}



// Потоки //

std::ostream& operator<<(std::ostream& cout, StandartComplex& in) {
	cout << in.Re << ",i*" << in.Im;
	return cout;
}

std::istream& operator>>(std::istream& cin, StandartComplex& out) {
	cin >> out.Re >> out.Re;
	return cin;
}

double abs(const StandartComplex& in)
{
	return sqrt(in.Re*in.Re + in.Im * in.Im);
}

double arg(const StandartComplex& in)
{
	return atan2l(in.Im, in.Re);
}

StandartComplex pown(const StandartComplex & x, int n)
{
	if (n < 0)
	{
		throw "Only natural numbers in pown";
	}
	if (n == 0)
	{
		return StandartComplex(1, 0);
	}
	return StandartComplex(powl(abs(x), n)*cos(arg(x)*n), powl(abs(x), n)*sin(arg(x)*n));
}
