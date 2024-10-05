#include "pch.h"
#include "D:\university\pioivis\sem_3\ppois\Laba_1_pois\Laba_Fraction\Fractions\Fractions.cpp"
#include <stdexcept>
#include <sstream>

// Test for constructor_1
TEST(FractionTest, Constructor1)
{
    Fraction frac(4, 8, true); 
    EXPECT_EQ(frac.GetNumerator(), 1); 
    EXPECT_EQ(frac.GetDenominator(), 2); 
}
// Test for constructor_2 (with an integer)
TEST(FractionTest, Constructor2)
{
    Fraction frac(5); 
    EXPECT_EQ(frac.GetNumerator(), 5);
    EXPECT_EQ(frac.GetDenominator(), 1);
}
// Test for the copy constructor
TEST(FractionTest, Constructor3)
{
    Fraction original(3, 4, true); 
    Fraction copy = original;
    EXPECT_EQ(copy.GetNumerator(), original.GetNumerator());
    EXPECT_EQ(copy.GetDenominator(), original.GetDenominator());
    EXPECT_EQ(copy.GetSign(), original.GetSign());
    EXPECT_EQ(copy.GetInteger(), original.GetInteger());
    EXPECT_NE(&copy, &original);
}
// Test for exception handling
TEST(FractionTest3, InvalidArgument)
{
    EXPECT_THROW(Fraction frac(-1, 2, true), std::invalid_argument);
    EXPECT_THROW(Fraction frac(1, 0, true), std::invalid_argument);
}
//getters are setters for the numerator
TEST(FractionTest, SetGetNumerator)
{
    Fraction fraction(1, 1, true);
    fraction.SetNumerator(5);
    EXPECT_EQ(fraction.GetNumerator(), 5);
    fraction.SetNumerator(-3);
    EXPECT_EQ(fraction.GetNumerator(), -3);
}
//getters and setters for the denominatortor
TEST(FractionTest, SetGetDenominator)
{
    Fraction fraction(1, 1, true);
    fraction.SetDenominator(4);
    EXPECT_EQ(fraction.GetDenominator(), 4);
    fraction.SetDenominator(-2);
    EXPECT_EQ(fraction.GetDenominator(), -2);
}
TEST(FractionTest, SetGetSign)
{
    Fraction fraction(1, 1, true);
    fraction.SetSign(true);
    EXPECT_EQ(fraction.GetSign(), true);
    fraction.SetSign(false);
    EXPECT_EQ(fraction.GetSign(), false);
}
TEST(FractionTest, GetInteger)
{
    Fraction fraction(1, 1, true);
    fraction.SetNumerator(7);
    fraction.SetDenominator(2);
    EXPECT_EQ(fraction.GetInteger(), 3);
    fraction.SetNumerator(-9);
    fraction.SetDenominator(4);
    EXPECT_EQ(fraction.GetInteger(), -2);
} 
TEST(FractionTest, GetDouble)
{
    Fraction fraction(1, 1, true);
    fraction.SetNumerator(3);
    fraction.SetDenominator(4);
    EXPECT_DOUBLE_EQ(fraction.GetDouble(), 0.75); 
    fraction.SetNumerator(-5);
    fraction.SetDenominator(2);
    EXPECT_DOUBLE_EQ(fraction.GetDouble(), -2.5); 
}

TEST(FractionTest, AssignmentOp)
{
    Fraction fraction1(1, 2, true);
    Fraction fraction2(1, 1, true);
    fraction2 = fraction1;
    EXPECT_EQ(fraction2.GetNumerator(), 1);
    EXPECT_EQ(fraction2.GetDenominator(), 2);
    EXPECT_EQ(fraction2.GetSign(), true);
    fraction2 = fraction2;
    EXPECT_EQ(fraction2.GetNumerator(), 1);
    EXPECT_EQ(fraction2.GetDenominator(), 2);
    EXPECT_EQ(fraction2.GetSign(), true);
}
TEST(FractionTest, EqualityOp)
{
    Fraction fraction1(1, 2, true);
    Fraction fraction2(1, 2, true);
    Fraction fraction3(2, 3, false);
    EXPECT_TRUE(fraction1 == fraction2);
    EXPECT_FALSE(fraction1 == fraction3);
}
TEST(FractionTest, InequalityOp)
{
    Fraction fraction1(1, 2, true);
    Fraction fraction2(1, 2, true);
    Fraction fraction3(2, 3, false);
    EXPECT_FALSE(fraction1 != fraction2);
    EXPECT_TRUE(fraction1 != fraction3);
}
TEST(FractionTest, AdditionOp)
{
    Fraction fraction1(1, 2, true); 
    Fraction fraction2(1, 3, true); 
    Fraction result = fraction1 + fraction2; 
    EXPECT_EQ(result.GetNumerator(), 5);
    EXPECT_EQ(result.GetDenominator(), 6);
    EXPECT_EQ(result.GetSign(), true);
}



