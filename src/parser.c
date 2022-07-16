#include "underfile.h"

void parser(char *str) {
    int len = strlen(str);
    leksem *output = NULL;
    leksem *stack = NULL;
    for (int i = 0; i < len; i++) {
        // Число - добавляем в строку вывода.
        if (is_digit(str[i])) {
            char *start_ptr = &str[i];
            for (; is_digit(str[i]); i++) {
            }
            char *end_ptr = &str[--i];

            double number = strtod(start_ptr, &end_ptr);

            output = push_double(number, output);
            //  output = push(str[i], output);
            priority_setter(&output);
        }
        if (str[i] == '(') {
            stack = push(str[i], stack);
            priority_setter(&stack);
        }
        // if (is_function(str, &i)){
        //     // stack = push(str[i], stack);
        //     // priority_setter(&stack);
        // }
        if (is_sign(str[i])) {
            while (stack && stack->priority >= priority_getter(str[i])) {
                output = push(pop(&stack), output);
                priority_setter(&output);
            }
            stack = push(str[i], stack);
            priority_setter(&stack);
        }
        if (str[i] == ')') {
            do {
                output = push(pop(&stack), output);
                priority_setter(&output);
            } while (stack->value != '(');
            //  && !stack убрал из скобок
            pop(&stack);
        }
    }
    while (stack) {
        output = push(pop(&stack), output);
        priority_setter(&output);
    }
    printer(output);
// ВЫЗЫВАЕМ ВНУТРИ ФУНКЦИЮ КАЛЬКУЛЯЦИИ
    calculate(&output);
    remove_all(output);
    remove_all(stack);
}

// int is_function(char *str, int *i) {
//     int exit_flag = FALSE;
//     if (str[*i] == m) {
//         strncmp(str[*i],"mod", 3);
//     }
//     // if (str[(*i)++] == 's'){
//     //     if (str[i] == 'i') {

//     //     } else if (str[i] == 'q'){

//     //     }
//     // }
//     return exit_flag;
// }

int calculate(leksem **output) {
    leksem *output_new = reverse_stack(*output);
    leksem *stack = NULL;

    while (output_new) {
        int typo = view_pop(&output_new);
        if (typo == number) {
            stack = push_double(pop_double(&output_new), stack);
        } else {
            pop(&output_new);
            if (num_el_in_stack(stack) == 1) {
                double a = pop_double(&stack);
                if (typo == add) {
                    stack = push_double(a * 1., stack);
                } else if (typo == sub) {
                    stack = push_double(a * -1., stack);
                }
            } else {
                double c = 0;
                double a = pop_double(&stack);
                double b = pop_double(&stack);
                if (typo == add) {
                    c = a + b;
                }

                else if (typo == sub) {
                    c = b - a;
                }

                else if (typo == multiply) {
                    c = a * b;
                }

                else if (typo == divide) {
                    c = a / b;
                }
                stack = push_double(c, stack);
            }
        }
    }
    printer(stack);
    remove_all(stack);
    remove_all(output_new);
}

int num_el_in_stack(leksem *head) {
    int count = 0;
    leksem *p = head;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}
leksem *push_double(double data, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->value_double = data;
    tmp->type = number;
    // Присваивание указателю на следующий элемент значения указателя на
    // «голову» первоначального списка
    tmp->next = head;
    return (tmp);
}

double pop_double(leksem **head) {
    leksem *tmp = *head;
    double value = tmp->value_double;

    *head = tmp->next;
    free(tmp);
    return value;
}

// for (int i = MINUS; i <= MULTIPLE; i++) {
//     printf("\n%d", i);
// }