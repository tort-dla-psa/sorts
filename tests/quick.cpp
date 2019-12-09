#include <iostream>
#include <algorithm>
#include <cassert>
#include "../sorts/quick.h"
#include "utils.h"

void test_case(size_t size){
    auto v0 = gen_vec<int>(2);
    auto v1 = v0;
    auto v2 = v0;
    std::sort(v0.begin(), v0.end());
    quick_hoare(v1);
    quick_lomuto(v2);
    assert(v1 == v0);
    assert(v2 == v0);
}

int main(){
    test_case(2);
    test_case(100);
    test_case(1001);
}