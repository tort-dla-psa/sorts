#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include "sorts/bubble.h"
#include "utils.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::bubble(beg, end); };
    auto elements = {1, 2, 1000, 10001};

    test_sorts<time, int>(elements, lbd);
}