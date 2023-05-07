/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main() {
    Fraction a(5, 3), b(14, 21);
    cout << "a: " << a << " b: " << b << endl;
    cout << "a+b " << a + b << endl;
    cout << "a-b " << a - b << endl;
    cout << "a/b " << a / b << endl;
    cout << "a*b " << a * b << endl;
    cout << "2.3*b " << 2.3 * b << endl;
    cout << "a+2.421 " << a + 2.421 << endl;
    Fraction c = (a + b) - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >= b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << "a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;
}
/**
 ** My Demo file for the exercise
 * @author Tomer Gozlan
 */


/*
int main() {
    Fraction a (12,36);
    Fraction b (24,40);
    cout << "-----------------"<<endl;
    cout << "Initial Fraction: "<<endl;
    cout << "-----------------"<<endl;
    cout<< "a: " << a << " b: " << b <<endl;
    int num = a.getNumerator();
    int den = a.getDenominator();
    a.setNumerator(num+1);
    a.setDenominator(den+1);
    num = b.getNumerator();
    den = b.getDenominator();
    b.setNumerator(num-4);
    b.setDenominator(den-7);
    cout<< "add 1 to numerator and denominator of 'a' " ;
    cout<< "- should show 'a' on his reduced form after set. "<<endl;
    cout<< "subtract 4 to numerator and subtract 7 to denominator of 'b' " ;
    cout<< "- should show 'b' on his reduced form after set. "  <<endl;
    cout<< "a: " << a << " b: " << b <<endl;
    cout << "-----------------------------"<<endl;
    cout << "Print all the basic operators: "<<endl;
    cout << "-----------------------------"<<endl;
    cout << "a+b " << a + b << endl;
    cout << "a-b " << a - b << endl;
    cout << "a/b " << a / b << endl;
    cout << "a*b " << a * b << endl;
    cout << "----------------------------------"<<endl;
    cout << "Print all the comparison operators: "<<endl;
    cout << "----------------------------------"<<endl;
    cout << "a==b ? ";
    if (a==b){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "a<b ? ";
    if (a<b){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "a>b ? ";
    if (a>b){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "a<=b ? ";
    if (a<=b){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "a>=b ? ";
    if (a>=b){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "--------------------------------------------------"<<endl;
    cout << "Print pre/post operators increment and decrement: "<<endl;
    cout << "--------------------------------------------------"<<endl;
    cout << "++a  " << ++a  << " ++b "<<++b<< endl;
    cout << "a++  " << a++  << " b++ "<<b++<< endl;
    cout << "a  " << a  << " b "<<b<< endl;
    cout << "--a  " << --a  << " --b "<<--b<< endl;
    cout << "a--  " << a--  << " b-- "<<b--<< endl;
    cout << "a  " << a  << " b "<<b<< endl;
    cout << "---------------------------"<<endl;
    cout << "use '>>' & '<<' operators: "<<endl;
    cout << "---------------------------"<<endl;
    cout<<"Please enter Fraction in the template of number / number "<<endl;
    Fraction in;
    cin >> in;
    cout <<"Print The input: " << in << endl;
    cout << "-------------------------------------------------------"<<endl;
    cout << "Print all operators support float right and left side: "<<endl;
    cout << "-------------------------------------------------------"<<endl;
    float float_num = 0.25;
    cout << "Initialize float number to: " << float_num << endl;
    cout << "Convert to Fraction : " << ariel::Fraction::convertFloatToFraction(float_num) << endl;

    Fraction sum_right= a + float_num;
    Fraction sum_left= float_num + a;
    Fraction difference_left = float_num - a;
    Fraction difference_right = a - float_num;
    Fraction product_right = a * float_num;
    Fraction product_left = float_num*a;
    Fraction quotient_right = float_num / a;
    Fraction quotient_left = a/float_num;

    cout << "Sum (float from right): " << sum_right << endl;
    cout << "Sum (float from left): " << sum_left << endl;

    cout << "Difference (float from right): " << difference_right << endl;
    cout << "Difference (float from left): " << difference_left << endl;

    cout << "Product (float from right): " << product_right << endl;
    cout << "Product (float from left): " << product_left<<endl;

    cout << "Quotient (float from right): " << quotient_right << endl;
    cout << "Quotient (float from left): " << quotient_left << endl;

    cout << "---------------------------------------------------------------"<<endl;
    cout << "Print compression operators support float right and left side: "<<endl;
    cout << "---------------------------------------------------------------"<<endl;
    Fraction c (-2,8);
    Fraction d (2,8);
    cout << "Initialize fraction to: " << c <<endl<< "Initialize fraction to: " << d <<endl<<"Initialize float number to: "<<float_num<<endl;
    cout << "********************"<<endl;
    cout << "Equal operator '==' "<<endl;
    cout << "********************"<<endl;
    cout << "1/4 == 0.25 ? ";
    if (d==float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 == 1/4 ?" ;
    if (float_num==d){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "-1/4 == 0.25 ? ";
    if (c == float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 == -1/4 ?" ;
    if (float_num == c){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "**************"<<endl;
    cout << "Less then '<' "<<endl;
    cout << "**************"<<endl;
        cout << "1/4 < 0.25 ? ";
    if (d<float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 < 1/4 ?" ;
    if (float_num<d){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "-1/4 < 0.25 ? ";
    if (c < float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 < -1/4 ?" ;
    if (float_num < c){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "***********************"<<endl;
    cout << "Less the or Equal '<=' "<<endl;
    cout << "***********************"<<endl;

    cout << "1/4 <= 0.25 ? ";
    if (d<=float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    cout << "0.25 <= 1/4 ?" ;
    if (float_num<=d){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    cout << "-1/4 <= 0.25 ? ";
    if (c <= float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 <= -1/4 ?" ;
    if (float_num <= c){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "*****************"<<endl;
    cout << "Greater then '<' "<<endl;
    cout << "*****************"<<endl;

    cout << "1/4 > 0.25 ? ";
    if (d>float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 > 1/4 ?" ;
    if (float_num>d){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    cout << "-1/4 > 0.25 ? ";
    if (c > float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 > -1/4 ?" ;
    if (float_num > c){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "***************************"<<endl;
    cout << "Greater then or Equal '<=' "<<endl;
    cout << "***************************"<<endl;


    cout << "1/4 >= 0.25 ? ";
    if (d>=float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    cout << "0.25 >= 1/4 ?" ;
    if (float_num>=d){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

    cout << "-1/4 >= 0.25 ? ";
    if (c >= float_num){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    cout << "0.25 >= -1/4 ?" ;
    if (float_num >= c){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}
*/