/*
Celina Vo
COP 3514
Project 8
Creates student database; can add student, search student, print students, and quit program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define INSTRUMENT_LEN 30
#define GROUP_LEN 30

struct student{
    char first[NAME_LEN + 1];
    char last[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    char instrument[INSTRUMENT_LEN + 1];
    char group[GROUP_LEN + 1];
    struct student *next;
};

//function prototypes
struct student *add(struct student *list);
void search(struct student *list);
void print_list(struct student *list);
void clear_list(struct student *list);
int read_line(char str[], int n);
void clear_string(char *string); //sets all characters in a string to null characters

int main(){
    char code;

    struct student *student_list = NULL; //list initially empty
    printf("Operation code:\n");
    printf("a for adding to the list;\n");
    printf("s for searching\n");
    printf("p for printing the list\n");
    printf("q for quit\n");

    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        printf("\n");

        while (getchar() != '\n'); //skips to end of the line

        switch(code){
            case 'a':
                student_list = add(student_list); //needs to return address of original list
                break;
            case 's':
                search(student_list);
                break;
            case 'p':
                print_list(student_list);
                break;
            case 'q':
                clear_list(student_list);
                return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct student *add(struct student *list){
    
    char name_buffer[31], email_buffer[101];
    struct student *current, *current2, *current3; //pointer of type struct, used to examine array

    struct student *new_student; //pointer of type struct, used to hold new node
    new_student = malloc(sizeof(struct student)); //allocate mem for new student to store data
    
    if (new_student == NULL){ //if unable to allocate mem for student
        printf("Cannot add student.");
        return list;
    }

    printf("Enter last name: ");
    read_line(name_buffer, 30);
    strcpy(new_student->last, name_buffer);
    clear_string(name_buffer);

    printf("Enter first name: ");
    read_line(name_buffer, 30);
    strcpy(new_student->first, name_buffer);
    clear_string(name_buffer);

    printf("Enter email address: ");
    read_line(email_buffer, 30);
    strcpy(new_student->email, email_buffer);

    printf("Enter instrument: ");
    read_line(name_buffer, 30);
    strcpy(new_student->instrument, name_buffer);
    clear_string(name_buffer);

    printf("Enter group: ");
    read_line(name_buffer, 30);
    strcpy(new_student->group, name_buffer);
    clear_string(name_buffer);

    //check whether student already exists
    for (current = list; current != NULL; current = current->next){ //current takes on each node to examine last name
        if (current != NULL && (strcmp(current->last, new_student->last) == 0)){
            for (current2 = list; current2 != NULL; current2 = current2->next){ //current takes on each node to examine email
                if (current2 != NULL && (strcmp(current2->email, new_student->email) == 0)){ //if last name and email match...
                    printf("Student already exists.\n");
                    free(new_student); //deallocate memory for new_student
                    return list;
                }
            }
        }
    }

    if (list == NULL){ //if list already empty, new_student becomes first node in list
        list = new_student;
    }
    else{ //add new_student to the end of the linked list
        for (current3 = list; current3 != NULL; current3 = current3->next){
            if (current3->next == NULL){ //when reached the end of the linked list
                current3->next = new_student;
                break;
            }
        }
    }

    return list; //returns pointer to linked list
}

void search(struct student *list){
    
    char name_buffer[31];
    struct student *target, *current, *current2;
    int flag = 0;

    target = malloc(sizeof(struct student));

    printf("Search last name: ");
    read_line(name_buffer, 30);
    strcpy(target->last, name_buffer);
    clear_string(name_buffer);

    printf("Search first name: ");
    read_line(name_buffer, 30);
    strcpy(target->first, name_buffer);
    clear_string(name_buffer);

    for (current = list; current != NULL; current = current->next){ //for loop searches last names
        if(current != NULL && (strcmp(current->last, target->last) == 0)){ //if match...
            for (current2 = list; current2 != NULL; current2 = current2->next){ //for loop searches first names
                if(current2 != NULL && (strcmp(current2->first, target->first) == 0)){ //if match, print names
                    printf("Last: %-15s First: %-15s Email: %-30s Instrument: %-10s Group: %-10s\n", current2->last, current2->first, current2->email, current2->instrument, current2->group);
                    flag = 1; //indicates program found matching names
                }
            }
        break;
        }
    }

    if (flag == 1){
        free(target);
        return;
    }
    else{ //if program did not find matching names
        printf("Could not find student.\n");
        free(target);
        return;
    }
}

void print_list(struct student *list){
    struct student *current;
    for (current = list; current != NULL; current = current->next){
        printf("Last: %-15s First: %-15s Email: %-30s Instrument: %-10s Group: %-10s\n", current->last, current->first, current->email, current->instrument, current->group);

    }
}
void clear_list(struct student *list){
    struct student *current;
    while (list != NULL){
        current = list;
        list = list->next;
        if(current != NULL) free(current);
    }
}

int read_line(char str[], int n){
    int ch, i = 0;
    while (isspace(ch = getchar())); //skip preceding whitespace
    str[i++] = ch;
    while ((ch = getchar()) != '\n'){
        if (i < n) str[i++] = ch;
    }
    str[i] = '\0';
    return i; //returns number of characters in string
}
void clear_string(char *string){
    char *p;
    for (p = string; *p != '\0'; p++) *p = '\0';
}
