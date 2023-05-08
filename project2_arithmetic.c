/*
Celina Vo
COP 3514
Problem 2: Arithmetic
Calculator for single digit positive numbers with operator +,-,*
*/

#include <stdio.h>

int main(){

char ch = 0, operator = 0;
char ch1 = 0; /*used to determine if int1 has been updated to current character*/
int int1 = 0, int2 = 0, answer = 0;
int invalid = 0;

printf("Enter input: ");
do{
    ch = getchar();
    ch1 = 0;
    if (ch == ' ') continue; /*if character space, skip to next character*/
    if (ch == '\n') break; /*if newline, end input*/
    if (!((ch >= '1' && ch <= '9') || ch == '+' || ch == '-' || ch == '*')){
        invalid = 1;
        break;
        /*if character invalid, make invalid true and break loop*/
    }

    while (int1 == 0){ /*while computer has not determined integer1...*/
        if (ch >= '1' && ch <= '9'){ /*determines if character is valid*/
            switch (ch){
                case '1': int1 = 1;
                    break;
                case '2': int1 = 2;
                    break;
                case '3': int1 = 3;
                    break;
                case '4': int1 = 4;
                    break;
                case '5': int1 = 5;
                    break;
                case '6': int1 = 6;
                    break;
                case '7': int1 = 7;
                    break;
                case '8': int1 = 8;
                    break;
                case '9': int1 = 9;
                    break;
            }
            ch1 = ch; /*lets computer know that int1 has been updated to current character*/
            break;
        }
        else{
            invalid = 1; /*sets invalid to true if character not an integer*/
            break;
        }
    }
    if (int1 != 0 && ch1 == ch) continue; /*if int1 updated, go to next character*/

    while (int1 != 0 && operator == 0){ /*while operator has not been determined but int1 has...*/
        if (ch == '+' || ch == '-' || ch == '*'){
            operator = ch; /*if operator valid, sets operator to character*/
            break;
        }
        else{
            invalid = 1; /*sets invalid to true if character not an operator*/
            break;
        }
    }
    if (int1 != 0 && operator == ch) continue; /*if operator updated to current ch, skip to next character*/

    while (int1 != 0 && operator != 0){ /*while int1 and operator have both been determined...*/
        if (ch >= '0' && ch <= '9'){
            switch (ch){
                case '1': int2 = 1;
                    break;
                case '2': int2 = 2;
                    break;
                case '3': int2 = 3;
                    break;
                case '4': int2 = 4;
                    break;
                case '5': int2 = 5;
                    break;
                case '6': int2 = 6;
                    break;
                case '7': int2 = 7;
                    break;
                case '8': int2 = 8;
                    break;
                case '9': int2 = 9;
                    break;
            }
            break;
        }
        else{
            invalid = 1; /*sets invalid to true if character is not an integer*/
            break;
        }
    }

}
while (ch != '\n'); /*as long as ch is not newline, keeps reading characters*/


if (invalid == 1){
    printf("Invalid operator.");
}
else{
    switch (operator){
        case '+': answer = int1 + int2;
            break;
        case '-': answer = int1 - int2;
            break;
        case '*': answer = int1 * int2;
            break;
    }
    printf("Output: %d\n", answer);
}


return 0;
}