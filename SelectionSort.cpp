#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <cstdlib>

// swaps data member at specified indices
void swap(int * t_data, int t_i, int t_j){
	// get a total
	t_data[t_i] = t_data[t_i] + t_data[t_j];

	// assign t_i member from total to t_j member
	t_data[t_j] = t_data[t_i] - t_data[t_j];

	// assign t_j member to t_i from total
	t_data[t_i] = t_data[t_i] - t_data[t_j];
}

// prints array argument
void printArray(int * t_data, int t_size){
	for(int i = 0; i < t_size; ++i){
		std::cout << "Member " << i << " = " << t_data[i] << "\n";
	}
	std::cout << "\n";
}

// gets arraysize from user
int getInput(){

	std::string input = "a";
	int times = 0;

	// get input from user
	while( isdigit(input[0]) == 0 && input.find(".") == std::string::npos){
		std::cout << "Please input a integer (100 or less) for the array size and press enter.\n";
		std::cin >> input;
		
		// quit if user enters wrong input too many times
		++times;
		if(times >= 3){
			std::cout << "Exiting.\n";
			exit(1);
		}

		// go back to the beginning if the number is too big
		if( atoi(input.c_str()) > 100){
			std::cout << "100 or less please.\n";
			continue;
		}
	}

	// return int form of input
	return atoi(input.c_str());
}

//selection sort
void SelectionSort(int * t_data, int t_size){

	// go through whole array
	for(int i = 0; i < t_size - 1; ++i){

		// store current index
		int index = i;

		// find index with smallest number
		for(int j = i + 1; j < t_size; ++j){

			if(t_data[j] < t_data[index]){
				index = j;
			}
		}

		// swap least with current data
		if(i != index){
			swap(t_data, i, index);
		}
	}
}

void fillWRandom(int * t_data, int t_size){

	// seed random number generator
	srand(time(NULL));

	// copy random numbers to the array
	while(t_size--){
		t_data[t_size] = rand()%100;
	}
}

int main(){

	try {

		// get input and make array
		int size = getInput();
		int * data = new int[size];

		// get random numbers
		fillWRandom(data,size);

		// print out data before
		std::cout << "Data before.\n";
		printArray(data, size);
		
		// sort array
		SelectionSort(data, size);

		// print out data after
		std::cout << "Data after.\n";
		printArray(data, size);

		delete [] data;

	// in case of allocation failure
	} catch (const std::bad_alloc& e) {

		std::cerr << "Allocation failed! Exception: " << e.what() << "\n";
	}

	return 0;
}
