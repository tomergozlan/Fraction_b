/**
 * @author Tomer Gozlan
 * @Date 4/15/23
 * @brief Implementation of instructions of assignment in a systems programming course for overloading operators in fraction class .
 */

#include "Fraction.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

namespace ariel {
/**
@brief Constructor that creates a Fraction object with the specified numerator and denominator.
@param numerator The numerator of the fraction.
@param denominator The denominator of the fraction.
@throw std::invalid_argument If the denominator is zero.
@throw std::out_of_range If the numerator is out of range.
This constructor creates a new Fraction object with the given numerator and denominator. \n It reduces the fraction to its
lowest form by calling the reduceForm() method. If the numerator is negative and the denominator is positive or both are
negative, the signs are adjusted to ensure that the numerator is negative and the denominator is positive.\n If the numerator
or denominator is out of range, an exception is thrown.
*/
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

/**
 * @brief Constructs a new Fraction object from a floating-point number
 * This constructor takes a floating-point number and converts it to a Fraction object. \n
 * The resulting fraction is reduced to its lowest terms before being stored.
 * @param float_num The floating-point number to convert to a fraction.
 */
    Fraction::Fraction(double float_num) {
        Fraction float_frac = Fraction::convertFloatToFraction(float_num);
        this->numerator = float_frac.getNumerator();
        this->denominator = float_frac.getDenominator();
    }

/**
 * @brief Constructs a new Fraction object that is a copy of the given Fraction object.
 * This constructor creates a new Fraction object that is a copy of the given Fraction object.
 * @param other The Fraction object to copy.
 */
    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

/**
 * @brief Destroys the Fraction object and releases any resources associated with it.
 * This destructor releases any resources associated with the Fraction object.
 */
    Fraction::~Fraction() {}

/**
 * @brief Computes the greatest common divisor of two integers.
 * This method computes the greatest common divisor of two integers using the Euclidean algorithm.
 * @param number1 The first integer.
 * @param number2 The second integer.
 * @return The greatest common divisor of number1 and number2.
 */
    int Fraction::gcd(int number1, int number2) {
        return (number2 == 0) ? number1 : gcd(number2, number1 % number2);
    }

/**
 * @brief Reduces the Fraction to its simplest form.
 * This method reduces the Fraction to its simplest form by dividing both the numerator and the denominator by their greatest common divisor.
 */
    void Fraction::reduceForm() {
        int gcd = this->gcd(::abs(this->numerator), this->denominator);
        if (gcd >= 1) {
            this->numerator /= gcd;
            this->denominator /= gcd;
        }
    }

/**
 * @brief Converts a floating-point number to a Fraction.
 * This method takes a floating-point number and converts it to a Fraction with a numerator and denominator that can be used to represent the same value as the original number.
 * @param value The floating-point number to convert to a Fraction.
 * @return A Fraction that represents the same value as the input floating-point number.
 */
    Fraction Fraction::convertFloatToFraction(double value) {
        int numerator = (value * 1000);
        int denominator = 1000;
        Fraction fraction(numerator, denominator);
        return fraction;
    }

/**
 * @brief Returns the numerator of the Fraction
 * This method returns the numerator of the Fraction as an integer value.
 * @return The numerator of the Fraction.
 */
    int Fraction::getNumerator() const {
        return this->numerator;
    }

/**
 * @brief Returns the denominator of the Fraction.
 * This method returns the denominator of the Fraction as an integer value.
 * @return The denominator of the Fraction.
 */
    int Fraction::getDenominator() const {
        return this->denominator;
    }

/**
 * @brief Sets the numerator of the Fraction to a new value.
 * This method sets the numerator of the Fraction to a new value and updates the Fraction to its simplest form.
 * @param new_numerator The new numerator value.
 */
    void Fraction::setNumerator(int new_numerator) {
        this->numerator = new_numerator;
        if (numerator < 0 && denominator < 0 || numerator > 0 && denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        this->reduceForm();
    }

/**
@brief Sets the denominator of the fraction to a new value.
@param new_denominator The new denominator value to set.
@throws std::invalid_argument if the new denominator value is zero.
Sets the denominator of the fraction to the specified value and reduces the fraction to its lowest terms.\n
If the resulting fraction has a negative numerator and denominator, both values will be negated to maintain proper sign.
*/
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

/**
@brief Overloads the + operator to add two fractions.
@param fraction The fraction to be added.
@return The sum of the two fractions.
@throw std::overflow_error If the result of the addition causes an integer overflow.
*/
    Fraction Fraction::operator+(const Fraction &fraction) const {
        Fraction resultFraction;
        if (this->denominator == fraction.getDenominator()) {
            long long checkNum = (long long) this->numerator + fraction.getNumerator();
            long long checkDen = (long long) this->denominator;
            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");
            } else {
                resultFraction.setNumerator(this->numerator + fraction.getNumerator());
                resultFraction.setDenominator(this->denominator);
            }
        } else {
            long long checkNum = (long long) this->numerator * fraction.getDenominator() +
                                 fraction.getNumerator() * this->denominator;
            long long checkDen = (long long) this->denominator * fraction.getDenominator();
            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");
            }
            resultFraction.setNumerator(
                    (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

/**
@brief Overloads the subtraction operator for the Fraction class.
@param fraction the Fraction object to subtract from this Fraction object
@return the new Fraction object that is the difference of the two fractions
@throw std::overflow_error if an arithmetic overflow occurs during the calculation
*/
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
        } else {
            long long checkNum = (long long) this->numerator * fraction.getDenominator() -
                                 fraction.getNumerator() * this->denominator;
            long long checkDen = (long long) this->denominator * fraction.getDenominator();
            if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
                throw std::overflow_error("Error: multiplication overflow");
            }
            resultFraction.setNumerator(
                    (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
            resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        }
        resultFraction.reduceForm();
        return resultFraction;
    }

/**
@brief Multiplies two fractions and returns the result as a new Fraction object.
@param fraction The fraction to multiply with.
@return The result of the multiplication as a new Fraction object.
@throws std::overflow_error If the multiplication of the numerator or denominator overflows the integer limits.
*/
    Fraction Fraction::operator*(const Fraction &fraction) const {
        Fraction resultFraction;
        long long checkNum = (long long) this->numerator * fraction.getNumerator();
        long long checkDen = (long long) this->denominator * fraction.getDenominator()
        if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
            throw std::overflow_error("Error: multiplication overflow");
        }
        resultFraction.setNumerator(this->numerator * fraction.getNumerator());
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());
        resultFraction.reduceForm();
        return resultFraction;
    }

/**
@brief Overloaded division operator for Fraction objects
This function performs division of two Fraction objects by multiplying the numerator of the first fraction with the denominator
of the second fraction and vice versa, then reduces the resulting fraction to its simplest form.
@param fraction the Fraction object to divide this Fraction object by
@return a new Fraction object representing the result of the division
@throws std::runtime_error if the denominator of the divisor fraction is zero
@throws std::overflow_error if the result of the multiplication overflows the int data type
*/
    Fraction Fraction::operator/(const Fraction &fraction) const {
        if (fraction.getNumerator() == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        Fraction resultFraction;
        long long checkNum = (long long) this->numerator * fraction.getDenominator();
        long long checkDen = (long long) this->denominator * fraction.getNumerator();
        if (checkNum > INT_MAX || checkNum < INT_MIN || checkDen > INT_MAX || checkDen < INT_MIN) {
            throw std::overflow_error("Error: multiplication overflow");
        }
        resultFraction.setNumerator(this->numerator * fraction.getDenominator());
        resultFraction.setDenominator(this->denominator * fraction.getNumerator());
        resultFraction.reduceForm();
        return resultFraction;
    }

/**
@brief Copy assignment operator for Fraction class
@param other Fraction object to be copied
@return Fraction& reference to this Fraction object
*/
    Fraction &Fraction::operator=(const Fraction &other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

/**
@brief Move assignment operator for Fraction class.
@param other The Fraction object to move from.
@return A reference to the Fraction object that was moved.
This method moves the contents of the given Fraction object other
into the current Fraction object. This is done by calling std::move()
on the numerator and denominator of other, and assigning them to the
numerator and denominator of the current object, respectively.
@note The behavior of this method is undefined if other is the same
*/
    Fraction &Fraction::operator=(Fraction &&other)

    noexcept {
    numerator = std::move(other.numerator);
    denominator = std::move(other.denominator);
    return *this;
}

/**
@brief Check if the calling Fraction object is equal to the passed Fraction object.
This function checks if the calling object is equal to the passed object. \n
It does so by checking if the product of the numerator of the calling object and the denominator of the passed object is equal to the product of the denominator of the calling object and the numerator of the passed object. \n
If the two products are equal, it means that the fractions are equivalent.
@param fraction The Fraction object to compare against.
@return True if the fractions are equal, false otherwise.
*/
bool Fraction::operator==(const Fraction &fraction) const {
    return (this->numerator * fraction.getDenominator()) == (this->denominator * fraction.getNumerator());
}

/**
@brief Overloads the ">" operator to compare two Fraction objects.
This function compares the decimal value of two fractions to check if the calling
object is greater than the fraction passed as an argument.
@param fraction The Fraction object to compare with.
@return True if the calling Fraction object is greater than the argument fraction object, false otherwise.
*/
bool Fraction::operator>(const Fraction &fraction) const {
    return (this->numerator * fraction.getDenominator()) > (this->denominator * fraction.getNumerator());
}

/**
@brief Overloaded less than operator for comparing two fractions.
@param fraction The other fraction to compare to.
@return True if the current fraction is less than the other fraction, false otherwise.
*/
bool Fraction::operator<(const Fraction &fraction) const {
    return (this->numerator * fraction.getDenominator()) < (this->denominator * fraction.getNumerator());
}

/**
@brief Checks if the current fraction is greater than or equal to the specified fraction.
@param fraction The fraction to compare to.
@return true if the current fraction is greater than or equal to the specified fraction, false otherwise.
*/
bool Fraction::operator>=(const Fraction &fraction) const {
    return (this->numerator * fraction.getDenominator()) >= (this->denominator * fraction.getNumerator());
}

/**
@brief Overloaded less than or equal to operator
Checks if the current fraction is less than or equal to another fraction.
@param fraction the fraction to compare against
@return true if the current fraction is less than or equal to the provided fraction, false otherwise
*/
bool Fraction::operator<=(const Fraction &fraction) const {
    return (this->numerator * fraction.getDenominator()) <= (this->denominator * fraction.getNumerator());
}

/**
@brief Prefix increment operator for Fraction.
Adds the fraction's denominator to its numerator and reduces the fraction to its simplest form.
@return Fraction& Returns a reference to the modified Fraction object.
*/
Fraction &Fraction::operator++() {
    this->numerator += this->denominator;
    this->reduceForm();
    return *this;
}

/**
@brief postfix increment operator for a Fraction object.
@return A copy of the original fraction before incrementing.
*/
Fraction Fraction::operator++(int) {
    Fraction temp = (*this);
    ++(*this);
    return temp;
}

/**
 * @brief Prefix decrement operator for Fraction class. Decrements the value of the fraction by 1 and returns the updated fraction.
 * @return Fraction& Reference to the updated fraction after decrement.
 */
Fraction Fraction::operator--() {
    this->numerator -= this->denominator;
    this->reduceForm();
    return *this;
}

/**
 * @brief Postfix decrement operator for Fraction class. Decrements the value of the fraction by 1 and returns the original value before decrement.
 * @return Fraction Copy of the fraction before decrement.
 */
Fraction Fraction::operator--(int) {
    Fraction temp = (*this);
    this->numerator -= this->denominator;
    temp.reduceForm();
    return temp;
}

/**
Overloads the << operator to output the fraction object to the given output stream.
@param out The output stream.
@param fraction The fraction object to output.
@return The output stream.
*/
std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out << fraction.getNumerator() << "/" << fraction.getDenominator();
    return out;
}

/**
@brief Reads a Fraction object from an input stream.
@param input The input stream to read from.
@param fraction The Fraction object to read into.
@return std::istream& The input stream after reading.
@throw std::runtime_error If the input format is invalid.
*/
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

/**
@brief Adds a double value from left to a fraction and returns the resulting fraction.
@param float_num The double value to add to the fraction.
@param fraction The fraction to add to the double value.
@return Fraction The resulting fraction after adding the double value to the fraction.
*/
Fraction operator+(const double float_num, const Fraction &fraction) {
    const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;
    resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                fraction.getNumerator() * float_frac.getDenominator());
    resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
    resultFraction.reduceForm();
    return resultFraction;
}

/**
 * @brief Adds a double to a fraction from right.
 * @param float_num The double to add to the fraction.
 * @param fraction The fraction to add the double to.
 * @return The result of adding the double to the fraction.
 */
Fraction operator+(const Fraction &fraction, const double float_num) {
    const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;
    resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator() +
                                fraction.getNumerator() * float_frac.getDenominator());
    resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
    resultFraction.reduceForm();
    return resultFraction;
}

