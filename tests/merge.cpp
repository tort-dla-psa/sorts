#include <iostream>
#include <algorithm>
#include <cassert>
#include <iterator>
#include "sorts/merge.h"
#include "utils.h"

template<class T>
void sort(std::list<T> &c){ c.sort(); }
template<class Cont>
void sort(Cont &c){ std::sort(c.begin(), c.end()); }

template<class Cont>
void test_case(Cont &c0){
    Cont c1 = c0;
    merge(c0.begin(), c0.end());
    sort(c1);
    std::copy(c0.begin(), c0.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(c1.begin(), c1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::cout.flush();
    assert(c1 == c0);
}

int main(){
    auto vec = gen_vec<int>(2);
    test_case(vec);
    vec = gen_vec<int>(100);
    test_case(vec);
    vec = gen_vec<int>(1001);
    test_case(vec);

    auto lst = gen_lst<int>(2);
    test_case(lst);
    lst = gen_lst<int>(100);
    test_case(lst);
    lst = gen_lst<int>(1001);
    test_case(lst);
}