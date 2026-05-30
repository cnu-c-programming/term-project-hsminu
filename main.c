/*
 * main.c  –  Mini Student Shell
 *
 * TODO: Implement admin_shell and client_shell.
 *
 * Build:
 *   make admin   →  admin_shell  (compiled with -DADMIN_MODE)
 *   make client  →  client_shell (compiled with -DCLIENT_MODE)
 *
 * Usage:
 *   ./admin_shell [students.csv]
 *   ./admin_shell -f commands.txt [students.csv]
 *   ./client_shell [students.csv]
 *   ./client_shell -f commands.txt [students.csv]
 * 
 * 26.05.30 run_shell 구현, command_file 미구현
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "file_io.h"
#include "command.h"

Student_SList students;
const char *csv_path;

/* TODO: Add your own header includes here */
/* #include "student.h"  */
/* #include "file_io.h"  */
/* #include "command.h"  */

/* ---------------------------------------------------------------
 * TODO: Implement the interactive shell loop.
 *   - Print a prompt and read a line from stdin.
 *   - Parse the line into a command and arguments.
 *   - Dispatch to the appropriate handler function.
 *   - Loop until the user types "exit" or EOF.
 * --------------------------------------------------------------- */
static int parse_line(char *line, char **argv) {
    int argc = 0;
    for(int i = 0; line[i] != '\0'; i++) {
        if(line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }

    char *token = strtok(line, " ");

    while(token != NULL && argc != 5) {
        argv[argc] = token;
        token = strtok(NULL, " ");
        argc ++;
    }

    return argc;
}

void run_shell() {
    /* TODO */
    char line[128];
    char *argv[5];

    while(1) {
        #ifdef ADMIN_MODE
        printf("admin> ");

        #elif defined(CLIENT_MODE)
        printf("client> ");
        #else
        #error "Define either -DADMIN_MODE or -DCLIENT_MODE when compiling."
        #endif

        if(fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        int argc = parse_line(line, argv);
        shellResult result = execute_command(argc, argv);

        if(result == SHELL_EXIT) {
            break;
        }
    }

    
}

/* ---------------------------------------------------------------
 * TODO: Implement batch mode – read commands from a file.
 *   - Open cmd_file for reading.
 *   - Execute each line as a command (same logic as run_shell).
 *   - Close the file when done.
 * --------------------------------------------------------------- */
void run_command_file(const char *cmd_file, const char *csv_path) {
    /* TODO */
    (void)cmd_file;
    (void)csv_path;
}

int main(int argc, char *argv[]) {
    csv_path  = "students.csv"; /* default CSV file */
    const char *cmd_file  = NULL;           /* -f <file> argument */

    init_Student_SList(&students);
    load_students_csv();

    /* TODO: Parse command-line arguments.
     *   Supported flags:
     *     -f <file>   run commands from <file> instead of stdin
     *   Remaining positional argument (if any): path to students CSV.
     *
     *   Example parsing skeleton:
     *
     *   for (int i = 1; i < argc; i++) {
     *       if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
     *           cmd_file = argv[++i];
     *       } else {
     *           csv_path = argv[i];
     *       }
     *   }
     */
    (void)argc;
    (void)argv;

#ifdef ADMIN_MODE
    /* Admin shell: supports add, delete, update, save, load, sort, list, find, help, exit */
    /*if (cmd_file) {
        run_command_file(cmd_file);
    } else {
        run_shell();
    }*/
   run_shell();

#elif defined(CLIENT_MODE)
    /* Client shell: supports find, list, help, exit  (read-only) */
    /*
    if (cmd_file) {
        run_command_file(cmd_file, csv_path);
    } else {
        run_shell();
    }*/

#else
#error "Define either -DADMIN_MODE or -DCLIENT_MODE when compiling."
#endif

    printf("Goodbye.\n");
    return 0;
}
