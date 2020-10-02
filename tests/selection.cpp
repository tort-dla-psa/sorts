#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include "sorts/selection.h"
#include "utils.h"

int main(int argc, char* argv[]){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::selection(beg, end); };
    std::vector<int> elements = {1, 2, 5, 1000, 100001};
    if(argc == 2){
        elements = {std::atoi(argv[1])};
    }

    test_sorts<time, int>(elements, lbd);
}