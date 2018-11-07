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
	ASSERT_NO_THROW(StandartComplex c(1.5,2););
	ASSERT_NO_THROW(StandartComplex c(1.5,2););
	StandartComplex c1(0.0003, 1.5);
	StandartComplex c2(c1);
	ASSERT_DOUBLE_EQ(c1.Re, c2.Re);
	ASSERT_DOUBLE_EQ(c1.Im, c2.Im);
	StandartComplex c3 (std::move(c1));
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
	ASSERT_TRUE(isEqual(c2.Re, -0.0004+1));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	c2--;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004));
	ASSERT_TRUE(isEqual(c2.Im, -1.5));
	++c2;
	ASSERT_TRUE(isEqual(c2.Re, -0.0004+1));
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
	ASSERT_TRUE(c1+c2 == StandartComplex(0,3));
	ASSERT_TRUE(c2+c2 == StandartComplex(-8,3));
	ASSERT_TRUE(c1-c2 == StandartComplex(8,0));
	ASSERT_TRUE(-c1+c2 == StandartComplex(-8,0));
	ASSERT_TRUE(c1+c2+5 == StandartComplex(5,3));
	ASSERT_TRUE((5+c4)+c3-5 == StandartComplex(0,-3));
	ASSERT_TRUE((5-c3)+c2-(c1+2) == StandartComplex(-9,-1.5));
}

TEST(StandartComplex, All_Operators)
{
	StandartComplex c1(4, 1.5);
	StandartComplex c2(-4, 1.5);
	StandartComplex c3(4, -1.5);
	StandartComplex c4(-4, -1.5);
	ASSERT_TRUE(((5 / (c1*c2)*((c2 / c3)*c4) / (2 * c1)) * 10) + c2 * c3*c3*c3 - 5 + (3 + ((c2*c4)/2) / (c1*c1*c1)) == StandartComplex(-48.376817883, 329.896978795271));
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
	ASSERT_TRUE(pown(c1,5)==StandartComplex(-314.75, 1387.59375));
	ASSERT_TRUE(pown(c1,1)==c1);
	ASSERT_TRUE(pown(c1,0)== StandartComplex(1,0));
	ASSERT_TRUE(pown(c1,6)==(StandartComplex(-314.75, 1387.59375)*c1));
	ASSERT_ANY_THROW(pown(c1, -1));
}