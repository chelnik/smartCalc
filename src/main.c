#include "underfile.h"
int validator_new(char *str);
int main() {
    char str[255] = "(6 * 2) + 8";

    char *str_clean = delete_space(str);
    validator(str);

    printf(str_clean);

    free(str_clean);
    return 0;
}

int validator_new(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
    }
}

















