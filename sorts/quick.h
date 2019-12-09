#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
#ifdef SORT_VERBOSE
void quick(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void quick(std::vector<T> &arr, order o, int begin, int end){
#endif
	if(begin>=end){
		return;
	}
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

	int pivot_place = begin+ (end - begin)/2;
	const auto &pivot = arr.at(pivot_place);
	auto i = begin-1;
	auto j = end+1;
	while(true){
		do{
			i++;
#ifdef SORT_VERBOSE
			compares++;
#endif
		}while(predicate(pivot,arr.at(i)));
		do{
			j--;
#ifdef SORT_VERBOSE
			compares++;
#endif
		}while(predicate(arr.at(j),pivot));
		if(i >= j){
			pivot_place = j;
			break;
		}
		std::swap(arr.at(i), arr.at(j));
#ifdef SORT_VERBOSE
		swaps++;
#endif
	}
#ifdef SORT_VERBOSE
	quick(arr, o, begin, pivot_place, swaps, compares);
	quick(arr, o, pivot_place+1, end, swaps, compares);
#else
	quick(arr, o, begin, pivot_place);
	quick(arr, o, pivot_place+1, end);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void quick(std::vector<T> &arr, int &swaps, int &compares){
	quick(arr, order::regular, 0, arr.size()-1, swaps, compares);
#else
void quick(std::vector<T> &arr){
	quick(arr, order::regular, 0, arr.size()-1);
#endif
}