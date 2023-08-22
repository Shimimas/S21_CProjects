#ifndef SRC_COMMON_BASH_H_
#define SRC_COMMON_BASH_H_

#include "../common/bash.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "regex.h"

struct Flag {
    int b;
    int e;
    int n;
    int s;
    int t;
    int i;
    int v;
    int c;
    int l;
    int h;
};

void FlagNull(struct Flag * flag);
int Findflag(int argc, char *argv[], struct Flag * flag, int type);
int FileLen(char argv[]);

#endif  // SRC_COMMON_BASH_H_
