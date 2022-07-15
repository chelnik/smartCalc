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

            int number = strtod(start_ptr, &end_ptr);
            output = push(number, output);

            // output = push(str[i], output);
            // priority_setter(&output);
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
            } while (stack->value != '(' && !stack);
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
    calculate(&output);
}

int calculate(leksem **output) {
    leksem *output_new = reverse_stack(*output);
    leksem *stack = NULL;
    while (output_new) {
        int t = pop(&output_new);
        if (is_digit(t)) {
            stack = push(t, stack);
        } else {
            int c = 0;
            int a = pop(&stack);
            int b = pop(&stack);
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


// atoi(strdup(itoa(pop(&stack))));

// for (int i = MINUS; i <= MULTIPLE; i++) {
//     printf("\n%d", i);
// }