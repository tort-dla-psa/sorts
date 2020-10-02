#include <iostream>
#include <algorithm>
#include <cassert>
#include "sorts/quick.h"
#include "utils.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd_hoare = [](auto beg, auto end){ sorts::quick_hoare(beg, end); };
    auto lbd_lomuto = [](auto beg, auto end){ sorts::quick_lomuto(beg, end); };
    auto elements = {1, 2, 5, 1000, 10001};

    test_sorts<time, int>(elements, lbd_hoare);
    test_sorts<time, int>(elements, lbd_lomuto);
}