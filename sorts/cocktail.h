#pragma once
#include <iterator>
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void cocktail(It beg, It end, Pred predicate){
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

template<class It>
void cocktail(It beg, It end){
	cocktail(beg, end, std::greater<typename It::value_type>());
}

}