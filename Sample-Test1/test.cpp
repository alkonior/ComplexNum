#include "pch.h"
#include "../StaticLib1/ComplexNum.h"

bool isEqual(double x, double y)
{
	return (abs(x - y) < COMPLEX_EPS);
}

TEST(StandartComplex, Creation)
{
	ASSERT_NO_THROW(StandartComplex c;);
	ASSERT_NO_THROW(StandartComplex c(1););
	ASSERT_NO_THROW(StandartComplex c(1.6););
	ASSERT_NO_THROW(StandartComplex c(1.5, 2););
	ASSERT_NO_THROW(StandartComplex c(1.5, 2););
	StandartComplex c1(0.0003, 1.5);
	StandartComplex c2(c1);
	ASSERT_DOUBLE_EQ(c1.Re, c2.Re);
	ASSERT_DOUBLE_EQ(c1.Im, c2.Im);
	StandartComplex c3(std::move(c1));
	ASSERT_DOUBLE_EQ(c1.Re, c2.Re);
	ASSERT_DOUBLE_EQ(c1.Im, c2.Im);
}

TEST(StandartComplex, Unary_Operators)
{
	StandartComplex c(0.0004, 1.5);
	StandartComplex c1(+c);
	ASSERT_TRUE(c1 == c);
	StandartComplex c2(-c);
	ASSERT_TRUE(c2 != c);
	ASSERT_TRUE(isEqual(c2.Re, -0.0004));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	c2++;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004 + 1));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	c2--;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	++c2;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004 + 1));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	--c2;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
}

TEST(StandartComplex, Summ_Diff_Operators)
{
	StandartComplex c1(4, 1.5);
	StandartComplex c2(-4, 1.5);
	StandartComplex c3(4, -1.5);
	StandartComplex c4(-4, -1.5);
	ASSERT_TRUE(c1 + c2 == StandartComplex(0, 3));
	ASSERT_TRUE(c2 + c2 == StandartComplex(-8, 3));
	ASSERT_TRUE(c1 - c2 == StandartComplex(8, 0));
	ASSERT_TRUE(-c1 + c2 == StandartComplex(-8, 0));
	ASSERT_TRUE(c1 + c2 + 5 == StandartComplex(5, 3));
	ASSERT_TRUE((5 + c4) + c3 - 5 == StandartComplex(0, -3));
	ASSERT_TRUE((5 - c3) + c2 - (c1 + 2) == StandartComplex(-9, -1.5));
}

TEST(StandartComplex, All_Operators)
{
	StandartComplex c1(4, 1.5);
	StandartComplex c2(-4, 1.5);
	StandartComplex c3(4, -1.5);
	StandartComplex c4(-4, -1.5);
	ASSERT_TRUE(((5 / (c1*c2)*((c2 / c3)*c4) / (2 * c1)) * 10) + c2 * c3*c3*c3 - 5 + (3 + ((c2*c4) / 2) / (c1*c1*c1)) == StandartComplex(-48.376817883, 329.896978795271));
}


TEST(StandartComplex, Equallyties)
{
	StandartComplex c1(4, 1.5);
	StandartComplex c2(-4, 1.5);
	StandartComplex c3(4, -1.5);
	StandartComplex c4(-4, -1.5);
	c2 += c1;
	ASSERT_TRUE(c2 == StandartComplex(0, 3));
	c3 -= c4;
	ASSERT_TRUE(c3 == StandartComplex(8, 0));
	c3 = c2;
	ASSERT_TRUE(c3 == c2);
	c3 = std::move(c2);
	ASSERT_TRUE(c3 == c2);
}

TEST(StandartComplex, arg_abs_pown)
{
	StandartComplex c1(4, 1.5);
	StandartComplex c2(-4, 1.5);
	ASSERT_TRUE(isEqual(abs(c1), 4.2720018726588));
	ASSERT_TRUE(isEqual(arg(c1), 0.35877067027057));
	ASSERT_TRUE(isEqual(abs(c2), 4.2720018726588));
	ASSERT_TRUE(isEqual(arg(c2), 2.7828219833192));
	ASSERT_TRUE(pown(c1, 5) == StandartComplex(-314.75, 1387.59375));
	ASSERT_TRUE(pown(c1, 1) == c1);
	ASSERT_TRUE(pown(c1, 0) == StandartComplex(1, 0));
	ASSERT_TRUE(pown(c1, 6) == (StandartComplex(-314.75, 1387.59375)*c1));
	ASSERT_ANY_THROW(pown(c1, -1));
}

