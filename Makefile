CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g -O3
LIBFLAGS= -lSDL2
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)
# TST_DIR=tests/
# TST= $(wildcard $(TST_DIR)/*.cc)
# OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC = foule

.PHONY : $(SRC) $(EXEC) mvOBJ

all: $(EXEC) mvOBJ

# testcase : 
# 	cd $(TST_DIR) ;  make

# test : testcase
# 	cd $(TST_DIR); ./testcase

$(EXEC): $(OBJ) 
	$(CC) $(CCFLAGS)  $^ -o $@  $(LIBFLAGS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(LIBFLAGS)

mvOBJ:
	mkdir -p OBJ && mv src/*.o ./OBJ

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC) OBJ/*.o
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest

