#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void gnome(It beg, It end, Pred predicate){
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

template<class It>
void gnome(It beg, It end){
	gnome(beg, end, std::greater<typename It::value_type>());
}

}