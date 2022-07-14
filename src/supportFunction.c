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
 * @brief удаляет пробелы и возвращает новую строку
 * Внимание работает с кучей
 */
// char *delete_space(char *str) {
//     int len = strlen(str);
//     char *str_result = malloc(sizeof(char) * len);
//     for (int i = 0, k = 0; i <= len; i++) {
//         if (str[i] != ' ') {
//             // str_result = realloc(str_result, sizeof(char));
//             str_result[k] = str[i];
//             k++;
//         }
//     }
//     return str_result;
// }
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
