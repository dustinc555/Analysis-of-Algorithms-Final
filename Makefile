



all: fun_sort.cpp
	g++ -std=c++11 fun_sort.cpp
	
timed:
	g++ -std=c++11 -DTIMED fun_sort.cpp

debug: fun_sort.cpp
	g++ -std=c++11 -DDEBUG fun_sort.cpp
