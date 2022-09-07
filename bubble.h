// =================================================================
//
// File: bubble.h
// Author: Pedro Perez
// Description: This file contains the implementation of the
//				bubble sort.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef BUBBLE_H
#define BUBBLE_H

#include "header.h"
#include <vector>

// =================================================================
// Performs the bubble sort algorithm on an array
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
int bubbleSort(T *arr, int size) {
	int counter = 0;
	for(int i = size - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr, j, j + 1);
				counter++;
			}
		}
	}
	return counter;
}

// =================================================================
// Performs the bubble sort algorithm on an vector.
//
// @param v, a vector of T elements.
// =================================================================
template <class T>
int bubbleSort(std::vector<T> &v) {
	vector <int> a = v;
	int counter = 0;
  bool bandera = false;
  for(int i = 0; i<a.size(); i++){
    for(int j = 0; j<a.size()-1; j++){
      if(a[j+1] < a[j]){
				counter++;
        swap(a[j+1],a[j]);
        bandera = true;
      }
    }
    if(bandera = false){
      break;
    }
  }
  return counter;
}

#endif /* BUBBLE_H */
