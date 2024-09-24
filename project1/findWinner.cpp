// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 6


#include <iostream>
#include <string>
using namespace std;
/*
* This function finds the Winner among 3 players and displays the winner in the console
* Parameters: 
○ seq1 (string) - Player 1 Sequence
○ seq2 (string) - Player 2 Sequence
○ seq3 (string) - Player 3 Sequence
○ gold_seq (string) - The Golden Sequence
* Return: No return value
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

void findWinner(string seq1, string seq2, string seq3, string gold_seq) 
{ 
    double bestLikenessScore1 = bestLikenessScore(seq1, gold_seq);
    double bestLikenessScore2 = bestLikenessScore(seq2, gold_seq);
    double bestLikenessScore3 = bestLikenessScore(seq3, gold_seq);
    //initialize variables

    //for conditionals, the players get priority first to ensure the correct player(s) is displayed
    //for example, if we wanted to check whether player 1 was equal to player 2 first and they are the same
    //it would say that they both won, without checking player 3, who could be the real winner
    if (bestLikenessScore1 > 0 && bestLikenessScore2 > 0 && bestLikenessScore3 > 0)
    {
        if (bestLikenessScore1 > bestLikenessScore2 && bestLikenessScore1 > bestLikenessScore3)
        {
            cout << "Congratulations Player 1! You have won!" << endl;
        }
        
        else if (bestLikenessScore2 > bestLikenessScore1 && bestLikenessScore2 > bestLikenessScore3)
        {
            cout << "Congratulations Player 2! You have won!" << endl;
        }

        else if (bestLikenessScore3 > bestLikenessScore1 && bestLikenessScore3 > bestLikenessScore2)
        {
            cout << "Congratulations Player 3! You have won!" << endl;
        }

        else if (bestLikenessScore1 == bestLikenessScore2  && bestLikenessScore1 == bestLikenessScore3)
        {
            cout << "Congratulations everyone! You have all won!" << endl;
        }

        else if (bestLikenessScore1 == bestLikenessScore2)
        {
            cout << "Congratulations Players 1 and 2! You have won!" << endl;
        }

        else if (bestLikenessScore1 == bestLikenessScore3)
        {
            cout << "Congratulations Players 1 and 3! You have won!" << endl;
        }

        else if (bestLikenessScore2 == bestLikenessScore3)
        {
            cout << "Congratulations Players 2 and 3! You have won!" << endl;
        }
    }

    else if (bestLikenessScore1 == 0 && bestLikenessScore2 == 0 && bestLikenessScore3 == 0)
    {
        cout << "Better luck next time everyone!" << endl;
    }

    //no return statement since type is void
}

int main()
{
    //test case 1: All players with a score of 0:
    findWinner("CAH7S5CJCK", "S7H9SQCA", "H2S6H7CTS9HK", "D4D5D6");
    //test case 2: All players with same Best Likeness Score:
    findWinner("DAH7S5CJ", "S7H9DQCA", "H2S6CTD7", "D4D5D6");
    //test case 3: Two players with same Best Likeness Score:
    findWinner("DAH7S5CJ", "S7D2DQCAH7", "H2DTCTD7S8C5", "DTD2D3");



    return 0;
}