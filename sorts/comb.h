#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

template<class T>
#ifdef SORT_VERBOSE
void comb(std::vector<T> &arr, order o, double shrink, int begin, int end, int &swaps, int &compares){
#else
void comb(std::vector<T> &arr, order o, double shrink, int begin, int end){
#endif
    auto gap = arr.size();
    bool sorted;
	auto predicate = (o == regular)?
		[](const T &el1, const T &el2){ return el1>el2; }
		:
		[](const T &el1, const T &el2){ return el1<el2; };
    do{
        sorted = true;
        gap = std::floor(gap/shrink);
        if(gap<=1){
            gap = 1;
            sorted = true;
        }
        for(size_t i=begin; i+gap<end; i++){
            auto &el = arr.at(i);
            auto &el_next = arr.at(i+gap);
#ifdef SORT_VERBOSE
            compares++;
#endif
            if(predicate(el, el_next)){
                std::swap(el, el_next);
                sorted = false;
#ifdef SORT_VERBOSE
                swaps++;
#endif
            }
        }
    }while(!sorted);
}

template<class T>
#ifdef SORT_VERBOSE
void comb(std::vector<T> &arr, double shrink, int &swaps, int &compares){
    comb(arr, order::regular, shrink, 0, arr.size(), swaps, compares);
}
#else
void comb(std::vector<T> &arr, double shrink){
    comb(arr, order::regular, shrink, 0, arr.size());
}
#endif