#pragma once
#include <iterator>
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void odd_even(It beg, It end, Pred predicate){
	bool sorted;
	static auto iteration = [&sorted, &predicate](auto it){
		auto &el = *it;
		auto &el_next = *std::next(it);
		if(predicate(el, el_next)){
			std::swap(el, el_next);
			sorted = false;
		}
	};
	do{
		sorted = true;
		for(auto i=beg; std::distance(i, end)>1; i = std::next(i,2)){
			iteration(i);
		}
		if(sorted){ break; }

		for(auto i=std::next(beg); std::distance(i, end)>1; i = std::next(i,2)){
			iteration(i);
		}
	}while(!sorted);
}

template<class It>
void odd_even(It beg, It end){
    odd_even(beg, end, std::greater<typename It::value_type>());
}

}