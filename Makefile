#Makefile
CPP = g++
FLAG = -std=c++11
MAIN = Main.cpp
OBJ = Main.o

all: SRI
SRI: Main.o
       $(CPP) -o SRI -g $(MAIN) $(FLAG)
Main.o: Main.cpp
       $(CPP) -c $(MAIN) $(FLAG)
clean:
       rm -f SRI $(MAIN)
