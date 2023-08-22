CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
TESTTARGET = s21_test_matrix
OS := $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
	LIBS = -lcheck -lsubunit -lrt -lpthread -lm
	BREW = .
endif
ifeq ($(OS), Darwin)
	OPEN = open
	ADD_LIB = 
	LIBS = -lcheck
	BREW = {$HOME}/homebrew
endif

PATH := $(PATH):$(BREW)/bin
GCOV = --coverage

all: clean s21_matrix.a

$(TARGET): s21_matrix.o s21_matrix.a
	$(CC) s21_matrix.o $(CFLAGS) $(LIBS) $(GCOV) -L. s21_matrix.a -o $@

s21_matrix.o: s21_matrix.c
	$(CC) -c s21_matrix.c $(CFLAGS) $(LIBS) -o $@

s21_matrix.a: s21_matrix.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

run: clean start

lintest:
	python3 ../materials/linters/cpplint.py --extensions=c s21_matrix.c
	python3 ../materials/linters/cpplint.py --extensions=c s21_matrix.h
	python3 ../materials/linters/cpplint.py --extensions=c test/s21_test_matrix.c

start:
	gcc s21_matrix.c $(CFLAGS) -lm
	./a.out

gcov_report: clean test/s21_test_matrix.c s21_matrix.c
	-mkdir report
	$(CC) $(GCOV) test/s21_test_matrix.c s21_matrix.c $(CFLAGS) $(ADD_LIB) $(LIBS) -lcheck
	$(CC) $(GCOV) -c s21_matrix.c $(CFLAGS) $(LIBS) -o s21_matrix.o
	$(CC) $(GCOV) -c test/s21_test_matrix.c $(CFLAGS) $(LIBS) -o test/s21_test_matrix.o
	$(CC) $(GCOV) -o $@ test/s21_test_matrix.o s21_matrix.o $(CFLAGS) $(LIBS) -lcheck
	-./$@
	gcov test/s21_test_matrix.c
	lcov -t test/s21_test_matrix -o test/s21_test_matrix.info -c -d .
	genhtml -o report test/s21_test_matrix.info
	$(OPEN) ./report/index.html

$(TESTTARGET): s21_matrix.a test/s21_test_matrix.o s21_matrix.o
	$(CC) test/s21_test_matrix.c s21_matrix.o $(CFLAGS) $(LIBS) -o $@

test/s21_test_matrix.o: test/s21_test_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) $(LIBS) -c test/s21_test_matrix.c -o $@ 
	$(CC) $(CFLAGS) $(LIBS) -c s21_matrix.c -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

valgrind: $(TESTTARGET)
	valgrind -s ./$(TESTTARGET)

clean:	
		rm -rf math.a
		rm -rf gcov_report
		rm -rf s21_matrix
		rm -rf s21_test_matrix
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild math.a
