#pragma once
#include <iterator>
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void odd_even(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
	bool sorted;
	static auto iteration = [&sorted, &compares, &swaps, &predicate](auto it){
		auto &el = *it;
		auto &el_next = *std::next(it);
		compares++;
		if(predicate(el, el_next)){
			std::swap(el, el_next);
			sorted = false;
			swaps++;
		}
	};
	do{
		sorted = true;
		for(auto i=beg; std::distance(i, end)>0; i = std::next(i,2)){
			iteration(i);
		}
		if(sorted){ break; }

		for(auto i=std::next(beg); std::distance(i, end)>0; i = std::next(i,2)){
			iteration(i);
		}
	}while(!sorted);
}

template<class It, class Pred>
void odd_even(It beg, It end, Pred predicate){
	static size_t swaps, compares;
	odd_even(beg, end, predicate, swaps, compares);
}

template<class It>
void odd_even(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
	odd_even(beg, end, func);
}

}