#pragma once
#include <algorithm>
#include <vector>

template<class It>
void merge(It beg, It end){
    auto size = std::distance(beg, end);
    if(size < 2){
        return;
    }
    std::vector<typename It::value_type> copy(beg, end);
    auto left_beg = copy.begin();
    auto left_end = std::next(left_beg, size/2);
    auto right_end = copy.end();
    merge(left_beg, left_end);
    merge(left_end, right_end);
    std::merge(left_beg, left_end, left_end, right_end, beg);
}