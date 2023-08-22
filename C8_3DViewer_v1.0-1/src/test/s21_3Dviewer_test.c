#include "../s21_3Dviewer.h"

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define EPS 0.000001

char *check_path() {
  char *PathName = malloc(sizeof(char) * PATH_MAX);
  char *PN;
  PN = getwd(PathName);
  strcat(PathName, "/test/test1.obj");
  // printf("Текущая директория: %s\n", PathName);

  return PathName;
}

char *check_path_2() {
  char *PathName = malloc(sizeof(char) * PATH_MAX);
  char *PN;
  PN = getwd(PathName);
  strcat(PathName, "/test/test2.obj");
  // printf("Текущая директория: %s\n", PathName);

  return PathName;
}

START_TEST(test1_1) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  int res_array[9] = {0, 1, -1, 1, 0, -1, 1, 1, 1};
  for (int j = 0; j < 9; j++) {
    ck_assert_int_eq(data.coord_array[j], res_array[j]);
  }
}
END_TEST

START_TEST(test1_2) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  int connect_res[6] = {0, 1, 1, 2, 0, 2};
  for (int j = 0; j < 6; j++) {
    ck_assert_float_eq(data.connect_array[j], connect_res[j]);
  }
}
END_TEST

START_TEST(test1_3) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Scale(data, 8);
  float scale_res[9] = {0, 2, -2, 2, 0, -2, 2, 2, 2};
  for (int k = 0; k < 9; k++) {
    ck_assert_float_eq(data.coord_array[k], scale_res[k]);
  }
}
END_TEST

START_TEST(test1_4) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'x');
  double tx[9] = {0.000000,  1.129441, -0.851095, 1.000000, 0.139173,
                  -0.990268, 1.000000, 0.851095,  1.129441};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - tx[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test1_5) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'y');
  double ty[9] = {-0.139173, 1.000000, -0.990268, 0.851095, 0.000000,
                  -1.129441, 1.129441, 1.000000,  0.851095};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - ty[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test1_6) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'z');
  double tz[9] = {-0.139173, 0.990268, -1.000000, 0.990268, 0.139173,
                  -1.000000, 0.851095, 1.129441,  1.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - tz[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}

START_TEST(test1_7) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'x');
  double sx[9] = {8.000000,  1.000000, -1.000000, 9.000000, 0.000000,
                  -1.000000, 9.000000, 1.000000,  1.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sx[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test1_8) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'y');
  double sy[9] = {0.000000,  9.000000, -1.000000, 1.000000, 8.000000,
                  -1.000000, 1.000000, 9.000000,  1.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sy[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}

START_TEST(test1_9) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'z');
  double sz[9] = {0.000000, 1.000000, 7.000000, 1.000000, 0.000000,
                  7.000000, 1.000000, 1.000000, 9.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sz[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test2_1) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  int res_array[9] = {2, 1, -1, 4, 5, -1, -6, 1, 3};
  for (int j = 0; j < 9; j++) {
    ck_assert_int_eq(data.coord_array[j], res_array[j]);
  }
}
END_TEST

START_TEST(test2_2) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  int connect_res[6] = {0, 1, 1, 2, 0, 2};
  for (int j = 0; j < 6; j++) {
    ck_assert_float_eq(data.connect_array[j], connect_res[j]);
  }
}
END_TEST

START_TEST(test2_3) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Scale(data, 8);
  float scale_res[9] = {4, 2, -2, 8, 10, -2, -12, 2, 6};
  for (int k = 0; k < 9; k++) {
    ck_assert_float_eq(data.coord_array[k], scale_res[k]);
  }
}
END_TEST

START_TEST(test2_4) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'x');
  double tx[9] = {2.000000,  1.129441,  -0.851095, 4.000000, 5.090513,
                  -0.294403, -6.000000, 0.572749,  3.109977};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - tx[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test2_5) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'y');
  double ty[9] = {1.841363,  1.000000,  -1.268614, 3.821899, 5.000000,
                  -1.546960, -5.524089, 1.000000,  3.805843};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - ty[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test2_6) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = TurnAround(data, 8, 'z');
  double tz[9] = {1.841363,  1.268614,  -1.000000, 3.265207, 5.508033,
                  -1.000000, -6.080782, 0.155229,  3.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - tz[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}

START_TEST(test2_7) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'x');
  double sx[9] = {10.000000, 1.000000, -1.000000, 12.000000, 5.000000,
                  -1.000000, 2.000000, 1.000000,  3.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sx[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

START_TEST(test2_8) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'y');
  double sy[9] = {2.000000,  9.000000,  -1.000000, 4.000000, 13.000000,
                  -1.000000, -6.000000, 9.000000,  3.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sy[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}

START_TEST(test2_9) {
  vertex_t data;
  int error = 0;
  FILE *fp = fopen(check_path_2(), "r");
  data = Parsing(fp, &error);
  fclose(fp);
  ck_assert_int_eq(data.col, 9);
  ck_assert_int_eq(data.col_connect, 6);
  ck_assert_int_eq(error, 0);
  data = Shift(data, 8, 'z');
  double sz[9] = {2.000000, 1.000000,  7.000000, 4.000000, 5.000000,
                  7.000000, -6.000000, 1.000000, 11.000000};
  for (int k = 0; k < 9; k++) {
    int flag = 0;
    if (fabs(data.coord_array[k] - sz[k]) < EPS) {
      flag = 1;
    } else {
      flag = 0;
    }
    ck_assert_int_eq(flag, 1);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_smart_calc");
  TCase *tc1_1 = tcase_create("s21_smart_calc");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test1_1);
  tcase_add_test(tc1_1, test1_2);
  tcase_add_test(tc1_1, test1_3);
  tcase_add_test(tc1_1, test1_4);
  tcase_add_test(tc1_1, test1_5);
  tcase_add_test(tc1_1, test1_6);
  tcase_add_test(tc1_1, test1_7);
  tcase_add_test(tc1_1, test1_8);
  tcase_add_test(tc1_1, test1_9);

  tcase_add_test(tc1_1, test2_1);
  tcase_add_test(tc1_1, test2_2);
  tcase_add_test(tc1_1, test2_3);
  tcase_add_test(tc1_1, test2_4);
  tcase_add_test(tc1_1, test2_5);
  tcase_add_test(tc1_1, test2_6);
  tcase_add_test(tc1_1, test2_7);
  tcase_add_test(tc1_1, test2_8);
  tcase_add_test(tc1_1, test2_9);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
