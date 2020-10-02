#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void quick_hoare(It beg, It end, Pred predicate){
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
		}
		while(predicate(*j, pivot)){
			j = std::prev(j);
		}
		if(std::distance(i, j) <= 0){
			pivot_place = j;
			break;
		}
		std::swap(*i, *j);
	}
	quick_hoare(beg, pivot_place, predicate);
	quick_hoare(std::next(pivot_place), end, predicate);
}

template<class It>
void quick_hoare(It beg, It end){
    quick_hoare(beg, end, std::greater<typename It::value_type>());
}


template<class It, class Pred>
void quick_lomuto(It beg, It end, Pred predicate){
	if(std::distance(beg, end) <= 0){
		return;
	}

	auto pivot_place = end;
	const auto &pivot = *pivot_place;
	auto i = beg;
	for(auto j=beg; j!=end; j=std::next(j)){
		if(predicate(*j, pivot)){
			std::swap(*i, *j);
			i = std::next(i);
		}
	}
	std::swap(*i, *std::prev(end));
	pivot_place = i;

	quick_lomuto(beg, std::prev(pivot_place), predicate);
	quick_lomuto(std::next(pivot_place), end, predicate);
}

template<class It>
void quick_lomuto(It beg, It end){
    quick_lomuto(beg, end, std::greater<typename It::value_type>());
}


}