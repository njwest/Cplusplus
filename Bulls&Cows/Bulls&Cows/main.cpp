//
//  main.cpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// App entrypoint
int main()
{
    do{
        PrintIntro();
        PlayGame();
    }
    while (AskToPlayAgain());
    return 0;
}


void PrintIntro() {
    constexpr int WORD_LENGTH = 5;
    
    std::cout << "Welcome to Bulls and Cows!\n" << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}


void PlayGame() {
    
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    // TODO Change from FOR to WHILE loop once we set validate guess logic
    for (int count = 1; count <= MaxTries; count++) {
        
        std::string Guess = GetGuess(); // TODO Validate Guess
        
        // TODO submit valid guess to the game
        // print number of bulls and cows
        
        std::cout << "Your guess was: " << Guess << std::endl;
    }
    
    // TODO summarise game
}


std::string GetGuess() {
    int CurrentTry = BCGame.GetCurrentTry();
    std::string Guess = "";
    std::cout << std::endl << "Try " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin,Guess);
    
    return Guess;
}

bool AskToPlayAgain() {
    std::string Response = "";
    std::cout << "Do you want to play again (y/n)?";
    std::getline(std::cin,Response);
    
    return (Response[0] == 'y' || Response[0] == 'Y');
}