/**
 * @brief Subtracts a fraction from a floating-point number from left.
 * @param float_num The floating-point number to subtract the fraction from.
 * @param fraction The fraction to subtract from the floating-point number.
 * @return The result of the subtraction operation as a new reduced Fraction object.
 */
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

/**
 * @brief Subtracts a fraction from a floating-point number from right.
 * @param float_num The floating-point number to subtract the fraction from.
 * @param fraction The fraction to subtract from the floating-point number.
 * @return The result of the subtraction operation as a new reduced Fraction object.
 */
Fraction operator-(const Fraction &fraction, const double float_num) {
    const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;
    if (float_frac.getDenominator() == fraction.getDenominator()) {
        resultFraction.setNumerator(fraction.getNumerator() - float_frac.getNumerator());
        resultFraction.setDenominator(fraction.getDenominator());
    } else {
        resultFraction.setNumerator((fraction.getNumerator() * float_frac.getDenominator()) -
                                    (fraction.getDenominator() * float_frac.getNumerator()));
        resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());
    }
    resultFraction.reduceForm();
    return resultFraction;
}

/**
 * @brief Overloaded operator for multiplying a Fraction object with a double value from right.
 * @param fraction The Fraction object to be multiplied
 * @param float_num The double value to multiply the Fraction object with
 * @return Fraction The product of the multiplication operation as a Fraction object
 */
