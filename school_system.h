
#ifndef SCHOOL_SYSTEM_H
#define SCHOOL_SYSTEM_H
#include "school_system.h"
#include "STD_TYPES.h"

// Structure to store student details
struct Student {
    char name[50];
    char dateOfBirth[20];
    int id;
    char address[100];
    char phoneNumber[15];
    float computerScienceScore;
    struct Student* next; // Pointer to the next student in the list
};

void MAIN_MENU();
struct Student* NEW_STUDENT(struct Student* head, int* numStudents);
struct Student* DELETE_STUDENT(struct Student* head, int* numStudents, int targetID);
void STUDENT_LIST(struct Student* head);
void STUDENT_EDIT(struct Student* head, int targetID);
void RANK_STUDENT(struct Student* head);
void STUDENT_SCORE(struct Student* head, int targetID);
void FREE_LIST(struct Student* head);



#endif 
