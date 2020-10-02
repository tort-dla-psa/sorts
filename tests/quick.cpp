#include <iostream>
#include <algorithm>
#include <cassert>
#include "sorts/quick.h"
#include "utils.h"

void test_case(size_t size){
    auto v0 = gen_vec<int>(size);
    auto v1 = v0;
    auto v2 = v0;
    std::sort(v0.begin(), v0.end());
    sorts::quick_hoare(v1.begin(), v1.end());
    sorts::quick_lomuto(v2.begin(), v2.end());
    assert(v1 == v0);
    assert(v2 == v0);
}

int main(){
    test_case(1);
    test_case(2);
    test_case(3);
    test_case(100);
    test_case(1001);
}