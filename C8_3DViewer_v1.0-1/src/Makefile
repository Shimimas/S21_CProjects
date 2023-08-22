CC = gcc
CFLAG = -Wall -Wextra -Werror
APP = build/s21_3Dviewer
BACKEND_FILES = s21_3Dviewer.c
BACKEND_FILES_O = s21_3Dviewer.o
TESTTARGET = test/s21_3Dviewer_test
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

all: install s21_3Dviewer.a check test run 

run:
	./build/s21_3Dviewer

build:
	mkdir build
	cd ./build/ && qmake ../ && make && mv 3DViewer.app/Contents/MacOS/3DViewer s21_3Dviewer

install: build
	@mkdir -p $(HOME)/Desktop/s21_3Dviewer_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/s21_3Dviewer_v1.0/

uninstall:
	@rm -rf $(HOME)/Desktop/s21_3Dviewer_v1.0/

dvi: 
	open dvi.html

dist:
	rm -rf Archive_s21_3Dviewer_v1.0/
	mkdir Archive_s21_3Dviewer_v1.0/
	mkdir Archive_s21_3Dviewer_v1.0/src
	cp Makefile *.c *.h *.pro *.cpp *.ui *.html Archive_s21_3Dviewer_v1.0/src/
	tar cvzf Archive_s21_3Dviewer_v1.0.tgz Archive_s21_3Dviewer_v1.0/
	mv Archive_s21_3Dviewer_v1.0.tgz $(HOME)/Desktop/

undist:
	rm -rf Archive_s21_3Dviewer_v1.0/
	rm -rf $(HOME)/Desktop/Archive_s21_3Dviewer_v1.0.tgz 

s21_3Dviewer.a: 
	$(CC) $(CFLAG) -c $(BACKEND_FILES) -lm
	@ar rcs s21_3Dviewer.a $(BACKEND_FILES_O)

gcov_report: clean test/s21_3Dviewer_test.c s21_3Dviewer.c
	-mkdir report
	$(CC) $(GCOV) test/s21_3Dviewer_test.c s21_3Dviewer.c $(CFLAGS) $(ADD_LIB) $(LIBS)
	$(CC) $(GCOV) -c s21_3Dviewer.c $(CFLAGS) $(LIBS) -o s21_3Dviewer.o
	$(CC) $(GCOV) -c test/s21_3Dviewer_test.c $(CFLAGS) $(LIBS) -o test/s21_3Dviewer_test.o
	$(CC) $(GCOV) -o $@ test/s21_3Dviewer_test.o s21_3Dviewer.o $(CFLAGS) $(LIBS)
	-./$@
	gcov test/s21_3Dviewer_test.c
	lcov -t test/s21_3Dviewer_test -o test/s21_3Dviewer_test.info -c -d .
	genhtml -o report test/s21_3Dviewer_test.info
	$(OPEN) ./report/index.html

$(TESTTARGET): s21_3Dviewer.a test/s21_3Dviewer_test.o s21_3Dviewer.o
	$(CC) test/s21_3Dviewer_test.c s21_3Dviewer.o $(CFLAGS) $(LIBS) -o $@
	

test/s21_3Dviewer_test.o: test/s21_3Dviewer_test.c s21_3Dviewer.h
	$(CC) $(CFLAGS) $(LIBS) -c test/s21_3Dviewer_test.c -o $@ 
	$(CC) $(CFLAGS) $(LIBS) -c s21_3Dviewer.c -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

clean:
	rm -rf *.o *.a *.out *.gcda *.gcno *.info *.gcov
	rm -rf test/*.o test/*.a test/*.out test/*.gcda test/*.gcno test/*.info test/*.gcov
	rm -rf s21_3Dviewer_test report
	rm -rf test/s21_3Dviewer_test test/report
	rm -rf gcov_report
	rm -rf s21_3Dviewer
	rm -rf ./build*
	rm -rf ./3DViewer.pro.*
	rm -rf .vscode

rebuild: clean all

check:
	python3 ../materials/linters/cpplint.py --extensions=c s21_3Dviewer.c
	python3 ../materials/linters/cpplint.py --extensions=c s21_3Dviewer.h
