/*
 * command.c - commands 배열 선언, 각 명렁어에 대한 함수 선언
 * 
 * 26.05.29 execute_command, add 함수 구현
 * 
 */

#include "command.h"
#include "student.h"
#include <string.h>
#include <stdlib.h>

extern Student_SList students;

#ifdef ADMIN_MODE
Command commands[] = {
    {"save", handle_save, "save", "Save students to CSV"},
    {"reload", handle_reload, "reload", "Reload students from CSV"},
    {"add", handle_add, "add <id> <name> <score>", "Add a student"},
    {"delete", handle_delete, "delete <id>", "Delete a student"},
    {"update", handle_update, "update <id> <score>", "Update student score"},
    {"find", handle_find, "find <id>", "Find student"},
    {"list", handle_list, "list", "List students"},
    {"stats", handle_stats, "stats", "Show stats"},
    {"help", handle_help, "help", "Show help"},
    {"clear", handle_clear, "clear", "Clear screen"},
    {"exit", handle_exit, "exit", "Exit shell"}
};
#endif

#ifdef CLIENT_MODE
Command commands[] = {
    {"reload", handle_reload, "reload", "Reload students from CSV"},
    {"find", handle_find, "find <id>", "Find student"},
    {"list", handle_list, "list", "List students"},
    {"stats", handle_stats, "stats", "Show stats"},
    {"help", handle_help, "help", "Show help"},
    {"clear", handle_clear, "clear", "Clear screen"},
    {"exit", handle_exit, "exit", "Exit shell"}
};
#endif

const int command_count = sizeof(commands) / sizeof(commands[0]);

shellResult execute_command(int argc, char **argv) {
    if (argc == 0) {
        return SHELL_OK;
    }

    for (int i = 0; i < command_count; i++) {
        if (strcmp(argv[0], commands[i].name) == 0) {
            return commands[i].handler(argc, argv);
        }
    }

    return SHELL_ERR_UNKNOWN_COMMAND;
}

shellResult handle_add(int argc, char **argv) {
    if(argc < 4) {
        return SHELL_ERR_MISSING_ARGUMENT;
    }
    if(argc > 4) {
        return SHELL_ERR_INVALID_ARGUMENT;
    }

    // id
    if(!is_allright_id(argv[1])) { 
        return SHELL_ERR_INVALID_ARGUMENT;
    }
    // name
    if(!is_allright_name(argv[2])) {
        return SHELL_ERR_INVALID_ARGUMENT;
    }
    // score
    if(!is_allright_score(argv[3])) { 
        return SHELL_ERR_INVALID_ARGUMENT;
    }

    int id = atoi(argv[1]);
    char *name = argv[2];
    int score = atoi(argv[3]);

    students.add_student(&students, id, name, score);
    return SHELL_OK;
}

// 정수인지 판별
static int is_allright_id(char *str) {
    if(str == NULL){
        return 0;
    }
    for(char *c = str; *c != '\0'; c++) {
        if(*c < '0' || *c > '9'){
            return 0;
        }
    }

    return 1;
}

// name 조건 판별
static int is_allright_name(char *str) {
    if(str == NULL){
        return 0;
    }
    if(strlen(str) <= 0){
        return 0;
    }
    for(char *c = str; *c != '\0'; c++) {
        if(*c == ','){
            return 0;
        }
    }

    return 1;
}

//score 판별
static int is_allright_score(char *str) {
    if(str == NULL){
        return 0;
    }
    for(char *c = str; *c != '\0'; c++) {
        if(*c < '0' || *c > '9'){
            return 0;
        }
    }
    int num = atoi(str);
    if(num < 0 || num > 100){
        return 0;
    }

    return 1;
}