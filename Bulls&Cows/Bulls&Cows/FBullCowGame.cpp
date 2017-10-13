//
//  FBullCowGame.cpp
//  Bulls&Cows
//
//  Created by Nick on 10/10/17.
//  Copyright © 2017 PangLong. All rights reserved.
//
#pragma once

#include "FBullCowGame.hpp"
#include <map>

// Unreal syntax
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // Default constructor

int32 FBullCowGame::GetCurrentTry() const{ return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const{ return bHasWon; }

int32 FBullCowGame::GetMaxTries() const{
    TMap<int32, int32> WordLengthToMaxTries { {3,5}, {4,7}, {5,10}, {6,13}, {7,20} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
    
    if (!IsIsogram(Guess)) {
        return EGuessStatus::Not_Isogram;
    } else if (!IsLowercase(Guess)) {
        return EGuessStatus::Not_Lowercase;
    } else if (GetHiddenWordLength() != Guess.length()) {
        return EGuessStatus::Wrong_Length;
    } else{
        return EGuessStatus::OK;
    }
}

bool FBullCowGame::IsIsogram(FString Word) const {
    // treat 0 and 1 letter words as isograms
    if (Word.length() <= 1) { return true; }
    
    // set up our map
    TMap<char, bool> LetterSeen;
    
    for (auto Letter : Word){
        Letter = tolower(Letter);
        
        if (LetterSeen[Letter]){
            return false;
        } else{
            LetterSeen[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
    
    for (auto Letter : Word){
        if (!islower(Letter)){
            return false;
        }
    }
    return true;
}


void FBullCowGame::Reset() {
    const FString HIDDEN_WORD = "planet"; //This MUST be an isogram
    MyHiddenWord = HIDDEN_WORD;
    
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

FString FBullCowGame::GetHiddenWord(FString LengthInput) const {
    auto MyHiddenWord = "";
    if (LengthInput == "3"){
         MyHiddenWord = "bat";
    } else if (LengthInput == "4"){
        MyHiddenWord = "gore";
    } else if (LengthInput == "5"){
        MyHiddenWord = "tombs";
    } else if (LengthInput == "6"){
        MyHiddenWord = "darken";
    } else if (LengthInput == "7"){
        MyHiddenWord = "vampire";
    } else{
        MyHiddenWord = "unloaded";
    }
    
    return MyHiddenWord;
}
