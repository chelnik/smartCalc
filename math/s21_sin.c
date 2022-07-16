#include "s21_math.h"


/**
 * @brief вычисляет синус
 */
long double s21_sin(double x) {
    remove_circle(&x);
    long double res = x;
    long double sumTeilor = x;
    int n = 1;

    while (s21_fabs(res) > s21_EPS) {
        res = -1 * res * x * x / (2 * n * (2 * n + 1));
        sumTeilor += res;
        n += 1;
    }

    return (sumTeilor);
}
// OLD version
// long double s21_sin(double x) {
//     // ряд тейлора
//     remove_circle(&x);
//     long double res = x;
//     long double sumTeilor = x;
//     int n = 3;
//     int count = 1;
//     while (count < 10) {
//         res = s21_pow(-1, count) * s21_pow(x, n) / factorial(n);
//         sumTeilor += res;
//         n += 2;
//         count++;
//     }
//     return sumTeilor;
// }

// long long int factorial(int x) {
//     if (x == 1) return 1;
//     return x * factorial(x - 1);
// }
