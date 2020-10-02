#include <iostream>
#include <algorithm>
#include <cassert>
#include "sorts/sort.h"
#include "utils.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::odd_even(beg, end); };
    auto elements = {1, 2, 5, 4, 1000, 10001};

    test_sorts<time, int>(elements, lbd);
}