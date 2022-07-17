// Мелочей не бывает
#include "underfile.h"

// выводи OK либо error
void error_checker(int flag_error) {
    if (flag_error == OK)
        printf("\n OK");
    else
        printf("\n error");
}

/**
 * @brief удаляет пробелы в старой строке
 *
 */
void delete_space(char *str) {
    int len = strlen(str);
    int k = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] != ' ') {
            str[k++] = str[i];
        }
    }
    str[k] = '\0';
}

leksem *reverse_stack(leksem *head) {
    leksem *p = head;
    leksem *new_list = NULL;
    while (p) {
        new_list = super_push(p, new_list);
        p = p->next;
    }

    return new_list;
}
leksem *super_push(leksem *old, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->value = old->value;
    tmp->value_double = old->value_double;
    tmp->priority = old->priority;
    tmp->type = old->type;
    // Присваивание указателю на следующий элемент значения указателя на
    // «голову» первоначального списка
    tmp->next = head;
    return (tmp);
}
