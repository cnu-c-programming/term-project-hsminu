typedef enum {
    SHELL_OK = 0,
    SHELL_EXIT, 
    SHELL_ERR_UNKNOWN_COMMAND,
    SHELL_ERR_INVALID_ARGUMENT,
    SHELL_ERR_MISSING_ARGUMENT,
    SHELL_ERR_FILE_OPEN,
    SHELL_ERR_FILE_WRITE,
    SHELL_ERR_STUDENT_NOT_FOUND,
    SHELL_ERR_DUPLICATE_STUDENT,
    SHELL_ERR_INVALID_SCORE
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
