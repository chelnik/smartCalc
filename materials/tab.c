// ВАЖНЫЕ ЗАДАЧИ :
// Проверить на valgrind функцию


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int *array = malloc(10 * sizeof(int));
    // array = realloc(array, 10 * sizeof(int));
    // for (int i = 0; i < 101; i++) {
    //     array[i] = i;
    // }
    // for (int i = 0; i < 101; i++) {
    //     printf("\n%d", array[i]);
    // }
    // for (int i = 0; i < 101; i++) {
    //     free(array[i]);
    // }
// free(array);
    return 0;
}

// where_from откуда
// where куда
// записывает строку из where_from в where
void string_recorder(char *where_from, char *where){

}
// аналог функции delete_space
void delete_space(char *str, char *str_result) {
    int len = strlen(str);
    for (int i, k = 0; i <= len; i++) {
        if (str[i] != ' ')
            continue;
        *str_result++ = str[i];
}
}




