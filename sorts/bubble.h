#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void bubble(It beg, It end, Pred predicate){
	bool sorted;
	do{
		sorted = true;
		auto i = beg;
		auto end_ = std::prev(end);
		while(i != end_){
			auto &el = *i;
			auto &el_next = *std::next(i);
			if(predicate(el, el_next)){
				std::swap(el, el_next);
				sorted = false;
			}
			i = std::next(i);
		}
	}while(!sorted);
}

template<class It>
void bubble(It beg, It end){
	bubble(beg, end, std::greater<typename It::value_type>());
}

}