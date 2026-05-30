/*
 * student.h - Student 구조체와 linked list 선언
 * 
 * 26.05.28 기본 구조체 선언, 구조체에 함수 포인터를 선언해 구현하기로 함. 
 * 데이터 오류에 대해서는 여기서 처리할지, command에서 처리할지 고민중.
 * 
 * 26.05.30 students에 dirty_flag 추가. 수정 사항이 있는 상태면 dirty_flag = 1, 없으면 0
 * 
 */

 #ifndef STUDENT_H
 #define STUDENT_H

typedef struct Student Student;
typedef struct Student_SList Student_SList;

struct Student {
    int id;
    char name[32];
    int score;
    struct Student* next;
};

struct Student_SList {
    Student *head;
    int size;
    int dirty_flag;

    void (*add_student)(Student_SList *self, int id, char name[], int score);
    void (*delete_student)(Student_SList *self, int id);
    void (*update_student)(Student_SList *self, int id, int score);
    Student *(*find_student)(Student_SList *self, int id);
    void (*list_students)(Student_SList *self);
    void (*stats_students)(Student_SList *self);
    int (*is_duplicate)(Student_SList *self, int id);
};

void init_Student_SList();

void add_student(Student_SList *self, int id, char name[], int score);
void delete_student(Student_SList *self, int id);
void update_student(Student_SList *self, int id, int score);
Student *find_student(Student_SList *self, int id);
void list_students(Student_SList *self);
void stats_students(Student_SList *self);
int is_duplicate(Student_SList *self, int id);

#endif