// CSCI1300 Fall 2021
// Author: Andrew Truong
// Recitation: 118 – Naga Sai Meenakshi Sistla
// Project 1 - Problem # 7


#include <iostream>
#include <string>
using namespace std;

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
        return -1;
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
}

int main()
{
    int choice = 0;
    string seq1;
    string seq2;
    string playerSeq1;
    string playerSeq2;
    string playerSeq3;
    string goldSeq;
    //initialize variables
    
    do //I used do while loop because I want the menu to be printed first and then after it is, the loop starts
    {
        cout << "----Menu!----"<< endl;  
        cout << "Choice 1: Calculate the Likeness Score between 2 strings of equal length." << endl;
        cout << "Choice 2: Calculate the Best Likeness Score between 2 sequences of possibly different length." << endl;
        cout << "Choice 3: Find winner among sequences of 3 players and a Golden Sequence." << endl;
        cout << "Choice 4: Exit." << endl;
        cout << "Enter your choice (1-4):" << endl;
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter Sequence 1" << endl;
            cin >> seq1;
            cout << "Enter Sequence 2" << endl;
            cin >> seq2;
            if (calcLikenessScore(seq1, seq2) != -1) //when the two string lengths ARE equal
            {
                cout << "Score: " << calcLikenessScore(seq1, seq2) << endl;
            }

            else  //when likeness score is returned as '-1'. This is when the two string lengths are NOT equal
            {
                cout << "Invalid input. Sequences of different length." << endl;
            }
        }
        

        else if(choice == 2)
        {
            cout << "Enter Sequence 1" << endl;
            cin >> seq1;
            cout << "Enter Sequence 2" << endl;
            cin >> seq2;
            cout << "Best Likeness Score: " << bestLikenessScore(seq1, seq2) << endl;
        }

        else if(choice == 3)
        {        
            cout << "Enter Sequence of Player 1" << endl;
            cin >> playerSeq1;
            cout << "Enter Sequence of Player 2" << endl;
            cin >> playerSeq2;
            cout << "Enter Sequence of Player 3" << endl;
            cin >> playerSeq3;
            cout << "Enter Golden sequence" << endl;
            cin >> goldSeq;
            findWinner(playerSeq1, playerSeq2, playerSeq3, goldSeq);
        }

        else if(choice == 4)
        {
            cout << "Exiting." << endl;
        }

        else //when choices are anything but 1-4 
        {
            cout << "Invalid Input. Choices between 1-4." << endl;
        }
    
    }
    while (choice !=4); //loop keeps running until they quit, even if they type a number like 100





    return 0;
}

