CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck
TARGET_CAT = cat/s21_cat
TARGET_GREP = grep/s21_grep
TESTTARGET = test/s21_stringTest
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

all: clean s21_cat

s21_cat: $(TARGET_CAT)
	
$(TARGET_CAT): cat/s21_cat.o cat/bash.o
	$(CC) cat/s21_cat.o cat/bash.o $(CFLAGS) $(GCOV) $(LIBS) -o $@

cat/s21_cat.o: cat/s21_cat.c
	$(CC) -c cat/s21_cat.c $(CFLAGS) $(GCOV) $(LIBS) -o $@

cat/bash.o: common/bash.c
	$(CC) -c common/bash.c $(CFLAGS) $(GCOV) $(LIBS) -o $@

s21_grep: $(TARGET_GREP)

$(TARGET_GREP): grep/s21_grep.o grep/bash.o
	$(CC) grep/s21_grep.o grep/bash.o -D_GNU_SOURCE $(CFLAGS) $(GCOV) $(LIBS) -o $@

grep/s21_grep.o: grep/s21_grep.c
	$(CC) -c grep/s21_grep.c -D_GNU_SOURCE $(CFLAGS) $(LIBS) -o $@

grep/bash.o: common/bash.c
	$(CC) -c common/bash.c $(CFLAGS) $(GCOV) $(LIBS) -o $@

$(TESTTARGET): test/testString.o cat/s21_cat.o common/bash.o
	$(CC) test/testString.c cat/s21_cat.c common/bash.c $(CFLAGS) $(LIBS) -o $@

testString.o: test/testString.c grep/s21_grep.h cat/s21_cat.h common/bash.h
	$(CC) -c test/testString.c $(CFLAGS) $(LIBS) -o $@ 
	$(CC) -c cat/s21_cat.c $(CFLAGS) $(LIBS) -o $@
	$(CC) -c common/bash.c $(CFLAGS) $(LIBS) -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

test_cat: s21_cat
	@cat/s21_cat -e cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/s21_cat_result.txt
	@cat -e cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/cat_result.txt
	@cat/s21_cat -b cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/s21_cat_result.txt
	@cat -b cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/cat_result.txt
	@cat/s21_cat -n cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/s21_cat_result.txt
	@cat -n cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/cat_result.txt
	@cat/s21_cat -s cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/s21_cat_result.txt
	@cat -s cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/cat_result.txt
	@cat/s21_cat -t cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/s21_cat_result.txt
	@cat -t cat/Tests/test1.txt cat/Tests/test2.txt cat/Tests/test3.txt cat/Tests/test4.txt >> cat/cat_result.txt
	# @cat/s21_cat -benst cat/Tests/test2.txt >> cat/s21_cat_result.txt
	# @cat -benst cat/Tests/test2.txt >> cat/cat_result.txt


test_grep: s21_grep
	@grep/s21_grep brown grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep brown grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep [a-c] grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep [a-c] grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	# @grep/s21_grep -e 1 grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	# @grep -e 1 grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -i '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -i '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -v '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -v '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -c '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -c '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -l '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -l '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -n '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -n '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt
	@grep/s21_grep -h '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/s21_grep_result.txt
	@grep -h '1' grep/Tests/test1.txt grep/Tests/test2.txt grep/Tests/test3.txt grep/Tests/test4.txt >> grep/grep_result.txt

clean:	
	rm -rf */*.o
	rm -rf gcov_report
	rm -rf test/s21_stringTest
	rm -rf *.o *.so *.a fizz *.gc* *.info report *.out 
	rm -rf cat/s21_cat grep/s21_grep
	rm -rf */*.gcda */*.gcno
		
rebuild: clean all

.PHONY: all clean test gcov_report rebild s21_grep s21_cat
