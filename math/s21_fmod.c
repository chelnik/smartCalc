#include "s21_math.h"

/**
 * @brief остаток операции деления с плавающей точкой
 */
long double s21_fmod(double x, double y) {
    long double result = x;
    if (y == 0)
        result = s21_NAN;
    else
        result -= (long long int)(x / y) * y;
    return result;
}
