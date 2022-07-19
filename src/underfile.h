#ifndef SRC_UNDERFILE_H_
#define SRC_UNDERFILE_H_
//  Тут нет магии...
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  #include "../math/s21_math.h"
//  тут приоритеты операторов
enum Sign {
    MINUS = 1,
    PLUS = 1,
    DIVIDE = 2,
    MULTIPLE = 2,
};
enum enum_type {
    open_bracket,
    close_bracket,
    x,
    number,
    add,
    sub,
    multiply,
    divide,
    e_exp,
    e_mod,
    e_sin,
    e_cos,
    e_tan,
    e_asin,
    e_acos,
    e_atan,
    e_sqrt,
    e_ln,
    e_log
};

//  создаем ноду
//  называем лексемой
// STACK
typedef struct Node {
    int value;
    double value_double;
    int priority;
    int type;
    struct Node *next;
} leksem;

#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0

// listFunction
leksem *create(int data);
leksem *add_element_start(int data, leksem *head);
leksem *push(int data, leksem *head);
int pop(leksem **head);
int notempty(leksem *head);

leksem *add_element_n_position(int data, int n, leksem *head);
leksem *remove_element(int data, leksem *head);
leksem *remove_all(leksem *head);
void print_list(leksem *head);
void printer(leksem *head);
// void test_to_remoove();

void delete_space(char *str);
void priority_setter(leksem **head);
int priority_getter(int symbol);
int validator(char *str);
int bracket_cheker(char *str);
//   -----------  Функции ожидающие продакшн
int sign_checker(char *str);
int grammatik_checker(char *str);
//   -----------

int is_digit(char symbol);
int is_sign(char symbol);
int is_bracket(char symbol);

// void sortstation(char *str, leksem **head);

//----------------------------------------------------------------
int parser(char *str, double x, double *result);
int calculate(leksem **output, double *result);
//----------------------------------------------------------------

leksem *reverse_stack(leksem *head);
// supportFunctions
void error_checker(int flag_error);

leksem *push_double(double data, leksem *head);
double pop_double(leksem **head);
int view_type(leksem **head);
leksem *super_push(leksem *old, leksem *head);
int num_el_in_stack(leksem *head);

int function_handler(char *str, int *i, leksem **head);
leksem *push_type(int type, leksem *head);
int is_function(int type);
char *return_name_function(int type);
double pop_type(leksem **head);
double pop_double_for_parser(leksem *head);
// void testing();
int divide_by_zero_checker(leksem **output);

#endif  // SRC_UNDERFILE_H_