TEST(PolarComplex, Constructors_Geters_Seters)
{
	ASSERT_NO_THROW(PolarComplex c;);
	ASSERT_NO_THROW(PolarComplex c(1););
	ASSERT_NO_THROW(PolarComplex c(1.6););
	ASSERT_NO_THROW(PolarComplex c(1.5, 2););
	ASSERT_NO_THROW(PolarComplex c(1.5, 2););
	ASSERT_NO_THROW(PolarComplex c(1.5, 20););
	ASSERT_NO_THROW(PolarComplex c(1.5, -20););
	ASSERT_NO_THROW(PolarComplex c(-1.5, 20););
	ASSERT_NO_THROW(PolarComplex c(-1.5, -20););
	{
		PolarComplex c1(1.5, 1);
		PolarComplex c2(1.5, -1);
		PolarComplex c3(-1.5, -1);
		PolarComplex c4(-1.5, 1);
		ASSERT_DOUBLE_EQ(c1.getFi(), 1);
		ASSERT_DOUBLE_EQ(c2.getFi(), -1 + 2*M_PI);
		ASSERT_DOUBLE_EQ(c3.getFi(), -1 + M_PI);
		ASSERT_DOUBLE_EQ(c4.getFi(), 1 + M_PI );
	}
	{
		PolarComplex c1(1.5, 3.5);
		PolarComplex c2(1.5, -3.5);
		PolarComplex c3(-1.5, -3.5);
		PolarComplex c4(-1.5, 3.5);
		ASSERT_DOUBLE_EQ(c1.getFi(), 3.5);
		ASSERT_DOUBLE_EQ(c2.getFi(), -3.5 + 2*M_PI);
		ASSERT_DOUBLE_EQ(c3.getFi(), -3.5 + 3*M_PI);
		ASSERT_DOUBLE_EQ(c4.getFi(), 3.5 - M_PI);
	}
	{
		PolarComplex c1(1.5, 7);
		PolarComplex c2(1.5, -7);
		PolarComplex c3(-1.5, -7);
		PolarComplex c4(-1.5, 7);
		ASSERT_DOUBLE_EQ(c1.getFi(), 7- 2*M_PI);
		ASSERT_DOUBLE_EQ(c2.getFi(), -7 + 4*M_PI);
		ASSERT_DOUBLE_EQ(c3.getFi(), -7 + 3*M_PI);
		ASSERT_DOUBLE_EQ(c4.getFi(), 7 -  M_PI);
	}
	{
		PolarComplex c1(1.5, 10);
		PolarComplex c2(1.5, -10);
		PolarComplex c3(-1.5, -10);
		PolarComplex c4(-1.5, 10);
		ASSERT_DOUBLE_EQ(c1.getFi(), 10 - 2 * M_PI);
		ASSERT_DOUBLE_EQ(c2.getFi(), -10 + 4 * M_PI);
		ASSERT_DOUBLE_EQ(c3.getFi(), -10 + 5 * M_PI);
		ASSERT_DOUBLE_EQ(c4.getFi(), 10 - 3 * M_PI);
	}
	PolarComplex c1(1.5, 10);
	PolarComplex c2(1.5, -10);
	PolarComplex c3(-1.5, -10);
	PolarComplex c4(-1.5, 10);
	ASSERT_NO_THROW(StandartComplex c(c1););
	ASSERT_NO_THROW(StandartComplex c(std::move(c1)););
	ASSERT_NO_THROW(StandartComplex c(c2););
	ASSERT_NO_THROW(StandartComplex c(c3););
	ASSERT_NO_THROW(StandartComplex c(c4););
	StandartComplex cc1(c1);
	StandartComplex cc2(c2);
	StandartComplex cc3(c3);
	StandartComplex cc4(c4);
	PolarComplex _c1(cc1);
	PolarComplex _c2(cc2);
	PolarComplex _c3(cc3);
	PolarComplex _c4(cc4);
	PolarComplex _c5(std::move(_c4));
	ASSERT_DOUBLE_EQ(_c1.getFi(), 10 - 2 * M_PI);
	ASSERT_DOUBLE_EQ(_c2.getFi(), -10 + 4 * M_PI);
	ASSERT_DOUBLE_EQ(_c3.getFi(), -10 + 5 * M_PI);
	ASSERT_DOUBLE_EQ(_c4.getFi(), 10 - 3 * M_PI);
	
}

TEST(PolarComplex, All_Operators)
{
	StandartComplex _c1(4, 1.5);
	StandartComplex _c2(-4, 1.5);
	StandartComplex _c3(4, -1.5);
	StandartComplex _c4(-4, -1.5);
	PolarComplex c1(_c1);
	PolarComplex c2(_c2);
	PolarComplex c3(_c3);
	PolarComplex c4(_c4);
	PolarComplex c5;
	ASSERT_TRUE(((5 / (c1*c2)*(((+(c2-c5)) / (--(++((c3++)--))))*c4) / (2 * (5+c1+c5+(-5)))) * 10) 
		+ c2 * c3*c3*c3 - 
		5 + (3 + ((c2*c4) / 2) / (c1*c1*c1)) == PolarComplex(StandartComplex(-48.376817883, 329.896978795271)));
	ASSERT_TRUE(c3 != PolarComplex(_c3));
}