TEST(FractionTest, AddInteger)
{
    Fraction fraction(1, 2, true);
    Fraction result = fraction + 1; 
    EXPECT_EQ(result.GetNumerator(), 3);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_EQ(result.GetSign(), true);
}
TEST(FractionTest, IntegerAddFraction)
{
    Fraction fraction(1, 2, true);
    Fraction result = 1 + fraction;
    EXPECT_EQ(result.GetNumerator(), 3);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_EQ(result.GetSign(), true);
}
TEST(FractionTest, AddAssignmentOp)
{
    Fraction fraction(1, 2, true);
    Fraction fractionToAdd(1, 3, true); 
    fraction += fractionToAdd;
    EXPECT_EQ(fraction.GetNumerator(), 5);
    EXPECT_EQ(fraction.GetDenominator(), 6);
    EXPECT_EQ(fraction.GetSign(), true);
}
TEST(FractionTest, AddAssignmentWithInteger)
{
    Fraction fraction(1, 2, true);
    fraction += 1;
    EXPECT_EQ(fraction.GetNumerator(), 3);
    EXPECT_EQ(fraction.GetDenominator(), 2);
    EXPECT_EQ(fraction.GetSign(), true);
}
TEST(FractionTest, SubtractionOp)
{
    Fraction fraction1(3, 4, true); 
    Fraction fraction2(1, 2, true); 
    Fraction result = fraction1 - fraction2;
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 4);
    EXPECT_EQ(result.GetSign(), true);
}
TEST(FractionTest, SubtractionInteger)
{
    Fraction fraction(3, 4, true);
    Fraction result = fraction - 1; 
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 4);
    EXPECT_EQ(result.GetSign(), false);
}
TEST(FractionTest, IntegerSubtractinFraction) 
{
    Fraction fraction(1, 2, true);
    Fraction result = 1 - fraction; 
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_EQ(result.GetSign(), true);
}

TEST(FractionTest, SubtractionAssignmentOp)
{
    Fraction fraction(3, 4, true); 
    Fraction fractionToSubtract(1, 2, true); 
    fraction -= fractionToSubtract; 
    EXPECT_EQ(fraction.GetNumerator(), 1);
    EXPECT_EQ(fraction.GetDenominator(), 4);
    EXPECT_EQ(fraction.GetSign(), true);
}

TEST(FractionTest, SubtractionAssignmentInteger)
{
    Fraction fraction(3, 4, true); 
    fraction -= 1; 
    EXPECT_EQ(fraction.GetNumerator(), 1);
    EXPECT_EQ(fraction.GetDenominator(), 4);
    EXPECT_EQ(fraction.GetSign(), false);
}

TEST(FractionTest, MultiOp) 
{
    Fraction fraction1(2, 3, true); 
    Fraction fraction2(3, 4, true); 
    Fraction result = fraction1 * fraction2; 
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_EQ(result.GetSign(), true);
}

TEST(FractionTest, MultiInteger) 
{
    Fraction fraction(2, 3, true);
    Fraction result = fraction * 3; 
    EXPECT_EQ(result.GetNumerator(), 2);
    EXPECT_EQ(result.GetDenominator(), 1);
    EXPECT_EQ(result.GetSign(), true);
}

TEST(FractionTest, IntMultiFraction) 
{
    Fraction fraction(3, 4, true); 
    Fraction result = 2 * fraction; 
    EXPECT_EQ(result.GetNumerator(), 3);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_EQ(result.GetSign(), true);
}

TEST(FractionTest, MultiAssignmentOp)
{
    Fraction fraction(2, 3, true); 
    Fraction fractionToMultiply(3, 4, true); 
    fraction *= fractionToMultiply; 
    EXPECT_EQ(fraction.GetNumerator(), 1);
    EXPECT_EQ(fraction.GetDenominator(), 2);
    EXPECT_EQ(fraction.GetSign(), true);
}

TEST(FractionTest, MultiAssignmentInt) 
{
    Fraction fraction(2, 3, true); 
    fraction *= 3; 
    EXPECT_EQ(fraction.GetNumerator(), 2);
    EXPECT_EQ(fraction.GetDenominator(), 1);
    EXPECT_EQ(fraction.GetSign(), true);
}

// Tests for operator overloading /
TEST(FractionTest, DivisionFractions) 
{
    Fraction fraction1(1, 2, true);
    Fraction fraction2(1, 3, true); 
    Fraction result = fraction1 / fraction2;
    EXPECT_EQ(result.GetNumerator(), 3);
    EXPECT_EQ(result.GetDenominator(), 2);
    EXPECT_TRUE(result.GetSign());
}
TEST(FractionTest, DivisionInt) 
{
    Fraction fraction(1, 2, true); 
    Fraction result = fraction / 2; 
    EXPECT_EQ(result.GetNumerator(), 1);
    EXPECT_EQ(result.GetDenominator(), 4);
    EXPECT_TRUE(result.GetSign());
}
TEST(FractionTest, IntDivisionFraction) 
{
    Fraction fraction(1, 2, true); 
    Fraction result = 2 / fraction;
    EXPECT_EQ(result.GetNumerator(), 4);
    EXPECT_EQ(result.GetDenominator(), 1);
    EXPECT_TRUE(result.GetSign());
}

