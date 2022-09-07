// =================================================================
//
// File: main.cpp
// Author: Ian Joab Padrón Corona A01708940
// Date: 06-09-2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "fstream"
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
	if (argc!=3) {
		cout<<"usage: "<<argv[0]<<"input_file output_file"<<endl;
		return -1;
	}
	inputFile.open(argv[1]);
	if (!inputFile.is_open()) {
		cout<<argv[0]<<" File \""<<argv[1]<<"\" Error al abrir archivo"<<endl;
		return -1;
	}
	outputFile.open(argv[2]);
	if (outputFile.fail()){
		cout << "Error al escribir archivo de salida" << endl;
		return -1;
	}

	outputFile.open(argv[2]);
	inputFile>>n;
	vector<int>numbers(n);
	for (int i=0; i<n; i++) {
		inputFile>>number;
		numbers[i]=number;
	}
	int bubble, selection, insertion;
	vector<int> x=numbers;
	bubble=bubbleSort(x);
	x=numbers;
	selection=selectionSort(x);
	x=numbers;
	insertion=insertionSort(x);
	outputFile<<bubble<<" "<<selection<<" "<<insertion<<endl;
	inputFile>>search;
	pair<int, int>solution;
	for (int i=0; i<search; i++) {
		inputFile>>number;
		solution=sequentialSearch(x, number);
		outputFile<<solution.first<<" "<<solution.second<<" ";
		solution=binarySearch(x, number);
		outputFile<<solution.second<<endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
