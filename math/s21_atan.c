#include "s21_math.h"

static long double atan_backend(double x);
/**
 * @brief вычисляет арктангенс
 */
long double s21_atan(double x) {
    long double atan = 0;

    if (x < 1 && x > -1) {
        atan = atan_backend(x);
    }

    if (x == 1) {
        atan = s21_PI / 4;
    }

    if (x == -1) {
        atan = -1 * s21_PI / 4;
    }

    if (x == 0) {
        atan = 0;
    }

    if (x > 1) {
       atan = s21_PI / 2 - atan_backend(1 / x);
    }

    if (x < -1) {
        atan = -s21_PI / 2 - atan_backend(1 / x);
    }

    return atan;
}
// ключевое слово static ограничение области видимости только из файла
static long double atan_backend(double x) {
    long double res = x;
    long double atan = x;
    int i = 1;

    while (s21_fabs(res) > s21_EPS) {
        res = -1 * res * x * x * (2 * i - 1) / (2 * i + 1);
        atan += res;
        i += 1;
    }

    return atan;
}

// old
// long double s21_atan(double x) {
//     long double atan = 0;
//     if (x == 1) {
//         atan = s21_PI / 4;
//     } else if (x == -1) {
//         atan = -1 * s21_PI / 4;
//     } else if (x == 0) {
//         atan = 0;
//     } else {
//         atan = s21_asin(x / sqrt(1 + x * x));
//     }
//     return atan;
// }
