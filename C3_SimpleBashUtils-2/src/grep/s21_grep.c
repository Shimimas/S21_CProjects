#include "s21_grep.h"

int ColFile(char *argv[], int argc) {
    int col = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '\0') {
            col++;
        }
    }
    return col;
}

int s21_grep(char argv[], struct Flag flag, regex_t * regex, int col) {
    FILE *result_f;
    int error = 0;
    if ((result_f = fopen(argv, "r")) != NULL) {
        int reg = 0;
        int str_num = 0;
        int name = 0;
        int col_sov = 0;
        while (reg != EOF && name == 0) {
            char * str = NULL;
            int len;
            int comp = 0;
            if (flag.v == 1) {
                comp = REG_NOMATCH;
            }
            reg = getline(&str, (size_t *) &len, result_f);
            if (str && reg != EOF) {
                str_num++;
                if (regexec(regex, str, 0, NULL, 0) == comp && name == 0) {
                    col_sov++;
                    if (flag.l == 1) {
                        printf("%s\n", argv);
                        name = 1;
                    }
                    if (name == 0) {
                        if (col > 1 && flag.h == 0 && flag.c == 0) {
                            printf("%s:", argv);
                        }
                        if (flag.n == 1 && flag.c == 0) {
                            printf("%d:", str_num);
                        }
                        for (int y = 0; y < (int)strlen(str)+1 && flag.c == 0; y++) {
                            if (str[y] == '\0' && y >= 1) {
                                if (str[y-1] != '\n') {
                                    printf("\n");
                                }
                            } else {
                                printf("%c", str[y]);
                            }
                        }
                    }
                }
            }
            free(str);
        }
        if (flag.c == 1) {
            if (col > 1 && flag.h == 0) {
                printf("%s:", argv);
            }
            printf("%d\n", col_sov);
        }
        fclose(result_f);
    } else {
        error = 2;
    }
    return error;
}

int main(int argc, char *argv[]) {
    struct Flag flag;
    int error = 0;
    regex_t regex;
    int flag_f = 0;
    int rgflag = 0;
    FlagNull(&flag);
    Findflag(argc, argv, &flag, 1);
    if (flag.i == 1) {
        rgflag = REG_ICASE;
    }
    int stop1 = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'e') {
            if (stop1 == 0) {
                regcomp(&regex, argv[i+1], rgflag);
                stop1 = 1;
            }
            argv[i][0] = '\0';
            argv[i+1][0] = '\0';
            flag_f = 1;
        }
    }
    int stop = 0;
    if (flag_f == 0) {
        for (int i = 1; i < argc && stop == 0; i++) {
            if (argv[i][0] != '\0') {
                regcomp(&regex, argv[i], rgflag);
                argv[i][0] = '\0';
                stop = 1;
            }
        }
    }
    int col = ColFile(argv, argc);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '\0') {
            error = s21_grep(argv[i], flag, &regex, col);
        }
    }
    if (flag.s == 1) {
        error = 0;
    }
    regfree(&regex);
    return error;
}
