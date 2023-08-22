#include "s21_smart_calc.h"

int check_unar_sym(char c) {
    int res = 0;
    if (c == '+') {
        res = UNARY_PLUS;
    } else if (c == '-') {
        res = UNARY_MINUS;
    } else if (c == '/') {
        res = DIV;
    } else if (c == '*') {
        res = MULT;
    } else if (c == '(') {
        res = OPEN_BRACKET;
    } else if (c == ')') {
        res = CLOSE_BRACKET;
    } else if (c == '^') {
        res = DEGREE;
    } else if (c == 'x') {
        res = IKS;
    } else if (c == '=' || c == ' ') {
        res = NT;
    }
    return res;
}

queue_element_t * add_arr_el(queue_element_t * operation_mass, int * n, int el, double data) {
    *n = *n + 1;
    operation_mass = realloc(operation_mass, sizeof(queue_element_t) * (*n));
    if (operation_mass != NULL) {
        operation_mass[*n-1].data = data;
        operation_mass[*n-1].type = el;
        operation_mass[*n-1].ptr = NULL;
    }
    return operation_mass;
}

int Parsing(int i, int N, int type, char * str, ...) {
    va_list point_f;
    va_start(point_f, str);
    int res = 0;
    if (i + type < N) {
        for (int j = 0; j < type; j++, i++) {
            char a = (char)va_arg(point_f, int);
            if (str[i] != a) {
                res = 1;
                break;
            }
        }
    } else {
        res = 1;
    }
    va_end(point_f);
    return res;
}

queue_element_t * input_check_and_parsing(char * string, int * res, int * n, int N) {
    queue_element_t * operation_mass = NULL;
    for (int i = 0; i < N; i++) {
        if (check_unar_sym(string[i]) > 0) {
            int type = check_unar_sym(string[i]);
            operation_mass = add_arr_el(operation_mass, n, type, 0);
        } else if (string[i] >= '0' && string[i] <= '9') {
            int temp = i;
            int col = 1, col_before_p = 0;
            int point = 0;
            i++;
            while (i < N) {
                if (string[i] == '.') {
                    col_before_p = i - temp;
                    point++;
                }
                if ((string[i] < '0' || string[i] > '9') && string[i] != '.') {
                    i--;
                    break;
                } else {
                    col++;
                    i++;
                }
            }
            if (i >= N) {
                i--;
            }
            if ((point != 0 && point != 1) || (point == 1 && string[i] == '.')) {
                *res = 1;
            }
            if (col_before_p == 0) {
                col_before_p = i - temp + 1;
            }
            if (*res != 1) {
                double result = 0;
                for (int z = 0, step = col_before_p - 1; z < col; z++, step--, temp++) {
                    if (string[temp] == '.') {
                        step++;
                    } else {
                        result += (string[temp] - '0') * pow(10, step);
                    }
                }
                operation_mass = add_arr_el(operation_mass, n, NUMBER, result);
            }
        } else if (i < N) {
            if ((*res = Parsing(i, N, 3, string, (int)'m', (int)'o', (int)'d')) == 0) {
                i = i + 2;
                operation_mass = add_arr_el(operation_mass, n, MOD, 0);
            } else if ((*res = Parsing(i, N, 3, string, (int)'c', (int)'o', (int)'s')) == 0) {
                i = i + 2;
                operation_mass = add_arr_el(operation_mass, n, COS, 0);
            } else if ((*res = Parsing(i, N, 3, string, (int)'s', (int)'i', (int)'n')) == 0) {
                i = i + 2;
                operation_mass = add_arr_el(operation_mass, n, SIN, 0);
            } else if ((*res = Parsing(i, N, 4, string, (int)'s', (int)'q', (int)'r', (int)'t')) == 0) {
                i = i + 3;
                operation_mass = add_arr_el(operation_mass, n, SQRT, 0);
            } else if ((*res = Parsing(i, N, 3, string, (int)'t', (int)'a', (int)'n')) == 0) {
                i = i + 2;
                operation_mass = add_arr_el(operation_mass, n, TAN, 0);
            } else if ((*res = Parsing(i, N, 4, string, (int)'a', (int)'c', (int)'o', (int)'s')) == 0) {
                i = i + 3;
                operation_mass = add_arr_el(operation_mass, n, ACOS, 0);
            } else if ((*res = Parsing(i, N, 4, string, (int)'a', (int)'s', (int)'i', (int)'n')) == 0) {
                i = i + 3;
                operation_mass = add_arr_el(operation_mass, n, ASIN, 0);
            } else if ((*res = Parsing(i, N, 4, string, (int)'a', (int)'t', (int)'a', (int)'n')) == 0) {
                i = i + 3;
                operation_mass = add_arr_el(operation_mass, n, ATAN, 0);
            } else if ((*res = Parsing(i, N, 2, string, (int)'l', (int)'n')) == 0) {
                i = i + 1;
                operation_mass = add_arr_el(operation_mass, n, LN, 0);
            } else if ((*res = Parsing(i, N, 3, string, (int)'l', (int)'o', (int)'g')) == 0) {
                i = i + 2;
                operation_mass = add_arr_el(operation_mass, n, LOG, 0);
            } else {
                *res = 1;
            }
        }
    }
    return operation_mass;
}

