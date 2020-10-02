#pragma once
#include <algorithm>
#include <functional>
#include <cmath>

namespace sorts{

template<class It, class Pred>
void comb(It beg, It end, double shrink, Pred predicate, size_t &swaps, size_t &compares){
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
            compares++;
            if(predicate(el, el_next)){
                std::swap(el, el_next);
                sorted = false;
                swaps++;
            }
        }
    }while(!sorted);
}

template<class It, class Pred>
void comb(It beg, It end, double shrink, Pred predicate){
    static size_t swaps, compares;
    comb(beg, end, shrink, predicate, swaps, compares);
}

template<class It>
void comb(It beg, It end, double shrink){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
    comb(beg, end, shrink, func);
}

}