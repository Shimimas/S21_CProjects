CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck
TARGET_GREP = s21_grep

all: clean s21_grep

$(TARGET_GREP): s21_grep.o bash.o
	$(CC) s21_grep.o bash.o -D_GNU_SOURCE $(CFLAGS) -o $@

s21_grep.o: s21_grep.c
	$(CC) -c s21_grep.c -D_GNU_SOURCE $(CFLAGS) -o $@

bash.o: ../common/bash.c
	$(CC) -c ../common/bash.c $(CFLAGS) -o $@

clean:
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out 
	rm -rf s21_grep
	rm -rf *.gcda *.gcno
