// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 4


#include <iostream>
#include <string>
using namespace std;
/*
* This function find the Likeness Score between two sequences of equal length
* Parameters: seq1 and seq2 (strings)
* Return: likeness score (double)
*/

double calcLikenessScore(string seq1, string seq2)
{
    double likeness_score = 0;
    double numberOfCards = seq1.length() / 2;
    double sameSuit = 0;
    double sameSuitAndRank = 0;
    int i = 0;
    //initialize varibles
    if (seq1.length() == seq2.length()) //string length must be same or else they aren't compared
    {
        for (int i = 0; i < seq1.length(); i = i + 2) //increment by 2 first to only look for same suits
        {
            if (seq1[i] == seq2[i])
            {
                sameSuit++;
                if (seq1[i+1] == seq2[i+1]) //once suit is the same, we check if the rank is the same
                {
                    sameSuitAndRank++;
                }
            }
        }
    likeness_score = (sameSuit / numberOfCards ) + ( 1 * sameSuitAndRank);
    }
    
    else
    {
        likeness_score = -1;
    }

    return likeness_score;

}

int main()
{
    //test case 1
    double likeness_score1 = calcLikenessScore("S7H8CJD9HA", "S7H8CJD9HA");
    cout <<likeness_score1;
    //test case 2
    double likeness_score2 = calcLikenessScore("C4DTSK", "C4DJSK");
    cout <<likeness_score2;
    //test case 3
    double likeness_score3 = calcLikenessScore("HQDASJ", "DAD8SJ");
    cout <<likeness_score3;
    //test case 4
    double likeness_score4 = calcLikenessScore("HJDKC3", "C3HJDK");
    cout <<likeness_score4;
    //test case 5
    double likeness_score5 = calcLikenessScore("D7H2S4", "H5DTS8C5");
    cout <<likeness_score5;
    return 0;
}