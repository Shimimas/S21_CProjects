#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include "../common/bash.h"

int ColFile(char *argv[], int argc);
int s21_grep(char argv[], struct Flag flag, regex_t * regex, int col);

#endif  // SRC_GREP_S21_GREP_H_
