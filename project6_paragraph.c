/*
Celina Vo
COP 3514
Project 6
Given the name of a file, removes newline characters and replaces with ' '
*/

#include <stdio.h>
#define FILE_LEN 100
#define STRING_LEN 10000

void convert(char *s1, char *s2);
void clear_string(char *s2);
void *strcat(char *s1, char *s2);

int main(){

    FILE *inputFile;                        //pointer to file
    char inputFileName[FILE_LEN];           //array of input string
    FILE *outputFile;                       //pointer to new file
    char outputFileName[FILE_LEN] = "new_"; //string to be added onto input string
    char string1[STRING_LEN];
    char string2[STRING_LEN];


    printf("Enter the file name: "); //get input file
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r"); //error when cannot open file
    if (inputFile == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    strcat(outputFileName, inputFileName); //string lib function in main to create new file name

    outputFile = fopen(outputFileName, "w"); //open file to write

    while (fgets(string1, STRING_LEN, inputFile) != NULL){ //gets line of text from input file and stores in string1
        convert(string1, string2); //removes newline character and replaces with ' '
        fputs(string2, outputFile); //writes modified string into output file
        clear_string(string2); //resets string2 to be empty
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File %s written.\n", outputFileName);
    
    return 0;
}

void convert(char *s1, char *s2){
    char *p, *q;
    for (p = s1, q = s2; *p != '\n'; p++, q++){
        *q = *p;
    }
    *q = ' ';
}

//function resets string entered in parameter to be empty.
void clear_string(char *s2){
    char *p;
    for (p = s2; *p != '\0'; p++) *p = '\0';
}