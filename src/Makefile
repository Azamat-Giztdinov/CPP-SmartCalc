CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
OS := $(shell uname)
TESTFILE = ./tests/tests_calc.cc ./tests/tests_credit.cc ./tests/tests.cc
MODFILE = ./model/smartcalcmod.cc ./model/creditcalcmod.cc

ifeq ($(OS),Linux)
FLAGS = -lgtest -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
FYLE = view/smart_calc
PROGOPEN = ./build/smart_calc
PROG = smart_calc

else
FLAGS = -lgtest -lm -lpthread -fprofile-arcs -ftest-coverage
FYLE = view/Smart_Calc.app
PROGOPEN = open ./build/Smart_Calc.app
PROG = Smart_Calc.app
endif

all: install open

install: uninstall
	make clean
	mkdir build
	cd view && qmake && make -j6 && make clean && rm Makefile && cd ../ && mv $(FYLE) build

uninstall:
	rm -rf build/

clean:
	@rm -rf */*.o */*.a */moc_* unit_test
	@rm -rf *.gcno *gcda *.gcov gcov
	@rm -rf report report.info
	@rm -rf *.dSYM
	@rm -rf ./view/.qmake.stash

test: clean
	$(CC) $(CFLAGS) $(TESTFILE) $(MODFILE) $(FLAGS) -o unit_test
	./unit_test

style:
	clang-format -style=Google -n ./*/*.cc ./*/*.h ./*/*.cpp

open:
	$(PROGOPEN)