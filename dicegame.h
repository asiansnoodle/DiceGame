//
//  dicegame.h
//  DiceGame
//
//  Created by Adrian Miro on 2/8/23.
//

#ifndef dicegame_h
#define dicegame_h

enum ROUNDTYPE {BONUS, DOUBLE, REGULAR};
enum ROUNDTYPE roundVal;

void printPlayerPoints(int, int);

enum ROUNDTYPE getRoundType(void);

int getRandomNumber(int, int);

int getRoundPoints( enum ROUNDTYPE);

void printRoundInfo( enum ROUNDTYPE, int, int );

#endif /* dicegame_h */
