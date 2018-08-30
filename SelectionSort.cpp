#include <iostream>

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

//selection sort
void selectionSort(int * t_data, int t_size){

	int index = 0;

	// go through whole array
	for(int i = 0; i < t_size; ++i){

		// store current index
		index = i;

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

int main(){

	// data to be sorted
	int data[] = { 4, 2, 1, 67, 342, 63, 32, 34, 5, 23, 15};
	int size = 11;

	// print out data before
	std::cout << "Data before.\n";
	printArray(data, size);
	
	// sort array
	selectionSort(data, size);

	// print out data after
	std::cout << "Data after.\n";
	printArray(data, size);

	return 0;
}