/*
 * file_io.c - Student 구조체와 linked list 선언
 * 
 * 26.05.30 save, load 함수 구현. 
 * 
 */

#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

extern Student_SList students;

shellResult save_students_csv(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL ) {
        return SHELL_ERR_FILE_OPEN;
    }

    fprintf(fp, "id,name,score\n");
    for(Student *p = students.head; p != NULL; p = p->next){
        if(fprintf(fp, "%d,%s,%d\n", p->id, p->name, p->score) < 0){
            fclose(fp);
            return SHELL_ERR_FILE_WRITE;
        }
    }

    fclose(fp);

    students.dirty_flag = 0;
    return SHELL_OK;
}

shellResult load_students_csv(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        return SHELL_ERR_FILE_OPEN;
    }

    char line[128];
    if(fgets(line, sizeof(line), fp) == NULL) {
        return SHELL_ERR_FILE_READ;
    }
    delete_newline(line);
    if(strcmp(line, "id,name,score") != 0){
        return SHELL_ERR_FILE_READ;
    }

    while(fgets(line, sizeof(line), fp) != NULL) {
        int id;
        char name[32];
        int score;

        delete_newline(line);
        parsing_rest(line, &id, name, &score);

        students.add_student(&students, id, name, score);
    }

    fclose(fp);
    return SHELL_OK;
}

// \n -> null
static void delete_newline(char *str){
    for(char *c = str; *c != '\0'; c++){
        if(*c == '\n'){
            *c = '\0';
            return;
        }
    }
}

// ,파싱
static void parsing_rest(char *str, int *id, char *name, int *score) {
    int argc = 0;
    char *token = strtok(str, ",");

    *id = atoi(token);
    token = strtok(NULL, ",");
    
    strcpy(name, token);
    token = strtok(NULL, ",");

    *score = atoi(token);
}