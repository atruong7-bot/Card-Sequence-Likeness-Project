This repository contains a C++ project that implements a card game where players try to match sequences of cards against a golden sequence. The project includes various functions to calculate likeness scores between the player's sequence and the golden sequence, find the best likeness score, and determine the winner among the players.

## Project Files
- `bestLikenessScore.cpp`: Finds the best likeness score among subsequences.
- `calcLikenessScore.cpp`: Calculates the likeness score between two sequences.
- `findWinner.cpp`: Determines the winner among three players based on the best likeness score.
- `isConsonant.cpp` and `numConsonant.cpp`: Helper functions to determine consonants in a string.
- `sequenceOfCards.cpp`: Contains the main function that ties all the functions together.
- `reverse.cpp`: A utility function for reversing strings.
- `project1.pdf`: Detailed project description and specifications.

## How to Run
1. Compile the code using your preferred C++ compiler (e.g., g++, clang++).
2. Run the program by calling the main function from `sequenceOfCards.cpp`.

## Example:
To compile and run:
```bash
g++ sequenceOfCards.cpp -o cardgame
./cardgame
