/*
Celina Vo
COP 3514
Problem 1: Parity
Checks if the parities of the elements match the parities of their indices
*/

#include <stdio.h>

int main(){

int length = 0, i = 0;
int pair_match = 0;
int do_not_match = 0;
int check_parity(int index, int value);

printf("Enter the length of the array: ");
scanf("%d", &length);

int array[length];

printf("Enter the elements of the array: ");
for (i = 0; i < length; i++){
	scanf("%d", &array[i]);

	pair_match = check_parity(i, array[i]); /*stores truth value if parities match*/	

	if (pair_match == 0) do_not_match = 1;
	/*if encounters an index/value pair that do not have matching parities, sets do_not_match to true*/
}
if (do_not_match == 1)
	printf("Parities of elements DO NOT match parities of indices.\n");
else printf("Parities of elements match parities of indices.\n");
return 0;
}

int check_parity(int index, int value){
	/*function to check if index parity matches value parity*/
	/*if parities match, returns 1*/

	int even_index = 0, even_value = 0;
	
	if ((index % 2) == 0) even_index = 1;
	if ((value % 2) == 0) even_value = 1;

	if (even_index == even_value) return 1;
	else return 0;
	

}
