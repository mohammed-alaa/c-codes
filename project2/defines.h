#ifndef DEFINES
#define DEFINES

#define bool _Bool
#define false (char)0
#define true (char)1
#define MAX_ENTRIES 10
#define COURSES_NUM 3
#define MIN_GRADE 0
#define MAX_GRADE 100
#define clamp(num, min, max) ((num < min) ? min : ((num > max) ? max : num))

typedef unsigned long long uint8;

typedef struct Courses
{
    uint8 id;
    uint8 grade;
} Course;

typedef struct Students
{
    uint8 id;
    uint8 year;
    Course courses[COURSES_NUM];
} Student;

typedef struct List
{
    Student student;
    struct List *next;
} List;
#endif