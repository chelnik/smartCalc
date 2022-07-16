#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    double a = 9.6;
    double b = 2.6;
    double c = (int)a % (int)b;
    printf("\n%lf", c);
    return 0;
}