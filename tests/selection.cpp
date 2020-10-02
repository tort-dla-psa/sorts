#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include "sorts/selection.h"
#include "utils.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::selection(beg, end); };
    auto elements = {1, 2, 5, 1000, 10001};

    test_sorts<time, int>(elements, lbd);
}