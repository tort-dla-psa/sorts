#pragma once
#include "sort.h"
#include <vector>
#include <algorithm>
#include <functional>

template<class T>
#ifdef SORT_VERBOSE
void heap(std::vector<T> &arr, order o, int begin, int end, int &swaps, int &compares){
#else
void heap(std::vector<T> &arr, order o, int begin, int end){
#endif
}
