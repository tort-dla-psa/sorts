#include <iostream>
#include <chrono>
#include <tuple>
#include "sorts/merge.h"
#include "utils.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::merge(beg, end); };
    auto elements = {1, 2, 1000, 100001};

    test_sorts<time, int>(elements, lbd);
}