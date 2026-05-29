/*
 * student.c - linked list 정의
 * 
 * 26.05.28 init, add, delete 구현. 중복 검사에 대해서는 함수 밖에서 할지 고민중.
 * 
 * 26.05.29 update, find, stats 구현. list출력에 대해서는 command에서 처리할지 생각중.
 * 중복 검사에 대해서는 함수 호출 전 command에서 find 함수를 호출해 그 값이 NULL이면 중복된 게 없다고 판단할 예정.
 * 
 */

#include "student.h"
#include <stdlib.h>
#include <string.h>

void init_Student_SList(Student_SList *self) {
    self->head = NULL;
    self->size = 0;

    self->add_student = add_student;
    self->delete_student = delete_student;
    self->update_student = update_student;
    self->find_student = find_student;
    self->list_students = list_students;
    self->stats_students = stats_students;
    self->is_duplicate = is_duplicate;
}

void add_student(Student_SList *self, int id, char name[], int score) {
    Student *new_student = malloc(sizeof(Student));

    new_student->id = id;
    new_student->score = score;
    strcpy(new_student->name, name);
    new_student->next = NULL;

    if(self->head == NULL) {
        self->head = new_student;
    }

    else {
        for(Student *p = self->head; p != NULL; p = p->next){
            if(p->next == NULL){
                p->next = new_student;
                break;
            }
        }
    }
    self->size++;
}

void delete_student(Student_SList *self, int id) {
    if(self->head->id == id) {
        Student *temp = self->head;
        self->head = self->head->next;
        free(temp);
    }

    else{
        for(Student *p = self->head; p != NULL; p = p->next) {
            if(p->next->id == id){
                Student *temp = p->next;
                p->next = temp->next;
                free(temp);
            }
        }
    }
    self->size--;
}

void update_student(Student_SList *self, int id, int score) {
    Student *temp = find_student(self, id);
    temp->id = score;
}

Student *find_student(Student_SList *self, int id) {
    for(Student *p = self->head; p!=NULL; p=p->next){
        if(p->id == id){
            return p;
        }
    }

    return NULL;
}

void list_students(Student_SList *self) {

}

void stats_students(Student_SList *self) {
    int sum_score = 0;
    int max_score = self->head->score;
    int min_score = self->head->score;

    for(Student *p = self->head; p!= NULL; p=p->next) {
        sum_score += p->score;

        if(max_score < p->score){
            max_score = p->score;
        }

        if(min_score > p->score){
            min_score = p->score;
        }
    }

    double avg_score = (double)sum_score / (double)self->size;

    printf("Count: %d\n", self->size);
    printf("Average: %.1f\n", avg_score);
    printf("Max: %d\n", max_score);
    printf("Min: %d\n", min_score);
}

int is_duplicate(Student_SList *self, int id) {
}