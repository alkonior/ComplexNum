#include "stdafx.h"
#include "ComplexNum.h"


PolarComplex::PolarComplex() : ro(0), fi(0) {}

PolarComplex::PolarComplex(double ro) : ro(ro), fi(0) {}

PolarComplex::PolarComplex(double ro, double fi) : ro(ro), fi(fi) {}

PolarComplex::PolarComplex(const StandartComplex& in) : ro(abs(in)), fi(arg(in)) {}

PolarComplex::~PolarComplex() {}

PolarComplex::PolarComplex(const PolarComplex&& in)
{
	ro = in.ro;
	fi = in.fi;
}

PolarComplex PolarComplex::operator-()
{
	return PolarComplex(ro, (fi + M_PI));
}

PolarComplex PolarComplex::operator+()
{
	return *this;
}

PolarComplex PolarComplex::operator--()
{
	if (ro-1 >= 0)
		ro--;
	return *this;
}

PolarComplex PolarComplex::operator++()
{
	ro++;
	return *this;
}

PolarComplex& PolarComplex::operator--(int)
{
	if (ro-1 >= 0)
		ro--;
	return *this;
}

PolarComplex& PolarComplex::operator++(int)
{
	ro++;
	return *this;
}

bool PolarComplex::operator==(const PolarComplex& in)
{
	return ((abs(ro - in.ro) < COMPLEX_EPS) && (abs(fi - in.fi) < COMPLEX_EPS));
}

bool PolarComplex::operator!=(const PolarComplex& right_in)
{
	return !(*this == right_in);
}

// + //

PolarComplex PolarComplex::operator+(const PolarComplex& in)
{
	return PolarComplex((ro * ro) + (in.ro * in.ro) - 2 * ro * in.ro * cos(fi + M_PI - in.fi), asin(5));
}

PolarComplex PolarComplex::operator+(const double& right_in)
{
	return PolarComplex(Re + right_in, Im);
}

PolarComplex operator+(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(left_in + right_in.Re, right_in.Im);
}

// - //

PolarComplex PolarComplex::operator-(const PolarComplex& in)
{
	return PolarComplex(Re - in.Re, Im - in.Im);
}

PolarComplex PolarComplex::operator-(const double& right_in)
{
	return PolarComplex(Re - right_in, Im);
}

PolarComplex operator-(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(left_in - right_in.Re, right_in.Im);
}

// * //

PolarComplex PolarComplex::operator*(const PolarComplex& in)
{
	return PolarComplex((this->Re * in.Re - Im * in.Im), (this->Re * in.Im + Im * in.Re));
}

PolarComplex PolarComplex::operator*(const double& right_in)
{
	return PolarComplex(Re * right_in, Im * right_in);
}

PolarComplex operator*(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(left_in * right_in.Re, left_in * right_in.Im);
}

// / //

PolarComplex PolarComplex::operator/(const PolarComplex& in)
{
	double cd = in.Im*in.Im + in.Re*in.Re;
	return PolarComplex((this->Re * in.Re + Im * in.Im) / cd, (-this->Re * in.Im + Im * in.Re) / cd);
}

PolarComplex PolarComplex::operator/(const double& right_in)
{
	return PolarComplex(Re / right_in, Im / right_in);
}

PolarComplex operator/(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(PolarComplex(left_in) / right_in);
}

// = //

PolarComplex& PolarComplex::operator+=(const PolarComplex& in)
{
	Re += in.Re;
	Im += in.Im;
	return *this;
}

PolarComplex& PolarComplex::operator-=(const PolarComplex& in)
{
	Re -= in.Re;
	Im -= in.Im;
	return *this;
}

PolarComplex& PolarComplex::operator=(const PolarComplex&& in)
{
	Re = in.Re;
	Im = in.Im;
	return *this;
}

// Потоки //

std::ostream& operator<<(std::ostream& cout, PolarComplex& in) {
	cout << in.Re << ",i*" << in.Im;
	return cout;
}

std::istream& operator>>(std::istream& cin, PolarComplex& out) {
	cin >> out.Re >> out.Re;
	return cin;
}

// Особые функции //

double abs(const PolarComplex& in)
{
	return sqrt(in.Re*in.Re + in.Im * in.Im);
}

double arg(const PolarComplex& in)
{
	return atan2l(in.Im, in.Re);
}

PolarComplex pown(const PolarComplex & x, int n)
{
	if (n < 0)
	{
		throw "Only natural numbers in pown";
	}
	if (n == 0)
	{
		return PolarComplex(1, 0);
	}
	return PolarComplex(powl(abs(x), n)*cos(arg(x)*n), powl(abs(x), n)*sin(arg(x)*n));
}
