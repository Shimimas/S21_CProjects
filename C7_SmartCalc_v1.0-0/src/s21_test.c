#include "s21_smart_calc.h"
#include <check.h>

START_TEST(check_value_test) {
    char * string = malloc(sizeof(char) * 256);
    string = "5";
    int error = 0, enter_arr_c = 0;
    double res = 0;
    queue_element_t * arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 5.0 && error == 0);
    string = "5+";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 0.0 && error == 1);
    string = "2";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res && error == 0);
    string = "2-(5*6-3)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == -25.0);
    string = "2-(5*6)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == -28.0);
    string = "+1+2";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 3.0);
    string = "-1+2";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 1.0);
    string = "cos((3+2)*5)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - cos((3+2)*5)) < 0.0000001);
    string = "(10-2)*(2-1)*5";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 40);
    string = "(10-2)*2-1*5";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 11);
    string = "4*2-5*1-5";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == -2);
    string = "1+2-5*1";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == -2);
    string = "1+2-5";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == -2);
    string = "3mod2";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(res == 3 % 2);
    string = "acos(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - acos(1)) < 0.0000001);
    string = "asin(1)*atan(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - asin(1)*atan(1)) < 0.0000001);
    string = "ln(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - log(1)) < 0.0000001);
    string = "log(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - log10(1)) < 0.0000001);
    string = "acos(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - acos(1)) < 0.0000001);
    string = "cos(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - cos(1)) < 0.0000001);
    string = "tan(1)";
    error = 0, enter_arr_c = 0;
    res = 0;
    arr = s21_deicstra_algorithm(string, &error, &enter_arr_c, (int)strlen(string), 0);
    if (error == 0) {
        res =  OPN_alg(arr, enter_arr_c, &error);
    }
    ck_assert(fabs(res - tan(1)) < 0.0000001);
    free(string);
} END_TEST


int main(void) {
  Suite *s1 = suite_create("s21_smart_calc");
  TCase *tc1_1 = tcase_create("s21_smart_calc");
  SRunner *sr = srunner_create(s1);
  int nf;
  tcase_add_test(tc1_1, check_value_test);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
