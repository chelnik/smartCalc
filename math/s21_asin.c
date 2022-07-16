#include "s21_math.h"

/**
 * @brief вычисляет арксинус
 */
long double s21_asin(double x) {
    // ряд тейлора
    long double res = x;
    long double sumTeilor = x;
    if (x < -1 || x > 1) {
        sumTeilor = s21_NAN;
    } else if (x == -1 || x == 1) {
        sumTeilor = s21_PI / 2 * x;
    } else {
        for (long double count = 1; s21_fabs(res) > s21_EPS; count++) {
            res *= ((x * x) * (2 * count - 1) * (2 * count - 1)) /
                   ((2 * count) * (2 * count + 1));
            sumTeilor += res;
        }
    }
    return sumTeilor;
}
