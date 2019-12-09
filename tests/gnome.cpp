#include <iostream>
#include <algorithm>
#include <cassert>
#include "../sorts/gnome.h"
#include "utils.h"

void test_case(size_t size){
    auto v0 = gen_vec<int>(2);
    auto v1 = v0;
    gnome(v0);
    std::sort(v1.begin(), v1.end());
    assert(v1 == v0);
}

int main(){
    test_case(2);
    test_case(100);
    test_case(1001);
}