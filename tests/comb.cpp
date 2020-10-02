#include <iostream>
#include <algorithm>
#include <cassert>
#include "sorts/comb.h"
#include "utils.h"


int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::comb(beg, end, 1.3); };
    auto elements = {1, 2, 1000, 10001};

    test_sorts<time, int>(elements, lbd);
}