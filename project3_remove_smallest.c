/*
Celina Vo
COP 3514
Problem 2: Remove Smallest
Removes the smallest number of elements in an array specified by user
*/

#include <stdio.h>

int main(){

    int numElements, numRemove;
    int i;
    int find_smallest_index(int array[], int numElements);
    int remove_smallest_numbers(int array[], int numElements, int numRemove);
    int newLength;

    /*reads in number of elements in array*/
    printf("Enter the number of elements in set A: ");
    scanf("%d", &numElements);
    /*declaration of input array*/
    int array[numElements];

    /*reads in numbers of array*/
    printf("Enter the numbers in set A: ");
    for (i = 0; i < numElements; i++)
        scanf("%d", &array[i]);

    printf("Enter the number of smallest elements to be removed: ");
    scanf("%d", &numRemove);

    /*receives length of array to print*/
    newLength = remove_smallest_numbers(array, numElements, numRemove);

    printf("Output: ");
    for (i = 0; i < newLength; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

int find_smallest_index(int array[], int numElements){
    int smallest_index = 0, i;

    /*if encounters an element smaller than the one stored in smallest_index,
    smallest_index takes on that index*/

    for (i = 1; i < numElements; i++){
        if (array[i] < array[smallest_index]) smallest_index = i;
    }
    return smallest_index;
}

int remove_smallest_numbers(int array[], int numElements, int numRemove){
    int newLength = numElements - numRemove;
    int i, smallest_index, k;

    /*repeats removal process for number of elements user wants to remove*/
    for (i = 0; i < numRemove; i++){
        /*find new smallest_index for each removal process*/
        smallest_index = find_smallest_index(array, numElements);

        /*shift all elements to the left starting from the smallest_index*/
        for (k = smallest_index; k < numElements; k++){
            array[k] = array[k+1];
        }

        /*adjust array length*/
        numElements--;
    }
    return newLength;
}
