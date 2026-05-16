#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 7
#define GRADES_COUNT 4

typedef struct {
    char lastName[50];
    char firstName[50];
    char patronymic[50];
    int groupNumber;
    int grades[GRADES_COUNT];
} STUDENT;

void inputStudents(STUDENT *students, int *count);
void calculateAverageScores(STUDENT *students, int count, float *averages);
void sortByAverageDesc(STUDENT *students, int count, float *averages);
void printExcellentStudents(STUDENT *students, int count, float *averages);
void deleteMinAverageStudent(STUDENT *students, int *count, float *averages);

#endif
