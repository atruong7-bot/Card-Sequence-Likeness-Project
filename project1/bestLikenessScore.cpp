// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 5


#include <iostream>
#include <string>
using namespace std;
/*
* This function finds the best Likeness Score between all the subsequences of a sequence (whose length is greater than or equal to the Golden 
Sequence) and the Golden Sequence. This function finds the maximum possible score a playercould have. 
* Parameters: seq1 (string, length greater than or equal to Golden Sequence) and gold_seq (string, the golden sequence)
* Return: Best Likeness Score
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

double bestLikenessScore(string seq1, string gold_seq)
{
    int goldSeqLength = gold_seq.length();
    double best_likeness_score = 0;
    double likeness_score = 0;
    //initialize variables 
    if(seq1.length() >= gold_seq.length())
    {
        for (int i = 0; i < seq1.length() - (goldSeqLength - 1); i = i + 2) //the amount of subsequences depends on the length of the gold seq
        //as the starting point is iterated to the right by 2
        {
           double likeness_score = calcLikenessScore(seq1.substr(i,goldSeqLength), gold_seq); //seq1.substr gets a subsequence which is compared to the gold_seq
           //then the likeness score is calculated for that subsequence
           if(likeness_score > best_likeness_score)
           {
                best_likeness_score = likeness_score; //since this is in the loop, it checks each time whether the new likeness score is bigger than the
                //previous one, and if it is the best likeness score variable is updated
           }
        }
       
        
    }
    
    else
    {
        best_likeness_score = -1;
    }




    return best_likeness_score;


}



int main()
{
    //test case 1
    double best_likeness_score1 = bestLikenessScore("S7H8SJD9H8CJD9", "H8C6D6");
    cout << best_likeness_score1;
    //test case 2
    double best_likeness_score2 = bestLikenessScore("H8C6D6", "H8C6D6");
    cout << best_likeness_score2;
    // test case 3
    double best_likeness_score3 = bestLikenessScore("SQDTD2SQC7H6HTHJ", "H8C6D6");
    cout << best_likeness_score3;

    return 0;
}