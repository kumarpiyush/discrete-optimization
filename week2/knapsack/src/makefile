all : knapsack

knapsack : knapsack.o greedy.o dp.o
	g++ --std=c++11 -O3 knapsack.o greedy.o dp.o -o knapsack

knapsack.o : knapsack.cpp dp.h greedy.h
	g++ --std=c++11 -O3 -c knapsack.cpp

greedy.o : greedy.cpp greedy.h
	g++ --std=c++11 -O3 -c greedy.cpp

dp.o : dp.cpp dp.h
	g++ --std=c++11 -O3 -c dp.cpp

clean :
	rm -f knapsack *.o
