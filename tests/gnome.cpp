#include <iostream>
#include <algorithm>
#include <cassert>
#include "utils.h"
#include "sorts/sort.h"

int main(){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::gnome(beg, end); };
    auto elements = {1, 2, 5, 1000, 10001};

    test_sorts<time, int>(elements, lbd);
}