TEST(FractionTest, DivisionAssignmentFraction) 
{
    Fraction fraction1(1, 2, true); 
    Fraction fraction2(1, 3, true); 
    fraction1 /= fraction2; 
    EXPECT_EQ(fraction1.GetNumerator(), 3);
    EXPECT_EQ(fraction1.GetDenominator(), 2);
    EXPECT_TRUE(fraction1.GetSign());
}
TEST(FractionTest, DivisionAssignmentInt) 
{
    Fraction fraction(1, 2, true); 
    fraction /= 2; 
    EXPECT_EQ(fraction.GetNumerator(), 1);
    EXPECT_EQ(fraction.GetDenominator(), 4);
    EXPECT_TRUE(fraction.GetSign());
}
TEST(FractionTest, LessThanFraction) 
{
    Fraction f1(1, 4, true); 
    Fraction f2(1, 2, true); 
    EXPECT_TRUE(f1 < f2);
    EXPECT_FALSE(f2 < f1);
}
TEST(FractionTest, GreaterEqualFraction) 
{
    Fraction f1(1, 2, true);  
    Fraction f2(1, 2, true);  
    EXPECT_TRUE(f1 >= f2);
    EXPECT_TRUE(f2 >= f1);
}
TEST(FractionTest, LessEqualFraction) 
{
    Fraction f1(1, 2, true);  
    Fraction f2(3, 4, true);  
    EXPECT_TRUE(f1 <= f2);
    EXPECT_FALSE(f2 <= f1);
}
TEST(FractionComparisonTest, GreaterInt)
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(frac1 > 1);
    EXPECT_FALSE(frac1 > 2);
}
TEST(FractionComparisonTest, LessInt) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(frac1 < 2);
    EXPECT_FALSE(frac1 < 1);
}
TEST(FractionComparisonTest, GreaterEqualInt) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(frac1 >= 1);
    EXPECT_FALSE(frac1 >= 2);
}
TEST(FractionComparisonTest, LessEqualInt) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(frac1 <= 2);
    EXPECT_FALSE(frac1 <= 1);
}
TEST(FractionComparisonTest, IntGreaterFraction) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(2 > frac1);
    EXPECT_FALSE(1 > frac1);
}
TEST(FractionComparisonTest, IntLessFraction) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(1 < frac1);
    EXPECT_FALSE(2 < frac1);
}
TEST(FractionComparisonTest, IntGreaterEqualFraction) 
{
    Fraction frac1(3, 2, true); 
    EXPECT_TRUE(2 >= frac1);
    EXPECT_FALSE(1 >= frac1);
}
TEST(FractionComparisonTest, IntLessEqualFraction) 
{
    Fraction frac1(3, 2, true);
    EXPECT_TRUE(1 <= frac1);
    EXPECT_FALSE(2 <= frac1);
}

TEST(FractionTest, PostfixIncrement)
{
    Fraction f1(1, 2, true);
    Fraction original = f1;
    Fraction result = f1++;
    EXPECT_EQ(result, original);
    EXPECT_EQ(f1, Fraction(3, 2, true)); 
}
TEST(FractionTest, PostfixDecrement)
{
    Fraction f1(1, 2, true);
    Fraction original = f1;
    Fraction result = f1--;
    EXPECT_EQ(result, original); 
    EXPECT_EQ(f1, Fraction(1, 2, false)); 
}
TEST(FractionTest, PrefixIncrement) 
{
    Fraction f1(1, 2, true);
    Fraction result = ++f1;
    EXPECT_EQ(result, Fraction(3, 2, true));
}
TEST(FractionTest, PrefixDecrement) 
{
    Fraction f1(1, 2, true);
    Fraction result = --f1;
    EXPECT_EQ(result, Fraction(1, 2, false)); 
}

// Test for the show method
TEST(FractionShowTest, ShowFunk) 
{
    Fraction f(3, 4, true);
    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf()); 
    f.show();
    cout.rdbuf(oldCout);
    string expected_output = "3/4\n"; 
    EXPECT_EQ(buffer.str(), expected_output); 
}
TEST(FractionShowTest, ShowFunk1) 
{
    Fraction f(3, 4, false); 
    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf()); 
    f.show(); 
    cout.rdbuf(oldCout); 
    string expected_output = "-3/4\n";
    EXPECT_EQ(buffer.str(), expected_output); 
}

