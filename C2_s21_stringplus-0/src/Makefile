CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck
TESTTARGET = s21_stringTest
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

all: clean s21_string.a test

$(TARGET): main.o s21_string.a
	$(CC) main.o $(CFLAGS) $(GCOV) -L. s21_string.a -o $@

s21_string.o: s21_string.c
	$(CC) -c s21_string.c $(CFLAGS) -o $@

s21_string.a: s21_string.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

gcov_report: clean testString.c s21_string.c
	-mkdir report
	$(CC) $(CFLAGS) $(ADD_LIB) $(GCOV) testString.c s21_string.c -lcheck
	$(CC) $(GCOV) -c s21_string.c $(CFLAGS) -o s21_string.o
	$(CC) $(GCOV) -c testString.c $(CFLAGS) -o testString.o
	$(CC) $(GCOV) -o $@ $(CFLAGS) $(GCOV) testString.o s21_string.o -lcheck
	-./$@
	gcov testString.c
	lcov -t testString -o testString.info -c -d .
	genhtml -o report testString.info
	$(OPEN) ./report/index.html

$(TESTTARGET): s21_string.a testString.o s21_string.o
	$(CC) testString.c s21_string.o $(CFLAGS) $(LIBS) -o $@
	

testString.o: testString.c s21_string.h
	$(CC) $(CFLAGS) -c testString.c -o $@ 
	$(CC) -c s21_string.c $(CFLAGS) -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

clean:	
		rm -rf s21_stringLib
		rm -rf s21_stringTest
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out 
		rm -rf *.o *.so *.a
		rm -rf main.gcda *.so main.gcno
		rm -rf *.o
		rm -rf s21_string.a
		rm -rf gcov_report

rebuild: clean all

.PHONY: all clean test rebild s21_string.a
