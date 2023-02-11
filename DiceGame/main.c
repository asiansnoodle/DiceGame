//
//  main.c
//  DiceGame
//
//  Created by Adrian Miro on 2/8/23.
//

#include <stdio.h>
#include "dicegame.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // intitialize rand()
    rand();
    
    // initialize player 1 & 2 points to 0
    int player1Points = 0;
    int player2Points = 0;
    
    // initialize all other variables:
    int numRounds;
    int currentPlayer = (rand() % (2-1+1))+1;
    int diceValue = 0;
    int roundPoints = 0;
    
    // Ask user for how many rounds to run the game:
    printf("Enter the number of rounds: ");
    scanf("%d", &numRounds);
    // Call printPlayerPoints() function to print the initial player points which will be 0
    printPlayerPoints(player1Points, player2Points);
    
    
    // Set up the for loop to go through all the rounds in one go
    for (int i=1; i<=numRounds; ++i){
        printf("\nROUND %d\n--------\n", i);
        printf("Player\t: %d\n", currentPlayer);
        
        // call fn to get the round type
        roundVal = getRoundType();
        // call fn to print a rando num from 1-6, this will serve as the dice value
        diceValue = getRandomNumber(1, 6);
        // call fn to get the amount of points awarded, will depend on round type
        roundPoints = getRoundPoints(roundVal);
        // finally, call printRoundInfo to print this stuff
        printRoundInfo(roundVal, diceValue, roundPoints);
        
        printf("\n");
        
        // set up if statement to check for SUCCESS, odd dice & odd player or even dice & even player
        if (diceValue % 2 != 0 && currentPlayer % 2 != 0){                      // dice is odd and player is odd
            player1Points = player1Points + roundPoints;
        }   // end if SUCCESS odd player
        else if (diceValue % 2 == 0 && currentPlayer % 2 == 0){                 // dice is even and player is even
            player2Points = player2Points + roundPoints;
        }   // end else if SUCCESS even player
        
        // set up if statement to check for FAILURE, odd dice & even player or even dice & odd player
        if (diceValue % 2 == 0 && currentPlayer % 2 != 0){                      // even dice & odd player
            player1Points = player1Points - roundPoints;
            currentPlayer = 2;
        }   // end if FAILURE odd player
        else if (diceValue % 2 != 0 && currentPlayer % 2 == 0){                 // odd dice & even player
            player2Points = player2Points - roundPoints;
            currentPlayer = 1;
        }   // end else if FAILURE even player
        
        // call fn to print player points
        printPlayerPoints(player1Points, player2Points);
        
    }   // end for loop to iterate through rounds
    
    // print game over indicator
    printf("\nGAME OVER!!\n");
    
    // create if else branch to print the winner of the match
    if (player1Points > player2Points){
        printf("P1 Won\n");
    }   // end if P1 winner
    else if (player2Points > player1Points){
        printf("P2 Won\n");
    }   // end else if P2 winner
    
    printf("\n");
    
    return 0;
}   // end main function
