#include "underfile.h"

int parser(char *str, double x, double *result) {
    int exit_flag = OK;
    delete_space(str);
    int len = strlen(str);
    leksem *output = NULL;
    leksem *stack = NULL;
    for (int i = 0; i < len; i++) {
        // Число - добавляем в строку вывода.
        if (str[i] == 'x') {
            output = push_double(x, output);
            priority_setter(&output);
        } else if (is_digit(str[i])) {
            char *start_ptr = &str[i];
            for (; is_digit(str[i]); i++) {
            }
            char *end_ptr = &str[--i];

            double number = strtod(start_ptr, &end_ptr);

            output = push_double(number, output);
            priority_setter(&output);
        } else if (str[i] == '(') {
            stack = push(str[i], stack);
            priority_setter(&stack);
        } else if(function_handler(str, &i, &stack)){
            exit_flag = OK;
        } else if (is_sign(str[i])) {
            while (stack && stack->priority >= priority_getter(str[i])) {
                output = push(pop(&stack), output);
                priority_setter(&output);
            }
            stack = push(str[i], stack);
            priority_setter(&stack);
        } else if (str[i] == ')') {
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
        } else {
            exit_flag = ERROR;
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
    // printer(output);
    // ВЫЗЫВАЕМ ВНУТРИ ФУНКЦИЮ КАЛЬКУЛЯЦИИ
    if (!divide_by_zero_checker(&output) && exit_flag == OK) {
        calculate(&output, result);
    } else {
        exit_flag = ERROR;
    }

    remove_all(output);
    remove_all(stack);
    return exit_flag;
}

int divide_by_zero_checker(leksem **output) {
    int exit_flag = OK;
    leksem *p = reverse_stack(*output);
    // printer(p);
    while (p) {
        if (p->type == 3 && p->value_double == 0.0) {
            leksem *new_p = p;
            new_p = new_p->next;
            if (new_p->type == 7) exit_flag = ERROR;
        }
        p = p->next;
    }
    return exit_flag;
}

int calculate(leksem **output, double *result) {
    leksem *output_new = reverse_stack(*output);
    leksem *stack = NULL;
    double (*array[8])(double) = {&sin, &cos, &tan, &asin, &acos, &atan, &sqrt};
    while (output_new) {
        int typo = view_type(&output_new);
        if (typo == number) {
            stack = push_double(pop_double(&output_new), stack);
        } else {
            pop(&output_new);
            double a = pop_double(&stack);
            // штука для обработки унарного минуса
            // if (num_el_in_stack(stack) == 1) {
            //     if (typo == add) {
            //         stack = push_double(a * 1., stack);
            //     } else if (typo == sub) {
            //         stack = push_double(a * -1., stack);
            //     }
            // }

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
                double c = log(a);
                stack = push_double(c, stack);
            }

            if (typo >= 4 && typo <= 9) {
                double c = 0;
                double b;
                if (stack) b = pop_double(&stack);
                if (typo == add) {
                    c = a + b;
                } else if (typo == sub) {
                    c = b - a;
                } else if (typo == multiply) {
                    c = a * b;
                } else if (typo == divide) {
                    c = b / a;
                } else if (typo == e_mod) {
                    c = fmod(b, a);
                } else if (typo == e_exp) {
                    c = pow(b, a);
                }
                stack = push_double(c, stack);
            }
        }
    }

    *result = pop_double(&stack);
    if (stack) remove_all(stack);
    if (output_new) remove_all(output_new);
    return 0;
}
double pop_double_for_parser(leksem *head) {
    leksem *tmp = head;
    double value = head->value_double;

    head = head->next;
    free(tmp);
    return value;
}
