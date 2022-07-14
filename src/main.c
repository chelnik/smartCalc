#include "underfile.h"

int main() {
    char str[255] = "(6 * 2) + 8";

    delete_space(str);
    validator(str);

    printf(str);
    leksem *head = NULL;

    sortstation(str, &head);

    




    print_list(head);
    remove_all(head);
    return 0;
}

void sortstation(char *str, leksem **head) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        creator(head, i);
    }
}


//  записывает лексему в связный список
void creator(leksem **head, int i) {
    if (*head == NULL) {
        *head = create(str[i]);
    } else {
        *head = push(str[i], *head);
    }
    priority_setter(head);
}

int is_bracket(char symbol) {
    int exit_flag = FALSE;
    for (int i = 40; i <= 41; i++) {
        if (symbol == i) {
            exit_flag = TRUE;
        }
    }
    return exit_flag;
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
void priority_setter(leksem **head) {
    switch ((*head)->value) {
        case ('('):
            (*head)->priority = 0;
            break;
        case (')'):
            (*head)->priority = 0;
            break;
        case ('x'):
            (*head)->priority = 1;
            break;
        case ('+'):
            (*head)->priority = 1;
            break;
        case ('-'):
            (*head)->priority = 1;
            break;
        case ('*'):
            (*head)->priority = 2;
            break;
        case ('/'):
            (*head)->priority = 2;
            break;
        case ('^'):
            (*head)->priority = 3;
            break;
        case ('m'):
            (*head)->priority = 2;
            break;
        case ('s'): {
            (*head)->priority = 4;
            break;
        }
        case ('c'): {
            (*head)->priority = 4;
            break;
        }
        case ('t'): {
            (*head)->priority = 4;
            break;
        }
        case ('a'): {
            (*head)->priority = 4;
            break;
        }
        case ('l'): {
            (*head)->priority = 4;
            break;
        }
        case (is_digit((*head)->value)):
            (*head)->priority = 1;
        default:
            break;
    }
}
    // while (notempty(head)) {
    //     printf("\n%c", pop(&head));
    // }