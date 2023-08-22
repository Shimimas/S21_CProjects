#include "../common/bash.h"

int s21_cat(char argv[], struct Flag flag) {
    int filelen = FileLen(argv);
    int error = 0;
    char * resarr;
    if (filelen != -1) {
        FILE *result_f;
        if ((resarr = (char *) malloc(sizeof(char) * filelen)) != NULL) {
            if ((result_f = fopen(argv, "r")) != NULL) {
                char c;
                for (int i = 0; (c = fgetc(result_f)) != EOF; i++) {
                    resarr[i] = c;
                }
                fclose(result_f);
            }
        } else {
            error = 1;
        }
        int strnum = 1;
        if (result_f != NULL && error == 0) {
            for (int i = 0; i < filelen; i++) {
                if (flag.n == 1) {
                    printf("%6d\t", strnum++);
                }
                if (flag.s == 1 && resarr[i] == '\n') {
                    printf("%c", resarr[i]);
                    while (resarr[i] == '\n') {
                        i++;
                    }
                }
                if (flag.b == 1 && flag.n == 0 && resarr[i] != '\n') {
                    printf("%6d\t", strnum++);
                }
                for (; i < filelen && resarr[i] != '\n'; i++) {
                    if (flag.v == 1 && resarr[i] < 32 && resarr[i] != 9 && resarr[i] != 10) {
                        printf("^%c", resarr[i] + 64);
                    } else if (flag.t == 1 && resarr[i] == '\t') {
                        printf("^I");
                    } else {
                        printf("%c", resarr[i]);
                    }
                }
                if (flag.e == 1 && i != filelen) {
                    printf("$");
                }
                if (i != filelen) {
                    printf("\n");
                }
            }
            free(resarr);
        }
    } else {
        error = 2;
    }
    return error;
}

int main(int argc, char *argv[]) {
    int error = 0;
    struct Flag flag;
    FlagNull(&flag);
    if (Findflag(argc, argv, &flag, 0) != -1) {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] != '\0') {
                if (s21_cat(argv[i], flag) == 2) {
                    error = 2;
                }
            }
        }
    } else {
        error = 1;
    }
    return error;
}
