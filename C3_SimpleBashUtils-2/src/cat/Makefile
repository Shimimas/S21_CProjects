CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck
TARGET_CAT = s21_cat

all: clean s21_cat
	
$(TARGET_CAT): s21_cat.o bash.o
	$(CC) s21_cat.o bash.o $(CFLAGS) -o $@

s21_cat.o: s21_cat.c
	$(CC) -c s21_cat.c $(CFLAGS) -o $@

bash.o: ../common/bash.c
	$(CC) -c ../common/bash.c $(CFLAGS) -o $@

clean:
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out 
	rm -rf s21_cat
	rm -rf *.gcda *.gcno
