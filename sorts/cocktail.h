#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "sort.h"

template<class T>
#ifdef SORT_VERBOSE
void cocktail(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void cocktail(std::vector<T> &arr, order o, int begin, int end){
#endif
#ifdef SORT_VIZ
	viz(arr);
#endif
	bool sorted;
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

	do{
		sorted = true;
		for(size_t i=begin; i<end-1; i++){
			auto &el = arr.at(i);
			auto &el_next = arr.at(i+1);
#ifdef SORT_VERBOSE
			compares++;
#endif
			if(predicate(el, el_next)){
				std::swap(el, el_next);
				sorted = false;
#ifdef SORT_VERBOSE
				swaps++;
#endif
#ifdef SORT_VIZ
				viz(arr);
#endif
			}
		}

		if(sorted){
			break;
		}
		for(size_t i=end-2; i>begin; i--){
			auto &el = arr.at(i);
			auto &el_next = arr.at(i+1);
#ifdef SORT_VERBOSE
			compares++;
#endif
			if(predicate(el, el_next)){
				std::swap(el, el_next);
				sorted = false;
#ifdef SORT_VERBOSE
				swaps++;
#endif
#ifdef SORT_VIZ
				viz(arr);
#endif
			}
		}
	}while(!sorted);
#ifdef SORT_VIZ
	viz(arr);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void cocktail(std::vector<T> &arr, int &swaps, int &compares){
	cocktail(arr, order::regular, 0, arr.size(), swaps, compares);
}
#else
void cocktail(std::vector<T> &arr){
	cocktail(arr, order::regular, 0, arr.size());
}
#endif