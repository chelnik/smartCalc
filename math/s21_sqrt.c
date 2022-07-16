#include "s21_math.h"

long double s21_sqrt(double x) {
    long double result = 4.0;
    long double temp = 0.0;
    if (x < 0) {
        result = s21_NAN;
    } else {
        while (s21_fabs(result - temp) > s21_EPS) {
            temp = result;
            result = (temp + x / temp) / 2;
        }
    }

    return (result);
}