Fraction operator*(const Fraction &fraction, const double float_num) {
    const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;

    resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
    resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

    resultFraction.reduceForm();
    return resultFraction;
}

/**
 * @brief Overloaded operator for multiplying a Fraction object with a double value from left.
 * @param fraction The Fraction object to be multiplied
 * @param float_num The double value to multiply the Fraction object with
 * @return Fraction The product of the multiplication operation as a Fraction object
 */
Fraction operator*(const double float_num, const Fraction &fraction) {
    const Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;

    resultFraction.setNumerator(float_frac.getNumerator() * fraction.getNumerator());
    resultFraction.setDenominator(float_frac.getDenominator() * fraction.getDenominator());

    resultFraction.reduceForm();
    return resultFraction;
}

/**
@brief Overloaded division operator to divide a fraction by a floating-point number from right.
@param fraction The Fraction object to be divided.
@param float_num The floating-point number to divide by.
@return The resulting fraction after division.
@throws std::runtime_error if the float_num is equal to 0.
*/
Fraction operator/(const Fraction &fraction, double float_num) {
    if (float_num == 0.0) {
        throw runtime_error("Error:the denominator cant be zero.");
    }
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;

    resultFraction.setNumerator(fraction.getNumerator() * float_frac.getDenominator());
    resultFraction.setDenominator(fraction.getDenominator() * float_frac.getNumerator());

    resultFraction.reduceForm();
    return resultFraction;
}

