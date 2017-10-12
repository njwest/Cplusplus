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

struct FBullCowCount
{
    // all values initialized to zero
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid,
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Length
};

class FBullCowGame
{
public:
    FBullCowGame(); //constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    FString GetHiddenWord(FString) const;
    
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;

    void Reset(); //TODO make a richer return value

    FBullCowCount SubmitValidGuess(FString Guess);
    
private:
    // see constructor for initial val
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bHasWon;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};
#endif /* FBullCowGame_hpp */
