#include "underfile.h"

int main() {
    char str[255] = "(6 * 2) + 8";

    char *str_clean = delete_space(str);
    validator(str);

    printf(str_clean);
    leksem *head = NULL;
    leksem *head_new = NULL;

    sortstation(str_clean, head, head_new);


    print_list(head);
    print_list(head_new);

    free(str_clean);
    return 0;
}

void sortstation(char *str, leksem *head, leksem *head_new) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (is_digit(str[i])) {
            if (head == NULL) {
                head = create(str[i]);
            } else {
                head = push(str[i], head);
            }
            printf("\n number");
        }
        if (is_sign(str[i])) {
            if (head_new == NULL) {
                head_new = create(str[i]);
            } else {
                head_new = push(str[i], head_new);
            }
            printf("\n sign");
        }
    }
}

int is_digit(char symbol) {
    int exit_flag = FALSE;
    for (int i = 48; i <= 57; i++) {
        if (symbol == i) {
            exit_flag = TRUE;
        }
    }
    return exit_flag;
}

int is_sign(char symbol) {
    int exit_flag = FALSE;
    int array_sign[] = {42, 43, 45, 47};
    for (int *i = array_sign; i <= array_sign + 4; i++) {
        if (symbol == *i) {
            exit_flag = TRUE;
        }
    }
    return exit_flag;
}
//
void priority_setter(leksem *head) {
    switch (head->value) {
        case ('('):
            head->priority = 0;
            break;
        case (')'):
            head->priority = 0;
            break;
        case ('x'):
            head->priority = 1;
            break;
        case ('+'):
            head->priority = 1;
            break;
        case ('-'):
            head->priority = 1;
            break;
        case ('*'):
            head->priority = 2;
            break;
        case ('/'):
            head->priority = 2;
            break;
        case ('^'):
            head->priority = 3;
            break;
        case ('m'):
            head->priority = 2;
            break;
        case ('s'): {
            head->priority = 4;
            break;
        }
        case ('c'): {
            head->priority = 4;
            break;
        }
        case ('t'): {
            head->priority = 4;
            break;
        }
        case ('a'): {
            head->priority = 4;
            break;
        }
        case ('l'): {
            head->priority = 4;
            break;
        }
        default:
            break;
    }
}
