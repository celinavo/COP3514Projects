/*
Celina Vo
COP 3514
Problem 1: Dice
Creates a dice game of multiple rounds. Whoever wins the most rounds wins.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

srand(time(NULL));

int upper = 6, lower = 1, num = 0;
int player1die = 0, player2die = 0;
int round = 1, numRounds = 0, player1points = 0, player2points = 0;

printf("Enter the number of rounds: ");
scanf("%d", &numRounds); /*sets number of rounds*/

for (round = 1; round <= numRounds; round++){
/*starting at round 1, continues until round reach final round user specified*/

	printf("Round %d: ", round);
	num = (rand() % (upper - lower + 1)) + lower; /* randomizes number between 1-6 */
	player1die = num; /*sets player1die to random number*/
	printf("Player 1's number is %d, ", player1die);

	num = (rand() % (upper - lower + 1)) + lower;
	player2die = num;
	printf("Player 2's number is %d.\n", player2die);

	if (player1die != player2die){ /*if there is not a draw*/
		if (player1die > player2die) player1points++; /*player 1 wins that round*/
		else player2points++; /*player 2 wins that round*/
		}
	}
if (player1points != player2points){ /*if both players did not win the same amount of rounds*/
	if (player1points > player2points)
		printf("Player 1 wins!\n");
	else printf("Player 2 wins!\n");
	}
else printf("It's a draw!\n");

return 0;
}


