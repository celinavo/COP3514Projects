/*
Celina Vo
COP 3514
Problem 1: Set Difference
Calculates the set difference A - B
*/

#include <stdio.h>

void find_set_difference(int *set_a, int *set_b, int n, int *set_difference);

int main(){
    
    #define RANGE 10 //valid range of numbers 0-9

    int numA, numB;
    int a[RANGE] = {0}, b[RANGE] = {0}, set_difference[RANGE] = {0}; //arrays of 10 0's
    int i, j;

    printf("Enter the number of elements in set A: "); //determines how many values will be inputted by user
    scanf("%d", &numA);

    printf("Enter the numbers in set A: "); //if value inputted by user matches index number, value at that index number set to 1
    for (i = 0; i < numA; i++){
        scanf("%d", &j);
        a[j] = 1;
    }

    printf("Enter the number of elements in set B: "); //determines how many values will be inputted by user
    scanf("%d", &numB);

    printf("Enter the numbers in set B: "); //if value inputted by user matches index number, value at that index number set to 1
    for (i = 0; i < numB; i++){
        scanf("%d", &j);
        b[j] = 1;
    }

    find_set_difference(a, b, RANGE, set_difference); //function call
    
    printf("The difference of set A - B is: ");
    for (i = 0; i < RANGE; i++){
        if (set_difference[i] == 1) printf("%d ", i);
    }
    printf("\n");
    return 0;
}

void find_set_difference(int *set_a, int *set_b, int n, int *set_difference){

    int *p = set_a, *q = set_b, *r = set_difference; //initialization of pointers

    for (p = set_a; p < set_a+RANGE; p++, q++, r++) //for each index value, determine if set_a values do not match set_b values
        if ((*p != *q) && (*p == 1)) *r = 1; //if values at index number are different, value at that index number set to 1
}
