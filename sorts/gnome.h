#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
#ifdef SORT_VERBOSE
void gnome(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void gnome(std::vector<T> &arr, order o, int begin, int end){
#endif
#ifdef SORT_VIZ
    viz(arr);
#endif
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };
	size_t pos = 0;
	while(pos<end){
		if(pos == 0){
			pos++;
		}else{
			auto &el = arr.at(pos);
			auto &el_prev = arr.at(pos-1);
#ifdef SORT_VERBOSE
			compares++;
#endif
			if(predicate(el_prev, el)){
				std::swap(el_prev, el);
				pos--;
#ifdef SORT_VERBOSE
				swaps++;
#endif
#ifdef SORT_VIZ
				viz(arr);
#endif
			}else{
				pos++;
			}
		}
	}
#ifdef SORT_VIZ
	viz(arr);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void gnome(std::vector<T> &arr, int &swaps, int &compares){
	gnome(arr, order::regular, 0, arr.size(), swaps, compares);
#else
void gnome(std::vector<T> &arr){
	gnome(arr, order::regular, 0, arr.size());
#endif
}