all : knapsack

knapsack : knapsack.o greedy.o
	g++-5 --std=c++11 -O3 knapsack.o greedy.o -o knapsack

knapsack.o : knapsack.cpp
	g++-5 --std=c++11 -O3 -c knapsack.cpp

greedy.o : greedy.cpp greedy.h
	g++-5 --std=c++11 -O3 -c greedy.cpp

clean :
	rm -f knapsack *.o
