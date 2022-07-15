#include "underfile.h"
// char str[255] = "(6 * 2) + 8 + 8 * 2 + (2 + 2)";
// 6 2 * 8 + 8 2 * + 2 2 + +
void parser(char *str) {
    int len = strlen(str);
    leksem *output = NULL;
    leksem *stack = NULL;
    for (int i = 0; i < len; i++) {
        // Число - добавляем в строку вывода.
        if (is_digit(str[i])) {
           char *start_ptr = &str[i];
           for (; is_digit(str[i]); i++) {}
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
    print_list(output);
    printf("\n ---------- stack : ----------\n");
    print_list(stack);
    printf("\n ---------- output : ----------\n");
    printer(output);
    // calculate(&output);
}

int calculate(leksem **output) {
    leksem *output_new = reverse_stack(*output);
    leksem *stack = NULL;
    while (output_new) {
        int t = pop(&output_new);
        if (is_digit(t)) {
            stack = push_double(t, stack);
        } else {
            int c = 0;
            double a = pop_double(&stack);
            double b = pop_double(&stack);
            if (t == '+') {
                c = a + b;
            }

            else if (t == '-') {
                c = a - b;
            }

            else if (t == '*') {
                c = a * b;
            }

            else if (t == '/') {
                c = a / b;
            }
            stack = push(c, stack);
        }
    }
    print_list(stack);
}

void new_printer(leksem *data, leksem *head) {
    // if (data->type == number) {

    // }
}
leksem *push_double(double data, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->value_double = data;
//    ВНИМАНИЕ НИЖЕ КОСТЫЛЬ
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
// int pop_(leksem **head) {
//     leksem *tmp = *head;
//     int value = tmp->value;

//     *head = tmp->next;
//     free(tmp);
//     return value;
// }

// atoi(strdup(itoa(pop(&stack))));

// for (int i = MINUS; i <= MULTIPLE; i++) {
//     printf("\n%d", i);
// }