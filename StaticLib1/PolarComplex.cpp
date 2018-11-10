#include "stdafx.h"
#include "ComplexNum.h"

PolarComplex::PolarComplex() : r(0), fi(0) {}

PolarComplex::PolarComplex(double ro) : r(0), fi(0) 
{
	setR(ro);
}

PolarComplex::PolarComplex(double ro, double fi) : r(0), fi(0) 
{
	setFi(fi);
	setR(ro);
}

PolarComplex::PolarComplex(const PolarComplex&& in)
{
	r = in.r;
	fi = in.fi;
}

PolarComplex::PolarComplex(const StandartComplex& in) : r(abs(in)), fi(arg(in)) { setFi(fi); }

PolarComplex::~PolarComplex() {}

void PolarComplex::setR(double in) 
{ 
	if (in < 0)
	{
		setFi(fi + M_PI);
	}
	r = abs(in);
}

double PolarComplex::getR() const { return r; }

void PolarComplex::setFi(double in) 
{
	if ((in) >= M_PI * 2 || (in) < 0)
	{
		int k = floor(((in) /(2 * M_PI)));
		double k2 = (in) /(2 * M_PI);
		fi = in - (floor(((in) / (2*M_PI))))*2*M_PI;
	}
	else {
		fi = (in);
	}
}

double PolarComplex::getFi() const { return fi; }

PolarComplex PolarComplex::operator-()
{
	return PolarComplex(r, (fi + M_PI));
}

PolarComplex PolarComplex::operator+()
{
	return *this;
}

PolarComplex PolarComplex::operator--()
{
	setR(r - 1);
	return *this;
}

PolarComplex PolarComplex::operator++()
{
	r++;
	return *this;
}

PolarComplex& PolarComplex::operator--(int)
{
	setR(r - 1);
	return *this;
}

PolarComplex& PolarComplex::operator++(int)
{
	r++;
	return *this;
}

bool PolarComplex::operator==(const PolarComplex& in)
{
	return ((abs(r - in.r) < COMPLEX_EPS) && (abs(fi - in.fi) < COMPLEX_EPS));
}

bool PolarComplex::operator!=(const PolarComplex& right_in)
{
	return !(*this == right_in);
}

// + //

PolarComplex PolarComplex::operator+(const PolarComplex& in)
{
	
	double z = sqrt((r * r) + (in.r * in.r) - 2 * r * in.r * cos(fi + M_PI - in.fi));
	return PolarComplex(z, fi - asin(sin(in.fi - M_PI - fi) * in.r / (z)));
	
	//return(PolarComplex(StandartComplex(*this) + StandartComplex(in)));
}

PolarComplex PolarComplex::operator+(const double& in)
{
	return(*this + PolarComplex(in));
}

PolarComplex operator+(const double& left_in, const PolarComplex& right_in)
{
	return(PolarComplex(right_in) + PolarComplex(left_in));
}

// - //

PolarComplex PolarComplex::operator-(const PolarComplex& in)
{
	return *this + (-PolarComplex(in));
}

PolarComplex PolarComplex::operator-(const double& in)
{
	return *this + (-PolarComplex(in));
}

PolarComplex operator-(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(left_in) + (-PolarComplex(right_in));
}

// * //

PolarComplex PolarComplex::operator*(const PolarComplex& in)
{
	return(PolarComplex(this->r*in.r, this->fi+in.fi));
}

PolarComplex PolarComplex::operator*(const double& in)
{
	return *this*PolarComplex(in);
}

PolarComplex operator*(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(right_in)*PolarComplex(left_in);
}

// / //

PolarComplex PolarComplex::operator/(const PolarComplex& in)
{
	return(PolarComplex(this->r/in.r, this->fi - in.fi));
}

PolarComplex PolarComplex::operator/(const double& in)
{
	return *this/PolarComplex(in);
}

PolarComplex operator/(const double& left_in, const PolarComplex& right_in)
{
	return PolarComplex(PolarComplex(left_in) / right_in);
}

// = //

PolarComplex& PolarComplex::operator+=(const PolarComplex& in)
{
	PolarComplex res = *this + in;
	*this = res;
	return *this;
}

PolarComplex& PolarComplex::operator-=(const PolarComplex& in)
{
	PolarComplex res = *this - in;
	*this = res;
	return *this;
}

PolarComplex& PolarComplex::operator=(const PolarComplex&& in)
{
	r = in.r;
	r = in.r;
	return *this;
}

// Потоки //

std::ostream& operator<<(std::ostream& cout, PolarComplex& in) {
	cout << in.r << "*(cos(" << in.fi<<")+isin("<<in.fi<<"))";
	return cout;
}

std::istream& operator>>(std::istream& cin, PolarComplex& out) {
	double _r, _fi;
	cin >> _r >> _fi;
	PolarComplex res(_r, _fi);
	out = res;
	return cin;
}

// Особые функции //

PolarComplex pown(const PolarComplex & x, int n)
{
	if (n < 0)
	{
		throw "Only natural numbers in pown";
	}
	if (n == 0)
	{
		return PolarComplex(1);
	}
	return PolarComplex(powl(x.r,n),x.fi*n);
}
