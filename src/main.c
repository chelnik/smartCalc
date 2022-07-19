#include "underfile.h"

 int main() {
//     char str[255] = "777+69-3333333333333";
     char str[255] = "(611 * 233) + 8 + 800 * 2 + (2 + 2 * (4 * 6 * 5 * (4 + 8231))) - 100";
     double x = 0.5;
     double result = 0;
     // delete_space(str);
     if (validator(str) == 0) {
         printf("%s", str);

         printf("\n ---------");
         if (parser(str, x, &result) == 0)
         printf("\n\n%lf", result);
     } else {
         printf("\n error");
     }
     // testing();
     return 0;
 }

