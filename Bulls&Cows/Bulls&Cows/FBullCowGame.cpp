//
//  FBullCowGame.cpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//

#include "FBullCowGame.hpp"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
    
    if (false) {
        return EGuessStatus::Not_Isogram;
    } else if (false) {
        return EGuessStatus::Not_Lowercase;
    } else if (GetHiddenWordLength() != Guess.length()) {
        return EGuessStatus::Wrong_Length;
    } else{
        return EGuessStatus::OK;
    }
}

bool FBullCowGame::IsGameWon() const{ 
    if(bHasWon){
        return 1;
    } else {
        return 0;
    };
}


void FBullCowGame::Reset() { 
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord =  HIDDEN_WORD;
    MyCurrentTry = 1;
    bHasWon = 0;
    return;
}

// receives a valid guess, increments turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess){
   
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = GetHiddenWordLength();
    
    // loop through all letters in the guess and the hidden word
    for (int32 i = 0; i < WordLength; i++) {
            if (MyHiddenWord[i] == Guess[i]){
                BullCowCount.Bulls++;
            } else {
            for (int32 j = 0; j < WordLength; j++) {
                if (MyHiddenWord[j] == Guess[i]) {
                BullCowCount.Cows++;
                }
            }
        }
    }
    /* alternative method
     for (int32 i = 0; i < HiddenWordLength; i++) {
         for (int32 j = 0; j < HiddenWordLength; j++){
             if(Guess[j] == MyHiddenWord[i]) {
                 if (i == j) {
                     BullCowCount.Bulls++;
                 } else {
                     BullCowCount.Cows++;
                 }
             }
         }
     }
    */
    
    if(BullCowCount.Bulls == WordLength){
        bHasWon = 1;
    }

    return BullCowCount;
}





