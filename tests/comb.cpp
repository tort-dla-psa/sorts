#include <iostream>
#include <algorithm>
#include <cassert>
#include "../sorts/comb.h"
#include "utils.h"

void test_case(size_t size){
    auto v0 = gen_vec<int>(size);
    auto v1 = v0;
    sorts::comb(v0.begin(), v0.end(), 1.3);
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