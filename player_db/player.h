#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct {

	/* No.
	*  position
	*  name
	*  three percentages (field-goal, 3-point, and free-throw)
	*/

	int no = 10;
	char name[31] = "", position = 'F';
	double percentages[3] = { 1.0, 1.0, 1.0 };

} Player;

void Output(Player);
void Input(Player *);

#endif