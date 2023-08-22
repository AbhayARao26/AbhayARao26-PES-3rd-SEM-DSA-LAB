/*
 Create a C program to manage a student database using structures. The program should allow the user to input information about students, such as their name, roll number, and marks in three subjects. It should then calculate the total marks and average marks for each student and display the information.
 Your program should include the following steps:

 Define a structure named Student that includes fields for the student's name (a string), roll number (an integer), and marks in three subjects (floating-point numbers).
 Declare an array of Student structures to hold information about multiple students (e.g., 5 students).
 Write a function to input information for each student from the user, including their name, roll number, and marks in each subject.
 Write a function to calculate the total marks and average marks for each student.
 Write a function to display the student information, including name, roll number, and total marks.
 Input Format

 Number of students
 student’s_name roll_number subject1_marks subject2_marks subject3_marks
 Constraints

 None

 Output Format

 Print each student’s name, roll number , total marks in one line See sample output for better understanding

 Sample Input 0

 2
 JohnDoe 101 85 76 92
 JaneSmith 102 90 88 76
 Sample Output 0

 JohnDoe 101 253
 JaneSmith 102 254
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct student{
        char name[20];
        int rollNum;
        float marks[3];
    }STUD;

int findSum(STUD s1, int noOfStudents)
{
    float total = s1.marks[0]+s1.marks[1]+s1.marks[2];
    // int average = total/noOfStudents;
    return (int)total;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int noOfStudents;
    scanf("%d", &noOfStudents);
    
    STUD class1[noOfStudents];
    for(int i=0; i<noOfStudents; i++)
    {
        scanf("%s %d %f %f %f", class1[i].name, &(class1[i].rollNum), &(class1[i].marks[0]), &(class1[i].marks[1]), &(class1[i].marks[2]));
    }
    for(int i=0; i<noOfStudents; i++)
    {
        printf("%s %d %d\n", class1[i].name, class1[i].rollNum, findSum(class1[i], noOfStudents));
    }
    return 0;
}

