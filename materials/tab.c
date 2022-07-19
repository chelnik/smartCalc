// ВАЖНЫЕ ЗАДАЧИ :
// Проверить на valgrind функцию

#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    write(0, "hi\n", 3);
    
    return 0;
}

// where_from откуда
// where куда
// записывает строку из where_from в where
// void string_recorder(char *where_from, char *where){

// }
// // аналог функции delete_space
// void delete_space(char *str, char *str_result) {
//     int len = strlen(str);
//     for (int i, k = 0; i <= len; i++) {
//         if (str[i] != ' ')
//             continue;
//         *str_result++ = str[i];
// }
// }







// for (int i = MINUS; i <= MULTIPLE; i++) {
//     printf("\n%d", i);
// }

// if (typo == e_sin) {
//     double c = sin(a);
//     stack = push_double(c, stack);
// } else if (typo == e_cos) {
//     double c = cos(a);
//     stack = push_double(c, stack);
// } else if (typo == e_tan) {
//     double c = tan(a);
//     stack = push_double(c, stack);
// } else if (typo == e_asin) {
//     double c = asin(a);
//     stack = push_double(c, stack);
// } else if (typo == e_asin) {
//     double c = asin(a);
//     stack = push_double(c, stack);
// }

// void testing() {
//     char str[255] =
        // "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * 1033)";
//     char str1[255] =
//         "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
//     char str2[255] = "-( -( - 4.4 - 1.1) ) ";
//     char str3[255] = "9mod2";
//     char str4[255] = "(6 * 2) + 8";
//     double x = 0.5;
//     double result = 0;
//     char* array_str[] = {str, str1, str2, str3, str4};
//     for (size_t i = 0; i < (sizeof(array_str) / sizeof(char*)); i++) {
//         // printf("\n%s", array_str[i]);
//         delete_space(array_str[i]);
//         if (validator(array_str[i]) == 0) {
//             // printf(str);

//             printf("\n ---------");
//             if (parser(array_str[i], x, &result) == 0)
//             printf("\n\n%lf", result);
//         } else {
//             printf("\n error");
//         }
//     }
// }

