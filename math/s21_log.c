#include "s21_math.h"

long double s21_log(double x) {
    long double sign = 1;
    long double degree = 0;
    long double count = 2;
    long double res = 0;
    long double temp = 0;

    if (x != 1.0) {
        if (x < 0) {
            x *= -1;
            sign *= -1;
        } else {
            x *= 1;
            sign *= 1;
        }
        while ((x >= 10) || (x < 1 && x > 0)) {
            if (x < 1 && x > 0) {
                x *= 10;
                degree -= 1;
            } else {
                x *= 0.1;
                degree += 1;
            }
        }
        x = sign * x / 10;
        if (x < 0) {
            res = -s21_NAN;
        } else if (x == 0) {
            res = -s21_INF;
        } else {
            x--;
            res = x;
            temp = x;
            while (s21_fabs(res) > s21_EPS) {
                res *= -x * (count - 1) / count;
                count += 1;
                temp += res;
            }
            res = temp + (degree + 1) * s21_LN10;
        }
    }

    return (res);
}
