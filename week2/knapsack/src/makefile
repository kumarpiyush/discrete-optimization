all : knapsack

knapsack : headers.o knapsack.o greedy.o dp.o bb.o
	g++ --std=c++11 -O3 headers.o knapsack.o greedy.o dp.o bb.o -o knapsack

headers.o : headers.cpp headers.h
	g++ --std=c++11 -O3 -c headers.cpp

knapsack.o : knapsack.cpp dp.h greedy.h headers.h
	g++ --std=c++11 -O3 -c knapsack.cpp

greedy.o : greedy.cpp greedy.h headers.h
	g++ --std=c++11 -O3 -c greedy.cpp

dp.o : dp.cpp dp.h headers.h
	g++ --std=c++11 -O3 -c dp.cpp

bb.o : bb.cpp bb.h headers.h
	g++ --std=c++11 -O3 -c bb.cpp

clean :
	rm -f knapsack *.o
