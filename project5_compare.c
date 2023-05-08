/*
Celina Vo
COP 3514
Problem 1: Compare
Creation of string comparison function that ignores letter case
*/

#include <stdio.h>
#define stringLen 1000

int compare(char *string1, char *string2);
int read_line(char *str, int n);
int tolower(int character);

int main(){

    char string1[stringLen];
    char string2[stringLen];
    int comparison;

    printf("Enter first string: "); //retrieves first string
    read_line(string1, stringLen);
    printf("Enter second string: "); //retrieves second string
    read_line(string2, stringLen);

    comparison = compare(string1, string2); //performs string comparison
    printf("%d\n", comparison); 

    return 0;
}

/*
read_line puts characters in array until encounters newline character.
parameter is string, return value is integer.
modifies string parameter to contain string characters.
*/
int read_line(char *str, int n){
    int ch, i = 0; 
    while ((ch = getchar()) != '\n'){
        if (i < n){
            *str++= ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}

/*
compare function compares each character of same index.
parameter is two strings, return value is integer.
*/
int compare(char *string1, char *string2){
    char *p = string1, *q = string2;
    char string1Char, string2Char;

    while (*p != '\0'){
        string1Char = tolower(*p); //if character is uppercase, converts character to lowercase
        string2Char = tolower(*q);

        if (string1Char == string2Char){ //if characters are the same, continue onto next character
            p++;
            q++;
            continue;
        }
        if (string1Char != string2Char){ //if characters are different...
            if (string1Char > string2Char) return 1; //...string2 is less than string1: print 1 
            if (string1Char < string2Char) return -1; //...string1is less than string2: print -1
        }
    }
    return 0; //if all chacacters are the same, print 0
}