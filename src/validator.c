#include "underfile.h"

int validator(char *str) {
    int exit_flag = 0;
    exit_flag += bracket_cheker(str);
    // нужно продолжить работу над этой функцией
    exit_flag += sign_checker(str);
    exit_flag += grammatik_checker(str);
    return exit_flag;
}

int bracket_cheker(char *str) {
    int exit_flag = OK;
    int len = strlen(str);
    int openbracket = 0, closebracket = 0;
    // Проверка на скобки
    for (int i = 0; i <= len; i++) {
        if (str[i] == '(') openbracket++;
        if (str[i] == ')') closebracket++;
    }

    if (openbracket != closebracket) exit_flag = ERROR;
    return exit_flag;
}

// Функции ожидающие продакшн
int sign_checker(char *str) {
    int exit_flag = OK;
    int len = strlen(str);
    for (int i = 0; i <= len; i++) {
    }
    return exit_flag;
}
int grammatik_checker(char *str) {
    int exit_flag = OK;
    int len = strlen(str);
    for (int i = 0; i <= len; i++) {
    }
    return exit_flag;
}