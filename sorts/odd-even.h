#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "sort.h"

template<class T>
#ifdef SORT_VERBOSE
void odd_even(std::vector<T> &vec, order o, int begin, int end, int &swaps, int &compares){
#else
void odd_even(std::vector<T> &vec, order o, int begin, int end){
#endif
#ifdef SORT_VIZ
	viz(vec);
#endif
	bool sorted;
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };

	do{
		sorted = true;
		for(int i=begin; i<end-1; i+=2){
			auto &el = vec.at(i);
			auto &el_next = vec.at(i+1);
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
				viz(vec);
#endif
			}
		}
		if(sorted){
			break;
		}
		for(int i=begin+1; i<end-1; i+=2){
			auto &el = vec.at(i);
			auto &el_next = vec.at(i+1);
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
				viz(vec);
#endif
			}
		}
#ifdef SORT_VIZ
		viz(vec);
#endif
	}while(!sorted);
#ifdef SORT_VIZ
	viz(vec);
#endif
}

template<class T>
#ifdef SORT_VERBOSE
void odd_even(std::vector<T> &vec, int &swaps, int &compares){
	odd_even(vec, order::regular, 0, vec.size(), swaps, compares);
}
#else
void odd_even(std::vector<T> &vec){
	odd_even(vec, order::regular, 0, vec.size());
}
#endif