int s21_balance_check(queue_element_t * arr, int n) {
    int res = 0;
    int brackes[2];
    for (int i = 0; i < 2; i++) {
        brackes[i] = 0;
    }
    for (int i = 0; i < n && res != 1; i++) {
        if (arr[i].type == OPEN_BRACKET) {
            brackes[0] += 1;
            if (i + 1 < n) {
                if (arr[i + 1].type == CLOSE_BRACKET) {
                    res = 1;
                }
            }
        } else if (arr[i].type == CLOSE_BRACKET) {
            brackes[1] += 1;
        } else if (arr[i].type >= COS && arr[i].type <= LOG) {
            if (i + 1 < n) {
                if (arr[i + 1].type != OPEN_BRACKET) {
                    res = 1;
                }
            }
        } else if (arr[i].type >= UNARY_PLUS && arr[i].type <= MOD) {
            if (i + 1 < n) {
                if (arr[i + 1].type >= UNARY_PLUS && arr[i + 1].type <= MOD) {
                    res = 1;
                }
            } else {
                res = 1;
            }
            if (i - 1 > -1) {
                if (arr[i - 1].type >= UNARY_PLUS && arr[i - 1].type <= MOD) {
                    res = 1;
                }
            } else if (arr[i].type != UNARY_MINUS && arr[i].type != UNARY_PLUS) {
                res = 1;
            }
            if (arr[i].type == UNARY_PLUS) {
                if (i - 1 > -1) {
                    if (arr[i - 1].type != OPEN_BRACKET) {
                        arr[i].type = BINARY_PLUS;
                    }
                }
            }
            if (arr[i].type == UNARY_MINUS) {
                if (i - 1 > -1) {
                    if (arr[i - 1].type != OPEN_BRACKET) {
                        arr[i].type = BINARY_MINUS;
                    }
                }
            }
        }
    }
    if (brackes[1] != brackes[0]) {
        res = 1;
    }
    return res;
}

queue_element_t * AddStackEll(queue_element_t * head, queue_element_t * ell) {
    queue_element_t * temp = head;
    ell->ptr = temp;
    head = ell;
    return head;
}

int ForPriorCheck(int type) {
    if (type == 9 || type == 10) {
        type = 0;
    } else if (type == 5 || type == 6) {
        type = 1;
    } else if (type == 3 || type == 4) {
        type = 4;
    } else {
        type = 3;
    }
    return type;
}

int AsocCheck(int type) {
    if (type == 9 || type == 10 || type == 5 || type == 6) {
        type = 1;
    } else {
        type = 0;
    }
    return type;
}