/**
@brief Overloaded division operator to divide a fraction by a floating-point number from left.
@param fraction The Fraction object to be divided.
@param float_num The floating-point number to divide by.
@return The resulting fraction after division.
*/
Fraction operator/(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    Fraction resultFraction;

    resultFraction.setNumerator(float_frac.getNumerator() * fraction.getDenominator());
    resultFraction.setDenominator(float_frac.getDenominator() * fraction.getNumerator());

    resultFraction.reduceForm();
    return resultFraction;
}

/**
@brief Overloaded equality operator for comparing a Fraction object with a double value from right.
@param fraction A constant reference to the Fraction object to be compared.
@param float_num A double value to be compared with the Fraction object.
@return true If the Fraction object and the double value are equal,otherwise return false.
*/
bool operator==(const Fraction &fraction, double float_num) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) ==
           (float_frac.getDenominator() * fraction.getNumerator());
}

/**
@brief Overloaded equality operator for comparing a Fraction object with a double value from left.
@param fraction A constant reference to the Fraction object to be compared.
@param float_num A double value to be compared with the Fraction object.
@return true If the Fraction object and the double value are equal,otherwise return false.
*/
bool operator==(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) ==
           (float_frac.getDenominator() * fraction.getNumerator());
}

/**
@brief Overloaded less than operator to compare a fraction with a double from right.
@param fraction The fraction object to be compared.
@param float_num The double value to be compared with the fraction.
@return True if the fraction is less than the double, false otherwise.
*/
bool operator<(const Fraction &fraction, double float_num) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getDenominator() * fraction.getNumerator() <
            (float_frac.getNumerator() * fraction.getDenominator()));
}

