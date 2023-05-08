/*
Celina Vo
COP 3514
Problem 1: Mutually Disjoint and Symmetric Difference
Determines if values overlap between the sets (mutally disjoint)
Gives the values that are different between the two sets
*/

#include <stdio.h>

int are_mutually_disjoint(int *set_a, int *set_b, int n);
void find_symmetric_difference(int *set_a, int *set_b, int n, int *symmetric_difference);

int main(){
    
    #define RANGE 10 //valid range of numbers 0-9

    int numA, numB;
    int a[RANGE] = {0}, b[RANGE] = {0}, symmetric_difference[RANGE] = {0}; //arrays of 10 0's
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

    int not_statement;
    // function calls
    not_statement = are_mutually_disjoint(a, b, RANGE);
    find_symmetric_difference(a, b, RANGE, symmetric_difference);
    
    if (not_statement == 0) printf("The two sets are NOT mutually disjoint.\n");
    else printf("The two sets are mutually disjoint.\n");

    printf("The symmetric difference is: ");
    for (i = 0; i < RANGE; i++){
        if (symmetric_difference[i] == 1) printf("%d ", i);
    }
    printf("\n");
    return 0;
}

int are_mutually_disjoint(int *set_a, int *set_b, int n){

    int *p = set_a, *q = set_b; //initialization of pointers
    int flag = 1;

    for (p = set_a; p < set_a+RANGE; p++, q++) //if encounters a match between the sets, set mutually disjoint to false
        if (*p == *q) flag = 0;
    
    return flag;
}

void find_symmetric_difference(int *set_a, int *set_b, int n, int *symmetric_difference){

    int *p = set_a, *q = set_b, *r = symmetric_difference; //initialization of pointers

    for (p = set_a; p < set_a+RANGE; p++, q++, r++) //for each index value, determine if set_a values do not match set_b values
        if (*p != *q) *r = 1; //if values at index number are different, value at that index number set to 1
}