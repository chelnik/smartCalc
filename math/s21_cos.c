#include "s21_math.h"

/**
 * @brief вычисляет абсолютное значение целого числа
 */
long double s21_cos(double x) {
    remove_circle(&x);
    return s21_sin(s21_PI / 2.0 - x);
}
