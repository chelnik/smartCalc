#include "underfile.h"

int is_function(int type) {
    int exit_flag = FALSE;
    for (int i = e_mod; i <= e_log; i++) {
        if (type == i) exit_flag = TRUE;
    }
    return exit_flag;
}
int function_handler(char *str, int *i, leksem **head) {
    int exit_flag = FALSE;
    int result = -1;
    if (str[*i] == 'm') {
        result = strncmp(str + *i, "mod", 3);
        if (result == 0) {
            *head = push_type(e_mod, *head);
            (*i) += 2;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "sin", 3) == 0) {
        result = strncmp(str + *i, "sin", 3);
        if (result == 0) {
            *head = push_type(e_sin, *head);
            (*i) += 2;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "cos", 3) == 0) {
        result = strncmp(str + *i, "cos", 3);
        if (result == 0) {
            *head = push_type(e_cos, *head);
            (*i) += 2;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "tan", 3) == 0) {
        result = strncmp(str + *i, "tan", 3);
        if (result == 0) {
            *head = push_type(e_tan, *head);
            (*i) += 2;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "asin", 4) == 0) {
        result = strncmp(str + *i, "asin", 4);
        if (result == 0) {
            *head = push_type(e_asin, *head);
            (*i) += 3;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "acos", 4) == 0) {
        result = strncmp(str + *i, "acos", 4);
        if (result == 0) {
            *head = push_type(e_acos, *head);
            (*i) += 3;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "atan", 4) == 0) {
        result = strncmp(str + *i, "atan", 4);
        if (result == 0) {
            *head = push_type(e_atan, *head);
            (*i) += 3;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "sqrt", 4) == 0) {
        result = strncmp(str + *i, "sqrt", 4);
        if (result == 0) {
            *head = push_type(e_sqrt, *head);
            (*i) += 3;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "ln", 2) == 0) {
        result = strncmp(str + *i, "ln", 2);
        if (result == 0) {
            *head = push_type(e_ln, *head);
            (*i) += 1;
            exit_flag = TRUE;
        }
    }
    if (strncmp(str + *i, "log", 3) == 0) {
        result = strncmp(str + *i, "log", 3);
        if (result == 0) {
            *head = push_type(e_log, *head);
            (*i) += 2;
            exit_flag = TRUE;
        }
    }
    return exit_flag;
}
leksem *push_type(int type, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->type = type;
    if (type == e_mod) {
        tmp->priority = 2;
    } else {
        tmp->priority = 4;
    }
    // tmp->priority = priority_setter_func(type);
    // Присваивание указателю на следующий элемент значения указателя на
    // «голову» первоначального списка
    tmp->next = head;
    return (tmp);
}
double pop_type(leksem **head) {
    leksem *tmp = *head;
    double type = tmp->type;

    *head = tmp->next;
    free(tmp);
    return type;
}
