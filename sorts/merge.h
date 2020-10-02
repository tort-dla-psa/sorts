#pragma once
#include <algorithm>
#include <vector>

namespace sorts{

template<class It, class Pred>
void merge(It beg, It end, Pred predicate){
    auto size = std::distance(beg, end);
    if(size < 2){
        return;
    }
    std::vector<typename It::value_type> copy(beg, end);
    auto left_beg = copy.begin();
    auto left_end = std::next(left_beg, size/2);
    auto right_end = copy.end();
    merge(left_beg, left_end, predicate);
    merge(left_end, right_end, predicate);
    std::inplace_merge(left_beg, left_end, right_end, predicate);
    std::move(copy.begin(), copy.end(), beg);
}

template<class It>
void merge(It beg, It end){
    merge(beg, end, std::less<typename It::value_type>());
}

}