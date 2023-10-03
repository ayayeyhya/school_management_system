#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school_system.h"

// Function to display the main menu
void MAIN_MENU() {
    printf("1. Create a new student account\n");
    printf("2. Update information of an existing student\n");
    printf("3. Delete an existing student\n");
    printf("4. View the list of students\n");
    printf("5. View sorted grades\n");
    printf("6. Update scores of all students\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new student to the end of the list
struct Student* NEW_STUDENT(struct Student* head, int* numStudents) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student date of birth: ");
    scanf("%s", newStudent->dateOfBirth);
    printf("Enter student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter student address: ");
    scanf("%s", newStudent->address);
    printf("Enter student phone number: ");
    scanf("%s", newStudent->phoneNumber);
    printf("Enter student computer science score: ");
    scanf("%f", &newStudent->computerScienceScore);

    newStudent->next = NULL; // Set the next pointer of the new student to NULL

    if (head == NULL) {
        // If the list is empty, make the new student the head
        head = newStudent;
    } else {
        // Otherwise, find the last student in the list and append the new student
        struct Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }

    (*numStudents)++;
    printf("Student added successfully.\n");
    return head;
}

// Function to delete an existing student
struct Student* DELETE_STUDENT(struct Student* head, int* numStudents, int targetID) {
  struct Student* current = head;
  struct Student* prev = NULL;

  while (current != NULL) {
    if (current->id == targetID) {
      if (prev == NULL) {
        // If the student is in the head
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      (*numStudents)--;
      printf("Student with ID %d deleted successfully.\n", targetID);
      return head;
    }
    prev = current;
    current = current->next;
  }

  printf("Student with ID %d not found.\n", targetID);
  return head;
}



// Function to update information of an existing student
void STUDENT_EDIT(struct Student* head, int targetID) {
    struct Student* current = head;

    while (current != NULL) {
        if (current->id == targetID) {
            printf("Enter new name: ");
            scanf("%s", current->name);
            printf("Enter new date of birth: ");
            scanf("%s", current->dateOfBirth);
            printf("Enter new address: ");
            scanf("%s", current->address);
            printf("Enter new phone number: ");
            scanf("%s", current->phoneNumber);
            printf("Enter new computer science score: ");
            scanf("%f", &current->computerScienceScore);
            printf("Student information updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Student with ID %d not found.\n", targetID);
}

// Function to rank students according to computer science score
void RANK_STUDENT(struct Student* head) {
    // Initialize a new linked list to store sorted students
    struct Student* sortedList = NULL;

    // Traverse the original linked list
    struct Student* current = head;
    while (current != NULL) {
        // Store the next student in a temporary pointer
        struct Student* nextStudent = current->next;
        
        // Insert the current student into the sorted list
        if (sortedList == NULL || current->computerScienceScore >= sortedList->computerScienceScore) {
            // Insert at the beginning
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert
            struct Student* temp = sortedList;
            while (temp->next != NULL && current->computerScienceScore < temp->next->computerScienceScore) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        
        // Move to the next student in the original list
        current = nextStudent;
    }

    // Print the sorted list
    printf("Students sorted by computer science score:\n");
    printf("ID\tName\tDOB\tAddress\tPhone\tCS Score\n");

    // Traverse and print the sorted list
    current = sortedList;
    while (current != NULL) {
        printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", current->id, current->name, current->dateOfBirth,
               current->address, current->phoneNumber, current->computerScienceScore);
        current = current->next;
    }

    // Free memory allocated for the sorted list
    while (sortedList != NULL) {
        struct Student* temp = sortedList;
        sortedList = sortedList->next;
        free(temp);
    }
}

// Function to update scores of all students
void STUDENT_SCORE(struct Student* head, int targetID) {
    struct Student* current = head;

    while (current != NULL) {
        if (current->id == targetID) {
            printf("Enter new computer science score for %s: ", current->name);
            scanf("%f", &current->computerScienceScore);
            printf("Computer science score updated successfully for %s.\n", current->name);
            return;
        }
        current = current->next;
    }

    printf("Student with ID %d not found.\n", targetID);
}

// Function to view the list of students
void STUDENT_LIST(struct Student* head) {
    struct Student* current = head;
    printf("List of Students:\n");
    printf("ID\tName\tDOB\tAddress\tPhone\tCS Score\n");
    while (current != NULL) {
        printf("%d\t%s\t%s\t%s\t%s\t%.2f\n", current->id, current->name, current->dateOfBirth,
               current->address, current->phoneNumber, current->computerScienceScore);
        current = current->next;
    }
}

// Function to destroy memory used by the linked list
void FREE_LIST(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        struct Student* next = current->next;
        free(current);
        current = next;
    }
}