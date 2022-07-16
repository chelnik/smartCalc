#include "s21_math.h"

// long double s21_pow(double base, double exp) {
//     if (exp == s21_NAN) return s21_NAN;
//     if (base == s21_NAN) return s21_NAN;
//     if (exp == 1) return base;
//     return base * s21_pow(base, exp-1);
// }


long double s21_pow(double base, double exp) {
    long double result = 1;

    if (exp == (long int)exp) {
        if (exp >= 0) {
            for (int i = 1; i <= exp; i++)
                result *= base;
        } else {
            base = 1/base;
            exp *= -1;
            for (int i = 1; i <= exp; i++)
                result *= base;
        }
    } else {
        if (base == 0) {
            result = 0;
            if (exp < 0) result = s21_INF;
        } else if (base < 0) {
            result = s21_NAN;
        } else {
            result = s21_exp(exp * s21_log(base));
        }
    }

    return (result);
}
