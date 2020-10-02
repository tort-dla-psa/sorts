#pragma once
#include <algorithm>
#include <functional>

namespace sorts{

template<class It, class Pred>
void selection(It beg, It end, Pred predicate){
    for (auto i = beg; i != end; i = std::next(i)) {
        auto el = i;
        for (auto j = std::next(i); j != end; j = std::next(j)) {
            if (!predicate(*j, *el)){
                el = j;
            }
        }

        if (el != i){ 
            std::swap(*i, *el);
        }
    }
}

template<class It>
void selection(It beg, It end){
    selection(beg, end, std::greater<typename It::value_type>());
}

}