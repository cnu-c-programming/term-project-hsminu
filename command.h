/*
 * command.h - command 타입, table, handler 선언
 * 
 * 26.05.28 자료에 있는 것으로 선언 완료, shellResult 자료에 이어서 추가 선언
 * 
 */

typedef enum {
    SHELL_OK = 0,
    SHELL_EXIT,                     //
    
    SHELL_ERR_UNKNOWN_COMMAND,      // 알 수 없는 명령어
    SHELL_ERR_INVALID_ARGUMENT,     // 잘못된 인자
    SHELL_ERR_MISSING_ARGUMENT,     // 인자 부족

    SHELL_ERR_FILE_OPEN,            // CSV 파일 열기 실패
    SHELL_ERR_FILE_READ,            // CSV 파일 읽기 실패
    SHELL_ERR_FILE_WRITE,           // CSV 파일 쓰기 실패

    SHELL_ERR_STUDENT_NOT_FOUND,    // 존재하지 않는 학생
    SHELL_ERR_DUPLICATE_STUDENT,    // 중복된 학생 ID
    SHELL_ERR_INVALID_ID,           // 잘못된 ID
    SHELL_ERR_INVALID_SCORE,        // 잘못된 점수
    SHELL_ERR_RANGE_SCORE,          // 점수 범위 오류
    SHELL_ERR_INVALID_NAME,         // 잘못된 이름
    SHELL_ERR_EMPTY_LIST            // 빈 목록
} shellResult;

typedef shellResult (*CommandHandler)(int argc, char** argv);

typedef struct {
    const char* name;
    CommandHandler handler;
    const char* usage;
    const char* description;
} Command;

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
