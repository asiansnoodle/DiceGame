//
//  dicegame.c
//  DiceGame
//
//  Created by Adrian Miro on 2/8/23.
//

#include <stdio.h>
#include "dicegame.h"
#include <stdlib.h>

void printPlayerPoints(int player1Pts, int player2Pts){
    printf("P1\t\t: %d\n", player1Pts);
    printf("P2\t\t: %d\n", player2Pts);
}   // end function printPlayerPoints

enum ROUNDTYPE getRoundType(){
    int randNum = (rand() % (10-1+1)) + 1;
    
    if (randNum == 1 || randNum == 2){
        roundVal = BONUS;
    }   // end if
    else if (randNum == 3 || randNum == 4 || randNum == 5){
        roundVal = DOUBLE;
    }   // end else if DOUBLE
    else if (randNum >= 6){
        roundVal = REGULAR;
    }   // end else if REGULAR
    
    return roundVal;
}   // end fn getRoundType

int getRandomNumber(int min, int max){
    int randNum = (rand() % (max-min+1)) + min;
    
    return randNum;
}   // end fn getRandomNumber

int getRoundPoints(enum ROUNDTYPE roundType){
    int points = 0;
    
    if (roundType == REGULAR){
        points = (rand() % (100-10+1)) + 10;
    }   // end if REGULAR
    else if (roundType == BONUS){
        points = 200;
    }   // end else if BONUS
    else if (roundType == DOUBLE){
        points = ((rand() % (100-10+1)) + 10) * 2;
    }   // end else if DOUBLE
    
    return points;
}   // end fn getRoundPoints

void printRoundInfo(enum ROUNDTYPE t, int dice, int points){
    if (t == REGULAR){
        printf("Type\t: REGULAR\n");
    }   // end if REGULAR
    else if (t == BONUS){
        printf("Type\t: BONUS\n");
    }   // end else if BONUS
    else if (t == DOUBLE){
        printf("Type\t: DOUBLE\n");
    }   // end else if DOuBLE
    
    printf("Dice\t: %d\n", dice);
    
    printf("Points \t: %d", points);
}   // end fn printRoundInfo

