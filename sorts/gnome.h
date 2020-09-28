#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void gnome(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
	auto pos = beg;
	while(pos != end){
		if(pos == beg){
			pos = std::next(pos);
		}else{
			auto &el = *pos;
			auto &el_prev = *std::prev(pos);
			if(predicate(el_prev, el)){
				std::swap(el_prev, el);
				pos = std::prev(pos);
			}else{
				pos = std::next(pos);
			}
		}
	}
}

template<class It, class Pred>
void gnome(It beg, It end, Pred predicate){
    static size_t swaps, compares;
    gnome(beg, end, predicate, swaps, compares);
}

template<class It>
void gnome(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
    gnome(beg, end, func);
}

}