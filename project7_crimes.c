/*
Celina Vo
COP 3514
Project 7
Given the name of a crime data file, sorts states by rate of crime in descending order
*/

#include <stdio.h>
#define MAXSTATES 100
#define STATESCHAR 150

struct state{ //declaration of struct
    char name[STATESCHAR];
    int population;
    double rateAssault;
    double rateMurder;
    double rateRape;
    double rateRobbery;
    double totalRate; //value will be computed by compute_total function
};

//function prototypes
void *strcat(char *s1, char *s2);
void *strcpy(char *s1, char *s2);
void compute_total(struct state list[], int n);
void sort_states(struct state list[], int n);
void reverse(struct state list[], int n);

int main(){

    FILE *inputFile;
    char inputFileName[1000];
    FILE *outputFile;
    char outputFileName[] = "sorted_"; //concatenate to file name
    int numStates = 0, i;

    char tempName[STATESCHAR]; //variables for temp storage of struct values
    int tempPopulation;
    double tempAssault, tempMurder, tempRape, tempRobbery;

    printf("Enter the file name: "); //opening input file
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r"); //input file open
    if (inputFile == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    struct state list[MAXSTATES]; //create struct array

    for (i = 0; i < MAXSTATES; i++){
        if (feof(inputFile) || ferror(inputFile)) break;
        fscanf(inputFile, "%[^,], %d, %lf, %lf, %lf, %lf\n", list[i].name, &list[i].population, &list[i].rateAssault, &list[i].rateMurder, &list[i].rateRape, &list[i].rateRobbery);
        numStates++; //counts the number of states in file
    }

    compute_total(list, numStates); //computes total of all violent crimes for each state in struct array
    sort_states(list, numStates); //sorts states by totalRate in ascending order
    reverse(list, numStates); //reverses the array to be in descending order

    strcat(outputFileName, inputFileName); //append sorted_ to new file name
    outputFile = fopen(outputFileName, "w"); //create output file
    for (i = 0; i < numStates; i++){
        strcpy(tempName, list[i].name); //hold values within struct
        tempPopulation = list[i].population;
        tempAssault = list[i].rateAssault;
        tempMurder = list[i].rateMurder;
        tempRape = list[i].rateRape;
        tempRobbery = list[i].rateRobbery;
        fprintf(outputFile, "%s, %d, %.1lf, %.1lf, %.1lf, %.1lf\n", tempName, tempPopulation, tempAssault, tempMurder, tempRape, tempRobbery);
    }
    printf("Output file: %s\n", outputFileName);

    return 0;
}
//computes the total rate of crime for each state and stores that data within the state's struct
void compute_total(struct state list[], int n){ //n is nunStates
    double tempAssault, tempMurder, tempRape, tempRobbery; //variables to hold values in struct
    double tempTotal;
    int i;
    for(i = 0; i < n; i++){ //puts values in struct in temporary variables to compute tempTotal
        tempAssault = list[i].rateAssault;
        tempMurder = list[i].rateMurder;
        tempRape = list[i].rateRape;
        tempRobbery = list[i].rateRobbery;
        tempTotal = tempAssault + tempMurder + tempRape + tempRobbery;
        list[i].totalRate = tempTotal; //puts value of tempTotal in struct
    }
}
//sorts each state by their total rate of crime in ascending order
void sort_states(struct state list[], int n){ //n is numStates
    int i, largest = 0;
    double testValue, largestValue;
    struct state temp;

    if (n == 1) return;

    
    for(i = 1; i < n; i++){
        testValue = list[i].totalRate;
        largestValue = list[largest].totalRate;
        if (testValue > largestValue) largest = i;
    }

    if(largest < (n-1)){
        temp = list[n-1];
        list[n-1] = list[largest];
        list[largest] = temp;
    }
    sort_states(list, n-1);
}
//reverses the order of an array so it is in descending order
void reverse(struct state list[], int n){
    int i = 0, j = (n-1);
    struct state temp;
    while (i < j){
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
        i++;
        j--;
    }
}