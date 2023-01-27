CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g 
LIBFLAGS= -lSDL2 -lSDL2_ttf -fopenmp
SRC= $(wildcard ../src/*.cpp)
OBJ= $(wildcard ../OBJ/*.o)
TST= $(wildcard *.cpp)
OBJ_TEST = $(filter-out ../OBJ/main.o, $(OBJ)) $(TST:.cpp=.o)

# .PHONY : testcase $(OBJ_TEST)

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS)  -o $@ $^ $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $< $(LIBFLAGS)

clean :
	rm -f $(OBJ_TEST) testcase

