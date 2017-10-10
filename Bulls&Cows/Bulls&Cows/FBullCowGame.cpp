//
//  FBullCowGame.cpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
    Reset();
}

int FBullCowGame::GetMaxTries() const{
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const{
    return MyCurrentTry;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
    return 0;
}


bool FBullCowGame::IsGameWon() const{ 
    return 0;
}


void FBullCowGame::Reset() { 
    constexpr int MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    MyCurrentTry = 1;
 
    return;
}

