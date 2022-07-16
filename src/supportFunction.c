// Мелочей не бывает
#include "underfile.h"

void parser_2(char *str);
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

// заготовка под парсер
void parser_2(char *str) {
    int exit_flag = OK;
    int len = strlen(str);
    int openbracket = 0, closebracket = 0;
    leksem *head;
    head = create(str[0]);
    for (int i = 1; i <= len; i++) {
        add_element_n_position(str[i], i + 1, head);
    }
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
char* itoa(int val){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= 10)
	
		buf[i] = "0123456789abcdef"[val % 10];
	
	return &buf[i+1];
	
}