#include <check.h>
#include <stdio.h>

#include "underfile.h"


START_TEST(s21_calc) {
    char str[255] =
        "-((611 * 233) + 8 + 800 * 2 - (2 - 2 * (4 * 6 * 245 - (4 + 8231))) * 1033)";
    char str1[255] =
        "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
    char str2[255] = "-( -( - 4.4 - 1.1) ) ";
    char str3[255] = "9mod2";
    char str4[255] = "(6 * 2) + 8";
    char str5[255] = "hi";
    char str6[255] = "(6 ^ 2) / 8";
    char str7[255] = "cos(sin(log(1)))";
    double x = 0.5;
    double result = 0;
    char* array_str[] = {str, str1, str2, str3, str4, str5, str6, str7};
    for (size_t i = 0; i < (sizeof(array_str) / sizeof(char*)); i++) {
        delete_space(array_str[i]);
        if (validator(array_str[i]) == 0) {
            printf("\n ---------");
            if (parser(array_str[i], x, &result) == 0)
            printf("\n\n%lf\n", result);
        } else {
            printf("\n error");
        }
    }
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);

    tcase_add_test(tc1_1, s21_calc);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
