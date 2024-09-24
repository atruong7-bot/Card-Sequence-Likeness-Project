
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
<img width="938" alt="Screenshot 2024-09-24 at 4 15 26 PM" src="https://github.com/user-attachments/assets/7ee6f2e7-40fe-4e84-8565-f940f0e1781d">
<img width="861" alt="Screenshot 2024-09-24 at 4 15 43 PM" src="https://github.com/user-attachments/assets/3bf98cbd-a41c-471f-8ca4-61910301bbeb">
<img width="981" alt="Screenshot 2024-09-24 at 4 15 51 PM" src="https://github.com/user-attachments/assets/c20e75cf-4a61-425e-bf5e-4ea528ee71ff">
<img width="901" alt="Screenshot 2024-09-24 at 4 16 02 PM" src="https://github.com/user-attachments/assets/1e23ba35-dc8c-49cd-8ed4-b39a13274ca6">
<img width="903" alt="Screenshot 2024-09-24 at 4 26 12 PM" src="https://github.com/user-attachments/assets/45dfd49d-e6ee-4ca9-9796-ebf37c8b1ee7">

