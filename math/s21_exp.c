#include "s21_math.h"

/**
 * @brief возвращает значение e, возведенное в заданную степень
 */
long double s21_exp(double x) {
    long double count = 1, sumTeilor = 1;
    long double res = 1;
    int sign = 0;
    if (x < 0) {
        x *= -1;
        sign = 1;
    }
    while (s21_fabs(res) > s21_EPS) {
        res *= x / count;
        count++;
        sumTeilor += res;
        if (sumTeilor > s21_MAX_DOUBLE) {
            sumTeilor = s21_INF;
            break;
        }
    }
    if (sign == 1) {
        if (sumTeilor > s21_MAX_DOUBLE) {
            sumTeilor = 0;
        } else {
            sumTeilor = 1. / sumTeilor;
        }
    }
    return sumTeilor > s21_MAX_DOUBLE ? s21_INF : sumTeilor;
}

// long double s21_power(long double x, int count) {
//     if (count == 1) return x;
//     return x * s21_power(x, count - 1);
// }

// long double factorial_for_exp(long double x) {
//     if (x == 1.0) return 1.0;
//     return x * factorial_for_exp(x - 1.0);
// }
