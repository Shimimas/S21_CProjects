#include <check.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

#include "../cat/s21_cat.h"
#include "../grep/s21_grep.h"

START_TEST(s21_cat_test) {
  FILE *s21_test = fopen("cat/s21_cat_result.txt", "r");
  FILE *cat_test = fopen("cat/cat_result.txt", "r");
  if (s21_test && cat_test) {
    char ct = '\0', cs = '\0';
    while (cs != EOF) {
      ct = getc(s21_test);
      cs = getc(cat_test);
      ck_assert_int_eq(ct, cs);
    }
  }
  fclose(s21_test);
  fclose(cat_test);
}
END_TEST

START_TEST(s21_grep_test) {
  FILE *s21_test = fopen("grep/s21_grep_result.txt", "r");
  FILE *grep_test = fopen("grep/grep_result.txt", "r");
  if (s21_test && grep_test) {
    char ct = '\0', cs = '\0';
    while (cs != EOF) {
      ct = getc(s21_test);
      cs = getc(grep_test);
      ck_assert_int_eq(ct, cs);
    }
  }
  fclose(s21_test);
  fclose(grep_test);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("StringSuite");
  SRunner *sr = srunner_create(s1);
  int nf;

  // BUILD CASE

  TCase *s21_cat_testCase = tcase_create("s21_cat_test");
  suite_add_tcase(s1, s21_cat_testCase);

  TCase *s21_grep_testCase = tcase_create("s21_grep_test");
  suite_add_tcase(s1, s21_grep_testCase);

  // ADD CASE

  tcase_add_test(s21_cat_testCase, s21_cat_test);
  tcase_add_test(s21_grep_testCase, s21_grep_test);

  // START
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
