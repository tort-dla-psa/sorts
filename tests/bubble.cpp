#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include "../sorts/bubble.h"
#include "utils.h"

void test_case(const size_t &size){
    auto v0 = gen_vec<int>(size);
    auto v1 = v0;
    std::copy(v0.begin(), v0.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    sorts::bubble(v0.begin(), v0.end());
    std::copy(v0.begin(), v0.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::sort(v1.begin(), v1.end());
    assert(v1 == v0);
}

int main(){
    test_case(1);
    test_case(2);
    test_case(3);
    test_case(100);
    test_case(1001);
}