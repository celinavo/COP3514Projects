/*
Celina Vo
COP 3514
Problem 1: Dice
Simulates a dice game between two players. Whoever rolls the highest number wins
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

srand(time(NULL));

int upper = 6, lower = 1, num = 0;
int player1die = 0, player2die = 0; /*initializing variables*/

num = (rand() % (upper - lower + 1)) + lower; /*randomizes number between 1-6*/
player1die = num; /*sets player1die to random number*/
printf("Player 1's number is %d, ", player1die);

num = (rand() % (upper - lower + 1)) + lower; /*performs same operation for player2*/
player2die = num;
printf("Player 2's number is %d. ", player2die);

if (player1die != player2die) /*checks if there is not a draw*/
	if (player1die > player2die) /*checks if player1 has higher number than player2*/
		printf("Player 1 wins!\n");
	else printf("Player 2 wins!\n");
else printf("It's a draw!\n");

return 0;
}
