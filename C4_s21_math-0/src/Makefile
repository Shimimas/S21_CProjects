CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TESTTARGET = s21_mathTest
OS := $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
	BREW = .
endif
ifeq ($(OS), Darwin)
	OPEN = open
	ADD_LIB = 
	BREW = {$HOME}/homebrew
endif

PATH := $(PATH):$(BREW)/bin
GCOV = --coverage

all: clean s21_math.a

$(TARGET): s21_math.o s21_math.a
	$(CC) s21_math.o $(CFLAGS) $(LIBS) $(GCOV) -L. s21_math.a -o $@

s21_math.o: s21_math.c
	$(CC) -c s21_math.c $(CFLAGS) $(LIBS) -o $@

s21_math.a: s21_math.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

gcov_report: clean test/s21_mathTest.c s21_math.c
	-mkdir report
	$(CC) $(GCOV) test/s21_mathTest.c s21_math.c $(CFLAGS) $(ADD_LIB) $(LIBS) -lcheck
	$(CC) $(GCOV) -c s21_math.c $(CFLAGS) $(LIBS) -o s21_math.o
	$(CC) $(GCOV) -c test/s21_mathTest.c $(CFLAGS) $(LIBS) -o test/s21_mathTest.o
	$(CC) $(GCOV) -o $@ test/s21_mathTest.o s21_math.o $(CFLAGS) $(LIBS) -lcheck
	-./$@
	gcov test/s21_mathTest.c
	lcov -t test/s21_mathTest -o test/s21_mathTest.info -c -d .
	genhtml -o report test/s21_mathTest.info
	$(OPEN) ./report/index.html

$(TESTTARGET): s21_math.a test/s21_mathTest.o s21_math.o
	$(CC) test/s21_mathTest.c s21_math.o $(CFLAGS) $(LIBS) -o $@
	

test/s21_mathTest.o: test/s21_mathTest.c s21_math.h
	$(CC) $(CFLAGS) $(LIBS) -c test/s21_mathTest.c -o $@ 
	$(CC) $(CFLAGS) $(LIBS) -c s21_math.c -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

clean:	
		rm -rf math.a
		rm -rf gcov_report
		rm -rf s21_math
		rm -rf s21_mathTest
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild math.a
