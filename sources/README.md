<div dir="rtl" lang="en">

# Field members:

* numerator: an integer representing the numerator of the fraction.
* denominator: an integer representing the denominator of the fraction.

# Constructor:

* Fraction(int numerator, int denominator): constructs a Fraction object with the given numerator and denominator. 
It reduces the fraction to its simplest form and throws an exception if the denominator is zero or if the numerator or denominator is out of range.
* Fraction::Fraction(int numerator, int denominator): constructor creates a Fraction object with the given numerator and denominator, while performing several checks to ensure that the values are valid. It reduces the fraction to its simplest form by calling the reduceForm method.
* Fraction::Fraction(const Fraction &other): copy constructor creates a new Fraction object that is a copy of the Fraction object passed in as an argument.
* Fraction::~Fraction() : destructor does nothing, as there is no dynamic memory allocated in the Fraction class.
* Fraction(Fraction&& other) noexcept : The move constructor initializes the fields of a new Fraction object using the fields of an existing Fraction object that is being moved from, without copying the data, for performance optimization.
# Public Methods:

* int getNumerator() const: returns the numerator of the fraction.
* int getDenominator() const: returns the denominator of the fraction.
* void setNumerator(int new_numerator): sets the numerator of the fraction to the new value and reduces the fraction to its simplest form.
* void setDenominator(int new_denominator): sets the denominator of the fraction to the new value and reduces the fraction to its simplest form. Throws an exception if the new denominator is zero.
* Fraction operator+(const Fraction& fraction) const: returns the sum of the current fraction and the input fraction.
* Fraction operator-(const Fraction& fraction) const: returns the difference between the current fraction and the input fraction.
* Fraction operator*(const Fraction& fraction) const: returns the product of the current fraction and the input fraction.
* Fraction operator/(const Fraction& fraction) const: returns the quotient of the current fraction and the input fraction.
* Fraction& operator=(const Fraction& other): assigns the value of the input fraction to the current fraction.
* Fraction& operator=(Fraction&& other) noexcept: assigns the value of the input fraction to the current fraction using move semantics.
* bool operator==(const Fraction& fraction) const: returns true if the current fraction is equal to the input fraction.
* bool operator>(const Fraction& fraction) const: returns true if the current fraction is greater than the input fraction.
* bool operator<(const Fraction& fraction) const: returns true if the current fraction is less than the input fraction.
* operator++(): pre-increment operator that increments the fraction by 1 and returns the new fraction.
* operator++(int): post-increment operator that increments the fraction by 1 and returns the old fraction.
* operator--(): pre-decrement operator that decrements the fraction by 1 and returns the new fraction.
* operator--(int): post-decrement operator that decrements the fraction by 1 and returns the old fraction.
* friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction): output stream operator that allows printing of the fraction object.
* friend std::istream& operator>>(std::istream& input, Fraction& fraction): input stream operator that allows reading of the fraction object.
* friend Fraction operator+(const Fraction& fraction,float float_num): addition operator that adds the fraction and a float number and returns a new fraction object.
* friend Fraction operator+(float float_num, const Fraction& fraction): addition operator that adds the fraction and a float number and returns a new fraction object.
* friend Fraction operator-(const Fraction& fraction,float float_num): subtraction operator that subtracts the float number from the fraction and returns a new fraction object.
* friend Fraction operator-(float float_num,const Fraction& fraction): subtraction operator that subtracts the fraction from the float number and returns a new fraction object.
* friend Fraction operator*(const Fraction& fraction,float float_num): multiplication operator that multiplies the fraction and a float number and returns a new fraction object.
* friend Fraction operator*(float float_num,const Fraction& fraction): multiplication operator that multiplies the fraction and a float number and returns a new fraction object.
* friend Fraction operator/(const Fraction& fraction,float float_num): division operator that divides the fraction by the float number and returns a new fraction object.
* friend Fraction operator/(float float_num,const Fraction& fraction): division operator that divides the float number by the fraction and returns a new fraction object.
* friend bool operator==(const Fraction& fraction,float float_num): equality operator that checks if the fraction is equal to the float number.
* friend bool operator==(float float_num,const Fraction& fraction): equality operator that checks if the float number is equal to the fraction.
* friend bool operator<(const Fraction& fraction,float float_num): less than operator that checks if the fraction is less than the float number.
* friend bool operator<(float float_num,const Fraction& fraction): less than operator that checks if the float number is less than the fraction.
* friend bool operator<=(const Fraction& fraction,float float_num): less than or equal to operator that checks if the fraction is less than or equal to the float number.
* friend bool operator<=(float float_num,const Fraction& fraction): less than or equal to operator that checks if the float number is less than or equal to the fraction.
* friend bool operator>(const Fraction& fraction,float float_num): greater than operator that checks if the fraction is greater than the float number.
* friend bool operator>(float float_num,const Fraction& fraction): greater than operator that checks if the float number is greater than the fraction.
* friend bool operator>=(const Fraction& fraction,float float_num): greater than or equal to operator that checks if the fraction is greater than or equal to the float number.
* friend bool operator>=(float float_num,const Fraction& fraction): greater than or equal to operator that checks if the float number is greater than or equal to the fraction.

# Private Methods:

* int gcd(int number1, int number2): returns the greatest common divisor of two integers.
* void reduceForm(): reduces the fraction to its simplest form.
* Fraction convertFloatToFraction(float value): converts a floating point number to a fraction. Throws an exception if the float value is out of range.

</div>
