#include "underfile.h"

int main() {
    // char str[255] = "(6 * 2) + 8";
    // char str[255] =
    //     "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) *
    //     1033)";
    // char str[255] =
    // "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    // char str[255] = "-( -( - 4.4 - 1.1) ) ";
    char str[255] = "9^2";
    delete_space(str);
    if (validator(str) == 0) {
        printf(str);

        printf("\n ---------");
        parser(str);

    } else {
        printf("\n error");
    }
    return 0;
}
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 5 * 4 8231 + - * + +
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 5 * 4 8231 + - * + +
