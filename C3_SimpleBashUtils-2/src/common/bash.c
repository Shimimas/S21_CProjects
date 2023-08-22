#include "bash.h"

void FlagNull(struct Flag * flag) {
    flag->b = 0;
    flag->e = 0;
    flag->n = 0;
    flag->s = 0;
    flag->t = 0;
    flag->i = 0;
    flag->v = 0;
    flag->c = 0;
    flag->l = 0;
    flag->h = 0;
}

int Findflag(int argc, char *argv[], struct Flag * flag, int type) {
    int s = 0;
    int error = 0;
    for (int i = 1; i < argc && s != -1; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'b':
                    flag->b = 1;
                    break;
                case 'e':
                    if (type == 0) {
                        flag->e = 1;
                        flag->v = 1;
                    }
                    break;
                case 'E':
                    flag->e = 1;
                    break;
                case 'n':
                    flag->n = 1;
                    break;
                case 's':
                    flag->s = 1;
                    break;
                case 't':
                    flag->t = 1;
                    flag->v = 1;
                    break;
                case 'T':
                    flag->t = 1;
                    break;
                case 'i':
                    flag->i = 1;
                    break;
                case 'v':
                    flag->v = 1;
                    break;
                case 'c':
                    flag->c = 1;
                    break;
                case 'l':
                    flag->l = 1;
                    break;
                case 'h':
                    flag->h = 1;
                    break;
                default:
                    error--;
                    break;
            }
            if (strcmp(argv[i], "--number") == 0) {
                flag->n = 1;
            } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
                flag->s = 1;
            } else if (strcmp(argv[i], "--number-nonblank") == 0) {
                flag->b = 1;
            } else if (error == -1) {
                s = -2;
            }
            s++;
            if (argv[i][1] == 'e' && type == 1) {
            } else {
                argv[i][0] = '\0';
            }
        }
    }
    return s;
}

int FileLen(char argv[]) {
    FILE *result_f;
    result_f = fopen(argv, "r");
    int len = 0;
    if (result_f != NULL) {
        char c;
        while ((c = fgetc(result_f)) != EOF) {
            len++;
        }
        fclose(result_f);
    } else {
        len = -1;
    }
    return len;
}
