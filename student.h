
typedef struct Student {
    int id;
    char name[32];
    int score;
    struct Student* next;
} Student;

typedef struct Student_SList {
    Student *head;

    void (*add_student)(Student_SList *self, int id, char name[], int score);
    void (*delete_student)(Student_SList *self, int id);
    void (*update_student)(Student_SList *self, int id, int score);
    Student *(*find_students)(Student_SList *self, int id);
    void (*list_students)(Student_SList *self);
    void (*stats_students)(Student_SList *self);
}Student_SList;