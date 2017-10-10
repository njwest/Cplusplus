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

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset(); //TODO make a richer return value
    bool CheckGuessValidity(std::string);
    // provide a method for counting bulls and cows, and incrementing try number
private:
    // see constructor for initial val
    int MyCurrentTry;
    int MyMaxTries;
};

#endif /* FBullCowGame_hpp */
