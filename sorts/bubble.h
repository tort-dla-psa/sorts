#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void bubble(It beg, It end, Pred predicate, size_t &compares, size_t &swaps){
	bool sorted;
	do{
		sorted = true;
		auto i = beg;
		auto end_ = std::prev(end);
		while(i != end_){
			auto &el = *i;
			auto &el_next = *std::next(i);
			compares++;
			if(predicate(el, el_next)){
				std::swap(el, el_next);
				sorted = false;
				swaps++;
			}
			i = std::next(i);
		}
	}while(!sorted);
}

template<class It, class Pred>
void bubble(It beg, It end, Pred predicate){
	static size_t swaps, compares;
	bubble(beg, end, predicate, swaps, compares);
}

template<class It>
void bubble(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
	bubble(beg, end, func);
}

}