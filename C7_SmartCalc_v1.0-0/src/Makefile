CC = gcc
CFLAG = -Wall -Wextra -Werror
APP = build/s21_calc
BACKEND_FILES = s21_smart_calc.c
BACKEND_FILES_O = s21_smart_calc.o

all: install s21_calc.a test
build:
	mkdir build
	cd ./build/ && qmake ../ && make && mv SmartCalck s21_calc

install: build
	@mkdir -p $(HOME)/Desktop/SmartCalc_v1.0/
	@cp -rf $(APP) $(HOME)/Desktop/SmartCalc_v1.0/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/SmartCalc_v1.0/

dvi:
	open dvi.html

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	cp Makefile *.c *.h *.pro *.cpp *.ui *.user Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/

s21_calc.a:
	$(CC) $(CFLAG) -c $(BACKEND_FILES) -lm
	@ar rcs s21_calc.a $(BACKEND_FILES_O)

test:
	$(CC) $(CFLAG) -c s21_test.c -o test1.o -lm -lrt -lpthread -lsubunit
	$(CC) test1.o s21_calc.a -lcheck -o test2.o -lm -lrt -lpthread -lsubunit
	./test2.o

gcov_report:
	$(CC) --coverage s21_test.c  -o s21_test -lcheck $(BACKEND_FILES) -lm -lrt -lpthread -lsubunit
	./s21_test
	lcov -t "s21_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clean:
	rm -rf *.o *.a
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test
	rm -rf ./build*

rebuild: clean all