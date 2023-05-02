//
// Created by david on 4/27/2023.
//
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
using namespace std;
TEST_CASE("Check ctor throws") {
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction((float )0.0));
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_NOTHROW(Fraction(0,2));
    CHECK_NOTHROW(Fraction((float )0.333));
}

TEST_CASE("Check ctor works"){
    Fraction fraction1(1,3);// =1/3
    Fraction fraction2(2,7);// =2/7
    Fraction fraction3((float )0.333);// 333/1000
    Fraction fraction4(3,6);// =1/2
    Fraction fraction5((float )0.25);// =1/4



    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==3);

    CHECK(fraction2.getNumerator()==2);
    CHECK(fraction2.getDenominator()==7);

    CHECK(fraction3.getNumerator()==333);
    CHECK(fraction3.getDenominator()==1000);

    //Checking fraction reduction.
    CHECK(fraction4.getNumerator()==1);
    CHECK(fraction4.getDenominator()==2);

    CHECK(fraction5.getNumerator()==1);
    CHECK(fraction5.getDenominator()==4);


}
TEST_CASE("checking basic Additive and a Multiplicative doesn't throw or throws") {
    Fraction fraction1(1, 2);
    Fraction fraction2(1, 3);
    Fraction fraction3(1, 4);
    CHECK_NOTHROW(fraction1 + fraction2);
    CHECK_NOTHROW(fraction1 + 1.1);
    CHECK_NOTHROW(1.1 + fraction2);

    CHECK_NOTHROW(fraction1 - fraction2);
    CHECK_NOTHROW(fraction1 - 1.1);
    CHECK_NOTHROW(1.1 - fraction2);

    CHECK_NOTHROW(fraction1 * fraction2);
    CHECK_NOTHROW(fraction1 * 1.1);
    CHECK_NOTHROW(1.1 * fraction2);

    CHECK_NOTHROW(fraction1 / fraction2);
    CHECK_NOTHROW(fraction1 / 1.1);
    CHECK_THROWS(fraction1/0.0);
    CHECK_NOTHROW(1.1 / fraction2);
    CHECK_NOTHROW(fraction1++);
    CHECK_NOTHROW(++fraction1);
    CHECK_NOTHROW(fraction1--);
    CHECK_NOTHROW(--fraction1);
    }

TEST_CASE("checking basic Additive and a Multiplicative between fractions  (+,-,*,/) "){
    Fraction fraction1(1,2);
    Fraction fraction2(1,3);
    Fraction fraction3(1,4);

    Fraction fraction4 = fraction1+fraction2;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction2.getNumerator()==1);
    CHECK(fraction2.getDenominator()==3);

    CHECK(fraction4.getNumerator()==5);
    CHECK(fraction4.getDenominator()==6);

    Fraction fraction5 = fraction1-fraction3;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction3.getNumerator()==1);
    CHECK(fraction3.getDenominator()==4);

    CHECK(fraction5.getNumerator()==1);
    CHECK(fraction5.getDenominator()==4);

    Fraction fraction6 = fraction1*fraction3;

    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction3.getNumerator()==1);
    CHECK(fraction3.getDenominator()==4);

    CHECK(fraction6.getNumerator()==1);
    CHECK(fraction6.getDenominator()==8);

    Fraction fraction7 = fraction1/fraction3;

    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction3.getNumerator()==1);
    CHECK(fraction3.getDenominator()==4);

    CHECK(fraction7.getNumerator()==1);
    CHECK(fraction7.getDenominator()==2);
    //fraction7==1/2.
    CHECK(fraction7++==Fraction(1,2));
    CHECK(fraction7==Fraction(3,2));
    CHECK(++fraction7==Fraction(5,2));

    CHECK(fraction7--==Fraction(5,2));
    CHECK(fraction7==Fraction(3,2));
    CHECK(--fraction7==Fraction(1,2));


}
TEST_CASE("checking basic Additive and a Multiplicative between fractions (+,-,*,/) and floats"){
    Fraction fraction1(1,2);
    Fraction fraction2 = fraction1+0.25;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction2.getNumerator()==1);
    CHECK(fraction2.getDenominator()==4);

    Fraction fraction3 = 0.25+fraction1;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction3.getNumerator()==1);
    CHECK(fraction3.getDenominator()==4);


    Fraction fraction4 =fraction1*0.5;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction4.getNumerator()==1);
    CHECK(fraction4.getDenominator()==4);


    Fraction fraction5 = 0.5*fraction1;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction5.getNumerator()==1);
    CHECK(fraction5.getDenominator()==4);

    Fraction fraction6 =0.25/fraction1;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction6.getNumerator()==1);
    CHECK(fraction6.getDenominator()==2);

    Fraction fraction7 =fraction1/0.25;
    CHECK(fraction1.getNumerator()==1);
    CHECK(fraction1.getDenominator()==2);

    CHECK(fraction7.getNumerator()==2);
    CHECK(fraction7.getDenominator()==1);
}

TEST_CASE("Checking boolean functions") {
    Fraction fraction1(1,2);
    Fraction fraction2(1,3);
    Fraction fraction3(1,3);

    //fraction compare to fraction
    CHECK(fraction1>fraction2);
    CHECK(fraction1>=fraction2);
    CHECK(fraction3>=fraction2);
    CHECK(!(fraction1<fraction2));
    CHECK(!(fraction1<=fraction2));
    CHECK(fraction3<=fraction2);//==
    CHECK(!(fraction1==fraction2));
    CHECK(fraction3==fraction2);
    CHECK(fraction1!=fraction2);
    CHECK(!(fraction3!=fraction2));//==

    //fraction compare to float

    CHECK(fraction1>0.1);
    CHECK(fraction1>=0.1);
    CHECK(fraction1>=0.5);//==
    CHECK(!(fraction1<0.5));
    CHECK(!(fraction1<=0.1));
    CHECK(fraction1<=0.5);//==
    CHECK(fraction1==0.5);//==
    CHECK(fraction1!=0.1);

    //float compare to fraction
    CHECK(0.5>fraction2);
    CHECK(0.5>=fraction2);
    CHECK(0.5>=fraction1);//==
    CHECK(!(0.5<fraction2));
    CHECK(!(0.5<=fraction2));
    CHECK(0.5<=fraction1);//==
    CHECK(0.5==fraction1);
    CHECK(0.5!=fraction2);
}


