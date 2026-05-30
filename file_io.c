/*
 * file_io.c - Student 구조체와 linked list 선언
 * 
 * 26.05.30 save, load 함수 구현. 
 * 
 */

#include "student.h"
#include "command.h"
#include "shell_result.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Student_SList students;
extern const char *csv_path;

static void delete_newline(char *str);
static int parsing_rest(char *str, int *id, char *name, int *score);

shellResult save_students_csv() {
    FILE *fp = fopen(csv_path, "w");
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

shellResult load_students_csv() {
    FILE *fp = fopen(csv_path, "r");
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
        if(!parsing_rest(line, &id, name, &score)){
            return SHELL_ERR_INVALID_ARGUMENT;
        }

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
static int parsing_rest(char *str, int *id, char *name, int *score) {
    int argc = 0;

    char *token = strtok(str, ",");
    if(!is_allright_id(token)) {
        return 0;
    }
    *id = atoi(token);

    token = strtok(NULL, ",");
    if(!is_allright_name(token)){
        return 0;
    }
    strcpy(name, token);

    token = strtok(NULL, ",");
    if(!is_allright_score(token)) {
        return 0;
    }
    *score = atoi(token);

    return 1;
}

