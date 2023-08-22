#include "s21_matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


matrix_t s21_create_matrix(int rows, int columns) {
    matrix_t zero;
    if (rows > 0 && columns > 0 && (zero.matrix = s21_memory_allocation(rows, columns)) != NULL) {
        s21_mat_res(&zero, columns, rows, ZERO_MATRIX);
    } else {
        zero.matrix = NULL;
        s21_mat_res(&zero, 0, 0, INCORRECT_MATRIX);
    }
    return zero;
}

void s21_remove_matrix(matrix_t *A) {
    if (s21_check(A) == 1) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                A->matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        s21_mat_res(A, 0, 0, INCORRECT_MATRIX);
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int res = 1;
    if (s21_check(A) == 1 && s21_check(B) == 1 && A->columns == B->columns && A->rows == B->rows) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j]) - fabs(B->matrix[i][j]) >= EPS
                && isinf_isnan_check(A->matrix[i][j]) == 1
                && isinf_isnan_check(B->matrix[i][j]) == 1) {
                    res = 0;
                    break;
                }
            }
        }
    } else {
        res = 0;
    }
    return res;
}

matrix_t s21_sum_matrix(matrix_t *A, matrix_t *B) {
    return s21_arifmetic_matrix(A, B, 1);
}

matrix_t s21_sub_matrix(matrix_t *A, matrix_t *B) {
    return s21_arifmetic_matrix(A, B, 0);
}

