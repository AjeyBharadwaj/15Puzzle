CC=g++
obj = $(src:.cpp=.o)

all:  
	$(CC) main.cpp Algo.cpp LeastPath.cpp -o Puzzle

clean:
	rm -rf Puzzle


