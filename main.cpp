// =================================================================
//
// File: main.cpp
// Author: Ian Joab Padrón Corona A01708940
// Date: 06-09-2022
//
// =================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile;
	int n, search, number;

	inputFile.open(argv[1], ios::in);
	outputFile.open(argv[2], ios::out);

	inputFile>>n;

	vector<int> numbers(n);
	for (int i=0; i<n; i++) {
		inputFile>>number;
		numbers[i]=number;
	}

	int bubble, selection, insertion;

	bubble=bubbleSort(numbers);

	selection=selectionSort(numbers);

	insertion=insertionSort(numbers);

	outputFile<<bubble<<" "<<selection<<" "<<insertion<<"\n\n";
	inputFile>>search;
	pair<int, int>solution;
	for (int i=0; i<search; i++) {
		inputFile>>number;
		solution=sequentialSearch(numbers, number);
		outputFile<<solution.first<<" "<<solution.second<<" ";
		solution=binarySearch(numbers, number);
		outputFile<<solution.second<<endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