matrix_t s21_mult_number(matrix_t *A, double number) {
    int error = 0;
    matrix_t res;
    if (s21_check(A) == 1 && isinf_isnan_check(number) == 1) {
        res = s21_create_matrix(A->rows, A->columns);
        if (res.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    if (isinf_isnan_check(A->matrix[i][j]) == 1) {
                        res.matrix[i][j] = number * A->matrix[i][j];
                    } else {
                        error = 1;
                        break;
                    }
                }
            }
            s21_mat_res(&res, A->columns, A->rows, s21_matrix_type(res));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

matrix_t s21_mult_matrix(matrix_t *A, matrix_t *B) {
    int error = 0;
    matrix_t res;
    if (s21_check(A) == 1 && s21_check(B) == 1 && A->columns == B->rows) {
        res = s21_create_matrix(A->rows, B->columns);
        if (res.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < res.rows; i++) {
                for (int j = 0; j < res.columns; j++) {
                    for (int k = 0; k < A->columns; k++) {
                        if (isinf_isnan_check(A->matrix[i][k]) == 1
                        && isinf_isnan_check(B->matrix[k][j]) == 1) {
                            res.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                        } else {
                            error = 1;
                            break;
                        }
                    }
                }
            }
            s21_mat_res(&res, B->columns, A->rows, s21_matrix_type(res));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

matrix_t s21_transpose(matrix_t *A) {
    int error = 0;
    matrix_t res;
    if (s21_check(A) == 1) {
        res = s21_create_matrix(A->columns, A->rows);
        if (res.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < res.rows; i++) {
                for (int j = 0; j < res.columns; j++) {
                    if (isinf_isnan_check(A->matrix[j][i]) == 1) {
                        res.matrix[i][j] = A->matrix[j][i];
                    } else {
                        error = 1;
                        break;
                    }
                }
            }
            s21_mat_res(&res, A->rows, A->columns, s21_matrix_type(res));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

double s21_determinant(matrix_t *A) {
    double res = 0;
    if (s21_check(A) == 1 && A->rows == A->columns) {
        if (A->rows == 1) {
            if (isinf_isnan_check(A->matrix[0][0]) == 1) {
                res = A->matrix[0][0];
            }
        } else if (A->rows == 2) {
            if (isinf_isnan_check(A->matrix[0][0]) == 1
            && isinf_isnan_check(A->matrix[1][1]) == 1
            && isinf_isnan_check(A->matrix[1][0]) == 1
            && isinf_isnan_check(A->matrix[0][1]) == 1) {
                res = (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
            }
        } else {
            for (int i = 0; i < A->columns; i++) {
                matrix_t minor = s21_minor(A, 0, i);
                if (isinf_isnan_check(A->matrix[0][i]) == 1) {
                    res += pow(-1, i) * A->matrix[0][i] * s21_determinant(&minor);
                }
                s21_remove_matrix(&minor);
            }
        }
    } else {
        res = NAN;
    }
    return res;
}

matrix_t s21_calc_complements(matrix_t *A) {
    int error = 0;
    matrix_t res;
    if (s21_check(A) == 1 && A->rows == A->columns) {
        res = s21_create_matrix(A->rows, A->columns);
        if (res.matrix_type != INCORRECT_MATRIX) {
            if (A->rows == 1) {
                    res.matrix[0][0] = A->matrix[0][0];
            } else {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        matrix_t minor = s21_minor(A, i, j);
                        res.matrix[i][j] = pow((-1), i+j) * s21_determinant(&minor);
                        s21_remove_matrix(&minor);
                    }
                }
            }
            s21_mat_res(&res, A->columns, A->rows, s21_matrix_type(res));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

matrix_t s21_inverse_matrix(matrix_t *A) {
    matrix_t res;
    int error = 0;
    if (s21_check(A) == 1 && A->columns == A->rows) {
        res = s21_create_matrix(A->rows, A->columns);
        if (res.matrix_type != INCORRECT_MATRIX) {
            double det = s21_determinant(A);
            if (isinf_isnan_check(det) == 1 && det != 0) {
                matrix_t calc_complements, transpose;
                calc_complements = s21_calc_complements(A);
                transpose = s21_transpose(&calc_complements);
                res = s21_mult_number(&transpose, (1.0/det));
                s21_remove_matrix(&transpose);
                s21_remove_matrix(&calc_complements);
            } else {
                error = 1;
            }
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

double ** s21_memory_allocation(int rows, int columns) {
    int error = 0;
    double ** matrix = calloc(rows, sizeof(double *));
    if (matrix != NULL) {
        for  (int i = 0; i < rows; i++) {
            matrix[i] = calloc(columns, sizeof(double));
            if (matrix[i] == NULL) {
                error = 1;
                break;
            }
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        matrix = NULL;
    }
    return matrix;
}

matrix_t s21_arifmetic_matrix(matrix_t *A, matrix_t *B, int type) {
    matrix_t res;
    int error = 0;
    if (s21_check(A) == 1 && s21_check(B) == 1 && A->columns == B->columns && A->rows == B->rows) {
        res = s21_create_matrix(A->rows, A->columns);
        if (res.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0; i < B->rows; i++) {
                for (int j = 0; j < B->columns; j++) {
                    if (isinf_isnan_check(A->matrix[i][j]) == 1 && isinf_isnan_check(B->matrix[i][j]) == 1) {
                        if (type == 1) {
                            res.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                        } else {
                            res.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                        }
                    } else {
                        error = 1;
                        break;
                    }
                }
            }
            s21_mat_res(&res, A->columns, A->rows, s21_matrix_type(res));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&res, 0, 0, INCORRECT_MATRIX);
    }
    return res;
}

int s21_matrix_type(matrix_t A) {
    int res = CORRECT_MATRIX;
    int diagonal = -1;
    int pereferia = 0;
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.columns; j++) {
            if (i != j && A.matrix[i][j] != 0) {
                pereferia = -1;
                break;
            }
        }
    }
    if (A.columns == A.rows && pereferia == 0) {
        diagonal = A.matrix[0][0];
        if (diagonal == 0 || diagonal == 1) {
            for (int i = 0; i < A.columns; i++) {
                if (A.matrix[i][i] != diagonal) {
                    diagonal = -1;
                    break;
                }
            }
        }
    }
    if (diagonal == 0) {
        res = ZERO_MATRIX;
    } else if (diagonal == 1) {
        res = IDENTITY_MATRIX;
    }
    return res;
}

int s21_check(matrix_t * A) {
    int res = 0;
    if (A != NULL && A->columns > 0 && A->rows > 0 && A->matrix_type != INCORRECT_MATRIX) {
        res = 1;
    }
    return res;
}

int isinf_isnan_check(double x) {
    int res = 1;
    if (isnan(x) || isinf(x)) {
        res = 0;
    }
    return res;
}

void s21_mat_res(matrix_t * A, int colums, int rows, int type) {
    A->columns = colums;
    A->rows = rows;
    A->matrix_type = type;
}

matrix_t s21_minor(matrix_t * A, int i_idx, int j_idx) {
    int error = 0;
    matrix_t minor;
    if (s21_check(A) == 1 && A->rows == A->columns) {
        minor = s21_create_matrix(A->rows - 1, A->columns - 1);
        if (minor.matrix_type != INCORRECT_MATRIX) {
            for (int i = 0, i_m = 0; i < A->rows; i++) {
                if (i != i_idx) {
                    for (int j = 0, j_m = 0; j < A->columns; j++) {
                        if (j != j_idx) {
                            minor.matrix[i_m][j_m] = A->matrix[i][j];
                            j_m++;
                        }
                    }
                    i_m++;
                }
            }
            s21_mat_res(&minor, A->columns - 1, A->rows - 1, s21_matrix_type(minor));
        } else {
            error = 1;
        }
    } else {
        error = 1;
    }
    if (error == 1) {
        s21_mat_res(&minor, 0, 0, INCORRECT_MATRIX);
    }
    return minor;
}
