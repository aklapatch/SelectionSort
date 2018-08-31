all:
	g++ -g -Og SelectionSort.cpp -o SelectionSort.exe

run: all
	./SelectionSort.exe