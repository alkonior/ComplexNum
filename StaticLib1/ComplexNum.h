#pragma once
#include <iostream>

#define COMPLEX_EPS 0.000000001

class StandartComplex {
public:

	// Data //

	double Re, Im;

	// Конструкторы //

	StandartComplex();
	StandartComplex(double re);
	StandartComplex(double re, double im);
	StandartComplex(const StandartComplex&) = default;  //К. копирования
	StandartComplex(const StandartComplex&&);  //К. перемещения

	// Унарные операторы //

	StandartComplex operator-();
	StandartComplex operator+();

	// ++ -- //

	StandartComplex operator--();
	StandartComplex operator++();
	StandartComplex& operator--(int);
	StandartComplex& operator++(int);


	// Операторы сравнения //

	friend bool operator==(const StandartComplex&, const StandartComplex&);
	friend bool operator!=(const StandartComplex&, const StandartComplex&);

	// Бинарные операторы //

	//+//

	StandartComplex operator+(const StandartComplex&);
	StandartComplex operator+(const double&);
	friend StandartComplex operator+(const double&, const StandartComplex&);

	//-//

	StandartComplex operator-(const StandartComplex&);
	StandartComplex operator-(const double&);
	friend StandartComplex operator-(const double&, const StandartComplex&);

	//*//

	StandartComplex operator*(const StandartComplex&);
	StandartComplex operator*(const double&);
	friend StandartComplex operator*(const double&, const StandartComplex&);

	// / //

	StandartComplex operator/(const StandartComplex&);
	StandartComplex operator/(const double&);
	friend StandartComplex operator/(const double&, const StandartComplex&);

	// =  //


	StandartComplex& operator+=(const StandartComplex&);
	StandartComplex& operator-=(const StandartComplex&);
	StandartComplex& operator=(const StandartComplex&) = default;
	StandartComplex& operator=(const StandartComplex&&);


	// Потоки //

	friend std::ostream &operator<<(std::ostream&, StandartComplex&);
	friend std::istream &operator>>(std::istream&, StandartComplex&);

	// Функции //

	friend double abs(const StandartComplex&);
	friend double arg(const StandartComplex&);

	friend StandartComplex pown(const StandartComplex &x, int n);

	// Деструктор //

	~StandartComplex();
};

/*
class PolarComplex {
public:

	// Data //

	double Re, Im;

	// Конструкторы //

	PolarComplex();
	PolarComplex(double re);
	PolarComplex(double re, double im);
	PolarComplex(const PolarComplex&) = default;  //К. копирования
	PolarComplex(const PolarComplex&&);  //К. перемещения

	// Унарные операторы //

	PolarComplex operator-();
	PolarComplex operator+();

	// ++ -- //

	PolarComplex operator--();
	PolarComplex operator++();
	PolarComplex& operator--(int);
	PolarComplex& operator++(int);


	// Операторы сравнения //

	friend bool operator==(const PolarComplex&, const PolarComplex&);
	friend bool operator!=(const PolarComplex&, const PolarComplex&);

	// Бинарные операторы //

	//+//

	PolarComplex operator+(const PolarComplex&);
	PolarComplex operator+(const double&);
	friend PolarComplex operator+(const double&, const PolarComplex&);

	//-//

	PolarComplex operator-(const PolarComplex&);
	PolarComplex operator-(const double&);
	friend PolarComplex operator-(const double&, const PolarComplex&);

	// * //

	PolarComplex operator*(const PolarComplex&);
	PolarComplex operator*(const double&);
	friend PolarComplex operator*(const double&, const PolarComplex&);

	// / //

	PolarComplex operator/(const PolarComplex&);
	PolarComplex operator/(const double&);
	friend PolarComplex operator/(const double&, const PolarComplex&);

	// =  //


	PolarComplex& operator+=(const PolarComplex&);
	PolarComplex& operator-=(const PolarComplex&);
	PolarComplex& operator=(const PolarComplex&) = default;
	PolarComplex& operator=(const PolarComplex&&);


	// Потоки //

	friend std::ostream &operator<<(std::ostream&, PolarComplex&);
	friend std::istream &operator>>(std::istream&, PolarComplex&);

	// Функции //

	friend double abs(const PolarComplex&);
	friend double arg(const PolarComplex&);

	friend PolarComplex pown(const PolarComplex &x, int n);

	// Деструктор //

	~PolarComplex();
};
*/