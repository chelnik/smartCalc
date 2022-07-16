#include "s21_math.h"

/**
 * @brief функция удаляет лишние круги в числе
 */
void remove_circle(double *x) {
    while (*x > s21_PI || *x < -s21_PI) {
        if (*x < s21_PI) {
            *x+= 2 * s21_PI;
        } else {
            *x-= 2 * s21_PI;
        }
    }
}
