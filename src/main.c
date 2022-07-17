#include "underfile.h"

int main() {
    char str[255] = "777+69-3333333333333";
    double x = 0.5;
    double result = 0;
    delete_space(str);
    if (validator(str) == 0) {
        printf("%s", str);

        printf("\n ---------");
        parser(str, x, &result);
        printf("\n");
        printf("\n%lf", result);
    } else {
        printf("\n error");
    }
    return 0;
}

