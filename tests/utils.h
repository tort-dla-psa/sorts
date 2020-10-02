#pragma once
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>

template<class T>
inline std::vector<T> gen_vec(size_t n){
	std::vector<T> arr(n);
	std::iota(arr.begin(), arr.end(), 0);
	std::random_shuffle(arr.begin(), arr.end());
	return arr;
}

template<class T>
inline std::list<T> gen_lst(size_t n){
	auto vec = gen_vec<T>(n);
	return std::list<T>(vec.begin(), vec.end());
}