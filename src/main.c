#include "underfile.h"

int main() {
    // testing();
    // char str[255] = "(6 * 2) + 8";

    // char str[255] ="-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4
    // + 8231))) *1033)"; char str[255] =
    //     "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) -
    //     100";
    // char str[255] = "-( -( - 4.4 - 1.1) ) ";
    // char str[255] = "9mod2";
    
    char str[255] = "ln(x)";
    double x = 0.5;
    delete_space(str);
    if (validator(str) == 0) {
        printf(str);

        printf("\n ---------");
        parser(str, x);

    } else {
        printf("\n error");
    }
    
    return 0;
}

void testing() {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * "
        "1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char* array_str[] = {str, str1, str2, str3, str4};
    for (int i = 0; i < (sizeof(array_str) / sizeof(char*)); i++) {
        // printf("\n%s", array_str[i]);
        delete_space(array_str[i]);
        if (validator(array_str[i]) == 0) {
            // printf(str);

            printf("\n ---------");
            parser(array_str[i], 1);

        } else {
            printf("\n error");
        }
    }
}
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 5 * 4 8231 + - * + +
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 5 * 4 8231 + - * + +
