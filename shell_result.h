#ifndef SHELL_RESULT_H
#define SHELL_RESULT_H

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

#endif