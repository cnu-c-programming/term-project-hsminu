/*
 * student.c - linked list 정의
 * 
 * 26.05.28 init, add, delete 구현. 중복 검사에 대해서는 함수 밖에서 할지 고민중.
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
    self->find_students = find_students;
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

int is_duplicate(Student_SList *self, int id) {
}