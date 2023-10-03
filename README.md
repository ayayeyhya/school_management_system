
## School Management System

This is a simple school management system written in C. It allows users to add, edit, delete, and view students, as well as rank them according to their computer science score.

### Features

* Add, edit, and delete students
* View a list of all students
* Rank students according to their computer science score
* Update the computer science score of an individual student

### Usage

To use the school management system, simply compile and run the `main.c` file. The program will display a menu with the following options:

1. Create a new student account
2. Update information of an existing student
3. Delete an existing student
4. View the list of students
5. View sorted grades
6. Update scores of all students
0. Exit

To select an option, simply enter the corresponding number and press enter.

### Example

```
# Compile the program
gcc main.c -o school_management_system

# Run the program
./school_management_system

----------Welcome to the School Management System!--------------

1. Create a new student account
2. Update information of an existing student
3. Delete an existing student
4. View the list of students
5. View sorted grades
6. Update scores of all students
0. Exit

Enter your choice: 1

Enter student name: Alice
Enter student date of birth: 2000-01-01
Enter student ID: 123456789
Enter student address: 123 Main Street
Enter student phone number: 123-456-7890
Enter student computer science score: 90

Student added successfully.

----------Welcome to the School Management System!--------------

1. Create a new student account
2. Update information of an existing student
3. Delete an existing student
4. View the list of students
5. View sorted grades
6. Update scores of all students
0. Exit

Enter your choice: 4

List of Students:

ID	Name	DOB	Address	Phone	CS Score
123456789	Alice	2000-01-01	123 Main Street	123-456-7890	90

----------Welcome to the School Management System!--------------

1. Create a new student account
2. Update information of an existing student
3. Delete an existing student
4. View the list of students
5. View sorted grades
6. Update scores of all students
0. Exit

Enter your choice: 0

Goodbye!
```

### Contributing

We welcome contributions to this project. Please feel free to submit bug reports, pull requests, and suggestions.
