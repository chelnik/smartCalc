#include "underfile.h"
void print_list(leksem *head) {
    leksem *p = head;
    while (p) {
        printf("\n%c", p->value);
        p = p->next;
    }
}
// выводит список в обратном порядке
void printer(leksem *head) {
    leksem *p = head;
    leksem *new_list = NULL;
    while (p) {
        if (p->type == number) {
            new_list = push_double(p->value_double, new_list);
            p = p->next;
        } else if (is_function(p->type)) {
            new_list = push_type(p->type, new_list);
            p = p->next;
        } else {
            new_list = push(p->value, new_list);
            p = p->next;
        }
        //        priority_setter(&new_list);
    }

    printf("\n");
    while (new_list) {
        if (new_list->type == number) {
            printf("%.9lf ", new_list->value_double);
            new_list = new_list->next;
        } else if (is_function(new_list->type)) {
            printf("%s ", return_name_function(new_list->type));
            new_list = new_list->next;
        } else {
            printf("%c ", new_list->value);
            new_list = new_list->next;
        }
    }
}
char *return_name_function(int type) {
    char *exit_flag;
    switch (type) {
        case e_mod:
            exit_flag = "mod";
            break;
        case e_sin:
            exit_flag = "sin";
            break;
        case e_cos:
            exit_flag = "cos";
            break;
        case e_tan:
            exit_flag = "tan";
            break;
        case e_asin:
            exit_flag = "asin";
            break;
        case e_acos:
            exit_flag = "acos";
        case e_atan:
            exit_flag = "atan";
            break;
        case e_sqrt:
            exit_flag = "sqrt";
            break;
        case e_ln:
            exit_flag = "ln";
            break;
        case e_log:
            exit_flag = "log";
            break;
        default:
            break;
    }
    return exit_flag;
}
