all:
	g++ -g SelectionSort.cpp -o SelectionSort.exe

run: all
	./SelectionSort.exe