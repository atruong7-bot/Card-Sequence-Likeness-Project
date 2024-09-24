// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 1
//https://cuboulder.zoom.us/j/91652474359


#include <iostream>
#include <string>
using namespace std;
/*
* This function takes a number (as a string) as a function parameter and prints that number in reverse.
* Parameters: number (string)
* Return: number in reverse
*/

void reverse(string number)
{
    for (int i = number.length() - 1; i >= 0; i--) //'i' starts at the last number of the string. 
    //Since the position of i is greater than/equal to zero(the first number), it prints i. Then, i becomes the number before the one that was just printed. 
    //In this loop, the numbers from last to first are printed. 
    {
        cout << number[i]; //prints the number that is in position i 
    } 
}

int main()
{
    //test case 1
    reverse ("1234567890");
    //test case 2
    reverse("04022021");
    //test case 3
    reverse("04022021");

return 0;
}
