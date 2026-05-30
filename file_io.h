/*
 * file_io.h - csv 파일 load, save 함수 정의
 * 
 * 26.05.30 각 함수 정의
 * 
 */

#ifndef FILE_IO_H
#define FILE_IO_H

#include "command.h"
#include "student.h"

shellResult load_students_csv();
shellResult save_students_csv();
shellResult reload_students_csv();

static void delete_newline(char *str);
static int parsing_rest(char *str, int *id, char *name, int *score);

#endif