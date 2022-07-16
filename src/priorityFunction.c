#include "underfile.h"

//  записывает лексему в связный список
// void sortstation(char *str, leksem **head) {
//     int len = strlen(str);
//     for (int i = 0; i < len; i++) {
//         if (*head == NULL) {
//             *head = create(str[i]);
//         } else {
//             *head = push(str[i], *head);
//         }
//         priority_setter(head);
//     }
// }

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
    // обработка точки

    if (symbol == 46) {
        exit_flag = TRUE;
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

void priority_setter(leksem **head) {
    if (is_digit((*head)->value)) {
        (*head)->priority = 1;
        (*head)->type = 3;
    }
    switch ((*head)->value) {
        case ('('):
            (*head)->priority = 0;
            (*head)->type = open_bracket;
            break;
        case (')'):
            (*head)->priority = 0;
            (*head)->type = close_bracket;
            break;
        case ('x'):
            (*head)->priority = 1;
            (*head)->type = x;
            break;
        case ('+'):
            (*head)->priority = 1;
            (*head)->type = add;
            break;
        case ('-'):
            (*head)->priority = 1;
            (*head)->type = sub;
            break;
        case ('*'):
            (*head)->priority = 2;
            (*head)->type = multiply;
            break;
        case ('/'):
            (*head)->priority = 2;
            (*head)->type = divide;
            break;
        case ('^'):
            (*head)->priority = 3;
            (*head)->type = e_exp;
            break;
        // case ('m'):
        //     (*head)->priority = 2;
        //     (*head)->type = e_mod;
        //     break;
        // case ('s'): {
        //     (*head)->priority = 4;
        //     // (*head)->type = e_asin;
        //     break;
        // }
        // case ('c'): {
        //     (*head)->priority = 4;
        //     // (*head)->type = e_exp;
        //     break;
        // }
        // case ('t'): {
        //     (*head)->priority = 4;
        //     // (*head)->type = e_exp;
        //     break;
        // }
        // case ('a'): {
        //     (*head)->priority = 4;
        //     // (*head)->type = e_exp;
        //     break;
        // }
        // case ('l'): {
        //     (*head)->priority = 4;
        //     // (*head)->type = e_exp;
        //     break;
        // }
        default:
            break;
    }
}

int priority_getter(int symbol) {
    int exit_flag = -1;
    if (is_digit(symbol)) {
        exit_flag = 1;
    }
    switch (symbol) {
        case ('('):
            exit_flag = 0;
            break;
        case (')'):
            exit_flag = 0;
            break;
        case ('x'):
            exit_flag = 1;
            break;
        case ('+'):
            exit_flag = 1;
            break;
        case ('-'):
            exit_flag = 1;
            break;
        case ('*'):
            exit_flag = 2;
            break;
        case ('/'):
            exit_flag = 2;
            break;
        case ('^'):
            exit_flag = 3;
            break;
        // case ('m'):
        //     exit_flag = 2;
        //     break;
        // case ('s'): {
        //     exit_flag = 4;
        //     break;
        // }
        // case ('c'): {
        //     exit_flag = 4;
        //     break;
        // }
        // case ('t'): {
        //     exit_flag = 4;
        //     break;
        // }
        // case ('a'): {
        //     exit_flag = 4;
        //     break;
        // }
        // case ('l'): {
        //     exit_flag = 4;
        //     break;
        // }
        default:
            break;
    }
    return exit_flag;
}

// while (notempty(head)) {
//     printf("\n%c", pop(&head));
// }