#pragma once
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#define COMPLEX_EPS 0.000000001
class PolarComplex;
class StandartComplex {
public:

	// Data //

	double Re, Im;

	// Конструкторы //

	StandartComplex();
	StandartComplex(double);
	StandartComplex(double, double);
	StandartComplex(const StandartComplex&) = default;  //К. копирования
	StandartComplex(const PolarComplex&);               //К. преобразования
	StandartComplex(const StandartComplex&&);           //К. перемещения

	// Унарные операторы //

	StandartComplex operator-();
	StandartComplex operator+();

	// ++ -- //

	StandartComplex operator--();
	StandartComplex operator++();
	StandartComplex& operator--(int);
	StandartComplex& operator++(int);


	// Операторы сравнения //

	bool operator==(const StandartComplex&);
	bool operator!=(const StandartComplex&);

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


class PolarComplex {
public:

	// Data //

	double ro, fi;

	// Конструкторы //

	PolarComplex();
	PolarComplex(double);
	PolarComplex(double, double);
	PolarComplex(const PolarComplex&) = default;  //К. копирования
	PolarComplex(const PolarComplex&&);           //К. перемещения
	PolarComplex(const StandartComplex&);         //K. преобразования 

	// Унарные операторы //

	PolarComplex operator-();
	PolarComplex operator+();

	// ++ -- //

	PolarComplex operator--();
	PolarComplex operator++();
	PolarComplex& operator--(int);
	PolarComplex& operator++(int);


	// Операторы сравнения //

	bool operator==(const PolarComplex&);
	bool operator!=(const PolarComplex&);

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
