//
//  main.cpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//

/* This is the console executable that makes use of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all
 user interaction. For game logic, see the FBullCowGame class.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// App entrypoint
int32 main()
{
    do{
        PrintIntro();
        PlayGame();
    }
    while (AskToPlayAgain());
    return 0;
}


void PrintIntro() {
    constexpr int32 WORD_LENGTH = 5;
    
    std::cout << "Welcome to Bulls and Cows!\n" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}


void PlayGame() {
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // TODO Change from FOR to WHILE loop once we set validate guess logic
    for (int32 count = 1; count <= MaxTries; count++) {
        
        FText Guess = GetGuess(); // TODO Validate Guess
        
        // submit valid guess, receive counts
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print number of bulls and cows
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
        
    }
    
    // TODO summarise game
}


FText GetGuess() {
    int32 CurrentTry = BCGame.GetCurrentTry();
    FText Guess = "";
    std::cout << std::endl << "Try " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin,Guess);
    
    return Guess;
}

bool AskToPlayAgain() {
    FText Response = "";
    std::cout << "Do you want to play again (y/n)?";
    std::getline(std::cin,Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}


