#include "underfile.h"

void parser(char *str, double x) {
    int len = strlen(str);
    leksem *output = NULL;
    leksem *stack = NULL;
    for (int i = 0; i < len; i++) {
        // Число - добавляем в строку вывода.
        if (str[i] == 'x') {
            output = push_double(x, output);
            priority_setter(&output);
        }
        if (is_digit(str[i])) {
            char *start_ptr = &str[i];
            for (; is_digit(str[i]); i++) {
            }
            char *end_ptr = &str[--i];

            double number = strtod(start_ptr, &end_ptr);

            output = push_double(number, output);
            priority_setter(&output);
        }
        if (str[i] == '(') {
            stack = push(str[i], stack);
            priority_setter(&stack);
        }
        // Важный элемент для ошибок
        function_handler(str, &i, &stack);

        if (is_sign(str[i])) {
            while (stack && stack->priority >= priority_getter(str[i])) {
                output = push(pop(&stack), output);
                priority_setter(&output);
            }
            stack = push(str[i], stack);
            priority_setter(&stack);
        }
        if (str[i] == ')') {
            // убрал do
            while (stack->value != '(') {
                output = push(pop(&stack), output);
                priority_setter(&output);
            }
            //  && !stack убрал из скобок
            pop(&stack);
            if (stack) {
                int typo = view_type(&stack);
                if (is_function(typo)) {
                    output = push_type(pop_type(&stack), output);
                }
            }
        }
    }
    while (stack) {
        int typo = view_type(&stack);
        if (is_function(typo)) {
            output = push_type(pop_type(&stack), output);
        } else {
            output = push(pop(&stack), output);
            priority_setter(&output);
        }
    }
    printer(output);
    // ВЫЗЫВАЕМ ВНУТРИ ФУНКЦИЮ КАЛЬКУЛЯЦИИ
    calculate(&output);
    remove_all(output);
    remove_all(stack);
}

int calculate(leksem **output) {
    leksem *output_new = reverse_stack(*output);
    leksem *stack = NULL;
    long double (*array[8])(double) = {&s21_sin,  &s21_cos,  &s21_tan,
                                       &s21_asin, &s21_acos, &s21_atan,
                                       &s21_sqrt};
    while (output_new) {
        int typo = view_type(&output_new);
        if (typo == number) {
            stack = push_double(pop_double(&output_new), stack);
        } else {
            pop(&output_new);
            double a = pop_double(&stack);
            // штука для обработки унарного минуса
            if (num_el_in_stack(stack) == 1) {
                if (typo == add) {
                    stack = push_double(a * 1., stack);
                } else if (typo == sub) {
                    stack = push_double(a * -1., stack);
                }
            }

            for (int i = e_sin; i <= e_sqrt; i++) {
                if (typo == i) {
                    double c = array[i - 10](a);
                    stack = push_double(c, stack);
                }
            }

            if (typo == e_ln) {
                double c = log10(a);
                stack = push_double(c, stack);
            }
            if (typo == e_log) {
                double c = s21_log(a);
                stack = push_double(c, stack);
            }

            if (typo >= 4 && typo <= 9) {
                double c = 0;

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
                    c = b / a;
                } else if (typo == e_mod) {
                    c = s21_fmod(b, a);
                } else if (typo == e_exp) {
                    c = s21_pow(b, a);
                }
                stack = push_double(c, stack);
            }
        }
    }
    // выводит результат
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

// if (typo == e_sin) {
//     double c = s21_sin(a);
//     stack = push_double(c, stack);
// } else if (typo == e_cos) {
//     double c = s21_cos(a);
//     stack = push_double(c, stack);
// } else if (typo == e_tan) {
//     double c = s21_tan(a);
//     stack = push_double(c, stack);
// } else if (typo == e_asin) {
//     double c = s21_asin(a);
//     stack = push_double(c, stack);
// } else if (typo == e_asin) {
//     double c = s21_asin(a);
//     stack = push_double(c, stack);
// }