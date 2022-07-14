#include "underfile.h"

void parser(char *str) {
    int len = strlen(str);
    leksem *output = NULL;
    leksem *stack = NULL;
    for (int i = 0; i < len; i++) {
        // Число - добавляем в строку вывода.
        if (is_digit(str[i])) {
            output = push(str[i], output);
        }
        if (is_bracket(str[i])) {
            stack = push(str[i], stack);
        }
        if (is_sign(str[i])) {
            while (stack->priority >= priority_getter(str[i])) {
            }
            stack = push(str[i], stack);
        }
        if (str[i] == ')') {
            do {
                output = push(pop(&stack), output);
            } while (stack->value != '(');
        }
    }
    print_list(output);
    printf("\n ---------- stack : ----------\n");
    print_list(stack);
     printf("\n ---------- stack : ----------\n");
    printer(output);
}
// for (int i = MINUS; i <= MULTIPLE; i++) {
//     printf("\n%d", i);
// }