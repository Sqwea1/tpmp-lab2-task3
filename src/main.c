#include <stdio.h>
#include "student.h"

int main() {
    STUDENT students[MAX_STUDENTS];
    float averages[MAX_STUDENTS];
    int count = 0;
    
    printf("========================================\n");
    printf("STUDENT MANAGEMENT - VARIANT 10\n");
    printf("Author: Kot Aleksey, Group 12a\n");
    printf("========================================\n");
    
    inputStudents(students, &count);
    calculateAverageScores(students, count, averages);
    sortByAverageDesc(students, count, averages);
    printExcellentStudents(students, count, averages);
    deleteMinAverageStudent(students, &count, averages);
    
    printf("\n=== Final student list ===\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s %s - Avg: %.2f\n",
               students[i].lastName,
               students[i].firstName,
               students[i].patronymic,
               averages[i]);
    }
    return 0;
}

