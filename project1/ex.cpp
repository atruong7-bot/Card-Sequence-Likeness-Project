// CSCI1300 Fall 2021
// Author: Punith Sandhu
// Recitation: 123 – TA name
// Project 1 - Problem # ...
#include <iostream>
using namespace std;
/*
* This function converts a temperature in fahrenheit to celsius
* and prints the equivalence.
* Parameters: fahrenheit - degrees fahrenheit
* Return: equivalent temperature in celsius
*/
double fahrenheit_to_celsius(double fahrenheit) {
 double celsius = (fahrenheit - 32) * (5/9.0);
 return celsius;
}

int main()
{
 double fahrenheit1 = 32;
 double fahrenheit2 = 100;
 double fahrenheit3 = -30;
 cout << fahrenheit1 << “F is “ <<
fahrenheit_to_celsius(fahrenheit1) << “ in celsius.” << endl;
cout << fahrenheit2 << “F is “ <<
fahrenheit_to_celsius(fahrenheit2) << “ in celsius.” << endl;
cout << fahrenheit3 << “F is “ <<
fahrenheit_to_celsius(fahrenheit3) << “ in celsius.” << endl;
 return 0;
}