CC = g++-6 --std=c++11 -O3

all : knapsack

knapsack : headers.o knapsack.o greedy.o dp.o bb.o
	$(CC) headers.o knapsack.o greedy.o dp.o bb.o -o knapsack

headers.o : headers.cpp headers.h
	$(CC) -c headers.cpp

knapsack.o : knapsack.cpp dp.h greedy.h headers.h
	$(CC) -c knapsack.cpp

greedy.o : greedy.cpp greedy.h headers.h
	$(CC) -c greedy.cpp

dp.o : dp.cpp dp.h headers.h
	$(CC) -c dp.cpp

bb.o : bb.cpp bb.h headers.h
	$(CC) -c bb.cpp

clean :
	rm -f knapsack *.o
