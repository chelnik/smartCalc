#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_digit(char symbol) {
    int exit_flag = 0;
    for (int i = 48; i <= 57; i++) {
        if (symbol == i) {
            exit_flag = 1;
        }
    }
    return exit_flag;
}
int main() {
    char *str = "2.23 + 78.7654 * 2132.2";
    
    for (int i = 0; i < strlen(str); i++) {
        if (is_digit(str[i])){
            char *start_ptr = &str[i];
            for (; is_digit(str[i]); i++) {}
            char *end_ptr = &str[--i];
            double number = strtod(start_ptr, &end_ptr);
            printf("%lf\n", number);
        }
    }
    char *num = "3.14";
    double x = strtod(num, NULL);
    printf("%lf\n", x);
    return 0;
}

// {
// char *start_ptr = &str[i];
// for (; is_digit(str[i]); i++) {}
// char *end_ptr = &str[--i];

// int number = strtod(start_ptr, &end_ptr);
// push(head, number);
// break;
// }
