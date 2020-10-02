#pragma once
#include <algorithm>
#include <functional>
#include <cmath>

namespace sorts{

template<class It, class Pred>
void comb(It beg, It end, double shrink, Pred predicate){
    auto gap = std::distance(beg, end);
    bool sorted;
    do{
        sorted = true;
        gap = std::floor(gap/shrink);
        if(gap <= 1){
            gap = 1;
            sorted = true;
        }
        for(auto i=beg; std::next(i, gap) != end; i = std::next(i)){
            auto &el = *i;
            auto &el_next = *std::next(i);
            if(predicate(el, el_next)){
                std::swap(el, el_next);
                sorted = false;
            }
        }
    }while(!sorted);
}

template<class It>
void comb(It beg, It end, double shrink){
	comb(beg, end, shrink, std::greater<typename It::value_type>());
}

}