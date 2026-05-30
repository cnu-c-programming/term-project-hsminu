/*
 * command.h - command 타입, table, handler 선언
 * 
 * 26.05.28 자료에 있는 것으로 선언 완료, shellResult 자료에 이어서 추가 선언
 * 
 * 26.05.29 commands 배열을 c파일로 옮김, execute_command 함수 정의
 * 
 * 26.05.30 
 * 
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "shell_result.h"

typedef shellResult (*CommandHandler)(int argc, char** argv);

typedef struct {
    const char* name;
    CommandHandler handler;
    const char* usage;
    const char* description;
} Command;

shellResult execute_command(int argc, char **argv);

shellResult handle_save(int argc, char** argv);
shellResult handle_reload(int argc, char** argv);
shellResult handle_add(int argc, char** argv);
shellResult handle_delete(int argc, char** argv);
shellResult handle_update(int argc, char** argv);
shellResult handle_find(int argc, char** argv);
shellResult handle_list(int argc, char** argv);
shellResult handle_stats(int argc, char** argv);
shellResult handle_help(int argc, char** argv);
shellResult handle_clear(int argc, char** argv);
shellResult handle_exit(int argc, char** argv);

void print_result(shellResult result, int line);


int is_allright_id(char *str);
int is_allright_name(char *str);
int is_allright_score(char *str);

#endif