#pragma once
#include <iterator>
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void cocktail(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
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
		const auto end_ = std::prev(end);
		for(auto i=beg; i!=end_; i = std::next(i)){
			iteration(i);
		}

		if(sorted){ break; }

		for(auto i=std::prev(end_); i!=beg; i = std::prev(i)){
			iteration(i);
		}
	}while(!sorted);
}

template<class It, class Pred>
void cocktail(It beg, It end, Pred predicate){
	static size_t swaps, compares;
	cocktail(beg, end, predicate, swaps, compares);
}

template<class It>
void cocktail(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
	cocktail(beg, end, func);
}

}