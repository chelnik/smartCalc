#include "s21_math.h"

/**
 * @brief возвращает ближайшее целое число, не превышающее заданное значение
 */
long double s21_floor(double x) {
    long long int temp = (long long int)x;
    if (temp > x) {
        temp--;
    }

    return temp;
}
