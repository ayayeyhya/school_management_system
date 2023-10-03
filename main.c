#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school_system.h"

int main() {
    struct Student* head = NULL; // The initial head of the list
    int numStudents = 0; // Number of students on the list
	 printf("\n----------Welcome to the School Management System!--------------\n\n");
    int choice;
    do {
        MAIN_MENU();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = NEW_STUDENT(head, &numStudents);
                break;
            case 2:
                if (numStudents > 0) {
                    int targetID;
                    printf("Enter the ID of the student you want to edit: ");
                    scanf("%d", &targetID);
                    STUDENT_EDIT(head, targetID);
                } else {
                    printf("No students to edit.\n");
                }
                break;
            case 3:
                if (numStudents > 0) {
                    int targetID;
                    printf("Enter the ID of the student you want to delete: ");
                    scanf("%d", &targetID);
                    head = DELETE_STUDENT(head, &numStudents, targetID);
                } else {
                    printf("No students to delete.\n");
                }
                break;
            case 4:
                if (numStudents > 0) {
                    STUDENT_LIST(head);
                } else {
                    printf("No students to display.\n");
                }
                break;
            case 5:
                if (numStudents > 0) {
                    // Sorting is done here when the user chooses option 5
                    RANK_STUDENT(head);
                } else {
                    printf("No students to rank.\n");
                }
                break;
            case 6:
                if (numStudents > 0) {
                    int targetID;
                    printf("Enter the ID of the student whose score you want to update: ");
                    scanf("%d", &targetID);
                    STUDENT_SCORE(head, targetID);
                } else {
                    printf("No students to update scores.\n");
                }
                break;
            case 0:
                FREE_LIST(head); // Before exiting, free up the memory allocated to the list
                printf("------------------Goodbye--------------------!");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n");
        
    } while (choice != 0);

    return 0;
}
