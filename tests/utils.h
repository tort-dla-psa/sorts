#pragma once
#include <algorithm>
#include <vector>
#include <numeric>

template<class T>
inline std::vector<T> gen_vec(size_t n){
	std::vector<int> arr(n);
	std::iota(arr.begin(), arr.end(), 0);
	std::random_shuffle(arr.begin(), arr.end());
	return arr;
}