#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void quick_hoare(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
	if(std::distance(beg, end)<=0){
		return;
	}

	auto pivot_place = beg;
	const auto &pivot = *pivot_place;
	auto i = beg;
	auto j = std::prev(end);
	while(true){
		while(predicate(pivot, *i)){
			i = std::next(i);
			compares++;
		}
		while(predicate(*j, pivot)){
			j = std::prev(j);
			compares++;
		}
		if(std::distance(i, j) <= 0){
			pivot_place = j;
			break;
		}
		std::swap(*i, *j);
		swaps++;
	}
	quick_hoare(beg, pivot_place, predicate, swaps, compares);
	quick_hoare(std::next(pivot_place), end, predicate, swaps, compares);
}

template<class It, class Pred>
void quick_hoare(It beg, It end, Pred predicate){
    static size_t swaps, compares;
    quick_hoare(beg, end, predicate, swaps, compares);
}

template<class It>
void quick_hoare(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
    quick_hoare(beg, end, func);
}


template<class It, class Pred>
void quick_lomuto(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
	if(std::distance(beg, end) <= 0){
		return;
	}

	auto pivot_place = end;
	const auto &pivot = *pivot_place;
	auto i = beg;
	for(auto j=beg; j!=end; j=std::next(j)){
		compares++;
		if(predicate(*j, pivot)){
			std::swap(*i, *j);
			i = std::next(i);
			swaps++;
		}
	}
	std::swap(*i, *std::prev(end));
	pivot_place = i;

	quick_lomuto(beg, std::prev(pivot_place), predicate, swaps, compares);
	quick_lomuto(std::next(pivot_place), end, predicate, swaps, compares);
}

template<class It, class Pred>
void quick_lomuto(It beg, It end, Pred predicate){
    static size_t swaps, compares;
    quick_lomuto(beg, end, predicate, swaps, compares);
}

template<class It>
void quick_lomuto(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
    quick_lomuto(beg, end, func);
}


}