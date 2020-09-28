#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void selection(It beg, It end, Pred predicate, size_t &swaps, size_t &compares){
    for (auto i = beg; i != end; i = std::next(i)) {
        auto el = i;
        for (auto j = std::next(i); j != end; j = std::next(j)) {
            compares++;
            if (!predicate(*j, *el)){
                el = j;
            }
        }

        if (el != i){ 
            std::swap(*i, *el);
            swaps++;
        }
    }
}

template<class It, class Pred>
void selection(It beg, It end, Pred predicate){
    static size_t swaps, compares;
    selection(beg, end, predicate, swaps, compares);
}

template<class It>
void selection(It beg, It end){
	using T = typename It::value_type;
	static auto func = [](const T &el0, const T &el1){ return el0>el1; };
    selection(beg, end, func);
}

}