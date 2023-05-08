/*
Celina Vo
COP 3514
Problem 2: Arithmetic
Modification of Project 2: Problem 2
Calculator for single digit positive number with operator +, -, *.
*/

#include <stdio.h>

int charToInt(char ch);

int main(int argc, char *argv[]){

    int int1, int2, answer;
    
    if (argc != 4){ //if incorrect number of arguments entered, terminates program
        printf("Error\n");
        return 0;
    }

    if (*argv[1] >= '0' && *argv[1] <= '9') //if argument2 is valid character 1-9, converts to integer
        int1 = charToInt(*argv[1]);
    else printf("Invalid integer\n");

    if (*argv[3] >= '0' && *argv[3] <= '9') //if argument4 is a valid character 1-9, converts to integer
        int2 = charToInt(*argv[3]);
    else printf("Invalid integer\n");

    if (*argv[2] == '+' || *argv[2] == '-'|| *argv[2] == '*'){ //if argument3 is a valid operator, performs calculation
        switch (*argv[2]){
            case '+': answer = int1 + int2;
                printf("The addition is %d\n", answer);
                break;
            case '-': answer = int1 - int2;
                printf("The subtraction is %d\n", answer);
                break;
            case '*': answer = int1 * int2;
                printf("The multiplication is %d\n", answer);
                break;
        }
    }
    else printf("Unrecognized operator\n");


    return 0;
}

/*
charToInt converts character 1-9 to integer.
parameter is character, return value is integer.
*/
int charToInt(char ch){ 
    int num;
    switch (ch){
        case '1': num = 1;
            break;
        case '2': num = 2;
            break;
        case '3': num = 3;
            break;
        case '4': num = 4;
            break;
        case '5': num = 5;
            break;
        case '6': num = 6;
            break;
        case '7': num = 7;
            break;
        case '8': num = 8;
            break;
        case '9': num = 9;
            break;
    }
    return num;
}