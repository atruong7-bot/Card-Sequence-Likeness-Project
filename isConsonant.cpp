// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 2


#include <iostream>
#include <string>
using namespace std;
/*
* This function takes a letter (char) as function parameter and prints out if the number if consonant or not.
* Parameters: char (letter)
* Return: 0 or 1 (false or true)
*/

bool isConsonant(char letter)
{
    
    string consonant = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz"; //string with all consonants, upper and lower cased
    for (int i = 0; i < consonant.length(); i++) //loop that goes through each letter in string
    {
        if(letter == consonant[i]) //if the user input matches any letter from the string
        {
            return true; 
        }

    }
    return false; //once loop goes through the whole string and the if statement is not true, it returns false
}

int main()
{
    //test case 1
    bool consonantCheck1 = isConsonant('I');
    cout << consonantCheck1;
    //test case 2
    bool consonantCheck2 = isConsonant('k');
    cout << consonantCheck2;
    //test case 3
    bool consonantCheck3 = isConsonant('o');
    cout << consonantCheck3;



    return 0;
}