I've updated the description to reflect that the execution file is named `sequenceOfCards.cpp`. Here's the final version:

---

# Card Sequence Likeness Project

This repository contains a C++ project that implements a card game where players try to match their sequence of cards against a golden sequence picked by a host. The project involves multiple components to calculate likeness scores, determine the best sequence, and find the overall winner among players. Each function has been tested and is designed to adhere to the rules of the game as described below.

## Project Overview

Players pick a sequence of cards from a standard deck of 52 cards, consisting of four suits: Spades (♠), Hearts (♥), Diamonds (♦), and Clubs (♣), with 13 ranks in each suit (Ace through King). The goal of the game is to compare each player’s card sequence to the host’s “golden sequence” and compute a Likeness Score. The game rewards players who closely match the suits and ranks of the golden sequence.

### Key Game Mechanics:
1. **Card Sequence Formation**: Players pick up to 10 cards, which form their sequence. Each card is represented by its suit and rank.
   - E.g., Ace of Diamonds, 5 of Hearts, Ten of Spades becomes: `DAH5ST`
   
2. **Likeness Score**: The Likeness Score is calculated by comparing each player’s sequence with the golden sequence. The score takes into account:
   - Matching suits
   - Matching ranks (with bonus points)

## Project Files

- **`bestLikenessScore.cpp`**: Implements a function to find the best likeness score among all subsequences of a player's card sequence.
- **`calcLikenessScore.cpp`**: Implements a function to calculate the likeness score between two card sequences.
- **`findWinner.cpp`**: Implements the logic to find the winner with the highest likeness score among three players.
- **`isConsonant.cpp`** & **`numConsonant.cpp`**: Functions for unrelated string manipulation tasks, used for consonant counting.
- **`sequenceOfCards.cpp`**: The main execution file that ties together all the card sequence-related functions to simulate the full game.
- **`reverse.cpp`**: Utility function for reversing a sequence of cards.
- **`project1.pdf`**: Project documentation with a detailed description of the game rules and function specifications.

## How to Run

To run the project, compile all the relevant `.cpp` files together and execute the program using a C++ compiler. Example:

```bash
g++ sequenceOfCards.cpp -o cardgame
./cardgame
```

### Likeness Score Calculation

The Likeness Score is calculated using this formula:

```text
Likeness Score = (Number of Cards with the Same Suit / Total Number of Cards)
               + (1 * Number of Cards with Same Suit and Rank)
```

Example inputs and their likeness scores:
- Player's sequence: `S7H8CJD9HA`
- Golden sequence: `S7H8CJD9HA`
- Likeness score: 6

More details about how the score is calculated and examples can be found in the project documentation (`project1.pdf`).

## Function Descriptions

### calcLikenessScore()

This function calculates the likeness score between two sequences of equal length based on suit and rank matching. If the sequences are of different lengths, it returns `-1`.

### bestLikenessScore()

This function finds the best likeness score by evaluating all possible subsequences from the player's sequence.

### findWinner()

This function compares the likeness scores of three players and determines the winner with the highest likeness score to the golden sequence.

---
