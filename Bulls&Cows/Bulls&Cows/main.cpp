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
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

// Unreal syntax substitutions
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void GetWord();
FText GetValidGuess();
void GameOver();
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
    
    std::cout << "**************************\nWelcome to Bulls and Cows!\n**************************\n" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

// Plays a single game to completion
void PlayGame() {
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){

        FText Guess = GetValidGuess(); // TODO Validate Guess
        
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
        
    }
    
    GameOver();
    return;
}

void GameOver() {
    if(BCGame.IsGameWon()){
        std::cout << "\nCorrect! You won!\n";
    } else{
        std::cout << "\nGame over, you're out of guesses!\n";
    }
    return;
}

void GetWord() {
    FText LengthInput;
    std::cout << std::endl << "With what length of hidden isogram would you like to play?\nOptions: 3, 4, 5, 6, 7\n\n" << "Enter a number between 3 and 7: ";
    
    std::getline(std::cin,LengthInput);
    
    BCGame.GetHiddenWord(LengthInput);
    
    return;
}

FText GetValidGuess() { // loop until the user gives a valid guess
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid;

    do{
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << std::endl << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
        std::cout << ". Enter your guess: ";

        std::getline(std::cin,Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram (a word with no repeating letters).\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
            default:
                // assume the guess is valid
                break;
        }
    } while(Status != EGuessStatus::OK); // keep looping until we get no errors

    std::cout << std::endl;

    return Guess;

}

bool AskToPlayAgain() {
    FText Response = "";
    std::cout << "\nDo you want to play again (y/n)?";
    std::getline(std::cin,Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
}
