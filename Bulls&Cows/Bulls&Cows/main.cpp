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
FText GetValidGuess();
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
    std::cout << "Welcome to Bulls and Cows!\n" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}


void PlayGame(){
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    for (int32 count = 1; count <= MaxTries; count++) {     // TODO Change from FOR to WHILE loop
        FText Guess = GetValidGuess(); // TODO Validate Guess
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
        
    }
    
    // TODO summarise game
}


FText GetValidGuess() { // loop until the user gives a valid guess
    EGuessStatus Status = EGuessStatus::Invalid;
    
    do{
        int32 CurrentTry = BCGame.GetCurrentTry();
        FText Guess = "";
        std::getline(std::cin,Guess);
        
        std::cout << std::endl << "Try " << CurrentTry << ". Enter your guess: ";
        
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
            default:
                return Guess;
        }
    } while(Status != EGuessStatus::OK); // keep looping until we get no errors

    std::cout << std::endl;
    
}

bool AskToPlayAgain() {
    FText Response = "";
    std::cout << "Do you want to play again (y/n)?";
    std::getline(std::cin,Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}


