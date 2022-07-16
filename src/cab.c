#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = "ddmodddmodus";
    for (int i = 0; i < strlen(str); i++) {
        int a = strncmp(&str[i], "mod", 3);
        if (a == 0) {
            i += 2;
        }

        printf("\n%d", a);
    }

    return 0;
}