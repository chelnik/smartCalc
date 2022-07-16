#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    double (*array[])(double) = {&sin,  &cos,  &tan, &asin, &acos,
                                  &atan, &sqrt, &log,  &log10};
    printf("\n%lf", array[0](1.));
    return 0;
}
