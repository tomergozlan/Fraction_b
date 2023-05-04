//
// Created by tomergozlan on 4/15/23.
//

#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        if (numerator < std::numeric_limits<int>::min() || numerator > std::numeric_limits<int>::max()) {
            throw std::out_of_range("Numerator or denominator value is out of range.");
        }
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->denominator = denominator;
        this->numerator = numerator;
        reduceForm();
    }

    Fraction::Fraction(double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        this->numerator = float_frac.getNumerator();
        this->denominator =float_frac.getDenominator();
    }

    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    Fraction::~Fraction(){}

    int Fraction::gcd(int number1, int number2) {
        return (number2 == 0) ? number1 : gcd(number2, number1 % number2);
    }

    void Fraction::reduceForm() {
        int gcd = this->gcd(::abs(this->numerator), this->denominator);
        if (gcd >= 1) {
            this->numerator /= gcd;
            this->denominator /= gcd;
        }
    }

    Fraction Fraction::convertFloatToFraction(double value) {

        int numerator =(value * 1000);
        int denominator = 1000;
        Fraction fraction(numerator, denominator);
        return fraction;
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    void Fraction::setNumerator(int new_numerator) {
        this->numerator = new_numerator;
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->reduceForm();
    }

    void Fraction::setDenominator(int new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Error: the denominator of fraction can't be zero.");
        }
        this->denominator = new_denominator;
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->reduceForm();
    }

    Fraction Fraction::operator+(const Fraction &fraction) const {
        Fraction resultFraction;

        if (this->denominator == fraction.getDenominator()) {

            long long checkNum = (long long)this->numerator + fraction.getNumerator();
            long long checkDen = (long long)this->denominator;

            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");
            }

            else {
                resultFraction.setNumerator(this->numerator + fraction.getNumerator());
                resultFraction.setDenominator(this->denominator);
            }
        }
        else {
                long long checkNum = (long long)this->numerator * fraction.getDenominator() + fraction.getNumerator() * this->denominator;
                long long checkDen = (long long)this->denominator * fraction.getDenominator();

                    if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                        throw std::overflow_error("Error: multiplication overflow");
                    }

                        resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
                        resultFraction.setDenominator(this->denominator * fraction.getDenominator());

        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction Fraction::operator-(const Fraction &fraction) const {
        Fraction resultFraction;
        if (this->denominator == fraction.getDenominator()) {

            long long checkNum = (long long) this->numerator - fraction.getNumerator();
            long long checkDen = (long long) this->denominator;

            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");

            }
                resultFraction.setNumerator(this->numerator - fraction.getNumerator());
                resultFraction.setDenominator(this->denominator);
        }else{
            long long checkNum = (long long)this->numerator * fraction.getDenominator() - fraction.getNumerator() * this->denominator;
            long long checkDen = (long long)this->denominator * fraction.getDenominator();

            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");
            }

            resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());

            }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction Fraction::operator*(const Fraction &fraction) const {
        Fraction resultFraction;

        long long checkNum = (long long)this->numerator * fraction.getNumerator();
        long long checkDen = (long long)this->denominator * fraction.getDenominator();

        if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
            throw std::overflow_error("Error: multiplication overflow");
        }

        resultFraction.setNumerator(this->numerator * fraction.getNumerator());
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }


    Fraction Fraction::operator/(const Fraction &fraction) const {
        if (fraction.getNumerator() == 0) {
            throw std::runtime_error("Error: division by zero");
        }

        Fraction resultFraction;
        long long checkNum = (long long)this->numerator * fraction.getDenominator();
        long long checkDen = (long long)this->denominator * fraction.getNumerator();

        if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
            throw std::overflow_error("Error: multiplication overflow");
        }

        resultFraction.setNumerator(this->numerator * fraction.getDenominator());
        resultFraction.setDenominator(this->denominator * fraction.getNumerator());

        resultFraction.reduceForm();
        return resultFraction;
    }


        Fraction& Fraction::operator=(const Fraction &other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

        Fraction& Fraction::operator=(Fraction &&other) noexcept {
        numerator = std::move(other.numerator);
        denominator = std::move(other.denominator);
        return *this;
        }

    bool Fraction::operator==(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) == (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator>(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) > (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator<(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) < (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator>=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) >= (this->denominator * fraction.getNumerator());
    }

    bool Fraction::operator<=(const Fraction &fraction) const {
        return (this->numerator * fraction.getDenominator()) <= (this->denominator * fraction.getNumerator());
    }

    Fraction& Fraction::operator++() {
        this->numerator += this->denominator;
        this->reduceForm();
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp= (*this);
        ++(*this);
        return temp;
    }

    Fraction Fraction::operator--() {
        this->numerator -= this->denominator;
        this->reduceForm();
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = (*this);
        this->numerator -= this->denominator;
        temp.reduceForm();
        return temp;
    }

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
        out << fraction.getNumerator() << "/" << fraction.getDenominator();
        return out;
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction) {
        int numerator, denominator;
        input >> numerator >> denominator;

        if (input.fail()) {
            throw runtime_error("Error: invalid format input.");
        }
        if (denominator == 0) {
            throw runtime_error("Error: denominator cant be zero.");
        }
        fraction = Fraction(numerator, denominator);
        return input;
    }

        Fraction operator+(const double float_num, const Fraction &fraction) {
            const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
            Fraction resultFraction;

            resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                        fraction.getNumerator() * float_frac.getDenominator());
            resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
            resultFraction.reduceForm();

            return resultFraction;
    }

    Fraction operator+(const Fraction &fraction, const double float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                    fraction.getNumerator() * float_frac.getDenominator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        resultFraction.reduceForm();

        return resultFraction;
    }

    Fraction operator-(const double float_num, const Fraction &fraction) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;
        if (float_frac.getDenominator() == fraction.getDenominator()) {
            resultFraction.setNumerator(float_frac.getNumerator() - fraction.getNumerator());
            resultFraction.setDenominator(float_frac.getDenominator());
        } else {
            resultFraction.setNumerator((float_frac.getNumerator() * fraction.getDenominator()) -
                                        (fraction.getNumerator() * float_frac.getDenominator()));
            resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator-(const Fraction &fraction, const double float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;
        if (float_frac.getDenominator() == fraction.getDenominator()) {
            resultFraction.setNumerator( fraction.getNumerator()-float_frac.getNumerator());
            resultFraction.setDenominator(fraction.getDenominator());
        } else {
            resultFraction.setNumerator((fraction.getNumerator() * float_frac.getDenominator()) -(fraction.getDenominator() * float_frac.getNumerator()));
            resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator*(const Fraction &fraction, const double float_num) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator*(const double float_num, const Fraction &fraction) {
        const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator/(const Fraction &fraction, double float_num) {
        if (float_num==0.0){
            throw runtime_error("Error:the denominator cant be zero.");
        }
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator( fraction.getNumerator()*float_frac.getDenominator());
        resultFraction.setDenominator( fraction.getDenominator()*float_frac.getNumerator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    Fraction operator/(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        Fraction resultFraction;

        resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator());
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getNumerator());

        resultFraction.reduceForm();
        return resultFraction;
    }

    bool operator==(const Fraction &fraction, double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) ==
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator==(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) ==
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator<(const Fraction &fraction, double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() <
                (float_frac.getNumerator() * fraction.getDenominator()));
    }
    bool operator<(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) <
               (float_frac.getDenominator() * fraction.getNumerator());
    }
    bool operator<=(const Fraction &fraction, double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() <=
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator<=(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) <=
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator>(const Fraction &fraction, double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() >
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator>(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) >
               (float_frac.getDenominator() * fraction.getNumerator());
    }

    bool operator>=(const Fraction &fraction, double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getDenominator() * fraction.getNumerator() >=
                (float_frac.getNumerator() * fraction.getDenominator()));
    }

    bool operator>=(double float_num, const Fraction &fraction) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        return (float_frac.getNumerator() * fraction.getDenominator()) >=
               (float_frac.getDenominator() * fraction.getNumerator());
    }
}