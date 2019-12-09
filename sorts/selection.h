#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
#ifdef SORT_VERBOSE
void selection(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void selection(std::vector<T> &arr, order o, int begin, int end){
#endif
	bool sorted;
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

    for (size_t i = begin; i < end; i++) {
        int el = i;
        for (size_t j = i+1; j < end; j++) {
#ifdef SORT_VERBOSE
            compares++;
#endif
            if (arr.at(j) < arr.at(el)) {
                el = j;
            }
        }

        if (el != i){ 
            std::swap(arr.at(i), arr.at(el));
#ifdef SORT_VERBOSE
            swaps++;
#endif
        }
    }
}

template<class T>
#ifdef SORT_VERBOSE
void selection(std::vector<T> &arr, int &swaps, int &compares){
	selection(arr, order::regular, 0, arr.size(), swaps, compares);
#else
void selection(std::vector<T> &arr){
	selection(arr, order::regular, 0, arr.size());
#endif
}