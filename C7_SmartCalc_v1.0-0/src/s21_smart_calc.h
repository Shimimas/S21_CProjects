#ifndef SRC_S21_SMART_CALC_H_
#define SRC_S21_SMART_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
    NUMBER = 0,
    OPEN_BRACKET = 1,
    CLOSE_BRACKET = 2,
    UNARY_PLUS = 3,
    UNARY_MINUS = 4,
    MULT = 5,
    DIV = 6,
    DEGREE = 7,
    MOD = 8,
    BINARY_PLUS = 9,
    BINARY_MINUS = 10,
    COS = 11,
    SIN = 12,
    TAN = 13,
    ACOS = 14,
    ASIN = 15,
    ATAN = 16,
    SQRT = 17,
    LN = 18,
    LOG = 19,
    IKS = 20,
    NT = 21
} operation_t;

typedef struct queue_struct {
    double data;
    operation_t type;
    struct queue_struct * ptr;
} queue_element_t;

double OPN_alg(queue_element_t * arr, int n, int * error);
queue_element_t * s21_deicstra_algorithm(char * string, int * error, int * enter_arr_c, int N, double x);

#endif  // SRC_S21_SMART_CALC_H_
