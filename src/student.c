#include <stdio.h>
#include <string.h>
#include "student.h"

void inputStudents(STUDENT *students, int *count) {
    *count = MAX_STUDENTS;
    
    for (int i = 0; i < *count; i++) {
        printf("\n=== Student %d ===\n", i + 1);
        printf("Last name: ");
        scanf("%s", students[i].lastName);
        printf("First name: ");
        scanf("%s", students[i].firstName);
        printf("Patronymic: ");
        scanf("%s", students[i].patronymic);
        printf("Group number: ");
        scanf("%d", &students[i].groupNumber);
        printf("Enter 4 grades (1-5): ");
        for (int j = 0; j < GRADES_COUNT; j++) {
            scanf("%d", &students[i].grades[j]);
        }
    }
}

void calculateAverageScores(STUDENT *students, int count, float *averages) {
    for (int i = 0; i < count; i++) {
        float sum = 0;
        for (int j = 0; j < GRADES_COUNT; j++) {
            sum += students[i].grades[j];
        }
        averages[i] = sum / GRADES_COUNT;
    }
}

void sortByAverageDesc(STUDENT *students, int count, float *averages) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (averages[i] < averages[j]) {
                float tempAvg = averages[i];
                averages[i] = averages[j];
                averages[j] = tempAvg;
                
                STUDENT temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printExcellentStudents(STUDENT *students, int count, float *averages) {
    printf("\n=== Students with only grades 4 and 5 ===\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        int excellent = 1;
        for (int j = 0; j < GRADES_COUNT; j++) {
            if (students[i].grades[j] < 4) {
                excellent = 0;
                break;
            }
        }
        if (excellent) {
            found = 1;
            printf("%s %s %s - Group %d, Avg: %.2f\n",
                   students[i].lastName,
                   students[i].firstName,
                   students[i].patronymic,
                   students[i].groupNumber,
                   averages[i]);
        }
    }
    if (!found) {
        printf("No students with only grades 4 and 5\n");
    }
}

void deleteMinAverageStudent(STUDENT *students, int *count, float *averages) {
    if (*count == 0) return;
    
    int minIndex = 0;
    for (int i = 1; i < *count; i++) {
        if (averages[i] < averages[minIndex]) {
            minIndex = i;
        }
    }
    
    printf("\nDeleting student with minimum average (%.2f): %s %s %s\n",
           averages[minIndex],
           students[minIndex].lastName,
           students[minIndex].firstName,
           students[minIndex].patronymic);
    
    for (int i = minIndex; i < *count - 1; i++) {
        students[i] = students[i + 1];
        averages[i] = averages[i + 1];
    }
    (*count)--;
}
