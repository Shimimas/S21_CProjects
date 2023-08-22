#include <check.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

// STR FUNCTIONS

START_TEST(strLenCheck) {
  char *array1 = "";
  char *array2 = "1234567890-=!@#$/q^&*(){}";
  char *array3 = "   qwertyuioplkjhgfdsazxcvbnm";
  char *array4 = " \r \33 ";
  char *array5 = "   1\0 dfgdfgdfgdf";

  ck_assert_msg(s21_strlen(array1) == strlen(array1), "failed on 0");
  ck_assert_msg(s21_strlen(array2) == strlen(array2), "failed on 24");
  ck_assert_msg(s21_strlen(array3) == strlen(array3), "failed on 29");
  ck_assert_msg(s21_strlen(array4) == strlen(array4), "failed on 5");
  ck_assert_msg(s21_strlen(array5) == strlen(array5), "failed on 4");
}
END_TEST

START_TEST(strCmpCheck) {
  char *array1 = "";
  char *array2 = "   qwertyuioplkjhgfdsazxcvbnm";
  char *array3 = "0  -=!@#$/q^&*(){}1234567890";
  char *array4 = "\n \4 \0 dfgdfgdfdfgdfgdfgdfgdfg";
  char *array5 = "qqqq";
  char *array6 = "qqqQ";

  ck_assert_msg(s21_strcmp(array1, array1) == strcmp(array1, array1),
                "failed on 0");
  ck_assert_msg(s21_strcmp(array2, array1) == strcmp(array2, array1),
                "failed on 32");
  ck_assert_msg(s21_strcmp(array1, array3) == strcmp(array1, array3),
                "failed on -48");
  ck_assert_msg(s21_strcmp(array4, array2) == strcmp(array4, array2),
                "failed on -22");
  ck_assert_msg(s21_strcmp(array5, array6) == strcmp(array5, array6),
                "failed on 32");
}
END_TEST

