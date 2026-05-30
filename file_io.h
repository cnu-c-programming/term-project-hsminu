/*
 * file_io.h - csv 파일 load, save 함수 정의
 * 
 * 26.05.30 각 함수 정의
 * 
 */

#include "command.h"
#include "student.h"

shellResult load_students_csv(Student_SList *list, const char *filename);
shellResult save_students_csv(Student_SList *list, const char *filename);
shellResult reload_students_csv(Student_SList *list, const char *filename);

static void delete_newline(char *str);
static void parsing_rest(char *str, int *id, char *name, int *score);