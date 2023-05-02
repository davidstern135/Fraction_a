//
// Created by david on 4/27/2023.
//

#include "Fraction.hpp"
using namespace std;
namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction :: Fraction(){
        this -> numerator = 0;
        this -> denominator = 1;
    }

    Fraction::Fraction(float floatNum) {
        this->numerator = (int)(floatNum * 1000);
        this->denominator = 1000;
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    Fraction Fraction::operator+(const Fraction &fraction) const {return fraction;}
    Fraction operator+(const float float_num, const Fraction &fraction) {return fraction;}
    Fraction operator+(const Fraction &fraction, const float float_num) {return fraction;}

    Fraction Fraction::operator-(const Fraction &fraction) const {return fraction;}
    Fraction operator-(const float float_num, const Fraction &fraction) {return fraction;}
    Fraction operator-(const Fraction &fraction, const float float_num) {return fraction;}

    Fraction Fraction::operator*(const Fraction &fraction) const {return fraction;}
    Fraction operator*(const Fraction &fraction, const float float_num) {return fraction;}
    Fraction operator*(const float float_num, const Fraction &fraction) {return fraction;}

    Fraction Fraction::operator/(const Fraction &fraction) const {return fraction;}
    Fraction operator/(const Fraction &fraction, float float_num) {return fraction;}
    Fraction operator/(float float_num, const Fraction &fraction) {return fraction;}


    Fraction& Fraction::operator=(const Fraction &other) {return *this;}

    bool Fraction::operator==(const Fraction &fraction) const {return true;}
    bool operator==(const Fraction &fraction, float float_num) {return true;}
    bool operator==(float float_num, const Fraction &fraction) {return true;}

    bool Fraction::operator!=(const Fraction &fraction) const {return true;}
    bool operator!=(const Fraction &fraction, float float_num) {return true;}
    bool operator!=(float float_num, const Fraction &fraction) {return true;}

    bool Fraction::operator>(const Fraction &fraction) const {return true;}
    bool operator>(const Fraction &fraction, float float_num) {return true;}
    bool operator>(float float_num, const Fraction &fraction) {return true;}


    bool Fraction::operator<(const Fraction &fraction) const {return true;}
    bool operator<(const Fraction &fraction, float float_num) {return true;}
    bool operator<(float float_num, const Fraction &fraction) {return true;}

    bool Fraction::operator>=(const Fraction &fraction) const {return true;}
    bool operator>=(float float_num, const Fraction &fraction) {return true;}
    bool operator>=(const Fraction &fraction, float float_num) {return true;}

    bool Fraction::operator<=(const Fraction &fraction) const {return true;}
    bool operator<=(float float_num, const Fraction &fraction) {return true;}
    bool operator<=(const Fraction &fraction, float float_num) {return true;}

    Fraction& Fraction::operator++() {return *this;}
    Fraction Fraction::operator++(int) {return Fraction(1,1);}

    Fraction& Fraction::operator--() {return *this;}
    Fraction Fraction::operator--(int) {return Fraction(1,1);}

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {return out;}
    std::istream &operator>>(std::istream &input, Fraction &fraction) {return input;}


}