/**
@brief Overloaded less than operator to compare a fraction with a double from left.
@param fraction The fraction object to be compared.
@param float_num The double value to be compared with the fraction.
@return True if the fraction is less than the double, false otherwise.
*/
bool operator<(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) <
           (float_frac.getDenominator() * fraction.getNumerator());
}
/**
@brief Overloaded operator that checks if a fraction is less than or equal to a float number from right.
@param fraction The fraction to compare.
@param float_num The float number to compare.
*/
bool operator<=(const Fraction &fraction, double float_num) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getDenominator() * fraction.getNumerator() <=
            (float_frac.getNumerator() * fraction.getDenominator()));
}
/**
@brief Overloaded operator that checks if a fraction is less than or equal to a float number from left.
@param fraction The fraction to compare.
@param float_num The float number to compare.
*/
bool operator<=(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) <=
           (float_frac.getDenominator() * fraction.getNumerator());
}
/**
@brief Overloaded > operator for comparing a fraction with a double from right.
@param fraction A constant reference to the Fraction object.
@param float_num A double value to compare with the Fraction object.
@return bool Returns true if the fraction is greater than the double value, false otherwise.
*/
bool operator>(const Fraction &fraction, double float_num) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getDenominator() * fraction.getNumerator() >
            (float_frac.getNumerator() * fraction.getDenominator()));
}
/**
@brief Overloaded > operator for comparing a fraction with a double from left.
@param fraction A constant reference to the Fraction object.
@param float_num A double value to compare with the Fraction object.
@return bool Returns true if the fraction is greater than the double value, false otherwise.
*/
bool operator>(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) >
           (float_frac.getDenominator() * fraction.getNumerator());
}
/**
@brief Overloaded operator to check if a fraction is greater than or equal to a float number from right.
@param fraction The fraction to be compared
@param float_num The float number to be compared with
@return true if the fraction is greater than or equal to the float number, false otherwise
*/
bool operator>=(const Fraction &fraction, double float_num) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getDenominator() * fraction.getNumerator() >=
            (float_frac.getNumerator() * fraction.getDenominator()));
}
/**
@brief Overloaded operator to check if a fraction is greater than or equal to a float number from left.
@param fraction The fraction to be compared
@param float_num The float number to be compared with
@return true if the fraction is greater than or equal to the float number, false otherwise
*/
bool operator>=(double float_num, const Fraction &fraction) {
    Fraction float_frac = Fraction::convertFloatToFraction(float_num);
    return (float_frac.getNumerator() * fraction.getDenominator()) >=
           (float_frac.getDenominator() * fraction.getNumerator());
}
}