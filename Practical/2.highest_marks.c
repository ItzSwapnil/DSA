/*
2) WAP to read a 2D array marks which stores the marks of 5 students in three subjects.
Also, write program to display the highest marks in each subject.
*/


#include <stdio.h>

void findHighestMarks(int marks[][3], int rows, int cols) {
    int highestSubjectMarks[3] = {0};
    int highestStudentIndex[3] = {-1, -1, -1};

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (marks[i][j] > highestSubjectMarks[j]) {
                highestSubjectMarks[j] = marks[i][j];
                highestStudentIndex[j] = i;
            }
        }
    }

    printf("Highest Marks in Each Subject:\n");
    char subjects[3][20] = {"Maths", "English", "Science"};
    for (int j = 0; j < cols; j++) {
        printf("%s: %d (Student %d)\n", subjects[j], highestSubjectMarks[j], highestStudentIndex[j] + 1);
    }
}

int main() {
    int marks[5][3];

    printf("Enter the marks for 5 students in Maths, English, and Science:\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter marks for student %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for %s: ", j == 0 ? "Maths" : (j == 1 ? "English" : "Science"));
            scanf("%d", &marks[i][j]);
        }
    }

    findHighestMarks(marks, 5, 3);

    return 0;
}
