//
//  FBullCowGame.hpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//
#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    bool CheckGuessValidity(FString) const;

    void Reset(); //TODO make a richer return value

    FBullCowCount SubmitGuess(FString Guess);
    
private:
    // see constructor for initial val
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif /* FBullCowGame_hpp */