START_TEST(strCpyCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = NULL;
  res_a1 = s21_strcpy(array2, array1);
  char *res_b1 = strcpy(arrayStr2, arrayStr1);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_strcpy(array2, array1);
  char *res_b2 = strcpy(arrayStr2, arrayStr1);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strcpy(array2, array3);
  char *res_b3 = strcpy(arrayStr2, arrayStr3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_strcpy(array3, array4);
  char *res_b4 = strcpy(arrayStr3, arrayStr4);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_strcpy(array4, array5);
  char *res_b5 = strcpy(arrayStr4, arrayStr5);
  ck_assert_str_eq(res_a5, res_b5);
}
END_TEST

START_TEST(strCatCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array2_2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr2_2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = strcat(array1, "");
  char *res_b1 = s21_strcat(arrayStr1, "");
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_strcat(array2, arrayStr2 + 2);
  char *res_b2 = s21_strcat(arrayStr2, array2 + 2);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strcat(array1, array3);
  char *res_b3 = s21_strcat(arrayStr1, arrayStr3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_strcat(array4, array2_2);
  char *res_b4 = s21_strcat(arrayStr4, arrayStr2_2);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_strcat(array4, array5);
  char *res_b5 = s21_strcat(arrayStr4, arrayStr5);
  ck_assert_str_eq(res_a5, res_b5);
}
END_TEST

START_TEST(strMemchrCheck) {
  char arr1[20] = "sdhfgsdkfg";
  char arr2[20] = "sdhf2g sdkfg";
  char arr3[20] = "sdhfg\0sdGfg";

  char *c1 = s21_memchr(arr1, 's', 20);
  char *c1_1 = s21_memchr(arr1, 'f', 20);
  char *c2 = s21_memchr(arr2, ' ', 20);
  char *c2_2 = s21_memchr(arr2, '2', 20);
  char *c3 = s21_memchr(arr3, 'G', 20);

  char *c1Str = s21_memchr(arr1, 's', 20);
  char *c1_1Str = s21_memchr(arr1, 'f', 20);
  char *c2Str = s21_memchr(arr2, ' ', 20);
  char *c2_2Str = s21_memchr(arr2, '2', 20);
  char *c3Str = s21_memchr(arr3, 'G', 20);

  int n1 = c1 - arr1;
  int n1_1 = c1_1 - arr1;
  int n2 = c2 - arr2;
  int n2_2 = c2_2 - arr2;
  int n3 = c3 - arr3;

  int n1Str = c1Str - arr1;
  int n1_1Str = c1_1Str - arr1;
  int n2Str = c2Str - arr2;
  int n2_2Str = c2_2Str - arr2;
  int n3Str = c3Str - arr3;

  ck_assert_int_eq(n1, n1Str);
  ck_assert_int_eq(n1_1, n1_1Str);
  ck_assert_int_eq(n2, n2Str);
  ck_assert_int_eq(n2_2, n2_2Str);
  ck_assert_int_eq(n3, n3Str);
}
END_TEST

START_TEST(strMemcmpCheck) {
  char *array1 = "";
  char *array2 = "   qwertyuioplkjhgfdsazxcvbnm";
  char *array3 = "0  -=!@#$/q^&*(){}1234567890";
  char *array4 = "\n \4 \0 dfgdfgdfdfgdfgdfgdfgdfg";
  char *array5 = "qqqq";
  char *array6 = "qqqQ";

  ck_assert_msg(s21_memcmp(array1, array1, 30) == memcmp(array1, array1, 30),
                "failed on 30");
  ck_assert_msg(s21_memcmp(array2, array1, 3) == memcmp(array2, array1, 3),
                "failed on 3");
  ck_assert_msg(s21_memcmp(array1, array3, 14) == memcmp(array1, array3, 14),
                "failed on 14");
  ck_assert_msg(
      s21_memcmp(array4 + 7, array2, 6) == memcmp(array4 + 7, array2, 6),
      "failed on 7 first shift");
  ck_assert_msg(s21_memcmp(array5 + 2, array6 + 1, 21) ==
                    memcmp(array5 + 2, array6 + 1, 21),
                "failed on 2/1 both shift");
}
END_TEST

START_TEST(strMemcpyCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  // char crutoiSanek[20]="SANEK_CRUTOI";
  // char crutoiSanekStr[20]="SANEK_CRUTOI";

  char *res_a1 = s21_memcpy(array2, array1, 5);
  char *res_b1 = memcpy(arrayStr2, arrayStr1, 5);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_memcpy(array2, array1, 10);
  char *res_b2 = memcpy(arrayStr2, arrayStr1, 10);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_memcpy(array2, array3, 3);
  char *res_b3 = memcpy(arrayStr2, arrayStr3, 3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_memcpy(array3 + 3, array4, 7);
  char *res_b4 = memcpy(arrayStr3 + 3, arrayStr4, 7);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_memcpy(array4, array5 + 3, 2);
  char *res_b5 = memcpy(arrayStr4, arrayStr5 + 3, 2);
  ck_assert_str_eq(res_a5, res_b5);

  /* char * res_a6 = s21_memcpy(crutoiSanek + 6, crutoiSanek + 3, 5);
   char * res_b6 = memcpy(crutoiSanekStr + 6, crutoiSanekStr + 3, 5);
   ck_assert_str_eq(res_a6, res_b6);*/ // BEDA-BAIDA

  /*char * res_a7 = s21_memcpy(array5 + 3, array5, 5);
  char * res_b7 = memcpy(arrayStr5 + 3, arrayStr5, 5);
  ck_assert_str_eq(res_a7, res_b7);*/ // BEDA-BAIDA
}
END_TEST

START_TEST(strMemmoveCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char crutoiSanek[20] = "SANEK_CRUTOI";
  char crutoiSanekStr[20] = "SANEK_CRUTOI";

  char *res_a1 = s21_memmove(array2, array1, 5);
  char *res_b1 = memmove(arrayStr2, arrayStr1, 5);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_memcpy(array2, array1, 10);
  char *res_b2 = memmove(arrayStr2, arrayStr1, 10);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_memmove(array2, array3, 3);
  char *res_b3 = memmove(arrayStr2, arrayStr3, 3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_memmove(array3 + 3, array4, 7);
  char *res_b4 = memmove(arrayStr3 + 3, arrayStr4, 7);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_memmove(array4, array5 + 3, 2);
  char *res_b5 = memmove(arrayStr4, arrayStr5 + 3, 2);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_memmove(crutoiSanek, crutoiSanek + 6, 7);
  char *res_b6 = memmove(crutoiSanekStr, crutoiSanekStr + 6, 7);
  ck_assert_str_eq(res_a6, res_b6);

  char *res_a7 = s21_memmove(array5 + 7, array5, 5);
  char *res_b7 = memmove(arrayStr5 + 7, arrayStr5, 5);
  ck_assert_str_eq(res_a7, res_b7);
}
END_TEST

START_TEST(strMemsetCheck) {
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char A = 'A';
  char space = ' ';
  char EOL = '\0';

  char crutoiSanek[20] = "SANEK_CRUTOI";
  char crutoiSanekStr[20] = "SANEK_CRUTOI";

  char *res_a1 = s21_memset(array2, A, 5);
  char *res_b1 = memset(arrayStr2, A, 5);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_memset(array2, space, 10);
  char *res_b2 = memset(arrayStr2, space, 10);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_memset(array2, EOL, 3);
  char *res_b3 = memset(arrayStr2, EOL, 3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_memset(array3 + 3, A, 7);
  char *res_b4 = memset(arrayStr3 + 3, A, 7);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_memset(array4 + 5, space, 2);
  char *res_b5 = memset(arrayStr4 + 5, space, 2);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_memset(crutoiSanek, EOL, 7);
  char *res_b6 = memset(crutoiSanekStr, EOL, 7);
  ck_assert_str_eq(res_a6, res_b6);

  char *res_a7 = s21_memset(array5 + 7, A, 5);
  char *res_b7 = memset(arrayStr5 + 7, A, 5);
  ck_assert_str_eq(res_a7, res_b7);
}
END_TEST

START_TEST(strStrncatCheck) {
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char A = 'A';
  char space = ' ';
  char EOL = '\0';

  char crutoiSanek[20] = "SANEK_CRUTOI";
  char crutoiSanekStr[20] = "SANEK_CRUTOI";

  char *res_a1 = s21_strncat(array2, &A, 5);
  char *res_b1 = strncat(arrayStr2, &A, 5);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_strncat(array2, &space, 10);
  char *res_b2 = strncat(arrayStr2, &space, 10);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strncat(array2, &EOL, 3);
  char *res_b3 = strncat(arrayStr2, &EOL, 3);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_strncat(array3 + 3, &A, 7);
  char *res_b4 = strncat(arrayStr3 + 3, &A, 7);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_strncat(array4 + 5, &space, 2);
  char *res_b5 = strncat(arrayStr4 + 5, &space, 2);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_strncat(crutoiSanek, &EOL, 7);
  char *res_b6 = strncat(crutoiSanekStr, &EOL, 7);
  ck_assert_str_eq(res_a6, res_b6);

  char *res_a7 = s21_strncat(array5 + 7, &A, 5);
  char *res_b7 = strncat(arrayStr5 + 7, &A, 5);
  ck_assert_str_eq(res_a7, res_b7);
}
END_TEST

START_TEST(strStrchrCheck) {
  char array2[512] = "A";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der04 34\0fefe";
  char array5[512] = "l33\eA";

  char arrayStr2[512] = "A";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der04 34\0fefe";
  char arrayStr5[512] = "l33\eA";

  int A = 'A';
  int space = ' ';

  char crutoiSanek[20] = "S1ANEK_CRUTOI";
  char crutoiSanekStr[20] = "S1ANEK_CRUTOI";

  char *res_a1 = s21_strchr(array2, A);
  char *res_b1 = strchr(arrayStr2, A);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_strchr(array2, space);
  char *res_b2 = strchr(arrayStr2, space);
  ck_assert_ptr_null(res_a2);
  ck_assert_ptr_null(res_b2);

  char *res_a3 = s21_strchr(array2, 0);
  char *res_b3 = strchr(arrayStr2, 0);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_strchr(array3 + 3, A);
  char *res_b4 = strchr(arrayStr3 + 3, A);
  ck_assert_ptr_null(res_a4);
  ck_assert_ptr_null(res_b4);

  char *res_a5 = s21_strchr(array4 + 3, space);
  char *res_b5 = strchr(arrayStr4 + 3, space);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_strchr(crutoiSanek + 5, 1);
  char *res_b6 = strchr(crutoiSanekStr + 5, 1);
  ck_assert_ptr_null(res_a6);
  ck_assert_ptr_null(res_b6);
  ;

  char *res_a7 = s21_strchr(array5 + 1, A);
  char *res_b7 = strchr(arrayStr5 + 1, A);
  ck_assert_str_eq(res_a7, res_b7);
}
END_TEST

START_TEST(strStrncmpCheck) {
  char *array1 = "";
  char *array2 = "   qwertyuioplkjhgfdsazxcvbnm";
  char *array3 = "0  -=!@#$\%^&*(){}1234567890";
  char *array4 = "\n \4 \0 dfgdfgdfdfgdfgdfgdfgdfg";
  char *array5 = "qqqq";
  char *array6 = "qqqQ";

  ck_assert_msg(
      s21_strncmp(array1, array1, 100) == strncmp(array1, array1, 100),
      "failed on 0");
  ck_assert_msg(s21_strncmp(array2, array1, 2) == strncmp(array2, array1, 2),
                "failed on 32");
  ck_assert_msg(s21_strncmp(array1, array3, 10) == strncmp(array1, array3, 10),
                "failed on -48");
  ck_assert_msg(
      s21_strncmp(array4, array2, 10) == strncmp(array4, array2, 10), // -10
      "failed on -22");
  ck_assert_msg(s21_strncmp(array5, array6, 0) == strncmp(array5, array6, 0),
                "failed on 32");
}
END_TEST

START_TEST(strStrncpyCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = s21_strncpy(array2, array1, 2);
  char *res_b1 = strncpy(arrayStr2, arrayStr1, 2);
  ck_assert_str_eq(res_a1, res_b1);

  char *res_a2 = s21_strncpy(array2, array1, 1);
  char *res_b2 = strncpy(arrayStr2, arrayStr1, 1);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strncpy(array2, array3, 0);
  char *res_b3 = strncpy(arrayStr2, arrayStr3, 0);
  ck_assert_str_eq(res_a3, res_b3);

  char *res_a4 = s21_strncpy(array3, array4, 100);
  char *res_b4 = strncpy(arrayStr3, arrayStr4, 100);
  ck_assert_str_eq(res_a4, res_b4);

  /* char * res_a5 = s21_strncpy(array4, array5, -23);
  char * res_b5 = strncpy(arrayStr4, arrayStr5, -23);
  ck_assert_str_eq(res_a5, res_b5); */

  char *res_a6 = s21_strncpy(array4, array5, 0);
  char *res_b6 = strncpy(arrayStr4, arrayStr5, 0);
  ck_assert_str_eq(res_a6, res_b6);
}
END_TEST

START_TEST(strStrcspnCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  int res1 = (int)s21_strcspn(array1, array1);
  int resS1 = (int)strcspn(array1, array1);

  int res2 = (int)s21_strcspn(array2, array1);
  int resS2 = (int)strcspn(array2, array1);

  int res3 = (int)s21_strcspn(array1, array3);
  int resS3 = (int)strcspn(array1, array3);

  int res4 = (int)s21_strcspn(array4, array2);
  int resS4 = (int)strcspn(array4, array2);

  int res5 = (int)s21_strcspn(array5, array2);
  int resS5 = (int)strcspn(array5, array2);

  ck_assert_int_eq(res1, resS1);
  ck_assert_int_eq(res2, resS2);
  ck_assert_int_eq(res3, resS3);
  ck_assert_int_eq(res4, resS4);
  ck_assert_int_eq(res5, resS5);
}
END_TEST

START_TEST(strStrerrorCheck) {
  char *res_a1;
  char *res_b1;

  for (int i = 0; i < 106; i++) {
    res_a1 = s21_strerror(i);
    res_b1 = strerror(i);
    ck_assert_str_eq(res_a1, res_b1);
  }
}
END_TEST

START_TEST(strStrpbrkCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = s21_strpbrk(array2, array1);
  char *res_b1 = strpbrk(arrayStr2, arrayStr1);
  ck_assert_ptr_null(res_a1);
  ck_assert_ptr_null(res_b1);

  char *res_a2 = s21_strpbrk("f", array4 + 100);
  char *res_b2 = strpbrk("f", arrayStr4 + 100);
  ck_assert_ptr_null(res_a2);
  ck_assert_ptr_null(res_b2);

  char *res_a3 = s21_strpbrk(array2 + 1, array3);
  char *res_b3 = strpbrk(arrayStr2 + 1, arrayStr3);
  ck_assert_ptr_null(res_a3);
  ck_assert_ptr_null(res_b3);

  char *res_a4 = s21_strpbrk(array3, array4);
  char *res_b4 = strpbrk(arrayStr3, arrayStr4);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_strpbrk(array4, array5 + 2);
  char *res_b5 = strpbrk(arrayStr4, arrayStr5 + 2);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_strpbrk("0\v0", array4);
  char *res_b6 = strpbrk("0\v0", arrayStr4);
  ck_assert_str_eq(res_a6, res_b6);

  char *res_a7 = s21_strpbrk(arrayStr3, "");
  char *res_b7 = strpbrk(arrayStr3, "");
  ck_assert_ptr_null(res_a7);
  ck_assert_ptr_null(res_b7);
}
END_TEST

START_TEST(strStrrchrCheck) {
  char arr1[20] = "sdhfgsdkfg";
  char arr2[20] = "sdhf2g sdkfg";
  char arr3[20] = "sdhfg\0sdGfg";
  char arr4[512] = "der04\v34\0fefe";

  char A = 'A';
  char digit = '2';
  char space = ' ';
  char EOL = '\0';

  char *c1 = s21_strrchr(arr1, A);
  char *c1_1 = s21_strrchr(arr1, EOL);
  char *c2 = s21_strrchr(arr2, space);
  char *c2_2 = s21_strrchr(arr2, digit);
  char *c3 = s21_strrchr(arr3, A);

  char *c1Str = strrchr(arr1, A);
  char *c1_1Str = strrchr(arr1, EOL);
  char *c2Str = strrchr(arr2, space);
  char *c2_2Str = strrchr(arr2, digit);
  char *c3Str = strrchr(arr3, A);

  int n1 = c1 - arr1;
  int n1_1 = c1_1 - arr1;
  int n2 = c2 - arr2;
  int n2_2 = c2_2 - arr2;
  int n3 = c3 - arr3;

  int n1Str = c1Str - arr1;
  int n1_1Str = c1_1Str - arr1;
  int n2Str = c2Str - arr2;
  int n2_2Str = c2_2Str - arr2;
  int n3Str = c3Str - arr3;

  char *res_a4 = s21_strrchr(arr3, digit);
  char *res_b4 = strrchr(arr3, digit);
  ck_assert_ptr_null(res_a4);
  ck_assert_ptr_null(res_b4);

  char *res_a5 = s21_strrchr(arr4, space);
  char *res_b5 = strrchr(arr4, space);
  ck_assert_ptr_null(res_a5);
  ck_assert_ptr_null(res_b5);

  ck_assert_int_eq(n1, n1Str);
  ck_assert_int_eq(n1_1, n1_1Str);
  ck_assert_int_eq(n2, n2Str);
  ck_assert_int_eq(n2_2, n2_2Str);
  ck_assert_int_eq(n3, n3Str);
}
END_TEST

START_TEST(strStrspnCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";
  char array6[512] = "Gfd67\0fsdf";

  int res1 = (int)s21_strspn(array1, array1);
  int resS1 = (int)strspn(array1, array1);

  int res2 = (int)s21_strspn(array2, array1);
  int resS2 = (int)strspn(array2, array1);

  int res3 = (int)s21_strspn(array1, array3);
  int resS3 = (int)strspn(array1, array3);

  int res4 = (int)s21_strspn(array4, array2);
  int resS4 = (int)strspn(array4, array2);

  int res5 = (int)s21_strspn(array5 + 2, array2 + 3);
  int resS5 = (int)strspn(array5 + 2, array2 + 3);

  int res6 = (int)s21_strspn(array6 + 3, array5);
  int resS6 = (int)strspn(array6 + 3, array5);

  int res7 = (int)s21_strspn(array6, array5 + 5);
  int resS7 = (int)strspn(array6, array5 + 5);

  ck_assert_int_eq(res1, resS1);
  ck_assert_int_eq(res2, resS2);
  ck_assert_int_eq(res3, resS3);
  ck_assert_int_eq(res4, resS4);
  ck_assert_int_eq(res5, resS5);
  ck_assert_int_eq(res6, resS6);
  ck_assert_int_eq(res7, resS7);
}
END_TEST

START_TEST(strStrstrCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = s21_strstr(array2, array1);
  char *res_b1 = strstr(arrayStr2, arrayStr1);
  ck_assert_ptr_null(res_a1);
  ck_assert_ptr_null(res_b1);

  char *res_a2 = s21_strstr("f", array4 + 100);
  char *res_b2 = strstr("f", arrayStr4 + 100);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strstr(array2 + 1, array3);
  char *res_b3 = strstr(arrayStr2 + 1, arrayStr3);
  ck_assert_ptr_null(res_a3);
  ck_assert_ptr_null(res_b3);

  char *res_a4 = s21_strstr(array3, array4);
  char *res_b4 = strstr(arrayStr3, arrayStr4);
  ck_assert_ptr_null(res_a4);
  ck_assert_ptr_null(res_b4);

  char *res_a5 = s21_strstr(array4, array5 + 2);
  char *res_b5 = strstr(arrayStr4, arrayStr5 + 2);
  ck_assert_str_eq(res_a5, res_b5);

  char *res_a6 = s21_strstr("0\v0", array4);
  char *res_b6 = strstr("0\v0", arrayStr4);
  ck_assert_ptr_null(res_a6);
  ck_assert_ptr_null(res_b6);

  char *res_a7 = s21_strstr(arrayStr3, "");
  char *res_b7 = strstr(arrayStr3, "");
  ck_assert_str_eq(res_a7, res_b7);

  char *res_a8 = s21_strstr(arrayStr3, "\0");
  char *res_b8 = strstr(arrayStr3, "\0");
  ck_assert_pstr_eq(res_a8, res_b8);
}
END_TEST

START_TEST(strStrtokCheck) {
  char array1[512] = "linarbebebe";
  char array2[512] = "";
  char array3[512] = "sdfsdfsd";
  char array4[512] = "der0434\0fefe";
  char array5[512] = "l33";

  char arrayStr1[512] = "linarbebebe";
  char arrayStr2[512] = "";
  char arrayStr3[512] = "sdfsdfsd";
  char arrayStr4[512] = "der0434\0fefe";
  char arrayStr5[512] = "l33";

  char *res_a1 = s21_strtok(array2, array1);
  char *res_b1 = strtok(arrayStr2, arrayStr1);
  ck_assert_ptr_null(res_a1);
  ck_assert_ptr_null(res_b1);

  char *res_a2 = s21_strtok("f", array4 + 100);
  char *res_b2 = strtok("f", arrayStr4 + 100);
  ck_assert_str_eq(res_a2, res_b2);

  char *res_a3 = s21_strtok(array2 + 1, array3);
  char *res_b3 = strtok(arrayStr2 + 1, arrayStr3);
  ck_assert_ptr_null(res_a3);
  ck_assert_ptr_null(res_b3);

  char *res_a4 = s21_strtok(array3, array4);
  char *res_b4 = strtok(arrayStr3, arrayStr4);
  ck_assert_str_eq(res_a4, res_b4);

  char *res_a5 = s21_strtok(array4, array5);
  char *res_b5 = strtok(arrayStr4, arrayStr5);
  ck_assert_str_eq(res_a5, res_b5);

  /*char * res_a6 = s21_strtok("0\v0", array4);
  char * res_b6 = strtok("0\v0", arrayStr4);
  ck_assert_ptr_null(res_a6);
  ck_assert_ptr_null(res_b6);*/

  // BUS_ERROR у обеих функций => правилно работает

  char *res_a7 = s21_strtok(arrayStr3, "");
  char *res_b7 = strtok(arrayStr3, "");
  ck_assert_str_eq(res_a7, res_b7);
}
END_TEST

START_TEST(strToUpper) {
  char *str;
  char result[18][18] = {"BEBE BE\0",    "A\n\0",     "A\v\n",         " \n\0",
                         "\t\t\n=R\n\0", "13 BE\n\0", "123 123 FAF\0", " \0",
                         "\n\0",         "\0"};
  for (short i = 0; i < 15; i++) {
    str = s21_to_upper(result[i]);
    if (str) {
      ck_assert_pstr_eq(str, result[i]);
      free(str);
    }
  }
  str = s21_to_upper("ebebebe");
  if (str) {
    ck_assert_pstr_eq(str, "EBEBEBE");
    free(str);
  }
  str = s21_to_upper("12\nbebe\nb\ve");
  if (str) {
    ck_assert_pstr_eq(str, "12\nBEBE\nB\vE");
    free(str);
  }
}
END_TEST

START_TEST(strToLower) {
  char *str;
  char result[18][18] = {"bebe be\0",    "a\n\0",     "a\v\n",         " \n\0",
                         "\t\t\n=r\n\0", "13 be\n\0", "123 123 faf\0", " \0",
                         "\n\0",         "\0"};
  for (short i = 0; i < 15; i++) {
    str = s21_to_lower(result[i]);
    if (str) {
      ck_assert_pstr_eq(str, result[i]);
      free(str);
    }
  }
  str = s21_to_lower("HELLO WORLD");
  if (str) {
    ck_assert_pstr_eq(str, "hello world");
    free(str);
  }
  str = s21_to_lower("TeSt\nTeSt\ntEsT\v");
  if (str) {
    ck_assert_pstr_eq(str, "test\ntest\ntest\v");
    free(str);
  }
}
END_TEST

START_TEST(strInsert) {
  char e1[100] = "123 123";
  char e1_1[100] = "987999999999999999";

  char e2[100] = "22";
  char e2_1[100] = "abcdefg";

  char e3[100] = "2342\t3\v432";
  char e3_1[100] = "1";

  char e4[100] = "1";
  char e4_1[100] = "987999999999999999";

  char e5[100] = "\0";
  char e5_1[100] = "987999999999999999";

  char* s1 = s21_insert(e1_1, e1, 3);
  ck_assert_str_eq(s1, "987123 123999999999999999");
  free(s1);

  char* s2 = s21_insert(e2_1, e2, 3);
  ck_assert_str_eq(s2, "abc22defg");
  free(s2);

  char* s3 = s21_insert(e3, e3_1, 3);
  ck_assert_str_eq(s3, "23412\t3\v432");
  free(s3);

  char* s4 = s21_insert(e4, e4_1, 3);
  ck_assert_ptr_null(s4);
  free(s4);

  char* s5 = s21_insert(e5, e5_1, 3);
  ck_assert_ptr_null(s5);
  free(s5);
}
END_TEST

START_TEST(strTrim) {
  char e1[100] = "12h";
  char e1_1[100] = "1h2bebebebeb12h";

  char e2[100] = "22";
  char e2_1[100] = "abcdefg";

  char e3[100] = "2342\t3\v432";
  char e3_1[100] = "1\t";

  char e4[100] = "1";
  char e4_1[100] = "987999999999999999";

  char e5[100] = "\0";
  char e5_1[100] = "987999999999999999";

  char *s1 = s21_trim(e1_1, e1);;
  char *s2 = s21_trim(e2_1, e2);
  char *s3 = s21_trim(e3, e3_1);;
  char *s4 = s21_trim(e4, e4_1);
  char *s5 = s21_trim(e5, e5_1);

  ck_assert_str_eq(s1, "bebebebeb");
  ck_assert_str_eq(s2, "abcdefg");
  ck_assert_str_eq(s3, "23423\v432");
  ck_assert_str_eq(s4, "1");
  ck_assert_str_eq(s5, "");
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
}
END_TEST

// SPRINTF

START_TEST(sprintf_d_Check) {
  int a = 0, b = -214748364, c = 214748364;
  int d = 214748364, e1 = 214748364, f = -214748364, g = -214748364;
  d = 214748365, e1 = 314748364, f = -214748365, g = -314748364;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5d %2d %0.2d %d %0.20d %d %d", a, b, c, d, e1, f, g);
  sprintf(e, "%-20.5d %2d %0.2d %d %0.20d %d %d", a, b, c, d, e1, f, g);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_i_Check) {
  int a = 0, b = -214748364, c = 214748364;
  int d = 214748364, e1 = 214748364, f = -214748364, g = -214748364;
  d = 214748365, e1 = 314748364, f = -214748365, g = -314748364;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5i %2i %0.2i %i %0.20i %i %i", a, b, c, d, e1, f, g);
  sprintf(e, "%-20.5i %2i %0.2i %i %0.20i %i %i", a, b, c, d, e1, f, g);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_f_Check) {
  float a = 0, b = 0100001.00000000001, c = -0100001.00000000001;
  float d = 0.00000000000000000001, e1 = 0.00001, f = 3.4E-38, g = 2.0000001,
        h = 2.1e+3;
  char *e = malloc(sizeof(char) * 250);
  char *s21_e = malloc(sizeof(char) * 250);
  s21_sprintf(s21_e, "%-20.16f %20f %0.2f %f %0.20f %.10f %.3f %-f", a, b, c, d,
              e1, f, g, h);
  sprintf(e, "%-20.16f %20f %0.2f %f %0.20f %.10f %.3f %-f", a, b, c, d, e1, f,
          g, h);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_u_Check) {
  unsigned int a = 0, b = 21, c = 4294967295, d = 1, e1 = 2;
  b = -20000, d = -2, e1 = 0;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5u %2u %0.2u %u %0.20u", a, b, c, d, e1);
  sprintf(e, "%-20.5u %2u %0.2u %u %0.20u", a, b, c, d, e1);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_c_Check) {
  char a = 'a', b = 'b', c = 'c', space = ' ', EOL = '\0', V = '\v', T = '\t';
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%c %-20c %c %c %c %c %c %c %c %c", a, b, c, space, V, b,
              T, b, EOL, a);
  sprintf(e, "%c %-20c %c %c %c %c %c %c %c %c", a, b, c, space, V, b, T, b,
          EOL, a);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_s_Check) {
  wchar_t k[20] = L"ads\vdf";
  wchar_t l[20] = L"ads   dfjhg\t ds \0f";
  char s21_h[50];
  char h[50];
  char *a = "bebe123     be";
  char *b = "aeae   3   \tae";
  char *c = "";
  char *d = "1\0oooo";
  char *e = malloc(sizeof(char) * 1000);
  char *s21_e = malloc(sizeof(char) * 1000);
  s21_sprintf(s21_e, "%-20.5s %2s %s %s", a, b, c, d);
  sprintf(e, "%-20.5s %2s %s %s", a, b, c, d);
  s21_sprintf(s21_h, "%s %s", k, l);
  s21_sprintf(h, "%s %s", k, l);
  ck_assert_str_eq(s21_e, e);
  ck_assert_str_eq(s21_h, h);
}
END_TEST

// SPRINTF h

START_TEST(sprintf_hd_Check) {
  short int a = 0, b = -32768, c = 32767, d = 0x1220;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5hd %+2hd %hd %0.20hd", a, b, c, d);
  sprintf(e, "%-20.5hd %+2hd %hd %0.20hd", a, b, c, d);
  ck_assert_str_eq(s21_e, e);
  free(e);
  free(s21_e);
}
END_TEST

START_TEST(sprintf_hi_Check) {
  short int a = 0, b = -32768, c = 32767, d = 0x1220;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5hi %+2hi %hi %0.20hi", a, b, c, d);
  sprintf(e, "%-20.5hi %+2hi %hi %0.20hi", a, b, c, d);
  ck_assert_str_eq(s21_e, e);
  free(e);
  free(s21_e);
}
END_TEST

START_TEST(sprintf_hu_Check) {
  unsigned short int a = 0, b = 3, c = 65535;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5hu %2hu %0.2hu", a, b, c);
  sprintf(e, "%-20.5hu %2hu %0.2hu", a, b, c);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

// SPRINTF l

START_TEST(sprintf_ld_Check) {
  unsigned long int a = 0, b = -214748364, c = 214748364;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5ld %+2ld %ld", a, b, c);
  sprintf(e, "%-20.5ld %+2ld %ld", a, b, c);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_li_Check) {
  long int a = 0, b = -214748364, c = 214748364;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5li %+2li %li", a, b, c);
  sprintf(e, "%-20.5li %+2li %li", a, b, c);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_lu_Check) {
  unsigned long int a = 0, b = 3, c = 4294967295;
  char *e = malloc(sizeof(char) * 100);
  char *s21_e = malloc(sizeof(char) * 100);
  s21_sprintf(s21_e, "%-20.5lu %2lu %0.2lu", a, b, c);
  sprintf(e, "%-20.5lu %2lu %0.2lu", a, b, c);
  ck_assert_str_eq(s21_e, e);
}
END_TEST

START_TEST(sprintf_lc_Check) {
  wchar_t a = 'm';
  wchar_t b = 'a';
  wchar_t c = '\v';
  wchar_t d = '\t';
  wchar_t e = '\0';

  char s21_h[50];
  char h[50];
  s21_sprintf(s21_h, "%lc %lc %lc %lc %lc %lc %lc %lc", a, b, c, a, d, b, e, a);
  sprintf(h, "%lc %lc %lc %lc %lc %lc %lc %lc", a, b, c, a, d, b, e, a);
  ck_assert_str_eq(s21_h, h);
}
END_TEST

START_TEST(sprintf_ls_Check) {
  wchar_t k[20] = L"ads\vdf";
  wchar_t l[20] = L"ads   dfjhg\t ds \0f";
  char s21_h[50];
  char h[50];
  s21_sprintf(s21_h, "%ls %ls", k, l);
  s21_sprintf(h, "%ls %ls", k, l);
  ck_assert_str_eq(s21_h, h);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("StringSuite");
  SRunner *sr = srunner_create(s1);
  int nf;

  // STR FUNCTIONS

  TCase *stringLenCase = tcase_create("strLenChecks");
  suite_add_tcase(s1, stringLenCase);
  TCase *stringCmpCase = tcase_create("strCmpChecks");
  suite_add_tcase(s1, stringCmpCase);
  TCase *stringCpyCase = tcase_create("strCpyChecks");
  suite_add_tcase(s1, stringCpyCase);
  TCase *stringCatCase = tcase_create("strCatCheck");
  suite_add_tcase(s1, stringCatCase);
  TCase *stringMemchrCase = tcase_create("strMemchrCheck");
  suite_add_tcase(s1, stringMemchrCase);
  TCase *stringMemcmpCase = tcase_create("strMemcmpCheck");
  suite_add_tcase(s1, stringMemcmpCase);
  TCase *stringMemcpyCase = tcase_create("strMemcpyCheck");
  suite_add_tcase(s1, stringMemcpyCase);
  TCase *stringMemmoveCase = tcase_create("strMemmoveCheck");
  suite_add_tcase(s1, stringMemmoveCase);
  TCase *stringMemsetCase = tcase_create("strMemsetCheck");
  suite_add_tcase(s1, stringMemsetCase);
  TCase *stringStrncatCase = tcase_create("strStrncatCheck");
  suite_add_tcase(s1, stringStrncatCase);
  TCase *stringStrchrCase = tcase_create("strStrchrCheck");
  suite_add_tcase(s1, stringStrchrCase);
  TCase *stringStrncmpCase = tcase_create("strStrncmpCheck");
  suite_add_tcase(s1, stringStrncmpCase);
  TCase *stringStrncpyCase = tcase_create("strStrncpyCheck");
  suite_add_tcase(s1, stringStrncpyCase);
  TCase *stringStrcspnCase = tcase_create("strStrcspnCheck");
  suite_add_tcase(s1, stringStrcspnCase);
  TCase *stringStrerrorCase = tcase_create("strStrerrorCheck");
  suite_add_tcase(s1, stringStrerrorCase);
  TCase *stringStrpbrkCase = tcase_create("strStrpbrkCheck");
  suite_add_tcase(s1, stringStrpbrkCase);
  TCase *stringStrrchrCase = tcase_create("strStrrchrCheck");
  suite_add_tcase(s1, stringStrrchrCase);
  TCase *stringStrspnCase = tcase_create("strStrspnCheck");
  suite_add_tcase(s1, stringStrspnCase);
  TCase *stringStrstrCase = tcase_create("strStrstrCheck");
  suite_add_tcase(s1, stringStrstrCase);
  TCase *stringStrtokCase = tcase_create("strStrtokCheck");
  suite_add_tcase(s1, stringStrtokCase);
  TCase *stringToUpperCase = tcase_create("strToUpper");
  suite_add_tcase(s1, stringToUpperCase);
  TCase *stringToLowerCase = tcase_create("strToLower");
  suite_add_tcase(s1, stringToLowerCase);
  TCase *stringInsertCase = tcase_create("strInsert");
  suite_add_tcase(s1, stringInsertCase);
  TCase *stringTrimCase = tcase_create("strTrim");
  suite_add_tcase(s1, stringTrimCase);

  // SPRINTF

  TCase *sprintf_d_Case = tcase_create("sprintf_d_Check");
  suite_add_tcase(s1, sprintf_d_Case);
  TCase *sprintf_i_Case = tcase_create("sprintf_i_Check");
  suite_add_tcase(s1, sprintf_i_Case);
  TCase *sprintf_f_Case = tcase_create("sprintf_f_Check");
  suite_add_tcase(s1, sprintf_f_Case);
  TCase *sprintf_u_Case = tcase_create("sprintf_u_Check");
  suite_add_tcase(s1, sprintf_u_Case);
  TCase *sprintf_c_Case = tcase_create("sprintf_c_Check");
  suite_add_tcase(s1, sprintf_c_Case);
  TCase *sprintf_s_Case = tcase_create("sprintf_s_Check");
  suite_add_tcase(s1, sprintf_s_Case);

  // SPRINTF h

  TCase *sprintf_hd_Case = tcase_create("sprintf_h_d_Check");
  suite_add_tcase(s1, sprintf_hd_Case);
  TCase *sprintf_hi_Case = tcase_create("sprintf_h_i_Check");
  suite_add_tcase(s1, sprintf_hi_Case);
  TCase *sprintf_hu_Case = tcase_create("sprintf_h_u_Check");
  suite_add_tcase(s1, sprintf_hu_Case);

  // SPRINTF l

  TCase *sprintf_ld_Case = tcase_create("sprintf_l_d_Check");
  suite_add_tcase(s1, sprintf_ld_Case);
  TCase *sprintf_li_Case = tcase_create("sprintf_l_i_Check");
  suite_add_tcase(s1, sprintf_li_Case);
  TCase *sprintf_lu_Case = tcase_create("sprintf_l_u_Check");
  suite_add_tcase(s1, sprintf_lu_Case);
  TCase *sprintf_lc_Case = tcase_create("sprintf_l_c_Check");
  suite_add_tcase(s1, sprintf_lc_Case);
  TCase *sprintf_ls_Case = tcase_create("sprintf_l_s_Check");
  suite_add_tcase(s1, sprintf_ls_Case);

  tcase_add_test(stringLenCase, strLenCheck);
  tcase_add_test(stringCmpCase, strCmpCheck);
  tcase_add_test(stringCpyCase, strCpyCheck);
  tcase_add_test(stringCatCase, strCatCheck);
  tcase_add_test(stringMemchrCase, strMemchrCheck);
  tcase_add_test(stringMemcmpCase, strMemcmpCheck);
  tcase_add_test(stringMemcpyCase, strMemcpyCheck);
  tcase_add_test(stringMemmoveCase, strMemmoveCheck);
  tcase_add_test(stringMemsetCase, strMemsetCheck);
  tcase_add_test(stringStrncatCase, strStrncatCheck);
  tcase_add_test(stringStrchrCase, strStrchrCheck);
  tcase_add_test(stringStrncmpCase, strStrncmpCheck);
  tcase_add_test(stringStrncpyCase, strStrncpyCheck);
  tcase_add_test(stringStrcspnCase, strStrcspnCheck);
  tcase_add_test(stringStrerrorCase, strStrerrorCheck);
  tcase_add_test(stringStrpbrkCase, strStrpbrkCheck);
  tcase_add_test(stringStrrchrCase, strStrrchrCheck);
  tcase_add_test(stringStrspnCase, strStrspnCheck);
  tcase_add_test(stringStrstrCase, strStrstrCheck);
  tcase_add_test(stringStrtokCase, strStrtokCheck);
  tcase_add_test(stringToUpperCase, strToUpper);
  tcase_add_test(stringToLowerCase, strToLower);
  tcase_add_test(stringInsertCase, strInsert);
  tcase_add_test(stringTrimCase, strTrim);

  tcase_add_test(sprintf_d_Case, sprintf_d_Check);
  tcase_add_test(sprintf_i_Case, sprintf_i_Check);
  tcase_add_test(sprintf_f_Case, sprintf_f_Check);
  tcase_add_test(sprintf_u_Case, sprintf_u_Check);
  tcase_add_test(sprintf_c_Case, sprintf_c_Check);
  tcase_add_test(sprintf_s_Case, sprintf_s_Check);

  tcase_add_test(sprintf_hd_Case, sprintf_hd_Check);
  tcase_add_test(sprintf_hi_Case, sprintf_hi_Check);
  tcase_add_test(sprintf_hu_Case, sprintf_hu_Check);

  tcase_add_test(sprintf_ld_Case, sprintf_ld_Check);
  tcase_add_test(sprintf_li_Case, sprintf_li_Check);
  tcase_add_test(sprintf_lu_Case, sprintf_lu_Check);
  tcase_add_test(sprintf_lc_Case, sprintf_lc_Check);
  tcase_add_test(sprintf_ls_Case, sprintf_ls_Check);

  //  Запустить всё это дело
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
