#include "s21_math.h"

/**
 * @brief возвращает ближайшее целое число, не меньшее заданного значения
 */
long double s21_ceil(double x) {
    long long int temp = (long long int)x;
    if (temp < x) {
        temp++;
    }
    return temp;
}
