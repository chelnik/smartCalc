// Тут нет магии...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  тут приоритеты операторов 
enum Sign{
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
    int priority;
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
void test_to_remoove();


void delete_space(char *str);
void priority_setter(leksem **head);
int priority_getter(int symbol);
int validator(char *str);
int bracket_cheker(char *str);
//   -----------  Функции ожидающие продакшн
int sign_checker(char *str);
int grammatik_checker(char *str);
//   -----------
void sortstation(char *str, leksem **head);
int is_digit(char symbol);
int is_sign(char symbol);
int is_bracket(char symbol);
void creator(leksem **head, int i, char *str);


void prefixnotation();
void postfixnotation();
void parser(char *str);

// supportFunctions 
void error_checker(int flag_error);
