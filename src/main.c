#include "underfile.h"

int main() {
    char str[255] = "(6 * 2) + 8";

    char *str_clean = delete_space(str);
    validator(str);

    printf(str_clean);

    free(str_clean);
    return 0;
}

void sortstation() {

}