queue_element_t * s21_deicstra_algorithm(char * string, int * error, int * enter_arr_c, int N, double x) {
    int res = 0;
    int n = 0;
    queue_element_t * arr = input_check_and_parsing(string, &res, &n, N);
    queue_element_t * enter_arr = NULL;
    if (s21_balance_check(arr, n) == 0 && res == 0) {
        queue_element_t * head = NULL;
        for (int i = 0; i < n; i++) {
            if (arr[i].type == NUMBER) {
                enter_arr = add_arr_el(enter_arr, enter_arr_c, NUMBER, arr[i].data);
            } else if (arr[i].type == IKS) {
                enter_arr = add_arr_el(enter_arr, enter_arr_c, NUMBER, x);
            } else if ((arr[i].type >= COS && arr[i].type <= LOG) || (arr[i].type == OPEN_BRACKET)) {
                head = AddStackEll(head, &(arr[i]));
            } else if (arr[i].type >= UNARY_PLUS && arr[i].type <= BINARY_MINUS) {
                while (head != NULL) {
                    int first = ForPriorCheck(head->type);
                    int second = ForPriorCheck(arr[i].type);
                    if (first >= second && head->type >= UNARY_PLUS && head->type <= BINARY_MINUS) {
                        if (first == second) {
                            if (AsocCheck(arr[i].type) == 1) {
                                enter_arr = add_arr_el(enter_arr, enter_arr_c, head->type, head->data);
                                head = head->ptr;
                                if (head != NULL) {
                                    if (head->ptr == NULL) {
                                        head = NULL;
                                    } else {
                                        head = head->ptr;
                                    }
                                }
                            } else {
                                break;
                            }
                        } else {
                            enter_arr = add_arr_el(enter_arr, enter_arr_c, head->type, head->data);
                            if (head->ptr == NULL) {
                                head = NULL;
                            } else {
                                head = head->ptr;
                            }
                        }
                    } else {
                        break;
                    }
                }
                head = AddStackEll(head, &(arr[i]));
            } else if (arr[i].type == CLOSE_BRACKET) {
                if (head != NULL) {
                    while (head->type != OPEN_BRACKET && head->type >= UNARY_PLUS
                    && head->type <= BINARY_MINUS) {
                        enter_arr = add_arr_el(enter_arr, enter_arr_c, head->type, head->data);
                        if (head->ptr == NULL) {
                            head = NULL;
                            break;
                        } else {
                            head = head->ptr;
                        }
                    }
                    if (head->type == OPEN_BRACKET) {
                        head = head->ptr;
                    } else {
                        *error = 1;
                        break;
                    }
                }
                if (head != NULL) {
                    if (head->type >= COS && head->type <= LOG) {
                        enter_arr = add_arr_el(enter_arr, enter_arr_c, head->type, head->data);
                        if (head->ptr == NULL) {
                            head = NULL;
                        } else {
                            head = head->ptr;
                        }
                    }
                }
            }
        }
        int stop = 0;
        while (stop == 0 && head != NULL) {
            if (head->ptr == NULL) {
                stop = 1;
            }
            enter_arr = add_arr_el(enter_arr, enter_arr_c, head->type, head->data);
            head = head->ptr;
        }
    } else {
        *error = 1;
    }
    free(arr);
    return enter_arr;
}

queue_element_t * OPN_support(queue_element_t * head, int type, int ind, int * error) {
    if (ind == 0) {
        if (head != NULL) {
            if (type == UNARY_MINUS) {
                head->data = -1 * (head->data);
            } else if (type == COS) {
                head->data = cos(head->data);
            } else if (type == SIN) {
                head->data = sin(head->data);
            } else if (type == TAN) {
                head->data = tan(head->data);
            } else if (type == ACOS) {
                head->data = acos(head->data);
            } else if (type == ASIN) {
                head->data = asin(head->data);
            } else if (type == ATAN) {
                head->data = atan(head->data);
            } else if (type == SQRT) {
                head->data = sqrt(head->data);
            } else if (type == LN) {
                head->data = log(head->data);
            } else if (type == LOG) {
                head->data = log10(head->data);
            }
        } else {
            *error = 1;
        }
    } else {
        if (head != NULL && head->ptr != NULL) {
            if (type == MULT) {
                head->ptr->data *= (head->data);
            } else if (type == DIV) {
                head->ptr->data /= (head->data);
            } else if (type == DEGREE) {
                head->ptr->data = pow(head->ptr->data, head->data);
            } else if (type == MOD) {
                head->ptr->data = fmod(head->ptr->data, head->data);
            } else if (type == BINARY_PLUS) {
                head->ptr->data += head->data;
            } else if (type == BINARY_MINUS) {
                head->ptr->data -= head->data;
            }
            head = head->ptr;
        } else {
            *error = 1;
        }
    }
    return head;
}

double OPN_alg(queue_element_t * arr, int n, int * error) {
    queue_element_t * head = NULL;
    double res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].type == NUMBER) {
            head = AddStackEll(head, &(arr[i]));
        } else if (arr[i].type == UNARY_MINUS || (arr[i].type >= COS && arr[i].type <= LOG)) {
            head = OPN_support(head, arr[i].type, 0, error);
        } else {
            head = OPN_support(head, arr[i].type, 1, error);
        }
    }
    if (head != NULL) {
        res = head->data;
    }
    free(arr);
    return res;
}
