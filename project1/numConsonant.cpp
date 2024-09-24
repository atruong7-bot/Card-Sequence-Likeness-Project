// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 3


#include <iostream>
#include <string>
using namespace std;
/*
* This function checks how many consonants are in a string and returns the number of consonants.
* Parameters: sentence (letter)
* Return: number of consonants (integer)
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


int numConsonant(string sentence) //int becaue we want the number of consonants in the parameter 
{
    int numOfConsonants = 0; 
    for (int j=0; j < sentence.length(); j++) //loop that goes through each letter in string 
        {
            if (isConsonant(sentence[j]) == true) //using the isConsonant function to check if each letter in the sentence string is a consonant
            {
                numOfConsonants++; 
            }
        }
    
    return numOfConsonants; //integer of how many times numOfConsonants was iterated
}

int main()
{
    //test case 1
    int numOfConsonants1 = numConsonant("CSCI 1300: Starting Computing 1");
    cout << numOfConsonants1;
    //test case 2
    int numOfConsonants2 = numConsonant("Can the lockdown end already?");
    cout << numOfConsonants2;
    //test case 3
    int numOfConsonants3 = numConsonant("PCR");
    cout << numOfConsonants3;
}
