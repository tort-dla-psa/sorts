#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
#ifdef SORT_VERBOSE
void quick_hoare(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void quick_hoare(std::vector<T> &arr, order o, int begin, int end){
#endif
	if(begin>=end){
		return;
	}
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

	int pivot_place = begin;
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
	quick_hoare(arr, o, begin, pivot_place, swaps, compares);
	quick_hoare(arr, o, pivot_place+1, end, swaps, compares);
#else
	quick_hoare(arr, o, begin, pivot_place);
	quick_hoare(arr, o, pivot_place+1, end);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void quick_hoare(std::vector<T> &arr, int &swaps, int &compares){
	quick_hoare(arr, order::regular, 0, arr.size()-1, swaps, compares);
#else
void quick_hoare(std::vector<T> &arr){
	quick_hoare(arr, order::regular, 0, arr.size()-1);
#endif
}


template<class T>
#ifdef SORT_VERBOSE
void quick_lomuto(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void quick_lomuto(std::vector<T> &arr, order o, int begin, int end){
#endif
	if(begin>=end){
		return;
	}
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

	int pivot_place = end;
	const auto &pivot = arr.at(pivot_place);
	auto i = begin;
	for(size_t j=begin; j<end; j++){
#ifdef SORT_VERBOSE
		compares++;
#endif
		if(arr.at(j)<pivot){
			std::swap(arr.at(i), arr.at(j));
			i++;
#ifdef SORT_VERBOSE
			swaps++;
#endif
		}
	}
	std::swap(arr.at(i), arr.at(end));
	pivot_place = i;

#ifdef SORT_VERBOSE
	quick_lomuto(arr, o, begin, pivot_place-1, swaps, compares);
	quick_lomuto(arr, o, pivot_place+1, end, swaps, compares);
#else
	quick_lomuto(arr, o, begin, pivot_place-1);
	quick_lomuto(arr, o, pivot_place+1, end);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void quick_lomuto(std::vector<T> &arr, int &swaps, int &compares){
	quick_lomuto(arr, order::regular, 0, arr.size()-1, swaps, compares);
#else
void quick_lomuto(std::vector<T> &arr){
	quick_lomuto(arr, order::regular, 0, arr.size()-1);
#endif
}