#include <iostream>
#include <algorithm>
#include <cassert>
#include "utils.h"
#include "sorts/sort.h"

int main(int argc, char* argv[]){
    using time = std::chrono::milliseconds;
    auto lbd = [](auto beg, auto end){ sorts::gnome(beg, end); };
    std::vector<int> elements = {1, 2, 5, 1000, 10000};
    if(argc == 2){
        elements = {std::atoi(argv[1])};
    }

    test_sorts<time, int>(elements, lbd);
}